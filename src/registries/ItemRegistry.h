#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include "../dbg.h"
#include "../Item.h"
#include <set>

struct itemComp {
    bool operator()(const Item& lhs, const Item& rhs) const
    {
        return (lhs.get_itemId() > 0);
    }
};

class ItemRegistry {
    private:
        static std::set<Item, itemComp> registry;

    public:
        static bool register_item(Item *item);
        static bool unregister_item(int itemId);
        static void dump_items();


};


#endif


