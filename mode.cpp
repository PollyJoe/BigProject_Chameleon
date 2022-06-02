/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#include "mode.h"
#include "ui_mode.h"

mode::mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mode)
{
    ui->setupUi(this);

}

mode::~mode(){
    delete ui;
}

void mode::on_mach_vs_mach_clicked(){
    this->hide();
    game = new Game;
    game->mach_vs_mach();
    game->endgame();
    game->show_all_giveup();
    while(!game->get_ifgoback()){
        delay(1);
        if(game->get_ifgoback()) break;
    }
    game->close();
    this->show();
    delete game;
}

void mode::on_human_vs_mach_clicked(){
    this->hide();
    game = new Game;
    game->human_vs_mach();
    game->endgame();
    game->show_all_giveup();
    while(!game->get_ifgoback()){
        delay(1);
        if(game->get_ifgoback()) break;
    }
    game->close();
    this->show();
    delete game;
}

void mode::on_goback_clicked(){
    emit goback();
}

void mode::on_mach_vs_mach_2_clicked(){
    this->hide();
    game = new Game;
    game->human_vs_human();
    game->endgame();
    game->show_all_giveup();
    while(!game->get_ifgoback()){
        delay(1);
        if(game->get_ifgoback()) break;
    }
    game->close();
    this->show();
    delete game;
}


void mode::on_pushButton_clicked(){
    QApplication::exit();
}

