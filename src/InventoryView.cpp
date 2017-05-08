#include "InventoryView.h"

void InventoryView::activate_inventory(bool isPlayer, IInventory *inventory){
    debug("Activating inventory");
    WINDOW *win = generate_window();
    Screen::set_panel_window(PANEL_MENU, win);
    Screen::activate_panel(PANEL_MENU);
    // show the menu
    activate_menu(win, inventory);
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
void InventoryView::activate_menu(WINDOW *win, IInventory *inv) {
    /* wattron(win, A_STANDOUT); */
    /* wattroff(win, A_STANDOUT); */
    /* mvwprintw(win, 1, 1, "TEST"); */
    log_info("Size of inventory: %lu", inv->get_items()->size());
    for (int i=0; i < inv->get_size(); i++) {
        if (i ==0) {
            wattron(win, A_STANDOUT);
        } else {
            wattroff(win, A_STANDOUT);
        }
        mvwprintw(win, i+1, 1, inv 
                ->get_item_at_pos(i)
                ->get_name()
                ->c_str());
    }

    // main menu loop
    Screen::srefresh();
    int ch = 0, i=0;
    while ((ch = getch()) != 'q') {
        // clear current row formatting
        wattroff(win, A_STANDOUT);
        mvwprintw(win, i+1, 1, inv
                ->get_item_at_pos(i)
                ->get_name()
                ->c_str());
        switch (ch) {
            // Up
            case 'k':
                log_info("Up hit");
                i--;
                i = (i<0) ? inv->get_size()-1 : i;
                break;
                // Down
            case 'j':
                log_info("Down hit");
                wattron(win, A_STANDOUT);
                i++;
                i = (i>inv->get_size()-1) ? 0 : i;
                break;
        }
        wattron(win, A_STANDOUT);
        mvwprintw(win, i+1, 1, inv
                ->get_item_at_pos(i)
                ->get_name()
                ->c_str());
        Screen::srefresh();
    }
}
