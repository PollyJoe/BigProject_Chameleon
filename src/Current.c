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
void destruct_current(Current *current){free(current);}


