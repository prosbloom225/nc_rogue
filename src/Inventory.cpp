#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

char *inv_items[] = {
                        "item 1",
                        "item 2",
                        "item 3",
                        "item 4",
                        "Exit",
                        (char *)NULL,
                  };

// Constructor
Inventory::Inventory() {
    _w = newwin(50, 50, 10, 10);
    box(_w, '*', '*');
}

Inventory::Inventory(int nr_rows, int nr_cols, int row_0, int col_0){
    _w = newwin(nr_rows, nr_cols, row_0, col_0);
    box(_w, '*', '*');
}

// Dealloc
Inventory::~Inventory(){
    delwin(_w);
}


// Menu
void Inventory::activate_menu() {
    ITEM **my_items;
    int c;				
    MENU *my_menu;
    int n_inv_items, i;

    n_inv_items = ARRAY_SIZE(inv_items);
    my_items = (ITEM **)calloc(n_inv_items + 1, sizeof(ITEM *));

    for(i = 0; i < n_inv_items; ++i)
        my_items[i] = new_item(inv_items[i], inv_items[i]);

    // Generate menu
    my_menu = new_menu((ITEM **)my_items);
    set_menu_win(my_menu, _w);
    set_menu_sub(my_menu, derwin(_w, 6, 38, 3, 1));   my_items[n_inv_items] = (ITEM *)NULL;

    mvprintw(LINES - 2, 0, "q to exit");
    post_menu(my_menu);
    refresh();

    while((c = getch()) != 'q')
    {   switch(c)
        {	case 'j':
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
            case 'k':
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        }
    }	
    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    /* free(_w); */
}



// Getters
WINDOW* Inventory::win() {
    return _w;
}
