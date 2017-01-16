#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <panel.h>
#include "Frame.h"


class Screen {
    int _height, _width;


    public:
    Screen();
    ~Screen();


    void add(const char *message);


    // getters
    int width();
    int height();


};

#endif
