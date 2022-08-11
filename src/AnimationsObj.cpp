#include "AnimationsObj.h"

AnimationsObj::AnimationsObj(): animations() {
  x = 0;
  y = 0;
}

void AnimationsObj::initAnimations(ALLEGRO_BITMAP* sheet) {

}

void AnimationsObj::update() {
  animations.update();
}

void AnimationsObj::draw(int drawX, int drawY) {
  animations.draw(drawX + x, drawY + y);
}

void AnimationsObj::destroy() {
  animations.destroy();
}
