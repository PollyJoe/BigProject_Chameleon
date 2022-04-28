//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//

#include <stdio.h>
#include "Card.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
int main()
{
    //Print the welcome interface for command line mode
    FILE *fp;
    char ch;
    fp = fopen("Chame_slant.txt","r");
    if(fp == NULL) printf("ERROR!");
    else
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    }
    
    //Debug the game
    Cardstack *cardstack = Cardstack_init();
    Players *players = Players_init();
    for(int i = 0; i < max_player * max_card_inhand; i++)
    {
        players->player[i % max_player]->card_inhand[i / max_player] = pop(cardstack);
    }
    Display_Players(players);
    printf("\n");
    for(int i = 0; i < max_player; i++)
    {
        Card *card = givecard(players->player[i], 0);
        printf("The first card of player %d is : ", i + 1);
        display_card(card);
        printf("\n");
        takecard(players->player[i], cardstack);
    }
    printf("\n");
    Display_Players(players);
    destruct_cardstack(cardstack);
    return 0;
}
