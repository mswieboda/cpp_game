#include "Animation.h"

Animation::Animation() {
  height = 0;
  width = 0;
  frame = 0;
  fpsFactor = 60;
  centered = true;
  loop = true;
}

Animation::Animation(int fpsFactor, bool loop, bool centered): Animation() {
  this->fpsFactor = fpsFactor;
  this->loop = loop;
  this->centered = centered;
}

void Animation::add(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h) {
  ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(sheet, x, y, w, h);

  if (!sprite)
    printf(">>> Animation#add !sprite\n");

  sprites.push_back(sprite);

  if (h > height)
    height = h;
  if (w > width)
    width = w;
}

void Animation::addBlank(int w, int h) {
  ALLEGRO_BITMAP* sprite = al_create_bitmap(w, h);
  al_set_target_bitmap(sprite);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_set_target_backbuffer(al_get_current_display());

  if (!sprite)
    printf(">>> Animation#addBlank !sprite\n");

  sprites.push_back(sprite);
}

int Animation::displayFrame() {
  return frame / fpsFactor;
}

void Animation::update() {
  int maxFrames = sprites.size() * fpsFactor - 1;

  if (frame < maxFrames)
    frame++;

  if (loop && frame >= maxFrames)
    frame = 0;
}

void Animation::draw(int x, int y) {
  ALLEGRO_BITMAP* sprite = sprites[displayFrame()];

  if (!sprite)
    cout << "> Animation::draw sprite IS NULL" << endl;

  int drawX = x;
  int drawY = y;

  if (centered) {
    drawX -= (al_get_bitmap_width(sprite) / 2);
    drawY -= (al_get_bitmap_height(sprite) / 2);
  }

  al_draw_bitmap(sprite, drawX, drawY, 0);
}

void Animation::destroy() {
  for (auto sprite: sprites)
    al_destroy_bitmap(sprite);
}
