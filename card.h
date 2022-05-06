#ifndef CARD_H
#define CARD_H
#include <stack>
#include <random>
#include <algorithm>
#include <memory>
#include "constants.h"
enum class Color{heart, club, diamond, spade, PANACEA};

class Card
{
public:
    Card(int num, Color c) : number(num), color(c){};
    Card() = default;
    ~Card() = default;
    int getpoint()const;
    int getnum()const{return number;}
    Color getcolor()const{return color;}

    void set_deployable(bool if_dep){deployable = if_dep;}
    bool if_deployable()const{return deployable;}
private:
    int number;
    Color color;
    bool deployable = false;
};

using CardStack = std::stack<Card>;
void CardStackInit(CardStack& stack);

#endif // CARD_H
