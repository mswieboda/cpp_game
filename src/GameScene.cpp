#include "GameScene.h"
#include <vector>
#include <functional>
#include "Tile.h"
#include "Ground.h"
#include "Coal.h"

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
  // ground
  int groundRows = 3;
  int groundCols = 3;

  for (int row = 0; row < groundRows; row++) {
    for (int col = 0; col < groundCols; col++) {
      Ground ground(row, col);
      map.groundTiles.push_back(ref(ground));
    }
  }

  // coal patches
  int initCoalRows = 3;
  int initCoalCols = 3;
  int coalRows = 3;
  int coalCols = 3;

  for (int row = initCoalRows; row < initCoalRows + coalRows; row++) {
    for (int col = initCoalCols; col < initCoalCols + coalCols; col++) {
      Coal coal(row, col);
      map.coalTiles.push_back(ref(coal));
    }
  }

  map.coal.row = 3;
  map.coal.col = 3;
}

void GameScene::initPlayer() {
  player.x = 100;
  player.y = 100;
  player.speed = 5;

  player.initAnimations(sheet);
}

void GameScene::update(Keys keys, Mouse mouse) {
  if (keys.isJustPressed(ALLEGRO_KEY_ESCAPE)) {
    isExit = true;
    return;
  }

  map.update(mouse);
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
