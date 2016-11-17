#include <ncurses.h>
#include "Constants.h"

#include "Screen.h"
#include "Frame.h"
#include "Character.h"


void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch) {

    if (ch == 'q' || ch == 'Q')
        return;

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
        }else if (ch == 'l') {
            game_map.add(main_char, main_char.row() - 1, main_char.col());
            viewport.center(main_char);
            viewport.refresh();
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}

int main (int argc, char* argv[]) {
    // Init
    Screen scr;

    scr.add("Welcome to nc_rogue.\nPress any key to start.\n");
    // Wait for user input to start
    int ch = getch();


    // Game map
    Frame game_map(2 * scr.height(), 2 * scr.width(), 0, 0);
    // Main viewport
    Frame viewport(game_map, scr.height(), scr.width(), 0, 0);


    // Init main char and dump in the middle
    Character main_char('@', game_map.height()/2, game_map.width()/2);

    // Fill screen test
    game_map.fill_window();

    // Main loop
    game_loop(game_map, viewport, main_char, ch);

    // Clean up 
    return 0;
}
