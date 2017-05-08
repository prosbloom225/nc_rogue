#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


// Constructor
Inventory::Inventory() {
    // TODO - seeding initial player inventory
    Item *a = ItemRegistry::get_item(new std::string("nc_rogue:testItem"));
    debug("Seeding inventory with item: %s", a->get_name()->c_str());
    items.push_back(*a);

    Item *b = ItemRegistry::get_item(new std::string("nc_rogue:testItem2"));
    debug("Seeding inventory with item: %s", b->get_name()->c_str());
    items.push_back(*b);
}

// Dealloc
Inventory::~Inventory(){
}

std::vector<Item> *Inventory::get_items() {
    return &items;
}

int Inventory::get_size() {
    return items.size();
}

Item *Inventory::get_item_at_pos(int pos) {
    return &items.at(pos);
}


