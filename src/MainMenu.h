#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Scene.h"
#include "Keys.h"

using namespace std;

class MainMenu: public Scene {
  public:
    MainMenu();
    MainMenu(string name);

    void update(Keys keys);
    void draw();
    void destroy();

    void reset();

    ALLEGRO_FONT* fontBig;
    ALLEGRO_FONT* fontNormal;
    bool isStart;
    bool isExit;
};

#endif
