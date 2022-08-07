#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include <iostream>

#include "Scene.h"

using namespace std;

class MainMenu: public Scene {
  public:
    MainMenu(string name);

    void update(unsigned char * key);
    void draw();

    ALLEGRO_FONT* fontBig;
    ALLEGRO_FONT* fontNormal;
};

#endif
