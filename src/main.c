//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include "game.h"
int main(int argc, const char * argv[])
{
    CardStack *stack = CardStack_Init();
    Players *players = Players_Init();
    Deck *deck = Deck_Init(); 
    deal(stack, players);
    display_players(players);
    int turn_num = 0;
    while (!ifempty(stack))
        play_a_turn(players, stack, deck, turn_num++);
    
    Destruct(stack, players, deck);
    return 0;
}
