#include "player.h"
#include "Cards.h"

Players *Players_Init(){
    Players *ps = malloc(sizeof(Players));
    for (int i = 0; i < player_num; i++){
        ps->players[i] = malloc(sizeof(Player));
        ps->players[i]->score = 0;
        for (int j = 0; j < playercards_capacity; j++)
                ps->players[i]->cards_on_hand[j] = NULL;
        ps->players[i]->null_position = playercards_capacity - 1;
    }
    return ps;
}

void increasescore(Player *p, int point){p->score += point;}

Card *givecard(Player *p, int position){
    Card *c = p->cards_on_hand[position];
    p->cards_on_hand[position] = NULL;
    p->null_position = position;
    return c;
}
void getcard(Player *p, CardStack *stack){p->cards_on_hand[p->null_position] =  pop(stack);}

void updatescore(Player *p, const Card *card){
    increasescore(p, getpoint(card));
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

void display_score(Players *ps){
    for (int i = 0; i < player_num; i++)
        printf("--Player%d: %d points          ", i, ps->players[i]->score);
}

void destruct_players(Players *ps){
    for(int i = 0; i < player_num; i++)
        free(ps->players[i]);
    free(ps); 
}