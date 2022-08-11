#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <vector>
#include <functional>
#include "Mouse.h"
#include "Tile.h"
#include "Ground.h"
#include "Coal.h"

using namespace std;

class Map {
  public:
    Map();

    void update(Mouse mouse);
    void draw();
    void destroy();

    int x;
    int y;
    int width;
    int height;

    vector<reference_wrapper<Ground>> groundTiles;
    vector<reference_wrapper<Coal>> coalTiles;
    vector<reference_wrapper<Tile>> tiles;

    Coal coal;
};

#endif
