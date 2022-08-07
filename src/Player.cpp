#include "Player.h"

#define FPS 60

Player::Player(): sprite(FPS / 6, true) {
  x = 0;
  y = 0;
  speed = 0;
}

void Player::initSprite(ALLEGRO_BITMAP* sheet) {
  sprite.add(sheet, 33, 10, 9, 9);
  sprite.add(sheet, 43, 9, 11, 11);
  sprite.add(sheet, 46, 21, 17, 18);
  sprite.add(sheet, 46, 40, 17, 17);
  sprite.addBlank(9, 9);
}

void Player::update(Keys keys) {
  if (keys.anyPressed(2, ALLEGRO_KEY_UP, ALLEGRO_KEY_W))
    y -= speed;
  if (keys.anyPressed(2, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_S))
    y += speed;
  if (keys.anyPressed(2, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_A))
    x -= speed;
  if (keys.anyPressed(2, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_D))
    x += speed;

  sprite.update();
}

void Player::draw() {
  sprite.draw(x, y);
}

void Player::destroy() {
  sprite.destroy();
}
