#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "help.h"
#include "deck.h"
#include "game.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void help_gotomain();
    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;
    Help *help_menu = new Help();
    Game *game = new Game();
};
#endif // MAINMENU_H
