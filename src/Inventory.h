#ifndef INVENTORY_H
#define INVENTORY_H

#include  "IInventory.h"
#include  "Item.h"
#include  "registries/ItemRegistry.h"

class Inventory : public IInventory {
    private:
        std::vector<Item> items;

    public:
        Inventory();
        ~Inventory();

        std::vector<Item> *get_items();


};


#endif

