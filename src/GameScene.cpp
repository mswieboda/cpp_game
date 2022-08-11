#include "GameScene.h"
#include <vector>
#include "Tile.h"
#include "Ground.h"

#define FPS 60

using namespace std;

GameScene::GameScene(): Scene(), map(), player() {
  sheet = al_load_bitmap("./assets/player.png");
}

void GameScene::init() {
  Scene::init();
  initMap();
  initPlayer();
}

void GameScene::initMap() {
  int groundRows = 16;
  int groundCols = 24;

  for (int row = 0; row < groundRows; row++) {
    vector<Ground> tileRow;

    for (int col = 0; col < groundCols; col++) {
      Ground ground(row, col);
      tileRow.push_back(ground);
    }

    map.groundTiles.push_back(tileRow);
  }
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
  map.draw();
  player.draw(0, 0);
}

void GameScene::destroy() {
  player.destroy();
  al_destroy_bitmap(sheet);
}
