#include "Coal.h"

using namespace std;

#define SIZE 64

Coal::Coal(): Tile() {
  cout << "> Coal::Coal()" << endl;
  hovering = false;
  num = 3;
}

Coal::Coal(int row, int col): Tile(row, col) {
  cout << "> Coal::Coal(row, col)" << endl;
  hovering = false;
  num = 13;
}

void Coal::update(Mouse mouse) {
  num = 69;
  hovering = false;

  if (mouse.x >= row * SIZE && mouse.x <= row * SIZE + SIZE) {
    if (mouse.y >= col * SIZE && mouse.y <= col * SIZE + SIZE) {
      hovering = true;
      cout << "> Coal::update";
      print();
      cout << endl;
    }
  }
}

void Coal::draw(int x, int y) {
  cout << "> Coal::draw";
  print();
  cout << endl;
  ALLEGRO_COLOR color = al_map_rgba_f(0.13, 0.13, 0.13, 0.69);

  x += col * SIZE;
  y += row * SIZE;

  al_draw_filled_rectangle(x, y, x + SIZE, y + SIZE, color);

  if (hovering) {
    al_draw_rectangle(x, y, x + SIZE, y + SIZE, al_map_rgb_f(1, 1, 1), 1);
  }
}

void Coal::destroy() {

}

void Coal::print() {
  cout << "> Coal";
  cout << " (" << row;
  cout << ", " << col << ")";
  cout << " h: " << hovering;
  cout << " num: " << num;
  // cout << endl;
}
