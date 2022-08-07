#include "Keys.h"

#define KEY_SEEN     1
#define KEY_RELEASED 2
#define KEY_PRESSED  3

Keys::Keys() {
  memset(keys, 0, sizeof(keys));
}

void Keys::reset() {
  for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
    keys[i] &= KEY_SEEN;
}

void Keys::pressed(int keycode) {
  keys[keycode] = KEY_PRESSED;
}

void Keys::released(int keycode) {
  keys[keycode] &= KEY_RELEASED;
}

bool Keys::isPressed(int keycode) {
  return keys[keycode];
}

bool Keys::anyPressed(const int count, ...) {
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; i++) {
    int keycode = va_arg(args, int);

    if (isPressed(keycode)) {
      return true;
    }
  }

  va_end(args);

  return false;
}

bool Keys::anyPressed() {
  for (int i = 0; i < ALLEGRO_KEY_MAX; i++) {
    if (isPressed(i))
      return true;
  }

  return false;
}

bool Keys::isJustPressed(int keycode) {
  return keys[keycode] == KEY_PRESSED;
}

bool Keys::anyJustPressed(const int count, ...) {
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; i++) {
    int keycode = va_arg(args, int);

    if (isJustPressed(keycode)) {
      return true;
    }
  }

  va_end(args);

  return false;
}

bool Keys::anyJustPressed() {
  for (int i = 0; i < ALLEGRO_KEY_MAX; i++) {
    if (isJustPressed(i))
      return true;
  }

  return false;
}
