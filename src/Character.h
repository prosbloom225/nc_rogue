#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    int _row, _col;
    char _symbol;

    public:
    Character(char symbol, int row_0, int col_0);

    void pos(int row_0, int col_0);

    // Getters
    int row();
    int col();
    char symbol();
};

#endif
