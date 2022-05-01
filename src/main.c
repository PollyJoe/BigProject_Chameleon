//
//  main.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/26.
//
#include "Game.h"
#include "Display_interface.h"
#include "Current.h"
int main()
{
    //Print the welcome interface for command line mode
    Display_welcome();
    
    //Debug the game
    mach2machgame();
    return 0;
}
