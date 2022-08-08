#include "Player.h"

#define FPS 60
Player::Player(): animations() {
  x = 0;
  y = 0;
  speed = 0;
}

void Player::initAnimations(ALLEGRO_BITMAP* sheet) {
  Animation spark(FPS, true, true);
  Animation explosion(FPS / 3, true, true);

  spark.add(sheet, 34, 0, 10, 8);
  spark.add(sheet, 45, 0, 7, 8);
  spark.add(sheet, 54, 0, 9, 8);

  explosion.add(sheet, 33, 10, 9, 9);
  explosion.add(sheet, 43, 9, 11, 11);
  explosion.add(sheet, 46, 21, 17, 18);
  explosion.add(sheet, 46, 40, 17, 17);
  explosion.addBlank(9, 9);

  animations.add(spark, "spark");
  animations.add(explosion, "explosion");

  animations.play("spark");
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
    animations.play("spark");

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
