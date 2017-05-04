#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


// Constructor
Inventory::Inventory() {
    // TODO - seeding initial player inventory
    Item *a = ItemRegistry::get_item(new std::string("nc_rogue:testItem"));
    ItemRegistry::dump_items();
    debug("Seeding inventory with item: %s", a->get_name()->c_str());
    /* items.push_back(*a); */
}

// Dealloc
Inventory::~Inventory(){
}

std::vector<Item> *Inventory::get_items() {
    return &items;
}


