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
/******************************************************************************************
Features of cards:
    1. Single card:
        (1) Number: K (0), A (1), 2-10, Q (12), J (11, Chameleon)
        (2) Color
    2. Card stack:
        (1) Data of each card;
        (2) Top of the stack;
        (3) Size of the stack
Operations towards cards:
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
typedef enum { spade, club, diamond, heart, chameleon } Color;      //J is a chameleon

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

bool ifempty(Cardstack *cardstack);
bool iffull(Cardstack *cardstack);
void push(Card *card, Cardstack *cardstack);
Card *pop(Cardstack *cardstack);

void swap(Card *a, Card *b);
Cardstack *init();
void display_card(Card *card);


#endif /* Card_h */
