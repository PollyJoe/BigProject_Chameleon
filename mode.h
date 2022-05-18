#ifndef MODE_H
#define MODE_H

#include <QWidget>
#include <QPushButton>
#include "game.h"
#include <QMessageBox>
namespace Ui {
class mode;
}

class mode : public QWidget{
    Q_OBJECT

public:
    explicit mode(QWidget *parent = nullptr);
    ~mode();
    friend class MainWindow;

signals:
    void goback();
    void mode_signal(int mode_num);

private slots:
    void on_goback_clicked();
    void on_mach_vs_mach_clicked();
    void on_human_vs_mach_clicked();
    void game_go_to_mode();

private:
    Ui::mode *ui;
    Game *game = new Game;

};

#endif // MODE_H