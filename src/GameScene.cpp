#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Scene.h"
#include "GameScene.h"
#include "Keys.h"

using namespace std;

GameScene::GameScene(string _name, int gameFps):
  Scene(_name),
  boxSpeed(10),
  sprite(gameFps / 6, true) {
  name = _name;

  sheet = al_load_bitmap("./assets/spritesheet.png");
  sprite.x = 100;
  sprite.y = 100;

  sprite.add(sheet, 33, 10, 9, 9);
  sprite.add(sheet, 43, 9, 11, 11);
  sprite.add(sheet, 46, 21, 17, 18);
  sprite.add(sheet, 46, 40, 17, 17);
  sprite.addBlank(9, 9);
}

void GameScene::update(Keys keys) {
  if (keys.anyPressed(2, ALLEGRO_KEY_UP, ALLEGRO_KEY_W))
    sprite.y -= boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_S))
    sprite.y += boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_A))
    sprite.x -= boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_D))
    sprite.x += boxSpeed;

  sprite.update();
}

void GameScene::draw() {
  sprite.draw();
}

void GameScene::destroy() {
  sprite.destroy();

  al_destroy_bitmap(sheet);
}
