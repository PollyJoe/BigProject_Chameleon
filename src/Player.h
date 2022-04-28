//
//  Player.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#ifndef Player_h
#define Player_h

#include "Card.h"

/***************************************************************************************
 Features of players:
    1. One player:
        (1) Score;
        (2) Cards in hand
    2. A group of players:
        (1) Players
 Basical operations of players:
    1. Calculate and update the score;
    2. Display the card in hand;
    3. Display the score of each player;
    4. Display the players;
 What can players do:
    1. Take a card from the stack;
    2. Give a card;
*****************************************************************************************/
static const int max_card_inhand = 5;
static const int max_player = 3;

typedef struct                                                  //Set a type to describe one player
{
    Card *card_inhand[max_card_inhand];
    int score;
    int null_slot;
    bool valid[max_card_inhand];                                //Judge whether his cards are available
}Player;
typedef struct                                                  //Set a type to describe a group of players
{
    Player *player[max_player];
}Players;


Players *Players_init();                                        //Initialize the players
void Update_Score(Player *player, Card *discard);               //Update the score
void Display_Player(Player *player);                            //Display information of one player
void Display_Players(Players *players);                         //Display the information of all the players
void takecard(Player *player, Cardstack *cardstack);            //Take a card from the cardstack
Card *givecard(Player *player, int position);                   //Give a card

#endif /* Player_h */
