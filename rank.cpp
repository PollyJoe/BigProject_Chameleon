/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日


#include "rank.h"
#include "ui_rank.h"
#include <QMessageBox>
#include <QStandardPaths>
Rank::Rank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    QString s = "";
    QDir dir("score.txt");
    QString location = QCoreApplication::applicationDirPath();
    QString filename = location + "/score.txt";
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()){
            QByteArray line = file.readLine();
            QString str(line);
            s += str;
        }
        file.close();
    }
    ui->textEdit->setText(s);
}

Rank::~Rank()
{
    delete ui;
}


void Rank::on_pushButton_clicked(){
    this->hide();
    emit goback();
}

