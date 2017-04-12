#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "lib/LibMisc.h"

class Item {
    protected:
        std::string *id;
        std::string *name;


    public:
        Item(std::string const& modid, std::string const& itemName);
        ~Item();


        // getters
        std::string *get_name() const { return name; };
        std::string *get_id() const { return id; };

};


#endif


