#ifndef _BUTTON_H
#define _BUTTON_H

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "../Box.h"

using namespace std;

class Button: public Box {
  public:
    Button();
    Button(ALLEGRO_FONT* font, string text);
    Button(ALLEGRO_FONT* font, string text, int width, int height);
    Button(ALLEGRO_FONT* font, string text, int x, int y, int width, int height);

    void update();
    void draw();
    void destroy();

    int x;
    int y;
    int width;
    int height;
    string text;
    ALLEGRO_FONT* font;
};

#endif
