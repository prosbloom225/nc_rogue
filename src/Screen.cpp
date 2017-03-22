#include "Screen.h"

int Screen::height = 0;
int Screen::width = 0;
int Screen::curr_panel = 0;
PANEL *Screen::panels[2];

void Screen::init() {
    // Init ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    // Get dims
    getmaxyx(stdscr, Screen::height, Screen::width);
    Screen::curr_panel = 0;
    
}


PANEL *Screen::set_panel_window(int p, WINDOW *win) {
    Screen::panels[p] = new_panel(win);
    return panels[p];
}

// Dealloc
void Screen::deinit() {
    endwin();
}

void Screen::add(const char *message) {
    printw(message);
}

void Screen::activate_panel(int p) {
    log_info("hiding panel: %d", curr_panel);
    log_info("activating panel: %d", p);
    hide_panel(panels[curr_panel]);
    show_panel(panels[p]);
    top_panel(panels[p]);
    curr_panel = p;
    srefresh();
}

void Screen::srefresh() {
    update_panels();
    doupdate();
}


// Getters
int Screen::getHeight() {
    return height;
}
int Screen::getWidth() {
    return width;
}
