#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <iostream>
#include <allegro5/allegro5.h>
#include "Scene.h"
#include "Keys.h"
#include "Mouse.h"
#include "MainMenu.h"
#include "GameScene.h"

using namespace std;

class SceneManager: public Scene {
  public:
    SceneManager();
    SceneManager(int screen_width, int screen_height);

    void update(ALLEGRO_EVENT event);
    void update(Keys keys, Mouse mouse) override;
    void draw() override;
    void destroy() override;

    bool redraw;

  private:
    void checkScenes();
    void switchScene(Scene* nextScene);

    Keys keys;
    Mouse mouse;
    Scene* scene;

    MainMenu mainMenu;
    GameScene gameScene;
};

#endif
