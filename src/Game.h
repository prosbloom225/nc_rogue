#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <vector>
#include "Screen.h"
#include "Inventory.h"
#include "InventoryView.h"
#include "registries/ItemRegistry.h"

class Game{ 

    Frame *game_map;
    Frame *viewport;

    Character *main_char;

    void pre_init();
    void init();
    void post_init();

    public:
    Game();
    ~Game();

    // getters
    Frame *get_game_map();
    Frame *get_viewport();
    Character *get_main_char();


    void game_loop( Game &game, int ch);
};

#endif

