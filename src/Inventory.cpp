#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *inv_items[] = {
    "item1",
    "item2"
};

// Constructor
Inventory::Inventory() {
    _w = newwin(50, 50, 7, 7);
}
Inventory::Inventory(int nr_rows, int nr_cols, int row_0, int col_0){
    _nr_rows = nr_rows;
    _nr_cols = nr_cols;
    _row_0 = row_0;
    _col_0 = col_0;
    _w = newwin(nr_rows, nr_cols, row_0, col_0);
}

// Dealloc
Inventory::~Inventory(){
    delwin(_w);
}


// Menu
void Inventory::activate_menu() {
    log_info("Opening inventory");

    mvwprintw(_w, 1, 2, "TEST");
    box(_w, '*', '*');
    // Menu
    //
    //
    log_info("Inventory has: %lu items", ARRAY_SIZE(inv_items));
    // display the items
    for (int i= 0 ; i <= sizeof(inv_items); i++) {
        int curr_row = i + get_row_0;
        mvwprintw(_w, curr_row, 2, inv_items[i]);
    }

    update_panels();
    doupdate();
    getch();
}



// Getters
WINDOW* Inventory::win() {
    return _w;
}
