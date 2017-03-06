#ifndef SCREEN_H
#define SCREEN_H
#include "dbg.h"

#include <ncurses.h>
#include <panel.h>
#include "Frame.h"
#include "Constants.h"


class Screen {
    int _height, _width;

    PANEL *_panels[2];
    int curr_panel;


    public:
    Screen();
    ~Screen();


    void add(const char *message);
    void activate_panel(int p);

    // setters
    PANEL *set_panel_window(int p, WINDOW *win);


    // getters
    int width();
    int height();


};

#endif
