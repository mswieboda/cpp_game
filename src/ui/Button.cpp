#include "Button.h"

Button::Button(): Box() {
  x = 0;
  y = 0;
  width = 0;
  height = 0;
  text = "";
  font = al_create_builtin_font();
}

Button::Button(ALLEGRO_FONT* font, string text): Button() {
  this->font = font;
  this->text = text;
}

Button::Button(ALLEGRO_FONT* font, string text, int width, int height): Button(font, text) {
  this->width = width;
  this->height = height;
}

Button::Button(ALLEGRO_FONT* font, string text, int x, int y, int width, int height): Button(font, text, width, height) {
  this->x = x;
  this->y = y;
}

void Button::update() {

}

void Button::draw() {
  al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb_f(0, 1, 0));

  // TODO: needs to take font height into consideration to be vertically centered
  al_draw_text(font, al_map_rgb(0, 0, 0), x + width / 2, y + height / 2, ALLEGRO_ALIGN_CENTRE, text.c_str());
}

void Button::destroy() {

}
