#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "Scene.h"
#include "Keys.h"
#include "Sprite.h"

using namespace std;

class GameScene: public Scene {
  public:
    GameScene(string name, int gameFps);

    void update(Keys keys);
    void draw();
    void destroy();

    const float boxSpeed;
    Sprite sprite;
    ALLEGRO_BITMAP* sheet;
};

#endif
