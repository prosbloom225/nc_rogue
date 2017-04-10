#include "ItemRegistry.h"

std::map<std::string*, Item*> ItemRegistry::registry;

bool ItemRegistry::register_item(Item *item){ 
    debug("%s", item->get_id()->c_str());
    /* registry.insert(std::make_pair(item->get_id(), item)); */
    registry.emplace(item->get_id(), item);
    // TODO - return codes
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

Item* ItemRegistry::get_item(std::string *id) {
    // TODO - full table scan - ick

    debug("Size of registry: %lu", ItemRegistry::registry.size());
    Item *t= ItemRegistry::registry.find(id)->second;
    return t;
    /* return nullptr; */
}

