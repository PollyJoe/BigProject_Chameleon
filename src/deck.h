#ifndef DECK_H_
#define DECK_H_ 
#include <stdio.h>
#include "Cards.h"
#include "player.h"
typedef struct 
{
    Color current_color;
    int current_num;
}Deck;

Deck *Deck_Init();
void destruct_deck(Deck *deck);
void changecolor(Deck *deck, Color c);
void changenum(Deck *deck, int point);

#endif // !DECK_H_
