#ifndef _BOX_H
#define _BOX_H

class Box {
  public:
    Box();
    Box(int width, int height);
    Box(int x, int y, int width, int height);

    int x;
    int y;
    int width;
    int height;
};

#endif
