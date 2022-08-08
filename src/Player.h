#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <allegro5/allegro_image.h>
#include "Keys.h"
#include "Animations.h"

class Player {
  public:
    Player();

    void initAnimations(ALLEGRO_BITMAP* sheet);
    void update(Keys keys);
    void draw();
    void destroy();

    Animations animations;
    int x;
    int y;
    int speed;
};

#endif
