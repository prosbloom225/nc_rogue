#include "Inventory.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


// Constructor
Inventory::Inventory() {
    items = *new std::vector<std::string>();
    items.push_back("test1");
}

// Dealloc
Inventory::~Inventory(){
}

std::vector<std::string> *Inventory::get_items() {
    return &items;
}


