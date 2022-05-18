#include "tableboard.h"
#include "ui_tableboard.h"

Tableboard::Tableboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tableboard)
{
    ui->setupUi(this);

    //Put the objects into the vector
    //cards
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
    //players
    players_label.append(ui->player1);
    players_label.append(ui->player2);
    //score
    score_label.append(ui->score_1);
    score_label.append(ui->score_2);
    ui->score_1->setText("0");
    ui->score_2->setText("0");   

    ui->goback->hide();
    QObject::connect(this, SIGNAL(play(int,int)), this, SLOT(human_play_slot(int,int)));
}

Tableboard::~Tableboard(){
    delete ui;
}

/*************************************************
 * APIs to get private members of Tableboard
*************************************************/
void Tableboard::init_ifhumanplay(){
    ifhumanplay = false;
}

int Tableboard::get_human_player_index(){
    return human_player_index;
}
int Tableboard::get_human_play_card(){
    return human_play_card;
}
bool Tableboard::get_ifhumanplay(){
    return ifhumanplay;
}

/********************************************************
 * Process the string to give the filename of the card
********************************************************/
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

QString filename_of_card(Color c, int num){
    QString s;
    QString s1 = color_of_card(c);
    QString s2 = number_of_card(num);
    s = ":/image/Card/" + s1 + s2 + ".png";
    return s;
}
/*********************************************************************
 * Functional module: provide the GUI intersurface
*********************************************************************/
void Tableboard::update_cards(int player_index, int card_index, const Card& card){
    QString filename = filename_of_card(card.GetColor(), card.GetNumber());
    player_cards_button[player_index][card_index]->setIcon(QIcon(filename));
    player_cards_button[player_index][card_index]->setIconSize(QSize(58, 90));
    player_cards_button[player_index][card_index]->show();
}

void Tableboard::turn_down_cards(int player_index, int card_index){
    player_cards_button[player_index][card_index]->hide();
}

void Tableboard::update_current(Color c, int num){
    QString filename = filename_of_card(c, num);
    ui->current->setPixmap(QPixmap(filename));
}

void Tableboard::update_score(int player_index, int score){
    score_label[player_index]->setText(QString::number(score));
}

void Tableboard::update_playcard(Card &card){
     QString filename = filename_of_card(card.GetColor(), card.GetNumber());
    ui->playcard->setPixmap(QPixmap(filename));
}

void Tableboard::update_turn(int turn){
    ui->turn->setText("Turn: " + QString::number(turn));
}

/**************************************************************
 * All the slots
 * 1. Button slots
 * 2. Tableboard slots
**************************************************************/
//Buttons
void Tableboard::on_goback_clicked(){
    emit stopgame();
    this->close();
}
void Tableboard::on_cards_button_2_1_clicked(){
    emit play(1,0);
}
void Tableboard::on_cards_button_2_2_clicked(){
    emit play(1,1);
}
void Tableboard::on_cards_button_2_3_clicked(){
    emit play(1,2);
}
void Tableboard::on_cards_button_2_4_clicked(){
    emit play(1,3);
}
void Tableboard::on_cards_button_2_5_clicked(){
    emit play(1,4);
}
//Game
void Tableboard::human_play_slot(int player_index, int card_index){
    human_player_index = player_index;
    human_play_card = card_index;
    ifhumanplay = true;
}




