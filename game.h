#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "tableboard.h"
#include <QSound>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
/************************************************************
 * Process of a game:
 *  1. Preparation:
 *      (1) Deal
 *      (2) Update current color and number
 *  2. Game:
 *      (1) Play once
 *      (2) Check the played card
 *      (3) Update current situation
*************************************************************
 * Props of a game:
 *  1. Players
 *  2. Cards
 * Game mode:
 *  1. Machine part:
 *      (1) Strategy: select card, select number
 *      (2) Operation:
 *          1)givecard
 *          2)getcard
 *  2. Human part:
 *      (1) Push button to play
 *      (2) Get card (same as machine)
 *      (3) Select color
 * Check:
 *  1. Give up: add point to opponent
 *  2. Change color: provide choices for human player
 *  3. Update current situation
 *  4. Update score
 * Service:
 *  1. Countdown
 *  2. Record the game
 *  3. Show given-up cards
************************************************************/
class Game : public Tableboard
{


public:

    //init
    Game();
    ~Game() = default;
    friend class mode;
    friend class MainWindow;

    //Preparation
    void deal();
    void human_deal();

    //Rules
    friend bool valid_rule(const Card& card, Game *g);
    friend bool chame_rule(const Card& card, Game *g);
    Color getcolor(){return current_color;}
    int getnumber(){return current_num;}
    void CheckValid(bool (*valid_rule)(const Card& card, Game *g), Player& player);
    void CheckChame(bool (*chame_rule)(const Card& card, Game *g), Player& player);


    //Machine play
    Card givecard(int player_index, int position);
    void getcard(int player_index);
    void mach_getcard(int player_index);    //Only for human-machine mode
    void check_all_card(int player_index);

    int select_card(bool (*valid_rule)(const Card& card, Game *g), bool (*chame_rule)(const Card& card, Game *g), int player_index);
    Color select_color(int player_index);

    //Human play: when under trustseeing status, the operation is the same as machne play
    Color human_select_color();

    //Background check
    void change_color(Color c){current_color = c;}
    void change_number(int num){current_num = num;}
    void check_play(int player_index, Card& cardgiven);
    void human_check_play(int player_index, Card& cardgiven);
    void update_playercard(int player_index);

    //Encapsulate the game
    //Once
    void play_once(int player_index);
    void mach_play_once(int player_index);  //Only for human-machine mode
    void human_play_once(int player_num);
    //Turn
    void play_a_turn(int turn);
    void human_play_a_turn(int turn);
    void humans_play_a_turn(int turn);
    //Total game
    void mach_vs_mach();
    void human_vs_mach();
    void human_vs_human();

    //Game service
    void game_countdown();
    void show_giveup(int player_index);
    void show_all_giveup();
    void score_record(Mode mode);
    void giveup_reminder(int player_index);
    void confirm_giveup();
    void pausegame();
    void cleargame();

private:
    Cardstack cardstack;
    Players players;
    Color current_color;
    int current_num;
    QVector<Card> player_1_giveup;
    QVector<Card> player_2_giveup;
    QVector<QVector<Card>> giveup_cards;
};

bool valid_rule(const Card& card, Game *g);
bool chame_rule(const Card& card, Game *g);
void delay(int time);


#endif // GAME_H
