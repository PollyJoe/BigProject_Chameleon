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
    game->mach_vs_mach();
}

void mode::on_human_vs_mach_clicked(){
    this->hide();
    game->human_vs_mach();
}

void mode::game_go_to_mode(){
    this->show();
}


void mode::on_goback_clicked(){
    emit goback();
}





