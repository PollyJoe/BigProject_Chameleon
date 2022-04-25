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
    //display_CardHeap(stack); 
    deal(stack, players);
    display_players(players);
    
    Destruct(stack, players);
    return 0;
}
