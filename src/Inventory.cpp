#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


// Constructor
Inventory::Inventory() {
    /* items.push_back("test1"); */
}

// Dealloc
Inventory::~Inventory(){
}

std::vector<Item> *Inventory::get_items() {
    return &items;
}


