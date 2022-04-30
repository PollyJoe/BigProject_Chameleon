//
//  Current.h
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/29.
//

#ifndef Current_h
#define Current_h

#include "Card.h"

typedef struct
{
    Color current_color;
    int current_num;
} Current;

//Change the assigned color
void change_color(Current *current, Color c);
//Change the assigned number
void change_num(Current *current, int num);
//Desturct the current color and number
void destruct_current(Current *current);
//Display current status
void Display_current(Current *current);
#endif /* Current_h */
