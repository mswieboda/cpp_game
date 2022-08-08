#include "Box.h"

Box::Box() {
  x = 0;
  y = 0;
  width = 0;
  height = 0;
}

Box::Box(int width, int height): Box() {
  this->width = width;
  this->height = height;
}

Box::Box(int x, int y, int width, int height): Box(width, height) {
  this->x = x;
  this->y = y;
}
