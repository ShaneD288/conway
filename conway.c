#include <string.h>
#include "conway.h"

/* Count live neighbours of (x, y), wrapping around the edges */
int count_alive(int w, int h, unsigned char univ[h][w], int x, int y)
{
    int n = 0;
    for (int dy = -1; dy <= 1; dy++)
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0)
                continue;
            n += univ[(y + dy + h) % h][(x + dx + w) % w];
        }
    return n;
}

/* Advance the universe by one generation */
void evolve(int w, int h, unsigned char univ[h][w])
{
    unsigned char next[h][w];
    for_xy {
        int n = count_alive(w, h, univ, x, y);
        next[y][x] = (n == 3 || (n == 2 && univ[y][x]));
    }
    memcpy(univ, next, sizeof next);
}
