#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

int main(int argc, char **argv) {
  al_init();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();
  al_install_keyboard();

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  ALLEGRO_DISPLAY* display = al_create_display(1024, 780);
  ALLEGRO_FONT* font = al_load_font("./assets/fonts/PressStart2P.ttf", 64, 0);
  ALLEGRO_BITMAP* image = al_load_bitmap("./assets/images/mysha.png");
  if (!image) {
    printf("couldn't load image\n");
    return 1;
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
      al_clear_to_color(al_map_rgb(0, 0, 0));
      al_draw_text(font, al_map_rgb(0, 255, 0), 1024 / 2, 780 / 2, ALLEGRO_ALIGN_CENTRE, "hello world!");
      al_draw_bitmap(image, 100, 100, 0);
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
