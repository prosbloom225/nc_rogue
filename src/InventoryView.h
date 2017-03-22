#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include "IInventory.h"
#include "Screen.h"
#include <ncurses.h>

class InventoryView {
    private:
        static WINDOW *generate_window();
        static void activate_menu(IInventory *inventory);

    public:

        static void activate_inventory(bool isPlayer, IInventory *inventory);
};


#endif
