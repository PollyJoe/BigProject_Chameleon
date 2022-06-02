/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#ifndef HELP_H
#define HELP_H

#include <QWidget>

namespace Ui {
class help;
}

class help : public QWidget{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();
signals:
    void goback();

private slots:
    void on_goback_clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
