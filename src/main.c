//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include "Preprocess.h"
struct Card card[52];
struct Player player[2];

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
        printf("%s %d\n", player[0].cards[i].color, player[0].cards[i].number);
    printf("\n");
    printf("player 2:\n");
    for(int i = 0;i < 4;i++)
        printf("%s %d\n", player[1].cards[i].color, player[1].cards[i].number);
    return 0;
}
// This is a project not a simple practice, so the display shouldn't be so careless, put all your displays into a single file like "display.c"
// say:
//void display(){
//    printf(R"a(  ____ _                          _
//               / ___| |__   __ _ _ __ ___   ___| | ___  ___  _ __
//              | |   | '_ \ / _` | '_ ` _ \ / _ \ |/ _ \/ _ \| '_ \
//              | |___| | | | (_| | | | | | |  __/ |  __/ (_) | | | |
//               \____|_| |_|\__,_|_| |_| |_|\___|_|\___|\___/|_| |_|
//)a");
// Although you need to use g++ -std=c++11 to compile it hhhhhh