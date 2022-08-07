#include "Sprite.h"

Sprite::Sprite(int _fpsFactor, bool _centered) {
  height = 0;
  width = 0;
  frame = 0;
  fpsFactor = _fpsFactor;
  centered = _centered;
}

void Sprite::add(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h) {
  ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(sheet, x, y, w, h);

  if (!sprite)
    printf(">>> Sprite#add !sprite\n");

  sprites.push_back(sprite);

  if (h > height)
    height = h;
  if (w > width)
    width = w;
}

void Sprite::addBlank(int w, int h) {
  ALLEGRO_BITMAP* sprite = al_create_bitmap(w, h);
  al_set_target_bitmap(sprite);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_set_target_backbuffer(al_get_current_display());

  if (!sprite)
    printf(">>> Sprite#addBlank !sprite\n");

  sprites.push_back(sprite);
}

int Sprite::displayFrame() {
  return frame / fpsFactor;
}

void Sprite::update() {
  frame++;

  if (frame >= sprites.size() * fpsFactor)
    frame = 0;
}

void Sprite::draw(int x, int y) {
  ALLEGRO_BITMAP* sprite = sprites[displayFrame()];
  int drawX = x;
  int drawY = y;

  if (centered) {
    drawX -= (al_get_bitmap_width(sprite) / 2);
    drawY -= (al_get_bitmap_height(sprite) / 2);
  }

  al_draw_bitmap(sprite, drawX, drawY, 0);
}

void Sprite::destroy() {
  for (auto sprite: sprites)
    al_destroy_bitmap(sprite);
}
