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
struct Card
{
    int number;
    char* color;
};
struct Player 
{
    struct Card cards[5];
    int score;
};


void init(struct Card a[52]);                                                           //Initialize a deck
void shuffle(struct Card a[52]);                                                        //Shuffle the deck
void deal(struct Player player[2], struct Card card[52], int state);                    //Deal the card to each player





#endif /* Preprocess_h */
