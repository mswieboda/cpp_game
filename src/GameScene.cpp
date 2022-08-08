#include "GameScene.h"

#define FPS 60

GameScene::GameScene(): Scene(), player() {
  sheet = al_load_bitmap("./assets/player.png");

  initPlayer();
}

GameScene::GameScene(string name): GameScene() {
  this->name = name;
}

void GameScene::initPlayer() {
  player.x = 100;
  player.y = 100;
  player.speed = 5;

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
