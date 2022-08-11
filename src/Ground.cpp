#include "Ground.h"

using namespace std;

#define SIZE 64

Ground::Ground(): Tile() {
  xyz = 0;
  cout << "> Ground::Ground()";
  print();
  cout << endl;
}

Ground::Ground(int row, int col): Tile(row, col) {
  xyz = 3;
  cout << "> Ground::Ground(row, col)";
  print();
  cout << endl;
}

void Ground::update() {
  xyz = 13;
  // cout << "> Ground::update";
  // print();
  // cout << endl;
}

void Ground::draw(int x, int y) {
  // cout << "> Ground::draw";
  // print();
  // cout << endl;
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
  cout << " xyz: " << xyz;
  // cout << endl;
}
