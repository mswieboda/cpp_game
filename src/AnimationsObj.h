#ifndef _ANIMATIONS_OBJ_H
#define _ANIMATIONS_OBJ_H

#include <iostream>
#include <allegro5/allegro_image.h>
#include "Animations.h"

class AnimationsObj {
  public:
    AnimationsObj();

    virtual void initAnimations(ALLEGRO_BITMAP* sheet);
    void update();
    void draw(int x, int y);
    void destroy();

    Animations animations;
    int x;
    int y;
};

#endif
