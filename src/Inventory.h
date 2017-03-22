#ifndef INVENTORY_H
#define INVENTORY_H

#include  "IInventory.h"
#include "dbg.h"

class Inventory : public IInventory {
    private:
        std::vector<std::string> items;

    public:
        Inventory();
        ~Inventory();

        std::vector<std::string> *get_items();


};


#endif

