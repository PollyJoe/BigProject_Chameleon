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

const Card* pop(CardStack *stack){
    const Card* card;
    if(ifempty(stack)) {return NULL; printf("Pop Error!");}
    else
        return card = stack->cards[stack->top--]; 
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
Define a struct to contain the number and color of a deck:
  1. Number: 1-13 => A, 2-10, J, Q, K
  2. Color: Spade, Heart, Diamond, Club
************************************************************/
void swap(int *i, int *j){
    int k;
    k = *j; *j = *i; *i = k;
}

void CardStack_Init(CardStack *stack){
    stack->top = 0;
    int n[CARDHEAP_SIZE];
    for (int i = 0; i < CARDHEAP_SIZE; i++) n[i] = i;

    srand((unsigned int)time(NULL));
    //shuffle the series
    for (int i = 0; i < CARDHEAP_SIZE; i++)
    {
        int j = rand() % CARDHEAP_SIZE;
        swap(&n[i], &n[j]);    
    }
    int k = 0;
    while (!isfull(stack))
    {
       Card *card = malloc(sizeof(Card));
       card->color = n[k] % color_num;
       card->number = n[k] % sets_size + 1;  
       push(stack, card);
       k++;
    }   
}

void displayCard(const Card *card){
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
Dealing function:
Deal cards to players before the game starts, including human-player mode and computer-player mode.
Principle:
  1. The function includes two modes: hvc mode and cvc mode
      (1) If you choose hvc mode:
          Human player choose the card number manually according to the prompt;
          Computer player choose the card based on random numbers;
      (2) If you choose cvc mode:
          Two computer players choose their card based on random numbers;
  2. To avoid duplication, an interal array is used to store the numbers of cards having already been chosen
************************************************************/

//void deal(struct Player player[2], struct Card card[52], int state)
//{
//    int i, j;
//    int cardnum[10];//Card that has been dealed
//    if(state == 1)//Computer-Computer mode
//    {
//        for(i = 0;i < 4;i++)
//        {
//            srand((unsigned int)time(NULL));
//            //Deal card to player 1
//            int num1 = rand()%52;
//            for(j = 0;j < 2 * i;j++)//Avoid duplication
//            {
//                if(num1 == cardnum[j])
//                    num1 = rand()%52;
//            }
//            cardnum[2 * i] = num1;
//            player[0].cards[i] = card[num1];
//            
//            
//            //Deal card to player 2
//            int num2 = rand()%52;
//            for(j = 0;j < 2 * i + 1;j++)//Avoid duplication
//            {
//                if(num2 == cardnum[j])
//                    num2 = rand()%52;
//            }
//            cardnum[2 * i + 1] = num2;
//            player[1].cards[i] = card[num2];
//        }
//    }
//    else if(state == 2)
//    {
//        for(i = 0;i < 4;i++)
//        {
//            int num1;
//            printf("please choose the number of your card %d:\n", i + 1);
//            scanf("%d", &num1);
//            for(j = 0;j < 2 * i;j++)
//            {
//                if(num1 == cardnum[j])
//                {
//                    printf("This card has been taken! Choose another one:\n");
//                    scanf("%d", &num1);
//                }
//            }
//            cardnum[2 * i] = num1;
//            player[0].cards[i] = card[num1];
//            
//            srand((unsigned int)time(NULL));
//            int num2 = rand()%52;
//            for(j = 0;j < 2 * i + 1;j++)
//            {
//                if(num2 == cardnum[j])
//                    num2 = rand()%52;
//            }
//            cardnum[2 * i + 1] = num2;
//            player[1].cards[i] = card[num2];
//        }
//    }
//    return;
//}
// Use enum instead of magic number, or else you will be confues with what is state 1 and state 2, jsut use "E" or "P" or sth
// There is no need to introduce the rand here, since the cards have been shuffled, you just need to deal from the top, that is random already.
// Actually we use PVE and PVP instead of hvc and cvc hahaha
// In poke game, "deal" means give cards to all people, this is always done by computer or third party, so there is no need to disdinguish to whom the card is dealt.


