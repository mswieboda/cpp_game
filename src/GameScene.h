#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

// #include <allegro5/allegro_image.h>

#include "Scene.h"
#include "Keys.h"
#include "Player.h"

using namespace std;

class GameScene: public Scene {
  public:
    GameScene(string name);

    void update(Keys keys);
    void draw();
    void destroy();

    Player player;
    ALLEGRO_BITMAP* sheet;
};

#endif
