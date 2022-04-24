//
//  Preprocess.h
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#ifndef Preprocess_h
#define Preprocess_h

#include <stdio.h>
//Players and props
//Card:
//  1. Number
//  2. Color
//Player:
//  1. Card
//  2. Score
struct CARD
{
    int number;
    char* color;
};
struct PLAYER
{
    struct CARD playercard[5];
    int score;
};


void init(struct CARD a[52]);                                                           //Initialize a deck
void shuffle(struct CARD a[52]);                                                        //Shuffle the deck
void deal(struct PLAYER player[2], struct CARD card[52], int state);                    //Deal the card to each player





#endif /* Preprocess_h */
