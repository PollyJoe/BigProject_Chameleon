/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <QVector>



class Player{
    /*************************************************************
     * Features of players:
     *  1. Cards in hand;
     *  2. Score;s
     *  3. Null-slots
     * Operations upon players:
     *  1. Update the score
     ************************************************************/
public:
    Player() = default;
    ~Player() = default;

    friend class Game;

    void IncreaseScore(int point){score += point;}
    void UpdateScore(Card card){IncreaseScore(card.GetPoint());}
    QVector<Card> cards_inhand;
private:
    int score = 0;
    int null_slot = max_inhand - 1;
    bool ifgiveup;
};

using Players = std::vector<Player>;
void players_init(Players &players);

#endif // PLAYER_H
