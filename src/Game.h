#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <vector>
#include "Screen.h"
#include "Inventory.h"

class Game{ 
    Screen *_scr;

    Frame *_game_map;
    Frame *_viewport;

    Character *_main_char;

    public:
    Game();
    ~Game();

    // getters
    Screen *scr();
    Frame *game_map();
    Frame *viewport();

    Character *main_char();


    void game_loop( Game &game, int ch);
};

#endif

