#ifndef _SCENE_H
#define _SCENE_H

#include <iostream>

#include "Keys.h"

using namespace std;

class Scene {
  public:
    Scene(string name);

    string getName();
    const char * getNameChars();
    virtual void update(Keys keys);
    virtual void draw();

  protected:
    string name;
};

#endif
