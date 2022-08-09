#include "MainMenu.h"

MainMenu::MainMenu(): Scene(), button() {
  isStart = false;
  fontBig = al_load_font("./assets/PressStart2P.ttf", 64, 0);
  fontNormal = al_load_font("./assets/PressStart2P.ttf", 24, 0);
}

void MainMenu::init() {
  Scene::init();
  initUI();
}

void MainMenu::initUI() {
  button.font = fontNormal;
  button.text = "START";
  button.x = 100;
  button.y = 100;
  button.width = 500;
  button.height = 100;
}

void MainMenu::update(Keys keys) {
  if (keys.isJustPressed(ALLEGRO_KEY_ESCAPE)) {
    isExit = true;
    return;
  }

  if (keys.isJustPressed(ALLEGRO_KEY_SPACE))
    isStart = true;
}

void MainMenu::draw() {
  al_draw_text(fontBig, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 3, ALLEGRO_ALIGN_CENTRE, "[YOUR GAME NAME HERE]");
  al_draw_text(fontNormal, al_map_rgb(0, 255, 0), 2048 / 2, 1440 / 2, ALLEGRO_ALIGN_CENTRE, "press [SPACE] to start!");

  button.draw();
}

void MainMenu::reset() {
  Scene::reset();

  isStart = false;
}

void MainMenu::destroy() {
  al_destroy_font(fontBig);
  al_destroy_font(fontNormal);
}
