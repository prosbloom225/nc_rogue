#ifndef ITEM_H
#define ITEM_H

#include "dbg.h"
#include <string>

class Item {
    private:
        const int id;
        std::string *name;


    public:
        Item();
        Item(int itemId, std::string *itemName);
        ~Item();


        // getters
        std::string *get_name() { return name; };
        int get_itemId() const { return id; };

};


#endif


