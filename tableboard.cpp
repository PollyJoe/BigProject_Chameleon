#include "tableboard.h"
#include "ui_tableboard.h"

Tableboard::Tableboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tableboard)
{
    this->setAttribute(Qt::WA_DeleteOnClose, false);
    ui->setupUi(this);
    setWindowTitle("Game");
    ui->sound->setIcon(QIcon(":/icon/icon/sound.png"));
    ui->sound->setIconSize(QSize(50,50));

    //Put the objects into the vector
    //Cards
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
    //Players
    players_label.append(ui->player1);
    players_label.append(ui->player2);
    //Score
    score_label.append(ui->score_1);
    score_label.append(ui->score_2);
    ui->score_1->setText("0");
    ui->score_2->setText("0");   

    //Pause/continue, go-back button, and countdown initialization
    ui->pause->setIcon(QIcon(":/icon/icon/pause.png"));
    ui->pause->setIconSize(QSize(50,50));
    ui->conti->setIcon(QIcon(":/icon/icon/continue.png"));
    ui->conti->setIconSize(QSize(141,141));
    ui->conti->hide();
    //ui->GoBack->hide();
    ui->countdown->hide();

    //Connection
    QObject::connect(this, SIGNAL(play(int,int)), this, SLOT(human_play_slot(int,int)));
    QObject::connect(this, SIGNAL(closegame()),this,SLOT(GoBack_slot()));

}

Tableboard::~Tableboard(){
    delete ui;
}

