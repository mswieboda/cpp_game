#include "Mouse.h"

Mouse::Mouse() {
  x = 0;
  y = 0;
}

Mouse::Mouse(int x, int y): Mouse() {
  this->x = x;
  this->y = y;
}
