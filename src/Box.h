#ifndef _BOXH
#define _BOXH

class Box {
  public:
    Box (int x, int y);
    Box(int x, int y, int width, int height);

    int x;
    int y;
    int width;
    int height;
};

#endif