/**********************************************************
 * Set the theme
**********************************************************/
void Tableboard::paintEvent(QPaintEvent *event){
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Tableboard::musicplayer(Mode mode){
    switch(mode){
    case(hh):{
        bgm = new QMediaPlayer;
        bgm->setMedia(QUrl("qrc:/game/music/human_human.wav"));
        bgm->setVolume(50);
        bgm->play();
        break;
    }
    case(hm):{
        bgm = new QMediaPlayer;
        bgm->setMedia(QUrl("qrc:/game/music/human_machine.wav"));
        bgm->setVolume(50);
        bgm->play();
        break;
    }
    case(mm):{
        bgm = new QMediaPlayer;
        bgm->setMedia(QUrl("qrc:/game/music/machine_machine.wav"));
        bgm->setVolume(50);
        bgm->play();
        break;
    }
    default:break;
    }
}

/********************************************************
 * Auxiliary module: filename and delaytime
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

void delaytime(int time){
    QTime dieTime= QTime::currentTime().addSecs(time);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

/*********************************************************************
 * Game service
*********************************************************************/
void Tableboard::start_game(){
    ui->gameover->setText("READY?");
    delaytime(1);
    //pausegame();
    for(int i = 3; i >=0; i--){ui->gameover->setText(QString::number(i));delaytime(1);//pausegame();
    }
    ui->gameover->setText("START!");
   // pausegame();
    delaytime(1);
   // pausegame();
    ui->gameover->hide();
}

void Tableboard::endgame(){
    bgm->stop();
    ui->cards_button_1_1->hide();
    ui->cards_button_1_2->hide();
    ui->cards_button_1_3->hide();
    ui->cards_button_1_4->hide();
    ui->cards_button_1_5->hide();
    ui->cards_button_2_1->hide();
    ui->cards_button_2_2->hide();
    ui->cards_button_2_3->hide();
    ui->cards_button_2_4->hide();
    ui->cards_button_2_5->hide();
    ui->current->hide();
    ui->playcard->hide();
    ui->current_card->hide();
    ui->turn->hide();
    ui->GoBack->show();
    ui->gameover->setText("Game over!");
    ui->gameover->show();
    ui->pause->hide();
}


/***********************************************************
 * Reminders
***********************************************************/
void Tableboard::player_remind(int player_index){
    ui->playcard->hide();
    ui->gameover->setText("Player " + QString::number(player_index) + "'s turn");
    ui->gameover->show();
    delaytime(1);
    ui->gameover->hide();
    ui->playcard->show();
}

void Tableboard::update_turn(int turn){
    ui->turn->setText("Turn: " + QString::number(turn));
}



/************************************************************
 * Current situation
************************************************************/
void Tableboard::update_playcard(Card &card){
     QString filename = filename_of_card(card.GetColor(), card.GetNumber());
     ui->playcard->setPixmap(QPixmap(filename));
     ui->playcard->show();
}

void Tableboard::hideplaycard(){
    ui->playcard->hide();
    ui->current->hide();
}

void Tableboard::update_current(Color c, int num){
    QString filename = filename_of_card(c, num);
    ui->current->setPixmap(QPixmap(filename));
    ui->current->show();
}

/************************************************************
 * Players
************************************************************/
void Tableboard::hidecards(){
    QString filename = ":/image/Card/back_img.png";
    int i;
    for(i = 0; i < max_inhand; i++){
        player_cards_button[0][i]->setIcon(QIcon(filename));
        player_cards_button[0][i]->setIconSize(QSize(58, 90));
        player_cards_button[0][i]->show();
    }
}

void Tableboard::update_cards(int player_index, int card_index, const Card& card){
    QString filename = filename_of_card(card.GetColor(), card.GetNumber());
    player_cards_button[player_index][card_index]->setIcon(QIcon(filename));
    player_cards_button[player_index][card_index]->setIconSize(QSize(58, 90));
    player_cards_button[player_index][card_index]->show();
}

void Tableboard::turn_down_cards(int player_index, int card_index){
    player_cards_button[player_index][card_index]->hide();
}

void Tableboard::update_score(int player_index, int score){
    score_label[player_index]->setText(QString::number(score));
}

/*********************************************************
 *Countdown
*********************************************************/
void Tableboard::countdown(int time){
    ui->countdown->setText(QString::number(time));
    ui->countdown->show();
}

void Tableboard::hidecountdown(){
    ui->countdown->hide();
}

/**************************************************************
 * All the slots
***************************************************************
 * Play cards
**************************************************************/
void Tableboard::on_cards_button_1_1_clicked(){if(playerturn[0]) emit play(0,0);}
void Tableboard::on_cards_button_1_2_clicked(){if(playerturn[0]) emit play(0,1);}
void Tableboard::on_cards_button_1_3_clicked(){if(playerturn[0]) emit play(0,2);}
void Tableboard::on_cards_button_1_4_clicked(){if(playerturn[0]) emit play(0,3);}
void Tableboard::on_cards_button_1_5_clicked(){if(playerturn[0]) emit play(0,4);}
void Tableboard::on_cards_button_2_1_clicked(){if(playerturn[1]) emit play(1,0);}
void Tableboard::on_cards_button_2_2_clicked(){if(playerturn[1]) emit play(1,1);}
void Tableboard::on_cards_button_2_3_clicked(){if(playerturn[1]) emit play(1,2);}
void Tableboard::on_cards_button_2_4_clicked(){if(playerturn[1]) emit play(1,3);}
void Tableboard::on_cards_button_2_5_clicked(){if(playerturn[1]) emit play(1,4);}

/***************************************************************
 * Game service
***************************************************************/
//Go back
void Tableboard::on_GoBack_clicked(){emit closegame();}

//Pause/Continue
void Tableboard::GoBack_slot(){ifgoback = true;}

void Tableboard::on_pause_clicked(){
    ui->conti->show();
    ifstop = true;
    bgm->pause();
}

void Tableboard::on_conti_clicked(){
    ui->conti->hide();
    ifstop = false;
    if(ifmute) bgm->play();
}

//Sound effect
void Tableboard::on_sound_clicked(){
    if(ifmute){
        ui->sound->setIcon(QIcon(":/icon/icon/mute.png"));
        ui->sound->setIconSize(QSize(50,50));
        bgm->setMuted(ifmute);
        ifmute = false;
    }
    else{
        ui->sound->setIcon(QIcon(":/icon/icon/sound.png"));
        ui->sound->setIconSize(QSize(50,50));
        bgm->setMuted(ifmute);
        ifmute = true;
    }
}

//Play or trustseeing
void Tableboard::human_play_slot(int player_index, int card_index){
    human_player_index = player_index;
    human_play_card = card_index;
    ifhumanplay = true;
}

void Tableboard::on_pushButton_clicked(){
    QApplication::quit();
    QApplication::exit();
}

