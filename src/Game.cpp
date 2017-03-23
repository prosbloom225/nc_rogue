#include "Game.h"


// constructor
Game::Game() {
    pre_init();
    init();
    post_init();

    // Set up game map
    //
    // Game map
    game_map = new Frame(2 * Screen::getHeight(), 2 * Screen::getWidth(), 0, 0);
    // Main viewport
    viewport = new Frame(*game_map, Screen::getHeight(), Screen::getWidth(), 0, 0);
    Screen::set_panel_window(PANEL_MAIN, viewport->win());

    main_char = new Character('@', game_map->height()/2, game_map->width()/2);
    game_map->add(*main_char);
    Screen::activate_panel(0);
}

// dealloc
Game::~Game() {
    endwin();
    Screen::deinit();
    free(game_map);
    free(viewport);
    free(main_char);
}

// init
void Game::pre_init(){
    Screen::init();
}
void Game::init(){}
void Game::post_init(){}

// getters

Frame *Game::get_viewport() {
    return viewport;
}

Frame *Game::get_game_map() {
    return game_map;
}

Character *Game::get_main_char(){
    return main_char;
}



// main loop
void Game::game_loop( Game &game, int ch) {

    if (ch == 'q' || ch == 'Q')
        return;

    // helpers
    Frame &game_map = *game.get_game_map();
    Frame &viewport = *game.get_viewport();
    Character &main_char = *game.get_main_char();

    /* game_map.add(main_char); */
    viewport.center(main_char);
    viewport.refresh();

    // Main loop
    while (1) {
        ch = getch();

        /* log_info("%d", ch); */
        log_info("Key pressed: %d\n", ch);

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
            // create inventory view for the specified character
            InventoryView::activate_inventory(true, main_char.inv());
            /* scr.set_panel_window(PANEL_MENU, main_char.inv()->win()); */
            /* scr.activate_panel(PANEL_MENU); */
            /* main_char.inv()->activate_menu(); */

            /* scr.activate_panel(PANEL_MAIN); */
            std::vector<std::string> *b = main_char.inv()->get_items();
            log_info("%s",b->at(0).c_str());



        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}
