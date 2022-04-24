//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include <stdio.h>
#include "Preprocess.h"
struct CARD card[52];
struct PLAYER player[2];

int main(int argc, const char * argv[])
{
    int a;
    printf("choose computer-computer mode (1) or human-computer mode (2):\n");
    scanf("%d", &a);
    init(card);
    shuffle(card);
    deal(player, card, a);
    printf("player 1:\n");
    for(int i = 0;i < 4;i++)
        printf("%s %d\n", player[0].playercard[i].color, player[0].playercard[i].number);
    printf("\n");
    printf("player 2:\n");
    for(int i = 0;i < 4;i++)
        printf("%s %d\n", player[1].playercard[i].color, player[1].playercard[i].number);
    return 0;
}
