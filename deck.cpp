#include "deck.h"
#include "ui_deck.h"
#include <QDir>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
Deck::Deck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deck)
{
    ui->setupUi(this);
    card_labels.append(ui->label_1_1);
    card_labels.append(ui->label_1_2);
    card_labels.append(ui->label_1_3);
    card_labels.append(ui->label_1_4);
    card_labels.append(ui->label_1_5);
    card_labels.append(ui->label_2_1);
    card_labels.append(ui->label_2_2);
    card_labels.append(ui->label_2_3);
    card_labels.append(ui->label_2_4);
    card_labels.append(ui->label_2_5);
    deck_labels.append(ui->label_15);
    deck_labels.append(ui->label_17);
    score_labels.append(ui->score_1);
    score_labels.append(ui->score_2);
}


Deck::~Deck()
{
    delete ui;
}
void Deck::change_color(Color c){
    current_c = c;
    deck_labels[0]->setText(color_to_string(c));
}

void Deck::change_num(int num){
    current_num = num;
    deck_labels[1]->setText(num_to_string(num));
}


void Deck::on_pushButton_clicked()
{
    //display_card(this->ui->label_2, ":/cards/resources/cards/spade6");
    Card c(3, Color::spade);
    update_screen(1, 1, c);
}
bool Deck::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    current_image = reader.read();
    if (current_image.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    current_pixmap.load(fileName);
    return true;
}

void Deck::display_card(QLabel *label, const QString &filename){
    loadFile(filename);
    label->setPixmap(current_pixmap);
    label->show();
}

void Deck::update_screen(int player_ind, int card_ind, const Card& card){
    QString s1, s2;
    s1 = color_to_string(card.getcolor());
    s2 = num_to_string(card.getnum());

   card_labels[player_ind * playercards_capacity + card_ind]->setText(s1+s2);
   card_labels[player_ind * playercards_capacity + card_ind]->show();
}

void Deck::turn_down_card(int player_ind, int card_ind){
   card_labels[player_ind * playercards_capacity + card_ind]->setText("");
}


void Deck::update_turn_num(int turn_num){
    ui->turn_label->setText(QString::number(turn_num));
    ui->turn_label->show();
}

void Deck::update_score(int player_ind, int score){
    score_labels[player_ind]->setText(QString::number(score));
}
QString color_to_string(Color c){
    QString s1;
     switch(c){
       case Color::spade: s1 = "Spade"; break;
       case Color::club : s1 = "Club" ; break;
       case Color::diamond: s1 = "Diamond" ; break;
       case Color::heart: s1 = "Heart" ; break;
        default:
        break;
    }
    return s1;
}

QString num_to_string(int num){
    QString s2;
    switch(num){
        case 1: s2 = "A"; break;
        case panacea: s2 = "J"; break;
        case 12: s2 = "Q"; break;
        case 13: s2 = "K"; break;
        default: s2 = QString::number(num);
   }
   return s2;
}
