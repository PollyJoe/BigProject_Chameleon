//
//  Current.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/29.
//

#include "Current.h"
/********************************************************************************
 1. Initialize the current state of game
 ********************************************************************************/
void Current_init(void)
{
    Current *current = (Current*)malloc(sizeof(Current));
    current->current_color = chameleon;
    current->current_num = -1;
}

void change_color(Current *current, Color c){current->current_color = c;}
void change_num(Current *current, int num){current->current_num = num;}
void Display_current(Current *current)
{
    printf("Current color: ");
    switch(current->current_color)
    {
        case spade:printf("Spade ");break;
        case club:printf("Club ");break;
        case diamond:printf("Diamond ");break;
        case heart:printf("Heart ");break;
        default:break;
    }
    printf("\n");
    printf("Current number: ");
    if(current->current_num >=2 && current->current_num <= 10)
        printf("%d", current->current_num);
    else if(current->current_num == 0)
        printf("K");
    else if(current->current_num == 1)
        printf("A");
    else if(current->current_num == 12)
        printf("Q");
    else
        printf("J");
}
void destruct_current(Current *current){free(current);}


