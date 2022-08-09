#ifndef _SCENE_H
#define _SCENE_H

#include <iostream>
#include "Keys.h"

using namespace std;

class Scene {
  public:
    Scene();
    Scene(string name);

    virtual void init();
    virtual void update(Keys keys);
    virtual void draw();
    virtual void destroy();

    const char * getNameChars();

    string name;
    bool isExit;
};

#endif
