#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"
#include "card.h"
#include <vector>
#include <memory>

class Player
{
public:
    Player() = default;
    ~Player() = default;
    void increasescore(int point){score += point;}
   void updatescore(const Card& card){increasescore(card.getpoint());}

    std::vector<Card> cards_on_hand;
    friend class Game;
private:
    int score = 0;
    int null_position = playercards_capacity - 1;
};

using Players = std::vector<Player>;
void Players_Init(Players& players);
#endif // PLAYER_H

