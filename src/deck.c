#include "deck.h"

Deck *Deck_Init(){
    Deck *deck = malloc(sizeof(Deck));
    deck->current_color = PANACEA;
    deck->current_num = -1; 
    return deck;
}
void destruct_deck(Deck *deck){free(deck);}
void changecolor(Deck *deck, Color c){deck->current_color = c;}
void changenum(Deck *deck, int point){deck->current_num = point;}

