//
//  Preprocess.h
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#ifndef CARDS_H_ 
#define CARDS_H_ 

#include <stdio.h>
#include <stdbool.h> 
typedef enum {heart, club, diamond, spade, PANACEA} Color;
static const int color_num  = 4;
static const int sets_size = 13; 
static const int CARDHEAP_SIZE = 52;
static const int panacea = 11;// J is panacea card

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


CardStack * CardStack_Init();
void destruct_cardstack(CardStack *stack);

int getpoint(const Card *card);
void displayCard(const Card *card);
void display_CardHeap(const CardStack *stack);
Card* pop(CardStack *stack);
bool ifempty(const CardStack *stack);

#endif /* Preprocess_h */
