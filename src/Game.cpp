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
