#ifndef ITEMREGISTRY_H
#define ITEMREGISTRY_H

#include "dbg.h"
#include "IItem.h"
#include <vector>

class ItemRegistry {
    private:
        static std::vector<IItem> registry;

    public:
        static bool register_item(IItem *item);
        static bool unregister_item(int itemId);

};


#endif


