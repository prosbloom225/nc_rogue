#include "ItemRegistry.h"

std::map<std::string*, Item*> ItemRegistry::registry;

bool ItemRegistry::register_item(Item *item){ 
    debug("%s", item->get_id()->c_str());
    registry.insert(std::pair<std::string*, Item*>(item->get_id(), item));
    /* registry.emplace(item->get_id(), item); */
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
    log_info("Size of registry: %lu", ItemRegistry::registry.size());

    for (auto f : ItemRegistry::registry) {
        if (id->compare( *f.first) == 0) {
            log_info("ITEM FOUND: %s - %s", id->c_str(), f.first->c_str());
            return f.second;
        }
    }
    return nullptr;

    /*
    auto search = ItemRegistry::registry.find(id);//new std::string("nc_rogue:testItem"));
    if (search != ItemRegistry::registry.end()) {
        log_info("Item found in registry: %s", id->c_str());
        return search->second;
    } else {
        log_info("Item not found in registry: %s", id->c_str());
        return nullptr;
    }
    */
}

