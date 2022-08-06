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

enum BOUNCER_TYPE {
  BT_HELLO = 0,
  BT_IMAGE,
  BT_TRIANGLE,
  BT_RECTANGLE_1,
  BT_RECTANGLE_2,
  BT_CIRCLE,
  BT_LINE_1,
  BT_LINE_2,
  BT_N
};

typedef struct BOUNCER {
  float x, y;
  float dx, dy;
  int type;
} BOUNCER;

int main(int argc, char **argv) {
  check_init(al_init(), "allegro");
  check_init(al_install_keyboard(), "keyboard");
  check_init(al_init_font_addon(), "font addon");
  check_init(al_init_ttf_addon(), "ttf addon");
  check_init(al_init_image_addon(), "image addon");
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

  ALLEGRO_BITMAP* image = al_load_bitmap("./assets/images/mysha.png");
  check_init(image, "image");

  ALLEGRO_VERTEX gradient_vertices[] = {
    { .x = 100, .y = 320, .z = 0, .color = al_map_rgb_f(1, 0, 0) },
    { .x = 500, .y = 320, .z = 0, .color = al_map_rgb_f(0, 1, 0) },
    { .x = 100, .y = 640, .z = 0, .color = al_map_rgb_f(0, 0, 1) },
    { .x = 500, .y = 640, .z = 0, .color = al_map_rgb_f(1, 1, 0) },
  };

  BOUNCER obj[BT_N];
  for(int i = 0; i < BT_N; i++) {
    BOUNCER* b = &obj[i];
    b->x = rand() % width;
    b->y = rand() % height;
    b->dx = ((((float)rand()) / RAND_MAX) - 0.5) * 2 * 10;
    b->dy = ((((float)rand()) / RAND_MAX) - 0.5) * 2 * 10;
    b->type = i;
  }

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
        // START GAME LOGIC
        for (int i = 0; i < BT_N; i++) {
          BOUNCER* b = &obj[i];
          b->x += b->dx;
          b->y += b->dy;

          if (b->x < 0) {
            b->x  *= -1;
            b->dx *= -1;
          } else if (b->x > width) {
            b->x -= (b->x - width);
            b->dx *= -1;
          }

          if (b->y < 0) {
            b->y  *= -1;
            b->dy *= -1;
          } else if (b->y > height) {
            b->x -= (b->y - height);
            b->dy *= -1;
          }
        }
        // END GAME LOGIC

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

      // bouncing stuff
      ALLEGRO_VERTEX v[4];

      for(int i = 0; i < BT_N; i++) {
        BOUNCER* b = &obj[i];

        switch(b->type) {
          case BT_HELLO:
            al_draw_text(font, al_map_rgb_f(0, 1, 0), b->x, b->y, ALLEGRO_ALIGN_CENTRE, "hello world!");
            break;

          case BT_IMAGE:
            al_draw_bitmap(image, b->x, b->y, 0);
            break;

          case BT_TRIANGLE:
            al_draw_filled_triangle(b->x, b->y, b->x + 50, b->y + 25, b->x, b->y + 50, al_map_rgb_f(0, 1, 0));
            break;

          case BT_RECTANGLE_1:
            al_draw_filled_rectangle(b->x, b->y, b->x + 100, b->y + 80, al_map_rgba_f(0, 0, 0.5, 0.5));
            break;

          case BT_RECTANGLE_2:
            v[0].x = b->x;       v[0].y = b->y;       v[0].z = 0; v[0].color = al_map_rgb_f(1, 0, 0);
            v[1].x = b->x + 120; v[1].y = b->y;       v[1].z = 0; v[1].color = al_map_rgb_f(0, 1, 0);
            v[2].x = b->x;       v[2].y = b->y + 100; v[2].z = 0; v[2].color = al_map_rgb_f(0, 0, 1);
            v[3].x = b->x + 120; v[3].y = b->y + 100; v[3].z = 0; v[3].color = al_map_rgb_f(1, 1, 0);

            al_draw_prim(v, NULL, NULL, 0, 4, ALLEGRO_PRIM_TRIANGLE_STRIP);
            break;

          case BT_CIRCLE:
            al_draw_circle(b->x, b->y, 30, al_map_rgb_f(1, 0, 1), 2);
            break;

          case BT_LINE_1:
            al_draw_line(b->x, b->y, b->x + 20, b->y + 100, al_map_rgb_f(1, 0, 0), 1);
            break;

          case BT_LINE_2:
            al_draw_line(b->x, b->y, b->x + 70, b->y - 20, al_map_rgb_f(1, 1, 0), 1);
            break;
        }
      }

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
