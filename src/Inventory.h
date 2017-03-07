#ifndef INVENTORY_H
#define INVENTORY_H

#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include <stdlib.h>
#include "dbg.h"

class Inventory {
    WINDOW *_w;
    int _nr_rows, _nr_cols, _row_0, _col_0;

    public:
    Inventory();
    Inventory(int nr_rows, int nr_cols, int row_0, int col_0);

    void activate_menu();

    ~Inventory();
    WINDOW *win();

    int get_nr_rows();
    int get_nr_cols();
    int get_row_0;
    int get_col_0;

};


#endif

