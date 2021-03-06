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
        (3) Empty positions
        (4) Numbers of valid cards
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
static const int max_player = 2;

typedef struct
{
    Card *card_inhand[max_card_inhand];
    int score;
    int null_slot;
    bool valid[max_card_inhand];
    bool chame[max_card_inhand];
    bool nogiveup;
} Player;
typedef struct
{
    Player *player[max_player];
} Players;

//Initialize the players
Players *Players_init(void);
//Update the score
void Update_Score(Player *player, int point);
//Update the score for the whole group
void Update_Scores(Players *players, int point);
//Judge whether all the cards have been played
bool ifHaveCard(Players *players);
//Display information of one player
void Display_Player(Player *player);
//Display the information of all the players
void Display_Players(Players *players);
//Take a card from the cardstack
void takecard(Player *player, Cardstack *cardstack);
//Give a card
Card *givecard(Player *player, int position);
//Destruct players
void Destruct_players(Players *players);
#endif /* Player_h */
