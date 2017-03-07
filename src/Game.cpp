#include "Game.h"


// constructor
Game::Game() {
    _scr = new Screen();

    // Set up game map
    //
    // Game map
    _game_map = new Frame(2 * _scr->height(), 2 * _scr->width(), 0, 0);
    // Main viewport
    _viewport = new Frame(*_game_map, _scr->height(), _scr->width(), 0, 0);
    _scr->set_panel_window(PANEL_MAIN, _viewport->win());

    _main_char = new Character('@', _game_map->height()/2, _game_map->width()/2);
    _game_map->add(*_main_char);

    _scr->activate_panel(0);
}

// dealloc
Game::~Game() {
    endwin();
    free(_scr);
    free(_game_map);
    free(_viewport);
    free(_main_char);
}

// getters
Screen *Game::scr() {
    return _scr;
}

Frame *Game::viewport() {
    return _viewport;
}

Frame *Game::game_map() {
    return _game_map;
}

Character *Game::main_char(){
    return _main_char;
}



// main loop
void Game::game_loop( Game &game, int ch) {

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
            main_char.inv()->activate_menu();

            scr.activate_panel(PANEL_MAIN);


        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}
