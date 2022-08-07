#ifndef _SPRITE_H
#define _SPRITE_H

#include <allegro5/allegro_image.h>

using namespace std;

class Sprite {
  public:
    Sprite(int fpsFactor, bool centered);

    void add(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h);
    int displayFrame();
    void update();
    void draw();
    void destroy();

    // vector<ALLEGRO_BITMAP *> sprites;
    ALLEGRO_BITMAP* sprite;
    int x;
    int y;
    int width;
    int height;
    int frame;
    int fpsFactor;
    bool centered;
};

#endif
