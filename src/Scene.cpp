#include <iostream>

#include "Scene.h"
#include "Keys.h"

using namespace std;

Scene::Scene(string _name) {
  name = _name;
}

string Scene::getName() {
  return name;
}

const char * Scene::getNameChars() {
  return name.c_str();
}

void Scene::update(Keys keys) {
  cout << ">>> Scene " << name << " update" << endl;
}

void Scene::draw() {
  cout << ">>> Scene " << name << " draw" << endl;
}
