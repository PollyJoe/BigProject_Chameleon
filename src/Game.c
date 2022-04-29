//
//  Game.c
//  BigProject_Chameleon
//
//  Created by Polly Zhou on 2022/4/27.
//

#include "Game.h"
/***********************************************************************************************
 Process of one game :
    1. Dealing the card: After dealing, there should be 4 cards in each player's hand
    2. Game begins:
        (1) Player 1 take one card from the stack, choose a card and play;
        (2) Other players take turns to play a card if this card is available;
        (3) Once the stack is full, game over and record the score.
    3. Status of the game:
        (1) Normal valid play:
            Same color.
        (2) Chameleon: change the color to any other one
            1) Same number;
            2) Play "J".
        (3) Discard: No card to play or choose to discard deliberately
            Give the point of the discarded card to his counterpart.
        (4) Foul: any play not included in what was mentioned above.
**************************************************************************************************/
/***************************************************************************************************
 Deal the card and check whether the card is valid in this turn
 ***************************************************************************************************/
void deal(Cardstack *cardstack, Players *players)
{
    for(int i = 0; i < max_player * (max_card_inhand); i++)
        players->player[i % max_player]->card_inhand[i / max_player] = pop(cardstack);
}

bool ifValid(Card *card, Current *current)
{
    return ((card->number == current->current_num) || (card->c == current->current_color) || (card->c == chameleon));
}

void check_valid(bool (*ifValid)(Card *card, Current *current), Player *player,  Current *current)
{
    int i;
    for(i = 0; i < max_card_inhand; i++)
    {
        if(player->card_inhand[i] == NULL)
            player->valid[i] = false;
        else
            player->valid[i] = ifValid(player->card_inhand[i], current);
    }
}

bool ifChame(Card *card, Current *current)
{
    return ((card->number == 11) || (card->number == current->current_num));
}

void check_chame(bool (*ifChame)(Card *card, Current *current), Player *player, Current *current)
{
    int i;
    for(i = 0; i < max_card_inhand; i++)
    {
        if(ifChame(player->card_inhand[i], current))
            player->chame[i] = true;
    }
}

/******************************************
 Strategies for AI playing
    1. Card selection
    2. Color selection
 ******************************************/
/******************************************************************************************************************
 Card selection:
 Give a strategy to select the number of card to be played (only for computer player):
    1. If have the same color, play the largest;
    2. If no same color, find chameleon;
    3. If none of the two mentioned above is available, give up.
 p.s. Both the playing and giving up selection are done in the same function
 *******************************************************************************************************************/
int select_card(bool (*ifValid)(Card *card, Current *current), Player *player, Current *current, bool *nogiveup)
{
    //Initialize the choice and check the attribute of each card
    int choice_index = -1;
    *nogiveup = false;
    check_valid(ifValid, player, current);
    check_chame(ifChame, player, current);
    //Select the card: validity -> same color ->chameleon
    int i, chame = -1;
    for(i = 0; i < max_card_inhand; i++)
    {
        if(player->valid[i])
        {
            *nogiveup = true;
            //If there is a non-chame card to play, choose this card first
            if(player->card_inhand[i]->c == current->current_color && i > choice_index)  choice_index = i;
            //If it is a chame card, we choose to go on first, and record the number of chame card in case we need it in this turn
            else {chame = i; continue;}
        }
        else
            continue;
    }
    //If there's only chameleon able to play, then play it
    if(*nogiveup){ if(choice_index == -1) choice_index = chame; }
    //If we have to give up, play the smallest card
    else
    {
        choice_index = 0;
        int j = 0;
        while(j < max_card_inhand - 1)
        {
            j++;
            if(player->card_inhand[j]->number < player->card_inhand[j - 1]->number) choice_index = j;
        }
    }
    return choice_index;
}

/*********************************************************************************************************
 
 *********************************************************************************************************/



 
