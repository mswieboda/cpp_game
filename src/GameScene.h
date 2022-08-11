#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include <iostream>
#include <vector>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Scene.h"
#include "Keys.h"
#include "Mouse.h"
#include "Map.h"
#include "Player.h"
#include "Ground.h"

using namespace std;

class GameScene: public Scene {
  public:
    GameScene();
    GameScene(string name);

    void init() override;
    void update(Keys keys, Mouse mouse) override;
    void draw() override;
    void destroy() override;


    Map map;
    Player player;
    ALLEGRO_BITMAP* sheet;

  private:
    void initMap();
    void initPlayer();
};

#endif
