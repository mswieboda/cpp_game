#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

void check_init(bool test, const char *description) {
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main(int argc, char **argv) {
  check_init(al_init(), "allegro");
  check_init(al_install_keyboard(), "keyboard");
  check_init(al_init_font_addon(), "font addon");
  check_init(al_init_ttf_addon(), "ttf addon");
  check_init(al_init_image_addon(), "image addon");
  check_init(al_init_primitives_addon(), "primitives addon");

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  check_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  check_init(queue, "queue");

  // DISPLAY options for anti-aliasing
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

  ALLEGRO_DISPLAY* display = al_create_display(1024, 780);
  check_init(display, "display");

  ALLEGRO_FONT* font = al_load_font("./assets/fonts/PressStart2P.ttf", 64, 0);
  check_init(font, "font");

  ALLEGRO_BITMAP* image = al_load_bitmap("./assets/images/mysha.png");
  check_init(image, "image");

  ALLEGRO_VERTEX gradient_vertices[] = {
    { .x = 100, .y = 320, .z = 0, .color = al_map_rgb_f(1, 0, 0) },
    { .x = 500, .y = 320, .z = 0, .color = al_map_rgb_f(0, 1, 0) },
    { .x = 100, .y = 640, .z = 0, .color = al_map_rgb_f(0, 0, 1) },
    { .x = 500, .y = 640, .z = 0, .color = al_map_rgb_f(1, 1, 0) },
  };

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(timer);

  while (true) {
    al_wait_for_event(queue, &event);

    switch(event.type) {
      case ALLEGRO_EVENT_TIMER:
        // game logic goes here.
        redraw = true;
        break;
      case ALLEGRO_EVENT_KEY_DOWN:
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        done = true;
        break;
    }

    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue)) {
      // clear background
      al_clear_to_color(al_map_rgb(0, 0, 0));

      // image
      al_draw_bitmap(image, 100, 100, 0);

      // primitives
      al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
      al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
      al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
      al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
      al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);

      // gradient
      al_draw_prim(gradient_vertices, NULL, NULL, 0, 4, ALLEGRO_PRIM_TRIANGLE_STRIP);

      // text
      al_draw_text(font, al_map_rgb_f(0, 1, 0), 1024 / 2, 780 / 2, ALLEGRO_ALIGN_CENTRE, "hello world!");

      // commit drawing
      al_flip_display();

      redraw = false;
    }
  }

  al_destroy_bitmap(image);
  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
