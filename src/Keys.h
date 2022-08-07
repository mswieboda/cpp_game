#ifndef _KEYS_H
#define _KEYS_H

#include <cstdarg>
#include <iostream>
#include <allegro5/allegro5.h>

class Keys {
  public:
    Keys();

    void reset();
    void pressed(int keycode);
    void released(int keycode);
    bool isPressed(int keycode);
    bool anyPressed(const int count, ...);
    bool anyPressed();
    bool isJustPressed(int keycode);
    bool anyJustPressed(const int count, ...);
    bool anyJustPressed();
    // bool isReleased(int keycode);

    unsigned char keys[ALLEGRO_KEY_MAX];
};

#endif
