#include "MainMenu.h"

MainMenu::MainMenu(string _name): Scene(_name) {
  isStart = false;
  isExit = false;
  name = _name;
  fontBig = al_load_font("./assets/PressStart2P.ttf", 64, 0);
  fontNormal = al_load_font("./assets/PressStart2P.ttf", 24, 0);
}

void MainMenu::update(Keys keys) {
  if (keys.isJustPressed(ALLEGRO_KEY_ESCAPE)) {
    isExit = true;
    return;
  }

  if (keys.anyJustPressed())
    isStart = true;
}

void MainMenu::draw() {
  al_draw_text(fontBig, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 3, ALLEGRO_ALIGN_CENTRE, getNameChars());
  al_draw_text(fontNormal, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 2, ALLEGRO_ALIGN_CENTRE, "press [SPACE] to start!");
}

void MainMenu::destroy() {
  al_destroy_font(fontBig);
  al_destroy_font(fontNormal);
}

void MainMenu::reset() {
  isStart = false;
  isExit = false;
}
