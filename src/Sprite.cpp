#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Sprite.h"

using namespace std;

Sprite::Sprite(int _fpsFactor, bool _centered) {
  x = 0;
  y = 0;
  height = 0;
  width = 0;
  frame = 0;
  fpsFactor = _fpsFactor;
  centered = _centered;
}

void Sprite::add(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h) {
  sprite = al_create_sub_bitmap(sheet, x, y, w, h);

  if (!sprite)
    printf(">>> !sprite\n");

  // sprites.push_back(sprite);

  if (h > height)
    height = h;
  if (w > width)
    width = w;
}

int Sprite::displayFrame() {
  return frame / fpsFactor;
}

void Sprite::update() {
  frame++;
}

void Sprite::draw() {
  cout << ">>> Sprite draw frame: " << frame << endl;
  // int frame = displayFrame();
  // ALLEGRO_BITMAP* sprite = sprites[frame];
  int drawX = x;
  int drawY = y;

  if (centered) {
    drawX -= (al_get_bitmap_width(sprite) / 2);
    drawY -= (al_get_bitmap_height(sprite) / 2);
  }

  al_draw_bitmap(sprite, drawX, drawY, 0);

  cout << ">>> Sprite drew x: " << x << "y: " << y << " drawX: " << drawX << " drawY: " << drawY << endl;
}

void Sprite::destroy() {
  al_destroy_bitmap(sprite);
  // for (int i = 0; i < sprites.size(); ++i)
  //   al_destroy_bitmap(sprites[i])
}
