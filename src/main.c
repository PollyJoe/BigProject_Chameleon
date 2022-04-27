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
    Cardstack *cardstack = Cardstack_init();
    Players *players = Players_init();
    srand((unsigned int)time(NULL));
    for(int i = 0; i < max_player; i++)
    {
        for(int j = 0; j < max_card_inhand; j++)
        {
            players->player[i]->card_inhand[j] = cardstack->cards[rand()%cardstack_size];
        }
    }
    Display_Dlayers(players);
    
    return 0;
}
