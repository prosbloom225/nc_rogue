#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include <stdlib.h>

class Game{ 
    Screen *_scr;

    Frame *_game_map;
    Frame *_viewport;

    public:
    Game();
    ~Game();

    // getters
    Screen *scr();
    Frame *game_map();
    Frame *viewport();
};

#endif

