#ifndef DECK_H
#define DECK_H

#include <QWidget>
#include <QImage>
#include "card.h"
namespace Ui {
class Deck;
}
QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE
class Deck : public QWidget
{
    Q_OBJECT

public:
    explicit Deck(QWidget *parent = nullptr);
    ~Deck();

    void change_color(Color c);
    void change_num(int num);
    Color get_color(){return current_c;}
    int get_num(){return current_num;}

    bool loadFile(const QString &fileName);
    void display_card(QLabel *label, const QString &);

    void update_screen(int player_ind, int card_ind, const Card&);
    void turn_down_card(int player_int, int card_ind);
    void update_turn_num(int turn_num);
    void update_score(int player_ind, int score);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Deck *ui;
    Color current_c = Color::PANACEA;
    int current_num = -1;
    QImage current_image;
    QPixmap current_pixmap;
    QVector<QLabel*> card_labels;
    QVector<QLabel*> deck_labels;
    QVector<QLabel*> score_labels;
};

QString color_to_string(Color c);
QString num_to_string(int num);
#endif // DECK_H
