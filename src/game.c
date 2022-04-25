#include "game.h"

void deal(CardStack *stack, Players *ps){
    for (int i = 0; i < player_num*(playercards_capacity - 1); i++)
        ps->players[i % player_num]->cards_on_hand[i / player_num] = pop(stack);
}

void Destruct(CardStack *stack, Players *ps){
    destruct_cardstack(stack);
    destruct_players(ps); 
}