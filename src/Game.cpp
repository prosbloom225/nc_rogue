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
}

// dealloc
Game::~Game() {
    free(_scr);
    free(_game_map);
    free(_viewport);
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
