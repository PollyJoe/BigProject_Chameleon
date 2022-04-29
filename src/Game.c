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
    for(int i = 0; i < max_player * (max_card_inhand-1); i++)
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
/**********************************************************************************************************************
 Give a strategy to select the number of card to be played (only for computer player):
    1. If have Chameleon, play it first;
    2. If no Chameleon:
        (1) Play the card with the largest
    
 ***********************************************************************************************************************/
int select_card(bool (*ifValid)(Card *card, Current *current), Player *player, bool *ifgiveup)
{
    //Initialize the choice
    int choice_index = -1;
    *ifgiveup = false;
    
    return 1;
}




