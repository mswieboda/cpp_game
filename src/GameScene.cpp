#include "GameScene.h"
#include <vector>
#include "Tile.h"

#define FPS 60
#define ROWS 3
#define COLS 10

GameScene::GameScene(): Scene(), map(), player()  {
  sheet = al_load_bitmap("./assets/player.png");
}

void GameScene::init() {
  Scene::init();
  initMap();
  initPlayer();
}

void GameScene::initMap() {
  vector<vector<Tile>> tiles;

  for (int row = 0; row < ROWS; row++) {
    vector<Tile> tileRow;

    for (int col = 0; col < COLS; col++) {
      Tile tile(row, col);
      tileRow.push_back(tile);
    }

    tiles.push_back(tileRow);
  }

  map.tiles = tiles;
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
