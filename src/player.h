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
}Player;
typedef struct 
{
    Player *players[player_num];
}Players;

Players *Players_Init();
void destruct_players(Players *ps);
void display_player(const Player *p);
void display_players(const Players *p);
#endif 