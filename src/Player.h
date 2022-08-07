#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <allegro5/allegro_image.h>
#include "Keys.h"
#include "Animation.h"

class Player {
  public:
    Player();

    void initAnimation(ALLEGRO_BITMAP* sheet);
    void update(Keys keys);
    void draw();
    void destroy();

    Animation animation;
    int x;
    int y;
    int speed;
};

#endif
