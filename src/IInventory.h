#ifndef IINVENTORY_H
#define IINVENTORY_H


#include <stdlib.h>
#include <vector>
#include <string>

class IInventory {
    private:
        std::vector<std::string> items;

    public:
        virtual ~IInventory() = default;
        virtual std::vector<std::string> *get_items() = 0;
};


#endif
