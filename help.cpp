#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}






void help::on_goback_clicked(){
    emit goback();
}

