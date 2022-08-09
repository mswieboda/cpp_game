#include "SceneManager.h"

SceneManager::SceneManager(): Scene(), keys(), mainMenu(), gameScene() {
  redraw = false;
  scene = &mainMenu;
}

void SceneManager::update(ALLEGRO_EVENT event) {
  switch(event.type) {
    case ALLEGRO_EVENT_TIMER:
      checkScenes();
      update(keys);
      keys.reset();

      redraw = true;
      break;

    case ALLEGRO_EVENT_MOUSE_AXES:
      // TODO: make a mouse input holder, similar to Keys
      //       then put both Keys and Mouse inside Input ?
      // box.x = event.mouse.x;
      // box.y = event.mouse.y;
      break;

    case ALLEGRO_EVENT_KEY_DOWN:
      keys.pressed(event.keyboard.keycode);
      break;

    case ALLEGRO_EVENT_KEY_UP:
      keys.released(event.keyboard.keycode);
      break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      isExit = true;
      break;
  }
}

void SceneManager::checkScenes() {
  if (scene == &mainMenu) {
    if (mainMenu.isStart)
      switchScene(&gameScene);

    if (mainMenu.isExit)
      isExit = true;
  }

  if (scene == &gameScene)
    if (gameScene.isExit)
      switchScene(&mainMenu);
}

void SceneManager::switchScene(Scene* nextScene) {
  scene->reset();

  scene = nextScene;

  scene->init();
}

void SceneManager::update(Keys keys) {
  scene->update(keys);
}

void SceneManager::draw() {
  scene->draw();
}

void SceneManager::destroy() {
  mainMenu.destroy();
  gameScene.destroy();
}
