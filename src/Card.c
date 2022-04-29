//
//  Card.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//

#include "Card.h"
#include <stdio.h>
/******************************************************************************************
 Features of cards:
    1. Single card:
        (1) Number: K (0), A (1), 2-10, Q (12), J (11, Chameleon)
        (2) Color
    2. Card stack:
        (1) Data of each card;
        (2) Top of the stack;
        (3) Size of the stack
 Basical operations towards cards:
    1. Initialize the cardstack and shuffle the cards;
    2. Transfer the number of the card into different points;
    3. Judge the status of the stack:
        (1) Full;
        (2)Empty.
    4. Display the card in each player's hand;
***********************************************************************************************
 Judge the state of the cardstack:
    1. Whether the cardstack is empty;
    2. Whether the cardstack is full;
***********************************************************************************************/
bool ifEmpty(Cardstack *cardstack)                  //Judge whether the stack is empty
{
    return (cardstack->top == -1) ? true : false;
}
bool ifFull(Cardstack *cardstack)                   //Judge whether the stack is full
{
    return (cardstack->top == cardstack_size) ? true : false;
}

/************************************************************************
 Operate the cards of the cardstack:
    1. Put cards into the stack;
    2. Take the card from the stack;
    3. Initialize the cardstack and shuffle the card;
***************************************************************************/

void push(Card *card, Cardstack *cardstack)         //Operation 1: Put the card into the stack
{
    if(!ifFull(cardstack))
        cardstack->cards[cardstack->top++] = card;
}

Card *pop(Cardstack *cardstack)                     //Operation 2: Take the card from the stack
{
    Card *card;
    if(ifEmpty(cardstack))
        return NULL;
    else
        card = cardstack->cards[--cardstack->top];
    return card;
}

void swap(Card *a, Card *b)                         //Swap two cards
{
    Card temp;
    temp = *a; *a = *b; *b = temp;
}

Cardstack *Cardstack_init(void)                         //Operation 3: Initialize the stack and shuffle
{
    Cardstack *cardstack;
    cardstack = (Cardstack*)malloc(sizeof(Cardstack));
    cardstack->top = 0;
    int i;
    //Initialize the cards
    for(i = 0; i < cardstack_size; i++)
    {
        cardstack->cards[i] = (Card*)malloc(sizeof(Card));
        cardstack->cards[i]->number = i % set_size;
        cardstack->cards[i]->c = (Color)i % color_num;
        cardstack->top++;
    }
    //Shuffle
    srand((unsigned int)time(NULL));
    for(i = 0; i < cardstack_size; i++)
        swap(cardstack->cards[i], cardstack->cards[rand()%cardstack_size]);
    return cardstack;
}

/***********************************************************************
 Display the card
*************************************************************************/
void display_card(Card *card)
{
    if(card == NULL)
        printf("");
    else
    {
        switch(card->c)
        {
            case spade:printf("Spade ");break;
            case club:printf("Club ");break;
            case diamond:printf("Diamond ");break;
            case heart:printf("Heart ");break;
            default:break;
        }
        if(card->number >=2 && card->number <= 10)
            printf("%d", card->number);
        else if(card->number == 0)
            printf("K");
        else if(card->number == 1)
            printf("A");
        else if(card->number == 12)
            printf("Q");
        else
            printf("J");
    }
}
void display_cardstack(Cardstack *cardstack)
{
    int i;
    for(i = 0; i < cardstack_size; i++)
    {
        display_card(cardstack->cards[i]);
        printf("\n");
    }
}

/************************************************************************
 Get the point of each card ( only used when the player decide to discard his card )
**************************************************************************/
int get_point(Card *card)
{
    int point = 0;
    if(card->number != 11) point = card->number;
    else printf("This is a Chameleon!\n");
    return point;
}

/*********************************************************************************
 Destruct a cardstack
************************************************************************************/
void destruct_cardstack(Cardstack *cardstack)
{
    int i;
    for(i = 0; i < cardstack_size; i++)
        free(cardstack->cards[i]);
    free(cardstack);
}
