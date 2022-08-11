#ifndef _MOUSE_H
#define _MOUSE_H

#include <cstdarg>
#include <iostream>
#include <allegro5/allegro5.h>

class Mouse {
  public:
    Mouse();
    Mouse(int x, int y);

    int x;
    int y;
};

#endif
