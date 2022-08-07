#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "GameScene.h"

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
  check_init(al_init_primitives_addon(), "primitives addon");

  int width = 2048;
  int height = 1440;

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  check_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  check_init(queue, "queue");

  // DISPLAY options for anti-aliasing
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

  ALLEGRO_DISPLAY* display = al_create_display(width, height);
  check_init(display, "display");

  ALLEGRO_FONT* font = al_load_font("./assets/fonts/PressStart2P.ttf", 64, 0);
  check_init(font, "font");

  al_hide_mouse_cursor(display);

  // add events to the event queue
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  GameScene gameScene("Start Menu");

  #define KEY_SEEN     1
  #define KEY_RELEASED 2

  unsigned char key[ALLEGRO_KEY_MAX];
  memset(key, 0, sizeof(key));

  al_start_timer(timer);

  while (true) {
    al_wait_for_event(queue, &event);

    switch(event.type) {
      case ALLEGRO_EVENT_TIMER:
        // START GAME LOGIC
        gameScene.update(key);

        if (key[ALLEGRO_KEY_ESCAPE])
          done = true;

        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
          key[i] &= KEY_SEEN;
        // END GAME LOGIC

        redraw = true;
        break;

      case ALLEGRO_EVENT_MOUSE_AXES:
        // box.x = event.mouse.x;
        // box.y = event.mouse.y;
        break;

      case ALLEGRO_EVENT_KEY_DOWN:
        key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
        break;

      case ALLEGRO_EVENT_KEY_UP:
        key[event.keyboard.keycode] &= KEY_RELEASED;
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

      gameScene.draw();

      // al_draw_text(font, al_map_rgb(0, 255, 0), 1024 / 2, 780 / 2, ALLEGRO_ALIGN_CENTRE, gameScene.getNameChars());

      // commit drawing
      al_flip_display();

      redraw = false;
    }
  }

  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
