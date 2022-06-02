/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#ifndef RANK_H
#define RANK_H

#include <QWidget>
#include <QFile>
#include <QDir>

namespace Ui {
class Rank;
}

class Rank : public QWidget
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = nullptr);
    ~Rank();
signals:
    void goback();
private slots:
    void on_pushButton_clicked();   /*Go back to main menu*/

private:
    Ui::Rank *ui;
};

#endif // RANK_H
