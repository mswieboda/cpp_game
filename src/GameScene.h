#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include <iostream>

#include "Scene.h"
#include "Box.h"
#include "Keys.h"

using namespace std;

class GameScene: public Scene {
  public:
    GameScene(string name);

    void update(Keys keys);
    void draw();

    Box box;

    const float boxSpeed;
};

#endif
