#include "Tile.h"

using namespace std;

#define SIZE 64

Tile::Tile() {
  row = 0;
  col = 0;
}

Tile::Tile(int row, int col): Tile() {
  this->row = row;
  this->col = col;
}

void Tile::update() {

}

void Tile::draw(int x, int y) {
  ALLEGRO_COLOR color = al_map_rgba_f(0, 0.13, 0, 0.13);

  // TODO: refactor into one line?
  if (row % 2 != 0) {
    if (col % 2 != 0) {
      color = al_map_rgba_f(0, 0, 0.13, 0.13);
    }
  } else {
    if (col % 2 == 0) {
      color = al_map_rgba_f(0, 0, 0.13, 0.13);
    }
  }

  x += col * SIZE;
  y += row * SIZE;

  al_draw_filled_rectangle(x, y, x + SIZE, y + SIZE, color);
}

void Tile::destroy() {

}

void Tile::print() {
  cout << "> Tile";
  cout << " (" << row;
  cout << ", " << col << ")";
  cout << endl;
}
