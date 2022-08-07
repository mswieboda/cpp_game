#include "Player.h"

#define FPS 60

Player::Player(): animation(FPS / 3, true, true) {
  x = 0;
  y = 0;
  speed = 0;
}

void Player::initAnimation(ALLEGRO_BITMAP* sheet) {
  animation.add(sheet, 33, 10, 9, 9);
  animation.add(sheet, 43, 9, 11, 11);
  animation.add(sheet, 46, 21, 17, 18);
  animation.add(sheet, 46, 40, 17, 17);
  animation.addBlank(9, 9);
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

  animation.update();
}

void Player::draw() {
  animation.draw(x, y);
}

void Player::destroy() {
  animation.destroy();
}
