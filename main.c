#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "conway.h"

void dump_field(int w, int h, unsigned char univ[h][w])
{
    fputs("\033[H", stdout);
    for_y {
        for_x fputs(univ[y][x] ? "\033[07m  \033[m" : "  ", stdout);
        fputs("\033[E", stdout);
    }
    fflush(stdout);
}

/* Usage: ./conway [width] [height] [generations]  (0 = run forever) */
int main(int argc, char *argv[])
{
    int w = 30, h = 30, gens = 0;
    if (argc > 1) w = atoi(argv[1]);
    if (argc > 2) h = atoi(argv[2]);
    if (argc > 3) gens = atoi(argv[3]);
    if (w <= 0) w = 30;
    if (h <= 0) h = 30;

    unsigned char univ[h][w];
    srand((unsigned) time(NULL));
    for_xy univ[y][x] = rand() < RAND_MAX / 10;

    fputs("\033[2J", stdout);
    for (int g = 0; gens == 0 || g < gens; g++) {
        dump_field(w, h, univ);
        evolve(w, h, univ);
        usleep(200000);
    }
    return 0;
}
