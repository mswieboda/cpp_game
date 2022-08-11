#ifndef _TILE_H
#define _TILE_H

#include <iostream>
#include <allegro5/allegro_primitives.h>

class Tile {
  public:
    Tile();
    Tile(int row, int col);
    virtual ~Tile() = default;

    virtual void update();
    virtual void draw(int x, int y);
    virtual void destroy();

    virtual void print();

    int row;
    int col;
};

#endif
