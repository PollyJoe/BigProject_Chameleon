//
//  main.c
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#include <stdio.h>
#include "Preprocess.h"
struct CARD card[52];

int main(int argc, const char * argv[])
{
    init(card);
    shuffle(card);
    return 0;
}
