#ifndef _GROUND_H
#define _GROUND_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Tile.h"

class Ground: public Tile {
  public:
    Ground();
    Ground(int row, int col);

    void update();
    void draw(int x, int y);
    void destroy();

    void print();

    int xyz;
};

#endif
