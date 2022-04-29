//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//
#include "Game.h"
#include "Display_interface.h"
int main()
{
    //Print the welcome interface for command line mode
    Display_welcome();
    char yn;
    scanf("%c", &yn);
    Cardstack *cardstack = Cardstack_init();
    //Debug the game
    
    display_cardstack(cardstack);
    return 0;
}
