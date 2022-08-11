#include "Map.h"

Map::Map() {
  x = 0;
  y = 0;
  width = 0;
  height = 0;
}

void Map::update() {

}

void Map::draw() {
  for (auto tileRow : groundTiles)
    for (auto tile : tileRow)
      tile.draw(x, y);

  for (auto tileRow : tiles)
    for (auto tile : tileRow)
      tile.draw(x, y);
}

void Map::destroy() {

}
