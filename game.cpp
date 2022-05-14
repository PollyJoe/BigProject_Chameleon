#include "game.h"
#include "mainwindow.h"
#include <QTime>
#include <QCoreApplication>
/************************************************
 * This is only the functional part, no GUI
************************************************/

/************************************************************
 * Process of a game:
 *  1. Initialize a cardstack
 *  2. Deal the card to players
 *  3. Play the card (rules have been finished in C project)
 *  4. End the game once the stack and vectors are all empty
 * Props of one game:
 *  1. Cards (stack)
 *  2. Players
 * Operations inside a game:
 *  1. Deal the card
 *  2. Play:
 *      (1) Give a card
 *          1) Check the calidity
 *          2) Choose a card due to the strategy
 *      (2) Take a card
************************************************************/
Game::Game(){
    stack_init(cardstack);
    players_init(players);
    current_color = static_cast<Color>(arc4random() % colornum);
    current_num = static_cast<int>(arc4random() % set_size);
}

void Game::deal(){
    int i;
    for(i = 0; i < (max_inhand - 1) * player_num; i++){
        players[i % player_num].cards_inhand.push_back(cardstack.top());
        update_cards(i % player_num, i / player_num, cardstack.top());
        cardstack.pop();
    }
}

Card Game::givecard(int player_index, int position){
    players[player_index].null_slot = position;
    Card givecard = players[player_index].cards_inhand[position];
    players[player_index].cards_inhand.erase(players[player_index].cards_inhand.begin() + position);
    turn_down_cards(player_index, position);

    return givecard;
}

void Game::getcard(int player_index){
    players[player_index].cards_inhand.push_back(cardstack.top());
    update_cards(player_index, max_inhand - 1, cardstack.top());//GUI
    cardstack.pop();
}

void Game::CheckValid(bool (*valid_rule)(const Card& card, Game *g), Player& player){
    for(auto &c : player.cards_inhand) c.SetValid(valid_rule(c, this));
}

void Game::CheckChame(bool (*chame_rule)(const Card& card, Game *g), Player& player){
    for(auto &c : player.cards_inhand) c.SetChame(chame_rule(c, this));
}

//Edit this later
int Game::select_card(bool valid_rule(const Card& card, Game *g), bool (*chame_rule)(const Card& card, Game *g), int player_index){
   int index = -1;
   int chame = 0;
   int i = -1;//Record the card when using for-loop

   players[player_index].ifgiveup = true;
   CheckValid(valid_rule, players[player_index]);
   CheckChame(chame_rule, players[player_index]);
   for(auto &c : players[player_index].cards_inhand){
       i++;
       //Chame-play or non-Chame-play
       if(c.GetValid()){
           bool iflarger = true;
           players[player_index].ifgiveup = false;
           for(int j = 0; j < i; j++){
               if(players[player_index].cards_inhand[j].GetValid()){
                   int point1 = c.GetPoint();
                   int point2 = players[player_index].cards_inhand[j].GetPoint();
                   if(point1 < point2) iflarger = false;
                   else continue;
               }
               else continue;
           }
           if(iflarger && !c.GetChame()) index = i;
           else {chame = i; continue;}
       }
   }
   if(!players[player_index].ifgiveup) {if(index == -1)index = chame;}
   //Play the smallest
   else{
       index = 0;
       int j = -1;
       for(auto &c : players[player_index].cards_inhand){
           j++;
           bool iflarger = false;
           for(int k = 0; k < j; k++){
                int point1 = c.GetPoint();
                int point2 = players[player_index].cards_inhand[k].GetPoint();
                if(point1 > point2) iflarger = true;
           }
           if(!iflarger) index = j;
       }
   }
   return index;
}

void Game::check_play(int player_index, Card& cardgiven){
    update_playcard(cardgiven);
    if(players[player_index].ifgiveup){
        players[(player_index + 1) % 2].UpdateScore(cardgiven);
    }
    else{
        if(cardgiven.GetChame()) change_color(select_color());
        else change_color(cardgiven.GetColor());
        change_number(cardgiven.GetNumber());
        update_current(current_color, current_num);
    }
    for(int i = 0; i < player_num; i++) update_score(i, players[i].score);
}

void Game::play_a_turn(int turn){
    for(int i = 0; i < player_num; i++){
        if(!cardstack.empty()) getcard(i);
        delay();
    }
    for(int i = 0; i < player_num; i++){
        update_turn(turn);
        int index = select_card(valid_rule, chame_rule, i);
        Card cardgiven = givecard(i, index);
        update_playercard(i);
        check_play(i, cardgiven);
        delay();
    }
}

void Game::update_playercard(int player_index){
    int i;
    for(i = 0; i < players[player_index].cards_inhand.size(); i++){
        update_cards(player_index, i, players[player_index].cards_inhand[i]);
    }
    turn_down_cards(player_index, players[player_index].cards_inhand.size());
}





//rule part
bool valid_rule(const Card& card, Game *g){
    return (card.GetColor() == g->current_color) || (card.GetNumber() == g->current_num) || (card.GetNumber() == 11);
}

bool chame_rule(const Card& card, Game *g){
    return (card.GetNumber() == 11) || (card.GetNumber() == g->current_num);
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

