#ifndef DECK_H_
#define DECK_H_ 
#include <stdio.h>
#include "Cards.h"
#include "player.h"
typedef struct 
{
    Color current_color;
    int current_num;
    Card *card_slot[player_num];
}Deck;

void changecolor(Deck *deck, Color c);
void changenum(Deck *deck, int point);
void clearDeck(Deck *deck);
#endif // !DECK_H_
