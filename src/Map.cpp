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
  // ground
  for (auto tileRow : groundTiles)
    for (auto tile : tileRow)
      tile.draw(x, y);

  // coal
  for (auto tileRow : coalTiles)
    for (auto tile : tileRow)
      tile.draw(x, y);

  // tiles
  for (auto tileRow : tiles)
    for (auto tile : tileRow)
      tile.draw(x, y);
}

void Map::destroy() {

}
