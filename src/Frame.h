#ifndef FRAME_H
#define FRAME_H

#include <ncurses.h>
#include <panel.h>
#include "Character.h"
#include "PerlinNoise.h"
#include "Constants.h"

class Frame {
    int _height, _width;
    int _row, _col;
    bool _has_super;

    // pointer to the window
    WINDOW *_w;
    // pointer to the parent window
    WINDOW *_super;

    public:
    // Init a main window
    Frame(int nr_rows, int nr_cols, int row_0, int col_0);
    // Init a viewport with a parent window
    Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);
    ~Frame();


    // Define the erase char
    void erase(Character &x);

    // Add char to window
    void add(Character &x);
    void add(Character &x, int row_0, int col_0);

    // Center the viewport around a character
    void center(Character &x);

    // Refresh
    void refresh();

    // Move a window to a new pos
    void move(int r, int c);
    
    // Test - Fill window with a flat char
    void fill_window();


    // gen_perlin - Fill window with water, floors, walls, and ice
    void gen_perlin(const unsigned int &seed);

    // Getters
    WINDOW *win();
    WINDOW *super();
    int height();
    int width();
    int row();
    int col();
    bool has_super();
};

#endif
