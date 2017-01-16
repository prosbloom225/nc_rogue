#include "Frame.h"

// Init a main window
Frame::Frame(int nr_rows, int nr_cols, int row_0, int col_0){
    _has_super = FALSE;
    _super = NULL;
    _w = newwin(nr_rows, nr_cols, row_0, col_0);
    _height = nr_rows;
    _width  = nr_cols;
    _row = row_0;
    _col = col_0;
}
// Init a viewport with a parent window
Frame::Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0){
    _has_super = TRUE;
    _super = sw.win();
    _w = derwin(sw.win(), nr_rows, nr_cols, row_0, col_0);
    _height = nr_rows;
    _width  = nr_cols;
    _row = row_0;
    _col = col_0;
}

// Dealloc
Frame::~Frame(){
    delwin(_w);
}


void Frame::add(Character &x) {
    mvwaddch(_w, x.row(), x.col(), x.symbol());
}

void Frame::add(Character &x, int row_0, int col_0) {
    if ((row_0 >= 0 && row_0 < _height) && (col_0 >= 0 && col_0 < _width)) {
        char target = (char)mvwinch(_w, row_0, col_0);
        if (target == WALL_CHAR || target == WATER_CHAR || target == ICE_CHAR) {
            return;
        }
        erase(x);
        mvwaddch(_w, row_0, col_0, x.symbol());
        x.pos(row_0, col_0);
    }
}

void Frame::erase(Character &x) {
    mvwaddch(_w, x.row(), x.col(), ' ');
}

void Frame::center(Character &x) {
    if (_has_super) {
        int rr = _row, cc = _col, hh, ww;
        int _r = x.row() - _height/2;
        int _c = x.col() - _width/2;
        getmaxyx(_super, hh, ww);

        if (_c + _width >= ww) {
            int delta = ww - (_c + _width);
            cc = _c + delta;
        } else {
            cc = _c;
        }
        if (_r + _height >= hh) {
            int delta = hh - (_r + _height);
            rr = _r + delta;
        } else {
            rr = _r;
        }

        if (_r < 0)
            rr = 0;
        if (_c < 0)
            cc = 0;

        move(rr, cc);
    }
}

void Frame::refresh() {
    if (_has_super) {
        touchwin(_super);
    }
    /* wrefresh(_w); */
    update_panels();
    doupdate();
}


void Frame::move(int r, int c) {
    if (_has_super) {
        mvderwin(_w, r, c);
        _row = r;
        _col = c;
        refresh();
    }
}

void Frame::gen_perlin(const unsigned int &seed) {
    PerlinNoise pn(seed);

    for (int i=0; i < _height; i++) {
        for (int j=0; j < _width; j++) {
            double x = (double)j/((double) _width);
            double y = (double)i/((double) _height);
            
            double n = pn.noise(10*x, 10*y, 0.8);

            if (n<0.35) {
            // Water
                mvwaddch(_w, i, j, WATER_CHAR);
            } else if (n >= 0.35 && n < 0.6) {
            // Floor
                mvwaddch(_w, i, j, FLOOR_CHAR);
            } else if (n >= 0.6) {
            // Walls
                mvwaddch(_w, i, j, WALL_CHAR);
            } else {
            // Ice
                mvwaddch(_w, i, j, ICE_CHAR);
            }
        }
    }

}
 
void Frame::fill_window() {
    int max_x = _width / 2;
    int max_y = _height / 2;
    // 0
    for (int y = 0; y < max_y; ++y) {
        for (int x = 0; x < max_x; ++x) {
            mvwaddch(_w, y, x, '0');
        }
    }
    // 1
    for (int y = 0; y < max_y; ++y) {
        for (int x = max_x; x < _width; ++x) {
            mvwaddch(_w, y, x, '1');
        }
    }
    // 2
    for (int y = max_y; y < _height; ++y) {
        for (int x = 0; x < max_x; ++x) {
            mvwaddch(_w, y, x, '2');
        }
    }
    // 3
    for (int y = max_y; y < _height; ++y) {
        for (int x = max_x; x < _width; ++x) {
            mvwaddch(_w, y, x, '3');
        }
    }

   // Borders
   for (int y = 0; y < _height; ++y) {
       mvwaddch(_w, y, 0, '-');
       mvwaddch(_w, y, _width-1, '-');
   } 
   for (int x = 0; x < _width; ++x) {
       mvwaddch(_w, 0, x, '|');
       mvwaddch(_w, _height-1, x, '|');
   }

}

bool Frame::has_super() {
    return _has_super;
}

// Getters
WINDOW* Frame::win() {
    return _w;
}

WINDOW* Frame::super() {
    return _super;
}

int Frame::height() {
    return _height;
}
int Frame::width() {
    return _width;
}
int Frame::row() {
    return _row;
}
int Frame::col() {
    return _col;
}
