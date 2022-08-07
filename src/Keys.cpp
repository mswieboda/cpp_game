#include <cstdarg>
#include <iostream>
#include <allegro5/allegro5.h>
#include "Keys.h"

using namespace std;

#define KEY_SEEN     1
#define KEY_RELEASED 2

Keys::Keys() {
  memset(keys, 0, sizeof(keys));
}

void Keys::reset() {
  for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
    keys[i] &= KEY_SEEN;
}

void Keys::pressed(int keycode) {
  keys[keycode] = KEY_SEEN | KEY_RELEASED;
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
      cout << endl;
      return true;
    }
  }

  va_end(args);

  cout << endl;
  return false;
}

// bool Keys::isReleased(int keycode) {
//   return keys[ALLEGRO_KEY_ESCAPE];
// }
