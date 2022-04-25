#include "game.h"

void deal(CardStack *stack, Players *ps){
    for (int i = 0; i < player_num*(playercards_capacity - 1); i++)
        ps->players[i % player_num]->cards_on_hand[i / player_num] = pop(stack);
}

bool deploy_rule(Card *card, Deck *deck){
    return ((card->number== deck->current_num) || (card->color == deck->current_color) || (card->number == panacea));
}

void check_deployable(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, Deck *deck){
    for (int i = 0; i < playercards_capacity; i++)
        p->deployable[i] = deploy_rule(p->cards_on_hand[i], deck)
}
/*****************************************************
 *This is the selection strategy 
 Overload this function to implement your AI
 Here I use the simplest: the first that can be used 
 * ***************************************************/
int select_card(Player *p){
    for (int i = 0; i < playercards_capacity; i++)
        if(p->deployable[i]) return i;
}

void Destruct(CardStack *stack, Players *ps){
    destruct_cardstack(stack);
    destruct_players(ps); 
}