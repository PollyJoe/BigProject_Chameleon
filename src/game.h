#ifndef GAME_H_
#define GAME_H_
#include<stdio.h>
#include "Cards.h"
#include "player.h"
#include "deck.h"

void deal(CardStack *stack, Players *ps);
bool deploy_rule(Card *card, Deck *deck);
void check_deployable(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, Deck *deck);
int select_card(Player *p);




void check_slot(Deck *deck);
void Destruct(CardStack *stack, Players *ps);
#endif // !GAME_H_