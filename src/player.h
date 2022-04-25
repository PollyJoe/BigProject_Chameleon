#ifndef PLAYER_H_
#define PLAYER_H_ 
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Cards.h"

static const int playercards_capacity = 5;
static const int player_num = 2;
typedef struct 
{
    Card *cards_on_hand[playercards_capacity];
    bool deployable[playercards_capacity];
    int score;
    int null_position;
}Player;
typedef struct 
{
    Player *players[player_num];
}Players;

Players *Players_Init();
void destruct_players(Players *ps);
void increasescore(Player *p, int point);
Card *givecard(Player *p, int position);// give our give out the card
void getcard(Player *p, CardStack *stack);
void updatescore(Player *p, const Card *card);
void display_player(const Player *p);
void display_players(const Players *p);
void display_score(Players *ps);
#endif 