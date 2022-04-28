//
//  Game.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#ifndef Game_h
#define Game_h

#include "Card.h"
#include "Player.h"

/***********************************************************************************************
 Process of one game :
    1. Dealing the card: After dealing, there should be 4 cards in each player's hand
    2. Game begins:
        (1) Player 1 take one card from the stack, choose a card and play;
        (2) Other players take turns to play a card if available;
        (3) Once the stack is full, game over and record the score.
    3. Status of the game:
        (1) Normal valid play:
            Same color.
        (2) Chameleon: change the color to any other one
            1) Same number;
            2) Play "J".
        (3) Discard: No card to play or choose to discard deliberately
            Give the point of the discarded card to his counterpart.
        (4) Foul: any play not included in what was mentioned above.
 Props:
    1. Current color of one card
    2. Current number of the card
**********************************************************************************************/
typedef struct
{
    Color current_color;
    int current_num;
} Current;

typedef enum { chame, invalid, valid, discard  } State;


#endif /* Game_h */
