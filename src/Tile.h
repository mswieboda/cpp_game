#ifndef _TILE_H
#define _TILE_H

#include <iostream>
#include <allegro5/allegro_primitives.h>

class Tile {
  public:
    Tile();
    Tile(int row, int col);

    void update();
    void draw(int x, int y);
    void destroy();

    void print();

    int row;
    int col;
};

#endif
