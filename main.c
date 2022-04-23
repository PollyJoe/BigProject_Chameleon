//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include <stdio.h>
#include "Preprocess.h"

int main(int argc, const char * argv[])
{
    int card[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,16,17,18,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
    shuffle(card);

    
    return 0;
}
