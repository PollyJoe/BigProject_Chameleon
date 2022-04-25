//
//  Preprocess.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

#include "Cards.h"

/***********************************************************
Functions used for stack
************************************************************/
bool ifempty(const CardStack *stack){
    return (stack->top == -1) ? true : false;
}
bool isfull(const CardStack * stack){
    return (stack->top == CARDHEAP_SIZE) ? true : false;
}

Card* pop(CardStack *stack){
    Card* card;
    if(ifempty(stack)) {printf("Pop Error!");return NULL; }
    else
        return card = stack->cards[--stack->top]; 
}

void push(CardStack *stack, Card *card){
    if(isfull(stack)) printf("Push Error!");
    else stack->cards[stack->top++] = card; 
}

const Card* peek(const CardStack *stack){
    return stack->cards[stack->top];
}
/***********************************************************
Initialization function:
Inittialize the color and number of the card.
  1. Number: 1-13 => A, 2-10, J, Q, K
  2. Color: Spade, Heart, Diamond, Club
************************************************************/
void swap(int *i, int *j){
    int k;
    k = *j; *j = *i; *i = k;
}

CardStack * CardStack_Init(){
    CardStack *stack = malloc(sizeof(CardStack));
    stack->top = 0;
    int n[CARDHEAP_SIZE];
    for (int i = 0; i < CARDHEAP_SIZE; i++) n[i] = i;

    srand((unsigned int)time(NULL));
    //shuffle the series
    for (int i = 0; i < CARDHEAP_SIZE; i++)
        swap(&n[i], &n[rand() % CARDHEAP_SIZE]);    
    int k = 0;
    while (!isfull(stack))
    {
       Card *card = malloc(sizeof(Card));
       card->color = n[k] % color_num;
       card->number = n[k] % sets_size + 1;  
       push(stack, card);
       k++;
    }   
    return stack;
}

int getpoint(const Card *card){
    int point = 0;
    if((card->number > 0) && (card->number < 11)) point = card->number;
    else if (card->number == 12) point = 12;
    else if (card->number == 13) point = 0;
    else {
        printf("You can not give up this card: ");
        displayCard(card);
    }
    return point;
}

/***********************************************************
Card display function
************************************************************/
void displayCard(const Card *card){
   if(card == NULL) return ;
   switch (card->color)
   {
   case spade:  printf("Spade"); break;
   case heart:  printf("Heart"); break;
   case club:  printf("Club"); break;
   case diamond:  printf("Diamond"); break;
   default:
       break;
   }
   printf("%d\n", card->number);
}
void display_CardHeap(const CardStack *stack){
    for (int i = 0; i < CARDHEAP_SIZE; i++)
        displayCard(stack->cards[i]);
}

/***********************************************************
Card Stack destructor
************************************************************/
void destruct_cardstack(CardStack *stack){
    for (int i = 0; i < CARDHEAP_SIZE; i++)
       free(stack->cards[i]);
    free(stack);
}

