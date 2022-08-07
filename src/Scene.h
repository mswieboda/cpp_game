#ifndef _SCENE_H
#define _SCENE_H

#include <iostream>

using namespace std;

class Scene {
  public:
    Scene(string name);

    string getName();
    const char * getNameChars();
    void update(unsigned char * key);
    void draw();

  protected:
    string name;
};

#endif
