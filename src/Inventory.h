#ifndef INVENTORY_H
#define INVENTORY_H

#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

class Inventory {
    WINDOW *_w;

    public:
    Inventory();
    Inventory(int nr_rows, int nr_cols, int row_0, int col_0);

    void activate_menu();

    ~Inventory();
    WINDOW *win();
};


#endif

