//
//  Card.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//

#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
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
***********************************************************************************************/
static const int cardstack_size = 52;                               //Size of the card heap
static const int color_num = 4;                                     //Number of colors of a normal deck of poke
static const int set_size = 13;                                     //A set of one color
typedef enum { spade, club, diamond, heart, chameleon} Color;      //J is a chameleon

typedef struct
{
    int number;
    Color c;
} Card;
typedef struct
{
    Card *cards[cardstack_size];
    int top;
} Cardstack;

//Judge whether the stack is empty
bool ifEmpty(Cardstack *cardstack);
//Judge whether the stack is full
bool ifFull(Cardstack *cardstack);
//Put the card into the stack
void push(Card *card, Cardstack *cardstack);
//Take the card from the stack
Card *pop(Cardstack *cardstack);
//Swap two cards
void swap(Card *a, Card *b);
//Initialize the stack and shuffle
Cardstack *Cardstack_init(void);
//Display info of one card
void display_card(Card *card);
//Display info of the whole cardstack
void display_cardstack(Cardstack *cardstack);
//Get the point of each card
int get_point(Card *card);
//Destruct the stack
void destruct_cardstack(Cardstack *cardstack);
#endif /* Card_h */
