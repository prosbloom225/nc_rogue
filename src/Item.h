#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "lib/LibMisc.h"

class Item {
    private:
        std::string *id;
        std::string *name;


    public:
        Item(std::string const& modid, std::string const& itemName);
        ~Item();


        // getters
        std::string *get_name() { return name; };
        std::string *get_id() const { return id; };

};


#endif


