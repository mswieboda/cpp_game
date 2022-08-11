#include "Map.h"
#include <functional>
#include <type_traits>

Map::Map(): coal() {
  x = 0;
  y = 0;
  width = 0;
  height = 0;
}

void Map::update(Mouse mouse) {
  Mouse mapMouse(mouse.x - x, mouse.y - y);

  // for (auto tileRow : coalTiles)
  //   for (auto tile : tileRow)
  //     tile.update(mapMouse);

  // for (auto t : coalTiles) {
  //   decltype(auto) tile = unwrap_reference_t<Coal>(t);
  //   tile.update(mapMouse);
  // }

  // coal.update(mapMouse);
}

void Map::draw() {
  // ground
  // for (auto tileRow : groundTiles)
  //   for (auto tile : tileRow)
  //     tile.draw(x, y);
  for (auto t : groundTiles) {
    Ground tile = unwrap_reference_t<Ground>(t);
    tile.draw(x, y);
  }

  // coal
  // for (auto tileRow : coalTiles)
  //   for (auto tile : tileRow)
  //     tile.draw(x, y);
  // for (auto t : coalTiles) {
  //   decltype(auto) tile = unwrap_reference_t<Coal>(t);
  //   tile.draw(x, y);
  // }
  // coal.draw(x, y);

  // tiles
  // for (auto tileRow : tiles)
  //   for (auto tile : tileRow)
  //     tile.draw(x, y);
  // for (auto t : tiles) {
  //   decltype(auto) tile = unwrap_reference_t<Tile>(t);
  //   tile.draw(x, y);
  // }
}

void Map::destroy() {

}
