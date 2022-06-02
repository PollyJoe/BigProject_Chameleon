/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

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
private slots:
    void on_goback_clicked();           /*Go back to mode list*/
    void on_mach_vs_mach_clicked();     /*Machine-machine mode*/
    void on_human_vs_mach_clicked();    /*Human-machine mode*/
    void on_mach_vs_mach_2_clicked();   /*Human-human mode*/
    void on_pushButton_clicked();       /*Exit game*/

private:
    Ui::mode *ui;
    Game *game = new Game;
};

#endif // MODE_H
