#include <iostream>
#include <allegro5/allegro_image.h>
#include "Scene.h"
#include "GameScene.h"
#include "Keys.h"

using namespace std;

#define FPS 60

GameScene::GameScene(string _name): Scene(_name), player() {
  name = _name;
  sheet = al_load_bitmap("./assets/spritesheet.png");

  player.x = 100;
  player.y = 100;
  player.speed = 10;

  player.initSprite(sheet);
}

void GameScene::update(Keys keys) {
  player.update(keys);
}

void GameScene::draw() {
  player.draw();
}

void GameScene::destroy() {
  player.destroy();
  al_destroy_bitmap(sheet);
}
