#include "GameScene.h"

#define FPS 60

GameScene::GameScene(string _name): Scene(_name), player() {
  isExit = false;
  name = _name;
  sheet = al_load_bitmap("./assets/spritesheet.png");

  player.x = 100;
  player.y = 100;
  player.speed = 10;

  player.initAnimations(sheet);
}

void GameScene::update(Keys keys) {
  if (keys.isJustPressed(ALLEGRO_KEY_ESCAPE)) {
    isExit = true;
    return;
  }

  player.update(keys);
}

void GameScene::draw() {
  player.draw();
}

void GameScene::destroy() {
  player.destroy();
  al_destroy_bitmap(sheet);
}

void GameScene::reset() {
  isExit = false;
}
