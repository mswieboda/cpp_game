#include <iostream>

#include "Scene.h"

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

void Scene::update(unsigned char * key) {
  cout << ">>> " << name << " update" << endl;
}

void Scene::draw() {
  cout << ">>> " << name << " draw" << endl;
}
