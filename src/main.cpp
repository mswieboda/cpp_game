#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "SceneManager.h"

using namespace std;

#define WIDTH 1024
#define HEIGHT 780

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

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
  check_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  check_init(queue, "queue");

  // DISPLAY options for anti-aliasing
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

  ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
  check_init(display, "display");

  // set to fullscreen windowed
  al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);

  // al_hide_mouse_cursor(display);

  // add events to the event queue
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  ALLEGRO_EVENT event;

  int screen_width = al_get_display_width(display);
  int screen_height = al_get_display_height(display);

  SceneManager sceneManager(screen_width, screen_height);

  al_start_timer(timer);

  while (true) {
    al_wait_for_event(queue, &event);

    sceneManager.update(event);

    if (sceneManager.isExit)
      break;

    if (sceneManager.redraw && al_is_event_queue_empty(queue)) {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      sceneManager.draw();

      // commit drawing
      al_flip_display();

      sceneManager.redraw = false;
    }
  }

  sceneManager.destroy();

  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
