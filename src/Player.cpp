#include "Player.h"

#define FPS 60
Player::Player(): animations() {
  x = 0;
  y = 0;
  speed = 0;
}

void Player::initAnimations(ALLEGRO_BITMAP* sheet) {
  Animation idle(FPS / 3, true, true);

  const int frames = 5;
  const int size = 64;

  for (int i = 0; i < frames; i++) {
    idle.add(sheet, i * size, 0, size, size);
  }

  animations.add(idle, "idle");

  animations.play("idle");
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

  if (keys.isJustPressed(ALLEGRO_KEY_1))
    animations.play("idle");

  if (keys.isJustPressed(ALLEGRO_KEY_2))
    animations.play("explosion");

  animations.update();
}

void Player::draw() {
  animations.draw(x, y);
}

void Player::destroy() {
  animations.destroy();
}
