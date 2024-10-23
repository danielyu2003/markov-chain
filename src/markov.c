/**
 * markov.c
 */

#include <stdio.h>
#include <stdlib.h>

#define DRSWR_IMPL
#include "drswr.h"

int main(void)
{
    srand(42);
    
    static const size_t n = 8;
    static const char* const words[n] = {"to", "be", "or", "not", "that", "is", "the", "question"};
    static const double t[n][n] = {
        [0] = {[1] = 1},
        [1] = {[2] = 0.5, [4] = 0.5},
        [2] = {[3] = 1},
        [3] = {[0] = 1},
        [4] = {[5] = 1},
        [5] = {[6] = 1},
        [6] = {[7] = 1},
        [7] = {0},
    };

    size_t curr = 0;
    printf("to ");

    while(1) {
        curr = DRSWR(n, t[curr]);
        printf("%s", words[curr]);
        if (curr == 7)
            break;
        printf(" ");
    }
    printf("\n");

    return EXIT_SUCCESS;
}