#include "mode.h"
#include "ui_mode.h"

mode::mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mode)
{
    ui->setupUi(this);
    QObject::connect(game, SIGNAL(stopgame()), this, SLOT(game_go_to_mode()));
}

mode::~mode(){
    delete ui;
    delete game;
}




void mode::on_mach_vs_mach_clicked(){
    int turn = 1;
    this->hide();
    //game = new Game;
    game->show();
    delay();
    game->deal();
    delay();
    game->update_current(game->current_color, game->current_num);
    delay();
    while(!game->cardstack.empty()){
        game->play_a_turn(turn++);
        delay();
    }
    while(!(game->players[0].cards_inhand.empty() && game->players[1].cards_inhand.empty())){
        game->play_a_turn(turn++);
        delay();
    }
}

void mode::on_human_vs_mach_clicked()
{
    int turn = 1;
    this->hide();
    //game = new Game;
    game->show();
    QMessageBox::information(NULL, "question", "Want to be the first player?", QMessageBox::Yes | QMessageBox::No);
    game->deal();
    delay();
    game->update_current(game->current_color, game->current_num);

}

void mode::game_go_to_mode(){
    this->show();
    game->hide();
    game = new Game;
}


void mode::on_goback_clicked(){
    emit goback();

}





