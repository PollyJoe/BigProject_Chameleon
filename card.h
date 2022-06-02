/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日

#ifndef CARD_H
#define CARD_H

#include <stack>
#include "Constant.h"
#include <random>
#include <algorithm>

class Card{
    /***************************************************************************
     * A class contianing all the features of one card.
     * The card will be set as a label.
     * Basic feature:
     *      1.Color
     *      2.Number
     *      3.Point
     *      4.Whether it is valid to play
     *      5.Whether it is a chameleon
     ***************************************************************************/

public:
    Card(Color c, int num) : color(c), number(num){};
    Card() = default;
    ~Card() = default;

    int GetPoint()const;
    int GetNumber()const{return number;}
    Color GetColor()const{return color;}
    void SetValid(bool valid){ifValid = valid;};
    void SetChame(bool chame){ifChame = chame;};
    bool GetValid(){return ifValid;}
    bool GetChame(){return ifChame;}
private:
    Color color;
    int number;
    bool ifValid = false;
    bool ifChame = false;
};

using Cardstack = std::stack<Card>;
void stack_init(Cardstack &cardstack);

#endif // CARD_H
