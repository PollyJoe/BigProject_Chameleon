//
//  Preprocess.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include "Preprocess.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************************************
Initialization function:
Inittialize the color and number of the card.
Define a struct to contain the number and color of a deck:
  1. Number: 1-13 => A, 2-10, J, Q, K
  2. Color: Spade, Heart, Diamond, Club
************************************************************/
void init(struct Card a[52])
{
    int i;
    for(i = 0;i < 13;i++)
    {
        a[i].number = i + 1;
        a[i].color = "Spade";
    }
    for(i = 13;i < 26;i++)
    {
        a[i].number = i - 12;
        a[i].color = "Heart";
    }
    for(i = 26;i < 39;i++)
    {
        a[i].number = i - 25;
        a[i].color = "Diamond";
    }
    for(i = 39;i < 52;i++)
    {
        a[i].number = i - 38;
        a[i].color = "Club";
    }
}

// A cooler version for init if you use enum
//void Cards_Init(struct Card a[52]){
//    for (int i = 0; i < 52; i++)
//    {
//        a[i].number = i % 12 +1;
//        a[i].color = i % 4;
//    }
//}


/***********************************************************
Shuffle function:
Shuffle the card each game.
Principle:
  1. Input: initial card order (1-52)
  2. Generate a number j ranging from 0 to 51 randomly, take it as the index of original card
  3. Exchange "card i" with "card j"
  4. Repeat 2,3
************************************************************/
void shuffle(struct Card a[52])
{
    srand((unsigned int)time(NULL));
    for(int i = 0;i < 52;i++)
    {
        int j = rand()%52;
        struct Card temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return;
}
// If you use Card* instead of Card, you need to swap pointer rather than the struct itself, which will be much more efficient.

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

void deal(struct Player player[2], struct Card card[52], int state)
{
    int i, j;
    int cardnum[10];//Card that has been dealed
    if(state == 1)//Computer-Computer mode
    {
        for(i = 0;i < 4;i++)
        {
            srand((unsigned int)time(NULL));
            //Deal card to player 1
            int num1 = rand()%52;
            for(j = 0;j < 2 * i;j++)//Avoid duplication
            {
                if(num1 == cardnum[j])
                    num1 = rand()%52;
            }
            cardnum[2 * i] = num1;
            player[0].cards[i] = card[num1];
            
            
            //Deal card to player 2
            int num2 = rand()%52;
            for(j = 0;j < 2 * i + 1;j++)//Avoid duplication
            {
                if(num2 == cardnum[j])
                    num2 = rand()%52;
            }
            cardnum[2 * i + 1] = num2;
            player[1].cards[i] = card[num2];
        }
    }
    else if(state == 2)
    {
        for(i = 0;i < 4;i++)
        {
            int num1;
            printf("please choose the number of your card %d:\n", i + 1);
            scanf("%d", &num1);
            for(j = 0;j < 2 * i;j++)
            {
                if(num1 == cardnum[j])
                {
                    printf("This card has been taken! Choose another one:\n");
                    scanf("%d", &num1);
                }
            }
            cardnum[2 * i] = num1;
            player[0].cards[i] = card[num1];
            
            srand((unsigned int)time(NULL));
            int num2 = rand()%52;
            for(j = 0;j < 2 * i + 1;j++)
            {
                if(num2 == cardnum[j])
                    num2 = rand()%52;
            }
            cardnum[2 * i + 1] = num2;
            player[1].cards[i] = card[num2];
        }
    }
    return;
}
// Use enum instead of magic number, or else you will be confues with what is state 1 and state 2, jsut use "E" or "P" or sth
// There is no need to introduce the rand here, since the cards have been shuffled, you just need to deal from the top, that is random already.
// Actually we use PVE and PVP instead of hvc and cvc hahaha
// In poke game, "deal" means give cards to all people, this is always done by computer or third party, so there is no need to disdinguish to whom the card is dealt.


