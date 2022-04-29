//
//  Display_interface.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/28.
//

#include "Display_interface.h"
#include <stdio.h>
void Display_welcome()
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
