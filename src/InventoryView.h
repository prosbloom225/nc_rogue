#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include "IInventory.h"
#include <ncurses.h>

class InventoryView {
    public:
        static void activate_inventory(IInventory *inventory);
    private:
        static WINDOW *generate_window();
        static void activate_menu(IInventory *inventory);
};


#endif
