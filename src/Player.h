#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <allegro5/allegro_image.h>
#include "Keys.h"
#include "AnimationsObj.h"

class Player: public AnimationsObj {
  public:
    Player();

    void initAnimations(ALLEGRO_BITMAP* sheet) override;
    void update(Keys keys);

    int speed;
};

#endif
