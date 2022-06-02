/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help.h"
#include "mode.h"
#include <QMediaPlayer>
#include "rank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *bgmusic = new QMediaPlayer;
    bool ifmute = true;

private slots:

    void help_goto_main();          /*Go back to main menu from help widget*/
    void game_goto_main();          /*Go back to main menu from game widget*/
    void rank_goto_main();          /*Go back to main menu from record widget*/
    void on_help_clicked();         /*Go to view help*/
    void on_exit_clicked();         /*Quit game*/
    void on_start_clicked();        /*Go to choose game mode*/
    void on_rank_clicked();         /*Go to record*/
    void on_soundeffect_clicked();  /*Mute and play the music*/

private:
    Ui::MainWindow *ui;
    help *help_menu = new help;
    mode *playmode = new mode;
    Rank *record_sheet = new Rank;

};


#endif // MAINWINDOW_H
