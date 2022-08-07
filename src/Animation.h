#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <iostream>
#include <vector>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Animation {
  public:
    Animation(int fpsFactor, bool loop, bool centered);

    void add(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h);
    void addBlank(int w, int h);
    int displayFrame();
    void update();
    void draw(int x, int y);
    void destroy();

    vector<ALLEGRO_BITMAP*> sprites;
    int width;
    int height;
    int frame;
    int fpsFactor;
    bool centered;
    bool loop;
};

#endif
