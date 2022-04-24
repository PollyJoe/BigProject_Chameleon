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

const int max_card = 5;
const int max_player = 3;
const int deck = 52;

struct Card
{
    int number;
    color c;
};
struct Player
{
    struct Card card[max_card];
    int score;
};

/***********************************************************
Initialization function:
Inittialize the color and number of the card.
Define a struct to contain the number and color of a deck:
  1. Number: 1-13 => A, 2-10, J, Q, K
  2. Color: Spade, Heart, Diamond, Club
************************************************************/
void init(struct Card a[deck])
{
    int i;
    for(i = 0; i < deck; i++)
    {
        a[i].number = i % 13 + 1;
        a[i].c = i % 4;
    }
}

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
    for(int i = 0;i < deck;i++)
    {
        int j = rand()%deck;
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

void deal(struct Player player[max_player], struct Card card[deck])
{
    int i, j;
    for(i = 0; i < max_card; i++)
    {
        for(j = 0; j < max_player; j++)
        {
            player[j].card[i] = card[max_player * i + j];
        }
    }
    
    return;
}
// Use enum instead of magic number, or else you will be confues with what is state 1 and state 2, jsut use "E" or "P" or sth
// There is no need to introduce the rand here, since the cards have been shuffled, you just need to deal from the top, that is random already.
// Actually we use PVE and PVP instead of hvc and cvc hahaha
// In poke game, "deal" means give cards to all people, this is always done by computer or third party, so there is no need to disdinguish to whom the card is dealt.


