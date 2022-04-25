#include "player.h"
#include "Cards.h"

Players *Players_Init(){
    Players *ps = malloc(sizeof(Players));
    for (int i = 0; i < player_num; i++){
        ps->players[i] = malloc(sizeof(Player));
        ps->players[i]->score = 0;
    }
    return ps;
}

void display_player(const Player *p){
    printf("Cards on Hand: \n");
    for (int i = 0; i < playercards_capacity; i++)
       displayCard(p->cards_on_hand[i]); 
}

void display_players(const Players *p){
    for (int i = 0; i < player_num; i++)
    {
        printf("Player %d: \n", i);
        display_player(p->players[i]);
    }
}

void destruct_players(Players *ps){
    for(int i = 0; i < player_num; i++)
        free(ps->players[i]);
    free(ps); 
}