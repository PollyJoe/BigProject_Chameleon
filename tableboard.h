#ifndef TABLEBOARD_H
#define TABLEBOARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QVector>
#include <QPixmap>
#include <QString>
#include "card.h"
#include "player.h"

/***************************************************
 * Table :
 *  1. Labels & buttons:
 *      (1) Cards (buttons)
 *      (2) Players
 *      (3) Score
 *      (4) Current card
 *      (5) Play card
 *  2. Functions:
 *      (1) Display cards (10)
 *      (2) Update cards
 *      (3) Update play_card
 *      (4) Update score
 *      (5) Update current card
***************************************************
 * Human-machine mode:
 *  1. Cards (button): clicked -> givecard
 *  2. Choose to be play first or second:
 *      (1) Choose first: be player1;
 *      (2) Choose second: be player2.
 *  3. Human-play:
 *      (1) Object connection: tableboard & tableboard
 *      (2) Process:
 *          1) User click the card button
 *          2) The card clicked turned down, and the index of the card will be recorded
 *          3) The bool-type mark will transfer the card info to Game module
 *          4) Game module do the background playing, and start next playing
***************************************************/


namespace Ui {
class Tableboard;
}

class Tableboard : public QWidget
{
    Q_OBJECT

public:

    explicit Tableboard(QWidget *parent = nullptr);
    ~Tableboard();
    friend class mode;
    friend class Tableboard;
    void update_cards(int player_index, int card_index, const Card& card);
    void turn_down_cards(int player_index, int card_index);
    void update_score(int player_index, int score);
    void update_current(Color c, int num);
    void update_playcard(Card &card);
    void update_turn(int turn);


    //trial: human-play signal
    int get_human_player_index();
    int get_human_play_card();
    bool get_ifhumanplay();
    void init_ifhumanplay();

signals:
    void stopgame();
    void play(int player_index,int card_index);


private slots:
    void on_goback_clicked();

    void on_cards_button_2_1_clicked();

    void on_cards_button_2_2_clicked();

    void on_cards_button_2_3_clicked();

    void on_cards_button_2_4_clicked();

    void on_cards_button_2_5_clicked();

    void human_play_slot(int player_index, int card_index);




private:
    Ui::Tableboard *ui;
    QVector<QVector<QPushButton*>> player_cards_button;
    QVector<QPushButton*> player1_cards_button;
    QVector<QPushButton*> player2_cards_button;
    QVector<QLabel*> score_label;
    QVector<QLabel*> players_label;



    //trial:human-play signal
    int human_player_index;
    int human_play_card;
    bool ifhumanplay;
};


QString color_of_card(Color c);
QString number_of_card(int num);
QString filename_of_card(Color c, int num);
#endif // TABLEBOARD_H
