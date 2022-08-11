#ifndef _SCENE_H
#define _SCENE_H

#include <iostream>
#include "Keys.h"
#include "Mouse.h"

using namespace std;

class Scene {
  public:
    Scene();

    virtual void init();
    virtual void update(Keys keys, Mouse mouse);
    virtual void draw();
    virtual void reset();
    virtual void destroy();

    bool isExit;
};

#endif
