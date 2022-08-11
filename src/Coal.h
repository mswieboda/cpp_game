#ifndef _COAL_H
#define _COAL_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Tile.h"
#include "Mouse.h"

class Coal: public Tile {
  public:
    Coal();
    Coal(int row, int col);

    void update(Mouse mouse);
    void draw(int x, int y);
    void destroy();

    void print();

    bool hovering;
    int num;
};

#endif
