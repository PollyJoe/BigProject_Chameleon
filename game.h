#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <memory>
#include "card.h"
#include "constants.h"
#include "deck.h"
#include "player.h"

class Game : public Deck
{
public:
    friend class MainMenu;
    Game();
    void deal();

    Card givecard(int player_ind, int position);
    int getcard(int player_ind);

    friend bool deploy_rule(const Card&);
    void check_deployable(bool (*deploy_rule)(const Card&, Game*), Player&);
    int select_card(bool (*deploy_rule)(const Card&, Game*), int player_index);
    Color select_color(){return static_cast<Color>(arc4random() % color_num);}
    void check_deck(int player_index, int index, const Card&);
    int play_once(int player_ind, bool (*deploy_rule)(const Card& c, Game *g));
    void play_a_turn(int turn_num);


private:
   CardStack stack;
   Players players;
};


bool deploy_rule(const Card&, Game *);

void delay();
#endif // GAME_H
