#include "Scene.h"

Scene::Scene() {
  isExit = false;
}

void Scene::init() {
  reset();
}

void Scene::update(Keys keys) {}

void Scene::draw() {}

void Scene::reset() {
  isExit = false;
}

void Scene::destroy() {}
