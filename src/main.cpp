#include "dbg.h"
#include <ncurses.h>
#include <panel.h>
#include "Constants.h"

#include "Screen.h"
#include "Character.h"
#include "Inventory.h"

#include "Game.h"


void game_loop(
        Game &game,
        int ch) {

    if (ch == 'q' || ch == 'Q')
        return;

    // helpers
    Screen &scr = *game.scr();
    Frame &game_map = *game.game_map();
    Frame &viewport = *game.viewport();
    Character &main_char = *game.main_char();

    /* game_map.add(main_char); */
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
            scr.set_panel_window(PANEL_MENU, main_char.inv()->win());
            scr.activate_panel(PANEL_MENU);
            /* main_char.inv()->activate_menu(); */
            getch();

            scr.activate_panel(PANEL_MAIN);


        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}

int main (int argc, char* argv[]) {
    // Init
    Game *game = new Game();

    // helper
    Frame game_map = *game->game_map();
    Frame viewport = *game->viewport();

    game->scr()->add("Welcome to nc_rogue.\nPress any key to start.\n");
    // Wait for user input to start
    int ch = getch();

    game->scr()->set_panel_window(PANEL_MAIN, viewport.win());
    

    // Init main char and dump in the middle
    Character main_char('@', game_map.height()/2, game_map.width()/2);

    // Fill screen test
    /* game_map.fill_window(); */
    game_map.gen_perlin(237);

    // Dev header
    game->scr()->add("DEVELOPMENT BUILD");

    // Main loop
    game_loop(*game, ch);

    // Clean up 
    game->~Game();
    return 0;
}
