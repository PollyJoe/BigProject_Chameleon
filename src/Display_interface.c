//
//  Display_interface.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/28.
//

#include "Display_interface.h"
#include <stdio.h>
#include <stdlib.h>
void Display_welcome(void)
{
    FILE *fp;
    char ch;
    fp = fopen("Welcome.txt","r");
    if(fp == NULL) printf("ERROR!");
    else
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    }
    printf("Start your game? <y/n> :\n");
}

void Display_Exit(void)
{
    FILE *fp;
    char ch;
    fp = fopen("Ending.txt","r");
    if(fp == NULL) printf("ERROR!");
    else
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    }
    printf("Exitting the game...\n");
}


