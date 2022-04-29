//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//
#include "Game.h"
#include "Display_interface.h"
int main()
{
    //Print the welcome interface for command line mode
    Display_welcome();
    
    Cardstack *cardstack = Cardstack_init();
    //Debug the game
    Players *players = Players_init();
    Current *current;
    current = (Current*)malloc(sizeof(Current));
    current->current_color = spade;
    current->current_num = 8;
    bool nogiveup;
    Card *play[2];
    for(int i = 0; i < 2; i++)
        play[i] = (Card*)malloc(sizeof(Card));
    deal(cardstack, players);
    Display_Players(players);
    
    for(int i = 0; i < max_player; i++)
    {
        play[i] = givecard(players->player[i], select_card(ifValid, players->player[i], current, &nogiveup));
        printf("Player %d played:", i + 1);
        display_card(play[i]);
        printf("\n");
    }
    Display_Players(players);
    Display_Exit();
    return 0;
}
