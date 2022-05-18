#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QObject::connect(help_menu, SIGNAL(goback()), this, SLOT(help_goto_main()));
    QObject::connect(playmode, SIGNAL(goback()), this, SLOT(game_goto_main()));
    QObject::connect(table, SIGNAL(goback()), playmode, SLOT(game_goto_mode()));

}

MainWindow::~MainWindow(){
    delete ui;
    delete help_menu;
}

//Mainwindow slots
void MainWindow::help_goto_main(){
    help_menu->hide();
    this->show();
}

void MainWindow::game_goto_main(){
    playmode->hide();
    this->show();
}

//Mainwindow buttons
void MainWindow::on_exit_clicked(){
    QApplication::exit();
}

void MainWindow::on_start_clicked(){
    playmode->show();
    this->hide();
}

void MainWindow::on_help_clicked(){
    help_menu->show();
    this->hide();
}



