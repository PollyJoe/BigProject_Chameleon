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
    void update_cards(int player_index, int card_index, const Card& card);
    void turn_down_cards(int player_index, int card_index);
    void update_score(int player_index, int score);
    void update_current(Color c, int num);
    void update_playcard(Card &card);
    void update_turn(int turn);

signals:
    void stopgame();


private slots:
    void on_goback_clicked();

private:
    Ui::Tableboard *ui;
    QVector<QVector<QPushButton*>> player_cards_button;
    QVector<QPushButton*> player1_cards_button;
    QVector<QPushButton*> player2_cards_button;
    QVector<QLabel*> score_label;
    QVector<QLabel*> players_label;
};

QString color_of_card(Color c);
QString number_of_card(int num);

#endif // TABLEBOARD_H
