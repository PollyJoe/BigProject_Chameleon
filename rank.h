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
    void on_pushButton_clicked();

private:
    Ui::Rank *ui;
};

#endif // RANK_H
