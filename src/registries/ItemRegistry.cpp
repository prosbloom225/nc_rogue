#include "ItemRegistry.h"

std::set<Item, itemComp> ItemRegistry::registry;

bool ItemRegistry::register_item(Item *item){ 
    debug("%s", item->get_name()->c_str());
    registry.insert(*item);
    // TODO - stub
    
    return true;
} 
bool ItemRegistry::unregister_item(int itemId) {
    // TODO - stub
    return true;
}


void ItemRegistry::dump_items() {
    debug("DUMPING ITEM REGISTRY");
    for (auto f : ItemRegistry::registry) {
        debug("Id: %d - Name: %s",f.get_itemId(), f.get_name()->c_str());
    }
}

