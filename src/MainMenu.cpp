#include <iostream>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "Scene.h"
#include "MainMenu.h"
#include "Keys.h"

using namespace std;

MainMenu::MainMenu(string _name): Scene(_name) {
  name = _name;
  fontBig = al_load_font("./assets/fonts/PressStart2P.ttf", 64, 0);
  fontNormal = al_load_font("./assets/fonts/PressStart2P.ttf", 24, 0);
}

void MainMenu::update(Keys keys) {
  
}

void MainMenu::draw() {
  al_draw_text(fontBig, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 3, ALLEGRO_ALIGN_CENTRE, getNameChars());
  al_draw_text(fontNormal, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 2, ALLEGRO_ALIGN_CENTRE, "press enter to start!");
}
