#ifndef _PLAYER_H
#define _PLAYER_H

#include <allegro5/allegro_image.h>
#include "Keys.h"
#include "Sprite.h"

using namespace std;

class Player {
  public:
    Player();

    void initSprite(ALLEGRO_BITMAP* sheet);
    void update(Keys keys);
    void draw();
    void destroy();

    Sprite sprite;
    int x;
    int y;
    int speed;
};

#endif
