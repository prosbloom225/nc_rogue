#include "Character.h"

Character::Character(char symbol, int row_0, int col_0){
    _symbol = symbol;
    _row = row_0;
    _col = col_0;
    _inv = new Inventory();
}

void Character::pos(int row_0, int col_0){
    _row = row_0;
    _col = col_0;
}

// Getters
int Character::row(){
    return _row;
}
int Character::col(){
    return _col;
}
char Character::symbol(){
    return _symbol;
}

Inventory *Character::inv() {
    return _inv;
}
