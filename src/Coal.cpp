#include "Coal.h"

using namespace std;

#define SIZE 64

Coal::Coal(): Tile() {}

Coal::Coal(int row, int col): Tile(row, col) {}

void Coal::update() {

}

void Coal::draw(int x, int y) {
  ALLEGRO_COLOR color = al_map_rgba_f(0.13, 0.13, 0.13, 0.69);

  x += col * SIZE;
  y += row * SIZE;

  al_draw_filled_rectangle(x, y, x + SIZE, y + SIZE, color);
}

void Coal::destroy() {

}

void Coal::print() {
  cout << "> Coal";
  cout << " (" << row;
  cout << ", " << col << ")";
  cout << endl;
}
