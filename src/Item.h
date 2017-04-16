#ifndef ITEM_H
#define ITEM_H

#include "dbg.h"
#include <string>

class Item {
    private:
        std::string id;
        std::string name;


    public:
        Item(std::string modid, std::string itemName);
        ~Item();


        // getters
        std::string get_name() { return name; };
        std::string get_id() const { return id; };

};


#endif


