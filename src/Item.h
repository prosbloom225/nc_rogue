#ifndef INVENTORY_H
#define INVENTORY_H

#include  "IItem.h"
#include "dbg.h"

class Item : public IItem {
    private:
        int id;
        std::string *name;


    public:
        Item();
        Item(int itemId, std::string *itemName);
        ~Item();


        // getters
        std::string *get_name() { return name; };
        int get_itemId() { return id; };


};


#endif


