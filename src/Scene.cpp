#include "Scene.h"

Scene::Scene() {
  name = "";
  isExit = false;
}

Scene::Scene(string name): Scene() {
  this->name = name;
}

void Scene::init() {
  cout << ">>> Scene " << name << " init" << endl;
}

void Scene::update(Keys keys) {
  cout << ">>> Scene " << name << " update" << endl;
}

void Scene::draw() {
  cout << ">>> Scene " << name << " draw" << endl;
}

void Scene::destroy() {
  cout << ">>> Scene " << name << " destroy" << endl;
}

const char * Scene::getNameChars() {
  return name.c_str();
}
