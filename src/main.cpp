#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Keys.h"
#include "MainMenu.h"
#include "GameScene.h"

using namespace std;

#define FPS 60

void check_init(bool test, const char *description) {
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main(int argc, char **argv) {
  check_init(al_init(), "allegro");
  check_init(al_install_keyboard(), "keyboard");
  check_init(al_install_mouse(), "mouse");
  check_init(al_init_font_addon(), "font addon");
  check_init(al_init_ttf_addon(), "ttf addon");
  check_init(al_init_image_addon(), "image addon");
  check_init(al_init_primitives_addon(), "primitives addon");

  int width = 2048;
  int height = 1440;

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
  check_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  check_init(queue, "queue");

  // DISPLAY options for anti-aliasing
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

  ALLEGRO_DISPLAY* display = al_create_display(width, height);
  check_init(display, "display");

  // al_hide_mouse_cursor(display);

  // add events to the event queue
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  MainMenu mainMenu("Main Menu");
  GameScene gameScene("Game");
  Scene *scene = &mainMenu;
  Keys keys;

  al_start_timer(timer);

  while (true) {
    al_wait_for_event(queue, &event);

    switch(event.type) {
      case ALLEGRO_EVENT_TIMER:
        // TODO: vvv put in scene manager
        if (scene == &mainMenu) {
          if (mainMenu.isStart) {
            scene = &gameScene;

            mainMenu.reset();
            gameScene.init();
          }

          if (mainMenu.isExit) {
            done = true;

            mainMenu.reset();
          }
        }

        if (scene == &gameScene) {
          if (gameScene.isExit) {
            scene = &mainMenu;

            gameScene.reset();
          }
        }
        // TODO: ^^^ put in scene manager

        // START GAME LOGIC
        scene->update(keys);

        // END GAME LOGIC
        keys.reset();

        redraw = true;
        break;

      case ALLEGRO_EVENT_MOUSE_AXES:
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
        done = true;
        break;
    }

    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue)) {
      // clear background
      al_clear_to_color(al_map_rgb(0, 0, 0));

      scene->draw();

      // commit drawing
      al_flip_display();

      redraw = false;
    }
  }

  mainMenu.destroy();
  gameScene.destroy();

  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
