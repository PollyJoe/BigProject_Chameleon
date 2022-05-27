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
 * 1. QObjects:
 *  (1) Cards (*10)
 *  (2) Players (*2)
 *  (3) Countdown
 *  (4) Current card
 *  (5) Player reminder
 *  (6) Played card
 *  (7) Start game module
 *  (8) End game module
 *  (9) Background music
 *  (10) Game turn
 * 2. Display:
 *  (1) Display and update players: cards and score
 *  (2) Display current color and number
 *  (3) Display played (not discard) card
 *  (4) For human-machine mode, hide machine's cards
 *  (5) Music playing
 *  (6) Countdown
 *  (7) Show game turn number
 *  (8) For human-human mode, remind players of who is going to play
 * 3. Game service:
 *  (1) Start and end the game
 *  (2) Pause and continue the game
 * 4. Contact with game part: private members operation
 * 5. Button operation:slots and signals
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

    //Set the theme
    void paintEvent(QPaintEvent* event) override;
    void musicplayer(Mode mode);

    //Players: cards and score
    void hidecards();
    void update_cards(int player_index, int card_index, const Card& card);
    void turn_down_cards(int player_index, int card_index);
    void update_score(int player_index, int score);


    //Current situation: played card and current color and number
    void update_playcard(Card &card);
    void hideplaycard();
    void update_current(Color c, int num);

    //Reminders: turn number and player's playing turn
    void update_turn(int turn);
    void player_remind(int player_index);

    //Private members operation
    int get_human_player_index(){return human_player_index;};
    int get_human_play_card(){return human_play_card;};
    bool get_ifgoback(){return ifgoback;};
    bool get_ifrestart(){return ifrestart;};

    bool get_ifhumanplay(){return ifhumanplay;};
    void init_ifhumanplay(){ifhumanplay = false;};

    //Count down
    void start_timer();
    void countdown(int time);
    void hidecountdown();

    //Game service: start,end and pause
    void start_game();
    void endgame();

    //Background music


signals:
    void closegame();
    void play(int player_index,int card_index);


private slots:

    //Play cards
    void on_cards_button_1_1_clicked();
    void on_cards_button_1_2_clicked();
    void on_cards_button_1_3_clicked();
    void on_cards_button_1_4_clicked();
    void on_cards_button_1_5_clicked();
    void on_cards_button_2_1_clicked();
    void on_cards_button_2_2_clicked();
    void on_cards_button_2_3_clicked();
    void on_cards_button_2_4_clicked();
    void on_cards_button_2_5_clicked();

    //Game service: pause/continue, go back to mode, choose to play or trustseeing, set the sound effect
    void human_play_slot(int player_index, int card_index);
    void on_GoBack_clicked();
    void GoBack_slot();
    void on_pause_clicked();
    void on_conti_clicked();
    void on_sound_clicked();

    void on_pushButton_clicked();

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

    bool playerturn[player_num] = {false, false};
};

//Auxiliary part: help to set filename and delay time
QString color_of_card(Color c);
QString number_of_card(int num);
QString filename_of_card(Color c, int num);
void delaytime(int time);

#endif // TABLEBOARD_H
