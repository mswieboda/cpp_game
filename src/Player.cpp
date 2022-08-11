#include "Player.h"

#define FPS 60

Player::Player(): AnimationsObj() {
  speed = 0;
}

void Player::initAnimations(ALLEGRO_BITMAP* sheet) {
  Animation idle(FPS / 3, true, true);

  const int size = 64;
  int frames = 5;
  int i = 0;

  for (; i < frames; i++)
    idle.add(sheet, i * size, 0, size, size);

  Animation idle_walk_left(FPS / 3, true, true);

  frames += 4;

  for (; i < frames; i++)
    idle_walk_left.add(sheet, i * size, 0, size, size);

  animations.add(idle, "idle");
  animations.add(idle_walk_left, "idle_walk_left");

  animations.play("idle");
}

void Player::update(Keys keys) {
  AnimationsObj::update();

  int dx = 0;
  int dy = 0;

  if (keys.anyPressed(2, ALLEGRO_KEY_UP, ALLEGRO_KEY_W))
    dy -= speed;
  if (keys.anyPressed(2, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_S))
    dy += speed;
  if (keys.anyPressed(2, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_A)) {
    dx -= speed;
    animations.play("idle_walk_left");
  }
  if (keys.anyPressed(2, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_D))
    dx += speed;

  if (dx == 0 && dy == 0)
    animations.play("idle");
  else {
    x += dx;
    y += dy;
  }
}
