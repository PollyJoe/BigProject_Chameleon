//
//  Player.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#include "Player.h"
#include "Card.h"
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************************
 Basical operations upon players:
    1. Initialize the players
    2. Update the score;
    3. Display information of one player; (p.s. In EVP mode, only human player's info will be displayed during the game)
    4. Display information of all the players (p.s. Only used in PVP mode)
**********************************************************************************************/
Players *Players_init()                                                 //Initialize the players
{
    Players *players = (Players*)malloc(sizeof(Players));
    //Initialize each player
    int i, j;
    for(i = 0; i < max_player; i++)
    {
        players->player[i] = (Player*)malloc(sizeof(Player));
        players->player[i]->score = 0;
        for(j = 0; j < max_card_inhand; j++)
            players->player[i]->card_inhand[j] = NULL;
    }
    return players;
}

void Update_Score(Player *player, Card *discard)                        //Update the score
{
    player->score += get_point(discard);
}

void Display_Player(Player *player)                                     //Display information of one player
{
    printf("Cards in hand:\n");
    int i;
    for(i = 0; i < max_card_inhand; i++)
    {
        display_card(player->card_inhand[i]);
        printf("\n");
    }
}

void Display_Dlayers(Players *players)
{
    int i;
    for(i = 0; i < max_player; i++)
    {
        printf("Player %d:", i+1);
        Display_Player(players->player[i]);
    }
}

/***********************************************************************************************
 Basical game operations:
    1. Take one card from the stack;
    2. Give a card;
*************************************************************************************************/