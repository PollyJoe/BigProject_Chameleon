#include "game.h"

void deal(CardStack *stack, Players *ps){
    for (int i = 0; i < player_num*(playercards_capacity - 1); i++)
        ps->players[i % player_num]->cards_on_hand[i / player_num] = pop(stack);
}

bool deploy_rule(Card *card, Deck *deck){
    return ((deck->current_color == PANACEA) || (card->number== deck->current_num) || (card->color == deck->current_color) || (card->number == panacea));
}

void check_deployable(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, Deck *deck){
    for (int i = 0; i < playercards_capacity; i++){
        if (p->cards_on_hand[i] == NULL)
            p->deployable[i] = false;
        else  p->deployable[i] = deploy_rule(p->cards_on_hand[i], deck);
    }
}
/*****************************************************
 *This is the selection strategy 
 Overload this function to implement your AI
 Here I use the simplest: the first that can be used 
 * ***************************************************/
int select_card(bool (*deploy_rule)(Card *card, Deck *deck), Player *p, bool *if_giveup, Deck *deck){
    int smallest = sets_size + 1;
    int index = -1;
    *if_giveup = false;
    check_deployable(deploy_rule, p, deck);
    for (int i = 0; i < playercards_capacity; i++)
    {
        if(p->deployable[i]) return i;
        //If there is no cards to give out, we can only give up, choose the smallest point to give up
        if(p->cards_on_hand[i] == NULL) continue;
        if (p->cards_on_hand[i]->number < smallest){
            smallest = p->cards_on_hand[i]->number;
            index = i;
        }
    }
    *if_giveup = true;
    return index;
}

Color select_color(){
    Color c = rand() % color_num; 
    return c;
}
/***************************************************************/
void check_deck(Player *winner, bool if_giveup, Deck *deck, const Card *card){
    // if the other player has no card to give, the turn is over
    if (if_giveup) {updatescore(winner,card);} 
    else{// if the other player gives a card
        if (card->number == panacea)  changecolor(deck, select_color());
        else changecolor(deck, card->color);
        changenum(deck, card->number);
    }
}

void play_a_turn(Players *ps, CardStack *stack, Deck *deck, int turn_num){
    Player *offensive = ps->players[turn_num % player_num];
    Player *defensive = ps->players[(turn_num + 1) % player_num];
    bool if_giveup = false;
    // Offensive get a card, and give a card
    if(!ifempty(stack)) getcard(offensive, stack);
    int index = select_card(&deploy_rule, offensive, &if_giveup, deck);
    const Card *card_to_give = givecard(offensive, index);
    check_deck(defensive, if_giveup, deck, card_to_give);
    if(if_giveup) {display_turn(ps, turn_num); return;}
   //defensive get a card, and give a card
    if(!ifempty(stack)) getcard(defensive, stack);
    index = select_card(&deploy_rule, defensive, &if_giveup, deck);
    card_to_give = givecard(defensive, index);
    check_deck(offensive, if_giveup, deck, card_to_give);
    display_turn(ps, turn_num);
    return;
}

void display_turn(Players *ps, int turn_num){
    printf("Turn %d :", turn_num);
    display_score(ps);
    printf("\n");
}
void Destruct(CardStack *stack, Players *ps, Deck *deck){
    destruct_cardstack(stack);
    destruct_players(ps); 
    destruct_deck(deck);
}