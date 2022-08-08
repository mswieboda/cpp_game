#include "Animations.h"

#define FPS 60

Animations::Animations() {
  animation = nullptr;
}

void Animations::add(Animation animation, string name) {
  animations[name] = animation;
}

void Animations::update() {
  if (animation != nullptr)
    animation->update();
}

void Animations::draw(int x, int y) {
  if (animation != nullptr)
    animation->draw(x, y);
}

void Animations::destroy() {
  for (auto itr : animations) {
    Animation ani = itr.second;
    ani.destroy();
  }
}

void Animations::play(string name) {
  std::map<string, Animation>::iterator itr = animations.find(name);

  if (itr != animations.end())
    animation = &itr->second;
}
