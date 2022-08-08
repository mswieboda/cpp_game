#ifndef _ANIMATIONS_H
#define _ANIMATIONS_H

#include <iostream>
#include <map>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Animation.h"

using namespace std;

class Animations {
  public:
    Animations();

    void add(Animation animation, string name);
    void update();
    void draw(int x, int y);
    void destroy();

    void play(string name);

    Animation* animation;
    map<string, Animation> animations;
};

#endif
