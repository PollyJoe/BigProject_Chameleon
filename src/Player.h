//
//  Player.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
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

typedef struct
{
    Card *card_inhand[max_card_inhand];
    int score;
}Player;
typedef struct
{
    Player *player[max_player];
}Players;


Players *Players_init();
void Update_Score(Player *player, Card *discard);
void Display_Player(Player *player);
void Display_Dlayers(Players *players);


#endif /* Player_h */
