#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <iostream>
#include <allegro5/allegro5.h>
#include "Scene.h"
#include "Keys.h"
#include "MainMenu.h"
#include "GameScene.h"

using namespace std;

class SceneManager: public Scene {
  public:
    SceneManager();

    void update(ALLEGRO_EVENT event);
    void update(Keys keys) override;
    void draw() override;
    void destroy() override;

    bool redraw;

  private:
    void checkScenes();
    void switchScene(Scene* nextScene);

    Keys keys;
    Scene* scene;

    MainMenu mainMenu;
    GameScene gameScene;
};

#endif
