#include "MainMenu.h"

MainMenu::MainMenu(): Scene() {
  screen_width = 0;
  screen_height = 0;
  isStart = false;
  fontBig = al_load_font("./assets/PressStart2P.ttf", 64, 0);
  fontNormal = al_load_font("./assets/PressStart2P.ttf", 24, 0);
}

MainMenu::MainMenu(int screen_width, int screen_height): MainMenu() {
  this->screen_width = screen_width;
  this->screen_height = screen_height;
}

void MainMenu::update(Keys keys, Mouse mouse) {
  if (keys.isJustPressed(ALLEGRO_KEY_ESCAPE)) {
    isExit = true;
    return;
  }

  if (keys.isJustPressed(ALLEGRO_KEY_SPACE))
    isStart = true;
}

void MainMenu::draw() {
  al_draw_text(fontBig, al_map_rgb(0, 255, 0), screen_width / 2, screen_height / 3, ALLEGRO_ALIGN_CENTRE, "[YOUR GAME NAME HERE]");
  al_draw_text(fontNormal, al_map_rgb(0, 255, 0), screen_width / 2, screen_height / 2, ALLEGRO_ALIGN_CENTRE, "press [SPACE] to start!");
}

void MainMenu::reset() {
  Scene::reset();

  isStart = false;
}

void MainMenu::destroy() {
  al_destroy_font(fontBig);
  al_destroy_font(fontNormal);
}
