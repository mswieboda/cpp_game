#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include <iostream>

#include "Scene.h"
#include "Keys.h"

using namespace std;

class MainMenu: public Scene {
  public:
    MainMenu(string name);

    void update(Keys keys);
    void draw();

    ALLEGRO_FONT* fontBig;
    ALLEGRO_FONT* fontNormal;
};

#endif
