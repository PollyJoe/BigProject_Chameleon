//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//
#include "Game.h"
#include "Display_interface.h"
#include "Current.h"
int main()
{
    //Print the welcome interface for command line mode
    ////Display_welcome();
    
    //Debug the game
    
    Cardstack *cardstack = Cardstack_init();
    Players *players = Players_init();
    Current *current;
    current = (Current*)malloc(sizeof(Current));
    current->current_color = spade;
    current->current_num = 10;
    deal(cardstack, players);
    //Display_Players(players);
    while(!ifEmpty(cardstack))
    {
        int point = 0;
        Display_current(current);
        printf("\n");
        Display_Players(players);
        printf("\n*****************\n");
        Card *play[max_player];
        for(int i = 0; i < max_player; i++)
        {
            play[i] = givecard(players->player[i], select_card(ifValid, ifChame, players->player[i], current, &players->player[i]->nogiveup));
            point += check_play(play[i], players->player[i]->nogiveup, current, ifValid);
            takecard(players->player[i], cardstack);
        }
        Update_Scores(players, point);
        Display_Players(players);
        Display_current(current);
        printf("\n***************************************\n");
    }
    
    return 0;
}
