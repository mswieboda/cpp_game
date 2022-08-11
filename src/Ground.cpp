#include "Ground.h"

using namespace std;

#define SIZE 64

Ground::Ground(): Tile() {}

Ground::Ground(int row, int col): Tile(row, col) {}

void Ground::update() {

}

void Ground::draw(int x, int y) {
  ALLEGRO_COLOR color = al_map_rgb(212, 139, 68);

  x += col * SIZE;
  y += row * SIZE;

  al_draw_filled_rectangle(x, y, x + SIZE, y + SIZE, color);
}

void Ground::destroy() {

}

void Ground::print() {
  cout << "> Ground";
  cout << " (" << row;
  cout << ", " << col << ")";
  cout << endl;
}
