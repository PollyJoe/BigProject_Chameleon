//
//  Player.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#include "Player.h"
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
/********************************************************************************************
 Basical operations upon players:
    1. Initialize the players
    2. Update the score;
    3. Display information of one player; (p.s. In EVP mode, only human player's info will be displayed during the game)
    4. Display information of all the players (p.s. Only used in PVP mode)
**********************************************************************************************/
Players *Players_init(void)                                                 //Initialize the players
{
    Players *players = (Players*)malloc(sizeof(Players));
    //Initialize each player
    int i, j;
    for(i = 0; i < max_player; i++)
    {
        players->player[i] = (Player*)malloc(sizeof(Player));
        players->player[i]->score = 0;
        for(j = 0; j < max_card_inhand; j++)
        {
            players->player[i]->card_inhand[j] = NULL;
            players->player[i]->null_slot = max_card_inhand - 1;
        }
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

void Display_Players(Players *players)                                  //Display the information of all the players
{
    int i;
    for(i = 0; i < max_player; i++)
    {
        printf("Player %d:", i + 1);
        Display_Player(players->player[i]);
    }
}

/***********************************************************************************************
 Basical game operations:
    1. Take one card from the stack;
    2. Give a card;
*************************************************************************************************/
void takecard(Player *player, Cardstack *cardstack)                     //Take a card from the cardstack
{
    player->card_inhand[player->null_slot] = pop(cardstack);
}

Card *givecard(Player *player, int position)                            //Give a card
{
    Card *card = player->card_inhand[position];
    player->card_inhand[position] = NULL;
    player->null_slot = position;
    return card;
}

void Destruct_players(Players *players)
{
    int i;
    for(i = 0; i < max_player; i++)
        free(players->player[i]);
    free(players);
}
