#include "InventoryView.h"

void InventoryView::activate_inventory(bool isPlayer, IInventory *inventory){
    debug("Activating inventory");
    WINDOW *win = generate_window();
    Screen::set_panel_window(PANEL_MENU, win);
    Screen::activate_panel(PANEL_MENU);
    // show the menu
    activate_menu(inventory);
    // reactivate the main panel
    Screen::activate_panel(PANEL_MAIN);
}

WINDOW *InventoryView::generate_window(){ 
    int height = Screen::getHeight();
    int width = Screen::getWidth();
    WINDOW *win = newwin(height/2, width/2, 1, 1);
    box(win, '*', '*');
    return win;
}
void InventoryView::activate_menu(IInventory *inventory) {
    getch();
}
