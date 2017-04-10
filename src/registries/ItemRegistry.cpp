#include "ItemRegistry.h"

std::map<std::string*, Item*> ItemRegistry::registry;

bool ItemRegistry::register_item(Item *item){ 
    debug("%s", item->get_id()->c_str());
    /* registry.insert(std::make_pair(item->get_id(), item)); */
    registry.emplace(item->get_id(), item);
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
        debug("Id: %s - Name: %s",f.first->c_str(), f.second->get_name()->c_str());
    }
}

Item* ItemRegistry::get_item(int id) {
    // TODO - full table scan - ick
    return nullptr;
}

