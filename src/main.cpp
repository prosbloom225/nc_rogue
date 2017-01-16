#include <ncurses.h>
#include <panel.h>
#include "Constants.h"

#include "Screen.h"
#include "Character.h"
#include "Inventory.h"

#include "Game.h"


void game_loop(
        Game *game,
        Character &main_char,
        int ch) {

    if (ch == 'q' || ch == 'Q')
        return;

    // helpers
    Frame game_map = *game->game_map();
    Frame viewport = *game->viewport();

    game_map.add(main_char);
    viewport.center(main_char);
    viewport.refresh();

    // Main loop
    while (1) {
        ch = getch();

        // Movement
        if (ch == 'h') {
            game_map.add(main_char, main_char.row(), main_char.col() - 1);
            viewport.center(main_char);
            viewport.refresh();
        } else if (ch == 'l') {
            game_map.add(main_char, main_char.row(), main_char.col() + 1);
            viewport.center(main_char);
            viewport.refresh();
        } else if (ch == 'j') {
            game_map.add(main_char, main_char.row() + 1, main_char.col());
            viewport.center(main_char);
            viewport.refresh();
        }else if (ch == 'k') {
            game_map.add(main_char, main_char.row() - 1, main_char.col());
            viewport.center(main_char);
            viewport.refresh();
            // Inventory
        }else if (ch == 'i') {
            /*
            hide_panel(main_panel);
            top_panel(menu_panel);
            update_panels();
            doupdate();
            // show the menu
            char_inv->activate_menu();

            hide_panel(menu_panel);
            top_panel(main_panel);
            update_panels();
            doupdate();
            */

        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}

int main (int argc, char* argv[]) {
    // Init
    Game *game = new Game();

    // helper
    Screen scr = *game->scr();
    Frame game_map = *game->game_map();
    Frame viewport = *game->viewport();

    scr.add("Welcome to nc_rogue.\nPress any key to start.\n");
    // Wait for user input to start
    int ch = getch();

    /*

    // Game map
    // Main viewport
    Frame game_map2(2 * scr->height(), 2 * scr->width(), 0, 0);
    Frame viewport2(*game_map, scr->height(), scr->width(), 0, 0);

    // testing panels
    // Inventory
    Inventory inv(scr.height()/3, scr.width()/3, 0, 0);
    
    PANEL *main_panel = new_panel(viewport.win());
    PANEL *menu_panel  = new_panel(inv.win());

    set_panel_userptr(main_panel, menu_panel);
    game_map.fill_window();
    top_panel(menu_panel);

    */


    // Init main char and dump in the middle
    Character main_char('@', game_map.height()/2, game_map.width()/2);

    // Fill screen test
    game_map.fill_window();
    /* game_map->gen_perlin(237); */

    // Dev header
    scr.add("DEVELOPMENT BUILD");
    viewport.refresh();

    // Main loop
    game_loop(game, main_char, ch);

    // Clean up 
    return 0;
}
