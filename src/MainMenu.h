#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Scene.h"
#include "Keys.h"
#include "Mouse.h"

using namespace std;

class MainMenu: public Scene {
  public:
    MainMenu();
    MainMenu(int screen_width, int screen_height);

    void update(Keys keys, Mouse mouse) override;
    void draw() override;
    void destroy() override;
    void reset() override;

    ALLEGRO_FONT* fontBig;
    ALLEGRO_FONT* fontNormal;
    bool isStart;

  private:
    void initUI();
    int screen_width;
    int screen_height;
};

#endif
