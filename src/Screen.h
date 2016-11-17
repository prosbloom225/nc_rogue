#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>


class Screen {
    int _height, _width;
    public:
    Screen();
    ~Screen();

    void add(const char *message);

    int width();
    int height();
};

#endif
