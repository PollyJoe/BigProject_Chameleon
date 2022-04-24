//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include "Cards.h"

int main(int argc, const char * argv[])
{
    CardStack stack;
    CardStack_Init(&stack);
    display_CardHeap(&stack); 
    return 0;
}
