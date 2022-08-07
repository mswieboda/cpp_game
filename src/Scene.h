#ifndef _SCENE_H
#define _SCENE_H

#include <iostream>

using namespace std;

class Scene {
  public:
    Scene(string name);

    string getName();
    const char * getNameChars();
    virtual void update(unsigned char * key);
    virtual void draw();

  protected:
    string name;
};

#endif
