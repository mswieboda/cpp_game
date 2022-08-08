#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Scene.h"
#include "Keys.h"
#include "Player.h"

class GameScene: public Scene {
  public:
    GameScene();
    GameScene(string name);

    void update(Keys keys);
    void draw();
    void destroy();

    void initPlayer();
    void reset();

    Player player;
    ALLEGRO_BITMAP* sheet;
    bool isExit;
};

#endif
