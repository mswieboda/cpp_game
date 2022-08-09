#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <vector>
#include "Tile.h"

using namespace std;

class Map {
  public:
    Map();

    void update();
    void draw();
    void destroy();

    int x;
    int y;
    int width;
    int height;
    vector<vector<Tile>> tiles;
};

#endif
