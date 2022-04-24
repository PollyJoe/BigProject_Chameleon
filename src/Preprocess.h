//
//  Preprocess.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/24.
//

#ifndef PREPROCESS
#define PREPROCESS

#include <stdio.h>
/*****************************************************************************
Players and props:
1. Props:
    (1) Number: related to the score
    (2) Color: enum type, control the color during each game
 2. Players:
    (1) Card
    (2) Score
 *****************************************************************************/
typedef enum { spade, club, diamond, heart } color;
extern const int max_card;
extern const int max_player;
extern const int deck;

void init(struct Card a[deck]);                                                         //Initialize a deck
void shuffle(struct Card a[deck]);                                                      //Shuffle the deck
void deal(struct Player player[max_player], struct Card card[deck]);                    //Deal the card to each player


#endif /* _PREPROCESS_H_ */
