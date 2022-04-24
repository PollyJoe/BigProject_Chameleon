//
//  Preprocess.h
//  chameleon
//
//  Created by Polly Zhou on 2022/4/23.
//

#ifndef Preprocess_h
#define Preprocess_h

#include <stdio.h>
struct CARD
{
    int number;
    char* color;
};

void init(struct CARD a[52]);
void shuffle(struct CARD a[52]);






#endif /* Preprocess_h */
