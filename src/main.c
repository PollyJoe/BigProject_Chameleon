//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//

#include <stdio.h>
#include "Card.h"


int main()
{
    Cardstack *cardstack = init();
    for(int i =0; i < cardstack_size; i++)
    {
        display_card(cardstack->cards[i]);
        printf("\n");
    }
    return 0;
}
