#include "deck.h"

void changecolor(Deck *deck, Color c){deck->current_color = c;}
void changenum(Deck *deck, int point){deck->current_num = point;}
void clearDeck(Deck *deck){
    for (int i = 0; i < player_num; i++)   deck->card_slot[i] = NULL;
}
