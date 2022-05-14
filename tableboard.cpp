#include "tableboard.h"
#include "ui_tableboard.h"

Tableboard::Tableboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tableboard)
{
    ui->setupUi(this);

    player1_cards_button.append(ui->cards_button_1_1);
    player1_cards_button.append(ui->cards_button_1_2);
    player1_cards_button.append(ui->cards_button_1_3);
    player1_cards_button.append(ui->cards_button_1_4);
    player1_cards_button.append(ui->cards_button_1_5);
    player2_cards_button.append(ui->cards_button_2_1);
    player2_cards_button.append(ui->cards_button_2_2);
    player2_cards_button.append(ui->cards_button_2_3);
    player2_cards_button.append(ui->cards_button_2_4);
    player2_cards_button.append(ui->cards_button_2_5);
    player_cards_button.append(player1_cards_button);
    player_cards_button.append(player2_cards_button);

    players_label.append(ui->player1);
    players_label.append(ui->player2);

    score_label.append(ui->score_1);
    score_label.append(ui->score_2);
    ui->score_1->setText("0");
    ui->score_2->setText("0");
}

Tableboard::~Tableboard()
{
    delete ui;
}

void Tableboard::update_cards(int player_index, int card_index, const Card& card){
    QString s1, s2;
    s1 = color_of_card(card.GetColor());
    s2 = number_of_card(card.GetNumber());



    player_cards_button[player_index][card_index]->setIcon(QIcon(":/image/Card/" + s1 + s2 + ".png"));
    player_cards_button[player_index][card_index]->setIconSize(QSize(58, 90));
    player_cards_button[player_index][card_index]->show();

}

void Tableboard::turn_down_cards(int player_index, int card_index){
    player_cards_button[player_index][card_index]->hide();
}

void Tableboard::update_current(Color c, int num){
    QString s1,s2;
    s1 = color_of_card(c);
    s2 = number_of_card(num);
    ui->current->setPixmap(QPixmap(":/image/Card/" + s1 + s2 + ".png"));
}

void Tableboard::update_score(int player_index, int score){
    score_label[player_index]->setText(QString::number(score));
}

void Tableboard::update_playcard(Card &card){
    QString s1,s2;
    s1 = color_of_card(card.GetColor());
    s2 = number_of_card(card.GetNumber());
    ui->playcard->setPixmap(QPixmap(":/image/Card/" + s1 + s2 + ".png"));
}

void Tableboard::update_turn(int turn){
    ui->turn->setText("Turn: " + QString::number(turn));
}





QString color_of_card(Color c){
    QString s1;
    switch(c){
    case spade: s1 = "spade"; break;
    case club: s1 = "club"; break;
    case diamond: s1 = "diamond";break;
    case heart: s1 = "heart";break;
    default:break;
    }
    return s1;
}

QString number_of_card(int num){
    QString s2;
    switch(num){
    case 1: s2 = "A";break;
    case 11: s2 = "J";break;
    case 12: s2 = "Q";break;
    case 13: s2 = "K";break;
    default: s2 = QString::number(num);
    }
    return s2;
}




void Tableboard::on_goback_clicked(){
    emit stopgame();
}

