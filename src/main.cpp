#include "dbg.h"
#include <ncurses.h>
#include <panel.h>
#include "Constants.h"

#include "Screen.h"
#include "Character.h"
#include "Inventory.h"

#include "Game.h"



int main (int argc, char* argv[]) {
    // Init
    log_info("Begin!");
    Game *game = new Game();

    // helper
    Frame game_map = *game->game_map();

    game->scr()->add("Welcome to nc_rogue.\nPress any key to start.\n");
    // Wait for user input to start
    int ch = getch();

    /* game->scr()->set_panel_window(PANEL_MAIN, viewport.win()); */
    
    // Fill screen test
    game_map.fill_window();
    /* game_map.gen_perlin(237); */

    // Dev header
    game->scr()->add("DEVELOPMENT BUILD");

    // Main loop
    game->game_loop(*game, ch);

    // Clean up 
    game->~Game();
    return 0;
}
