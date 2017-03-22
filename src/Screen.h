#ifndef SCREEN_H
#define SCREEN_H
#include "dbg.h"

#include <ncurses.h>
#include <panel.h>
#include "Frame.h"
#include "Constants.h"


class Screen {
    static int height, width;

    static PANEL *panels[2];
    static int curr_panel;


    public:
    static void init();
    static void deinit();


    static void add(const char *message);
    static void activate_panel(int p);
    static void srefresh();

    // setters
    static PANEL *set_panel_window(int p, WINDOW *win);


    // getters
    static int getWidth();
    static int getHeight();


};

#endif
