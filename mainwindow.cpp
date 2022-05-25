#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->soundeffect->setIcon(QIcon(":/icon/icon/sound.png"));
    ui->soundeffect->setIconSize(QSize(50,50));
    bgmusic->setMedia(QUrl("qrc:/welcome/music/welcome.wav"));
    bgmusic->setVolume(50);
    bgmusic->play();
    QObject::connect(help_menu, SIGNAL(goback()), this, SLOT(help_goto_main()));
    QObject::connect(playmode, SIGNAL(goback()), this, SLOT(game_goto_main()));
    QObject::connect(record_sheet, SIGNAL(goback()), this, SLOT(rank_goto_main()));
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
    bgmusic->play();
    this->show();
}

void MainWindow::rank_goto_main(){
    record_sheet->hide();
    this->show();
}
//Mainwindow buttons
void MainWindow::on_exit_clicked(){
    QApplication::exit();
}

void MainWindow::on_start_clicked(){
    playmode->show();
    bgmusic->stop();
    this->hide();
}

void MainWindow::on_help_clicked(){
    help_menu->show();
    this->hide();
}

void MainWindow::on_rank_clicked(){
    record_sheet->show();
    this->hide();
}

void MainWindow::on_soundeffect_clicked(){
    if(ifmute){
        bgmusic->setMuted(ifmute);
        ui->soundeffect->setIcon(QIcon(":/icon/icon/mute.png"));
        ui->soundeffect->setIconSize(QSize(50,50));
        ifmute = false;
    }
    else{
        bgmusic->setMuted(ifmute);
        ui->soundeffect->setIcon(QIcon(":/icon/icon/sound.png"));
        ui->soundeffect->setIconSize(QSize(50,50));
        ifmute = true;
    }
}

