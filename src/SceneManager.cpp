#include "SceneManager.h"

SceneManager::SceneManager(): Scene(), keys(), mouse(), mainMenu(), gameScene() {
  redraw = false;
  scene = &mainMenu;
}

SceneManager::SceneManager(int screen_width, int screen_height): Scene(), keys(), mouse(), mainMenu(screen_width, screen_height), gameScene() {
  redraw = false;
  scene = &mainMenu;
}

void SceneManager::update(ALLEGRO_EVENT event) {
  switch(event.type) {
    case ALLEGRO_EVENT_TIMER:
      checkScenes();
      update(keys, mouse);
      keys.reset();

      redraw = true;
      break;

    case ALLEGRO_EVENT_MOUSE_AXES:
      // cout << "> Mouse: (" << event.mouse.x << ", " << event.mouse.y << ")" << endl;
      // TODO: make a mouse input holder, similar to Keys
      //       then put both Keys and Mouse inside Input ?
      mouse.x = event.mouse.x;
      mouse.y = event.mouse.y;
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

void SceneManager::update(Keys keys, Mouse mouse) {
  scene->update(keys, mouse);
}

void SceneManager::draw() {
  scene->draw();
}

void SceneManager::destroy() {
  mainMenu.destroy();
  gameScene.destroy();
}
