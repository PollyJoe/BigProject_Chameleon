#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <QVector>


/*************************************************************
 * Features of players:
 *  1. Cards in hand;
 *  2. Score;s
 *  3. Null-slots
 * Operations upon players:
 *  1. Update the score
*************************************************************/
class Player{
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
