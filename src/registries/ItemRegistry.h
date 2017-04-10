#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include "../dbg.h"
#include "../Item.h"
#include <map>

class ItemRegistry {
    private:
        static std::map<std::string*, Item*> registry;

    public:
        static bool register_item(Item *item);
        static bool unregister_item(int itemId);
        static void dump_items();

        static Item* get_item(std::string *id);


};


#endif


