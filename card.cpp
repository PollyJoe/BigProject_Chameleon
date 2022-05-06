#include "card.h"
#include <vector>
void CardStackInit(CardStack &stack){
   std::vector<int> n;
   for(int i = 0; i < CARDHEAP_SIZE; ++i) n.push_back(i);

   std::random_device rd;
   std::mt19937 g(rd());;
   std::shuffle(n.begin(), n.end(), g);

   while(stack.size() != CARDHEAP_SIZE)
     stack.push(Card(n[stack.size()] % sets_size + 1, static_cast<Color>(n[stack.size()] % color_num)));
}

int Card::getpoint()const{
    int point = 0;
    if((number > 0) && ( number < 11)) point =  number;
    else if ( number == 12) point = 12;
    else if ( number == 13) point = 0;
    else  printf("You can not give up this card: ");
    return point;
}
