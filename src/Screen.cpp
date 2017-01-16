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
}

// Dealloc
Screen::~Screen() {
    endwin();
}

void Screen::add(const char *message) {
    printw(message);
}


// Getters
int Screen::height() {
    return _height;
}
int Screen::width() {
    return _width;
}
