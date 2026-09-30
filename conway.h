#ifndef CONWAY_H
#define CONWAY_H

#define for_x  for (int x = 0; x < w; x++)
#define for_y  for (int y = 0; y < h; y++)
#define for_xy for_x for_y

int  count_alive(int w, int h, unsigned char univ[h][w], int x, int y);
void evolve(int w, int h, unsigned char univ[h][w]);

#endif
