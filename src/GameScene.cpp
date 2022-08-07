#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "Scene.h"
#include "GameScene.h"
#include "Keys.h"

using namespace std;

GameScene::GameScene(string _name): Scene(_name), box(333, 555, 300, 300), boxSpeed(10) {
  name = _name;
}

void GameScene::update(Keys keys) {
  if (keys.isPressed(ALLEGRO_KEY_UP) || keys.isPressed(ALLEGRO_KEY_W))
    box.y -= boxSpeed;
  if (keys.isPressed(ALLEGRO_KEY_DOWN) || keys.isPressed(ALLEGRO_KEY_S))
    box.y += boxSpeed;
  if (keys.isPressed(ALLEGRO_KEY_LEFT) || keys.isPressed(ALLEGRO_KEY_A))
    box.x -= boxSpeed;
  if (keys.isPressed(ALLEGRO_KEY_RIGHT) || keys.isPressed(ALLEGRO_KEY_D))
    box.x += boxSpeed;
}

void GameScene::draw() {
  al_draw_filled_rectangle(box.x, box.y, box.x + box.width, box.y + box.height, al_map_rgb_f(0, 1, 0));
}
