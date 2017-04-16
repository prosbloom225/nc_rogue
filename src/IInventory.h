#ifndef IINVENTORY_H
#define IINVENTORY_H


#include <stdlib.h>
#include <vector>
#include <string>
#include "Item.h"

class IInventory {
    private:
        std::vector<Item> items;

    public:
        virtual ~IInventory() = default;
        virtual std::vector<Item> *get_items() = 0;
};


#endif
