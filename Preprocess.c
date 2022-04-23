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

//Shuffling function, shuffle the card each game.
//Principle:
//  1. Input: initial card order (1-52)
//  2. Generate a number j ranging from 0 to 51 randomly, take it as the index of original card
//  3. Exchange "card i" with "card j"
//  4. Repeat 2,3
void shuffle(int a[52])
{
    srand((unsigned int)time(NULL));
    for(int i = 0;i < 52;i++)
    {
        int j = rand()%52;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return;
}

//Dealing function, deal the card to players
//Principle:
//  1. :

