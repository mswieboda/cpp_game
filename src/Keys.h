#ifndef _KEYS_H
#define _KEYS_H

#include <allegro5/allegro5.h>

class Keys {
  public:
    Keys();

    void reset();
    void pressed(int keycode);
    void released(int keycode);
    bool isPressed(int keycode);
    // bool isReleased(int keycode);

    unsigned char keys[ALLEGRO_KEY_MAX];
};

#endif
