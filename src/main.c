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
    for(int i = 0; i < max_player * max_card_inhand; i++)
    {
        players->player[i % max_player]->card_inhand[i / max_player] = pop(cardstack);
    }
    Display_Players(players);
    printf("\n");
    for(int i = 0; i < max_player; i++)
    {
        Card *card = givecard(players->player[i], 1);
        printf("The second card of player %d is : ", i + 1);
        display_card(card);
        printf("\n");
        takecard(players->player[i], cardstack);
    }
    printf("\n");
    Display_Players(players);
    
    return 0;
}
