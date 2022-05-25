#ifndef TABLEBOARD_H
#define TABLEBOARD_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QStyle>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QVector>
#include <QPixmap>
#include <QString>
#include <QTime>
#include "card.h"
#include "player.h"
#include <QMediaPlayer>
#include <QSoundEffect>
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
    friend class Game;
    bool ifmute = true;
    QMediaPlayer *bgm = new QMediaPlayer;

    void paintEvent(QPaintEvent* event) override;

    void hidecards();
    void update_cards(int player_index, int card_index, const Card& card);
    void turn_down_cards(int player_index, int card_index);
    void update_score(int player_index, int score);
    void update_current(Color c, int num);
    void update_playcard(Card &card);
    void update_turn(int turn);

    void start_timer();
    void start_game();
    void player_remind(int player_index);
    void musicplayer(Mode mode);

    int get_human_player_index(){return human_player_index;};
    int get_human_play_card(){return human_play_card;};
    bool get_ifhumanplay(){return ifhumanplay;};
    void init_ifhumanplay();
    bool get_ifgoback(){return ifgoback;};

    void hideplaycard();
    void countdown(int time);
    void hidecountdown();
    void endgame();
    void pausegame();
    bool get_ifrestart(){return ifrestart;}



signals:
    void closegame();
    void play(int player_index,int card_index);


private slots:
    void on_cards_button_2_1_clicked();
    void on_cards_button_2_2_clicked();
    void on_cards_button_2_3_clicked();
    void on_cards_button_2_4_clicked();
    void on_cards_button_2_5_clicked();
    void human_play_slot(int player_index, int card_index);
    void on_GoBack_clicked();
    void GoBack_slot();
    void on_pause_clicked();
    void on_conti_clicked();

    void on_cards_button_1_1_clicked();
    void on_cards_button_1_2_clicked();
    void on_cards_button_1_3_clicked();
    void on_cards_button_1_4_clicked();
    void on_cards_button_1_5_clicked();
    void on_sound_clicked();

private:
    Ui::Tableboard *ui;
    QVector<QVector<QPushButton*>> player_cards_button;
    QVector<QPushButton*> player1_cards_button;
    QVector<QPushButton*> player2_cards_button;
    QVector<QLabel*> score_label;
    QVector<QLabel*> players_label;

    int human_player_index;
    int human_play_card;
    bool ifhumanplay;
    bool ifgoback = false;
    bool ifstop = false;
    bool ifrestart = false;
};

QString color_of_card(Color c);
QString number_of_card(int num);
QString filename_of_card(Color c, int num);
void delaytime(int time);

#endif // TABLEBOARD_H
