#include "game.h"
#include <cmath>
Game::Game()
{
    CardStackInit(stack);
    Players_Init(players);
}

void Game::deal(){
    for (int i = 0; i < player_num*(playercards_capacity - 1); i++){
      int player_ind = i % player_num;
      players[player_ind].cards_on_hand.push_back(stack.top());
      update_screen(player_ind, i / player_num, stack.top());
      stack.pop();
      delay();
    }
}

Card Game::givecard(int player_ind, int position){
   players[player_ind].null_position = position;
   Card c = players[player_ind].cards_on_hand[position];
   players[player_ind].cards_on_hand.erase(players[player_ind].cards_on_hand.begin() + position);
   turn_down_card(player_ind, position);
   return c;
}

int Game::getcard(int player_ind){
     players[player_ind].cards_on_hand.push_back(stack.top());

     update_screen(player_ind, players[player_ind].null_position, stack.top());
     stack.pop();
     return players[player_ind].null_position;
 }


bool deploy_rule(const Card& card, Game * g){
    return ((g->get_color()== Color::PANACEA) || (card.getnum() == g->get_num())
            || (card.getcolor() == g->get_color()) || (card.getnum() == panacea));
}


void Game::check_deployable(bool (*deploy_rule)(const Card&, Game *g), Player& p){
    for(auto c : p.cards_on_hand) c.set_deployable(deploy_rule(c, this));
}

int Game::select_card(bool (*deploy_rule)(const Card& c, Game *g), int player_index){
    int smallest = sets_size + 1;
    int index = -1;
    int i = 0;
    Player &p = players[player_index];
    check_deployable(deploy_rule, p);
    for(auto c : p.cards_on_hand){
       if(c.if_deployable()) return i;
       else{
            if(c.getpoint() < smallest){
                smallest = c.getpoint();
                index = i;
            }}
    }
    return -index; // minus to indicate give up
}

void Game::check_deck(int player_index, int index, const Card& card){
    if(index < 0) {
        players[player_index].updatescore(card);
        update_score(player_index, players[player_index].score);
    }

    else{
        if(card.getcolor() == Color::PANACEA) change_color(select_color());
        else change_color(card.getcolor());
        change_num(card.getnum());
    }
}

int Game::play_once(int player_ind, bool (*deploy_rule)(const Card& c, Game *g)){
    if(!stack.empty()) getcard(player_ind);
    delay();
    int index = select_card(deploy_rule, player_ind);
    Card card_to_give = givecard(player_ind, abs(index));
    check_deck((player_ind + 1) % 2, index, card_to_give);
    return index;
}

void Game::play_a_turn(int turn_num){
    int offensive = turn_num % player_num;
    int defensive = (turn_num + 1)  % player_num ;
    int index = play_once(offensive, deploy_rule);
    if(index < 0) return;
    else play_once(defensive, deploy_rule);
    update_turn_num(turn_num);
}
