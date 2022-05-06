#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QThread>
#include <QTime>
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    this->setFixedSize(QSize(1500, 1200));
    ui->setupUi(this);
    QPixmap bkgnd(":/basic/resources/basic/chamaleon.jpeg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QObject::connect(help_menu, SIGNAL(Goback_button()), this, SLOT(help_gotomain()), Qt::AutoConnection);
}

MainMenu::~MainMenu()
{
    delete ui;
    delete help_menu;
    delete game;
}


void MainMenu::on_pushButton_3_clicked()
{
   this->close();
   this->help_menu->close();
}




void MainMenu::on_pushButton_2_clicked()
{
    help_menu->show();
    this->hide();
}

void MainMenu::help_gotomain(){
   help_menu->hide();
   this->show();
}
void MainMenu::on_pushButton_clicked()
{
   game->show();
   game->deal();
   int turn_num = 0;
   while(!game->stack.empty())   {
       game->play_a_turn(++turn_num);
       delay();
   }
   this->hide();
}
void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

