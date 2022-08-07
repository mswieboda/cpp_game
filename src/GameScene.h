#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include <iostream>

#include "Scene.h"
#include "Box.h"

using namespace std;

class GameScene: public Scene {
  public:
    GameScene(string name);

    void update(unsigned char * key);
    void draw();

    Box box;

    const float boxSpeed;
};

#endif
