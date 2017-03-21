#include "Screen.h"

Screen::Screen() {
    // Init ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    // Get dims
    getmaxyx(stdscr, _height, _width);
    
    curr_panel = 0;
}


PANEL *Screen::set_panel_window(int p, WINDOW *win) {
    _panels[p] = new_panel(win);
    return _panels[p];
}

// Dealloc
Screen::~Screen() {
    endwin();
}

void Screen::add(const char *message) {
    printw(message);
}

void Screen::activate_panel(int p) {
    log_info("activating panel: %d", p);
    log_info("hiding panel: %d", curr_panel);
    /* hide_panel(_panels[curr_panel]); */
    /* show_panel(_panels[p]); */
    /* top_panel(_panels[p]); */
    curr_panel = p;
    srefresh();
}

void Screen::srefresh() {
    update_panels();
    doupdate();
}


// Getters
int Screen::height() {
    return _height;
}
int Screen::width() {
    return _width;
}
