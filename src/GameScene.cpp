#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Scene.h"
#include "GameScene.h"
#include "Keys.h"

using namespace std;

GameScene::GameScene(string _name, int gameFps):
  Scene(_name),
  box(333, 555, 300, 300),
  boxSpeed(10),
  sprite(gameFps / 12, true) {
  name = _name;

  sheet = al_load_bitmap("./assets/spritesheet.png");
  sprite.x = 100;
  sprite.y = 100;
  sprite.add(sheet, 34, 0, 10, 8);
  // sprite.add(34, 0, 10, 8);
  // sprite.add(sheet, 45, 0, 7, 8);
  // sprite.add(sheet, 54, 0, 9, 8);
  cout << ">>> GameScene() sprite x: " << sprite.x << " y: " << sprite.y << " w: " << sprite.width << " h:" << sprite.height << endl;
}

void GameScene::update(Keys keys) {
  printf(">>> GameScene update\n");
  if (keys.anyPressed(2, ALLEGRO_KEY_UP, ALLEGRO_KEY_W))
    box.y -= boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_S))
    box.y += boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_A))
    box.x -= boxSpeed;
  if (keys.anyPressed(2, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_D))
    box.x += boxSpeed;

  sprite.update();
}

void GameScene::draw() {
  printf(">>> GameScene draw\n");
  al_draw_filled_rectangle(box.x, box.y, box.x + box.width, box.y + box.height, al_map_rgb_f(0, 1, 0));

  sprite.draw();
}

void GameScene::destroy() {
  printf(">>> GameScene destroy\n");
  // if (sprite != 0)
  sprite.destroy();

  al_destroy_bitmap(sheet);
}
