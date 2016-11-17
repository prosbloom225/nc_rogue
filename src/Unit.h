#ifndef UNIT_H
#define UNIT_H

#include "Constants.h"

class Unit {
    private:
        char _symbol;
    public:
        Unit();
        Unit(char symbol);
        char getSymbol() {return _symbol;}
        
};

#endif
