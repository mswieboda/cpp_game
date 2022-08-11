#ifndef _COAL_H
#define _COAL_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Tile.h"

class Coal: public Tile {
  public:
    Coal();
    Coal(int row, int col);

    virtual void update();
    virtual void draw(int x, int y);
    virtual void destroy();

    virtual void print();
};

#endif
