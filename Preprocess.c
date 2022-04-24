//
//  Preprocess.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//
//This is a pre-process module, including shuffling, allocating, and player setting.


#include "Preprocess.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialization function, inittialize the color and number of the card.
//Define a struct to contain the number and color of a deck.
//  1. Number: 1-13 => A, 2-10, J, Q, K
//  2. Color: Spade, Heart, Diamond, Club
void init(struct CARD a[52])
{
    int i;
    for(i = 0;i < 12;i++)
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

//Shuffle function, shuffle the card each game.
//Principle:
//  1. Input: initial card order (1-52)
//  2. Generate a number j ranging from 0 to 51 randomly, take it as the index of original card
//  3. Exchange "card i" with "card j"
//  4. Repeat 2,3
void shuffle(struct CARD a[52])
{
    srand((unsigned int)time(NULL));
    for(int i = 0;i < 52;i++)
    {
        int j = rand()%52;
        struct CARD temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        printf("%s %d\n", a[i].color, a[i].number);
        printf("\n");
    }
    return;
}

//Dealing function, deal the card to players
//Principle:
//  1. :

