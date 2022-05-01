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
***************************************************************************************************
 Deal the card and check whether the card is valid in this turn
***************************************************************************************************/
void deal(Cardstack *cardstack, Players *players)
{
    for(int i = 0; i < max_player * (max_card_inhand - 1); i++)
        players->player[i % max_player]->card_inhand[i / max_player] = pop(cardstack);
}

bool ifValid(Card *card, Current *current)
{
    return ((card != NULL)&&((card->number == current->current_num) || (card->c == current->current_color) || (card->number == 11)));
}

void check_valid(bool (*ifValid)(Card *card, Current *current), Player *player,  Current *current)
{
    int i;
    for(i = 0; i < max_card_inhand; i++)
            player->valid[i] = ifValid(player->card_inhand[i], current);
}

bool ifChame(bool (*ifValid)(Card *card, Current *current), Card *card, Current *current)
{
    return (ifValid(card, current) && ((card->number == 11) || (card->number == current->current_num)));
}

void check_chame(bool (*ifChame)(bool (*ifValid)(Card *card, Current *current), Card *card, Current *current), Player *player, Current *current)
{
    int i;
    for(i = 0; i < max_card_inhand; i++)
    {
        if(ifChame(ifValid, player->card_inhand[i], current))
            player->chame[i] = true;
    }
}

/******************************************************************************************************************
 Strategies for AI playing
    1. Card selection
    2. Color selection
*********************************************************************************************************************
 Card selection:
 Give a strategy to select the number of card to be played (only for computer player):
    1. If have the same color, play the largest;
    2. If no same color, find chameleon;
    3. If none of the two mentioned above is available, give up.
 p.s. Both the playing and giving up selection are done in the same function
 *******************************************************************************************************************/
int select_card(bool (*ifValid)(Card *card, Current *current), bool (*ifChame)(bool (*ifValid)(Card *card, Current *current), Card *card, Current *current), Player *player, Current *current, bool *nogiveup)
{
    //Initialize the choice and check the attribute of each card
    int choice_index = -1;
    *nogiveup = false;
    check_valid(ifValid, player, current);
    check_chame(ifChame, player, current);
    //Select the card: validity -> same color ->chameleon
    int i, j, chame = -1;
    for(i = 0; i < max_card_inhand; i++)
    {
        if(player->valid[i])
        {
            *nogiveup = true;
            int flag = 1;
            for(j = 0; j < i; j++) if(get_point(player->card_inhand[i]) < get_point(player->card_inhand[j])) flag = 0;
            //If there is a non-chame card to play, choose this card first
            if(!(player->chame[i]) && flag)  choice_index = i;
            //If it is a chame card, we choose to go on first, and record the number of chame card in case we need it in this turn
            else {chame = i; continue;}
        }
        else continue;
    }
    //If there's only chameleon able to play, then play it
    if(*nogiveup){ if(choice_index == -1) choice_index = chame; }
    //If we have to give up, play the smallest card
    else
    {
        choice_index = 0;
        while(player->card_inhand[choice_index] == NULL && choice_index < max_card_inhand - 1) choice_index++;
        int j = 0;
        while(j < max_card_inhand - 1)
        {
            j++;
            if((player->card_inhand[j] != NULL) && (get_point(player->card_inhand[j]) < get_point(player->card_inhand[choice_index]))) choice_index = j;
        }
    }
    return choice_index;
}

Color select_color(void){srand((unsigned int)time(NULL)); Color c = rand()%color_num; return c;}

/*********************************************************************************************************
 Game begins:
    1. In one turn, if players play, change the color and number instantly;
    2. If there is a player giving up, record the point of the card, allocate the total point to each player that doesn't give up
    3. If there is a chameleon played, change the color only
    4. When the stack is empty, and all the card is invalid, end the game
 *********************************************************************************************************
  Point allocation
 *********************************************************************************************************/
int check_play(Card *cardgiven, bool nogiveup, Current *current, bool (*ifValid)(Card *card, Current *current))
{
    int point = 0;
    if(nogiveup)
    {
        if(ifChame(ifValid, cardgiven, current)) change_color(current, select_color());
        else change_color(current, cardgiven->c);
        change_num(current, cardgiven->number);
    }
    else point += get_point(cardgiven);
    return point;
}

/**********************************************************************************************************
 Play a turn
 **********************************************************************************************************/
void one_turn(Players *players, Cardstack *cardstack, Current *current, int turn_num)
{
    int i;
    int point = 0;
    Display_current(current);
    printf("\n");
    for(i = 0; i < max_player; i++)
        if(!ifEmpty(cardstack)) takecard(players->player[i], cardstack);
    for(i = 0; i < max_player; i++)
    {
        int index = select_card(ifValid, ifChame, players->player[i], current, &players->player[i]->nogiveup);
        Card *cardgiven = givecard(players->player[i], index);
        point += check_play(cardgiven, players->player[i]->nogiveup, current, ifValid);
    }
    Update_Scores(players, point);
}

bool ifContinue(Players *players)
{
    bool ifContinue = true;
    int i, j;
    for(i = 0; i < max_player; i++)
    {
        for(j = 0; j < max_card_inhand; j++)
            ifContinue = players->player[i]->valid[j];
    }
    return ifContinue;
}

/*************************************************************************************************************
 Real game
    1. Machine-machine
    2. Man-Machine
    3. Man-man
 *************************************************************************************************************/
void mach2machgame(void)
{
    Cardstack *cardstack = Cardstack_init();
    Players *players = Players_init();
    Current *current;
    current = (Current*)malloc(sizeof(Current));
    deal(cardstack, players);
    int turn = 0;
    
    srand((unsigned int)time(NULL));
    current->current_color = rand()%color_num;
    current->current_num = rand()%set_size;
    
    //If the stack isn't empty, keep taking cards
    while(!(ifEmpty(cardstack)))
    {
        turn++;
        printf("************************************************\nturn %d\n", turn);
        Display_Players(players);
        one_turn(players, cardstack, current, turn);
        Display_Players(players);
    }
    //When the stack is empty, we can't take cards, only play
    while(ifContinue(players))
    {
        turn++;
        int i;
        int point = 0;
        printf("************************************************\nturn %d\n", turn);
        Display_Players(players);
        for(i = 0; i < max_player; i++)
        {
            Display_current(current);
            int index = select_card(ifValid, ifChame, players->player[i], current, &players->player[i]->nogiveup);
            Card *cardgiven = givecard(players->player[i], index);
            point += check_play(cardgiven, players->player[i]->nogiveup, current, ifValid);
        }
        Update_Scores(players, point);
        Display_Players(players);
    }
}
