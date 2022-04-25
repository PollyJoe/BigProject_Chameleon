#ifndef GAME_H_
#define GAME_H_
#include<stdio.h>
#include "Cards.h"
#include "player.h"
#include "deck.h"

void deal(CardStack *stack, Players *ps);
// Some basic functions
bool deploy_rule(Card *card, Deck *deck);
void check_deployable(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, Deck *deck);
int select_card(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, bool *if_giveup, Deck *deck);
Color select_color();
// Some integrated functions
void check_deck(Player *winner, bool if_giveup, Deck *deck, const Card *card);
void play_a_turn(Players *ps, CardStack *stack, Deck *deck, int turn_num);



void display_turn(Players *ps, int turn_num);
void Destruct(CardStack *stack, Players *ps, Deck *deck);
#endif // !GAME_H_