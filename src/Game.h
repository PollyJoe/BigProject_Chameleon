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
#include "Current.h"

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


//Deal the cards
void deal(Cardstack *cardstack, Players *players);
//Judge whether the cards in players' hands are able to be played
bool ifValid(Card *card, Current *current);
//Change the validity of each players' cards
void check_valid(bool (*ifValid)(Card *card, Current *current), Player *player,  Current *current);
//Judge whether it is a chameleon
bool ifChame(Card *card, Current *current);
//Change the color of chameleon card into chameleon
void check_chame(bool (*ifChame)(Card *card, Current *current), Player *player, Current *current);
//Select the card
int select_card(bool (*ifValid)(Card *card, Current *current), bool (*ifChame)(Card *card, Current *current), Player *player, Current *current, bool *nogiveup);
//Check the state of each play
int check_play(Card *cardgiven, bool ifgiveup, Current *current, bool (*ifValid)(Card *card, Current *current));
#endif /* Game_h */
