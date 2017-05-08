#ifndef IINVENTORY_H
#define IINVENTORY_H


#include <stdlib.h>
#include <vector>
#include <string>
#include "Item.h"

class IInventory {
    private:
        std::vector<std::string> items;

    public:
        virtual ~IInventory() = default;
        virtual std::vector<Item> *get_items() = 0;
        virtual Item *get_item_at_pos(int pos) = 0;
        virtual int get_size() = 0;
};


#endif
