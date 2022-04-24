//
//  Preprocess.h
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#ifndef CARDS_H_ 
#define CARDS_H_ 

#include <stdio.h>
typedef enum {heart, club, diamond, spade} Color;
static const int color_num  = 4;
static const int sets_size = 13; 
static const int CARDHEAP_SIZE = 52;


typedef struct 
{
    int number;
    Color color;
}Card;
typedef struct 
{
    Card *cards[CARDHEAP_SIZE];
    int top;
}CardStack;


void CardStack_Init(CardStack *stack);
void displayCard(const Card *card);
void display_CardHeap(const CardStack *stack);




#endif /* Preprocess_h */
