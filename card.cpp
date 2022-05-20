#include "card.h"
#include <vector>

using namespace std;

/***************************************
 * For cards:
 *  Get the point of the card
***************************************/
int Card::GetPoint()const{
    int point = 0;
    if(this->number == 13 || this->number == 11) point = 0;
    else if(this->number == 12) point = 12;
    else point = this->number;
    return point;
}

/***************************************
 * For cardstack:
 *  1. Push cards
 *  2. Shuffle
***************************************/
void stack_init(Cardstack &cardstack){
    vector<int> n;
    int i;
    for(i = 0; i < stack_size; i++) n.push_back(i);
    random_device rd;
    mt19937 gen(rd());
    shuffle(n.begin(), n.end(), gen);
    int k = 0;
    while(cardstack.size() != stack_size){
        cardstack.push(Card(static_cast<Color>(n[k]% colornum), n[k] % set_size + 1));
        k++;
    }
}
