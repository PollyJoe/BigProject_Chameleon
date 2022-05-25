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

    void help_goto_main();
    void game_goto_main();
    void rank_goto_main();
    void on_help_clicked();
    void on_exit_clicked();
    void on_start_clicked();
    void on_rank_clicked();
    void on_soundeffect_clicked();

private:
    Ui::MainWindow *ui;
    help *help_menu = new help;
    mode *playmode = new mode;
    Rank *record_sheet = new Rank;

};


#endif // MAINWINDOW_H
