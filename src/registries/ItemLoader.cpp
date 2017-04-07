#include "../Item.h"
#include "ItemLoader.h"
#include "ItemRegistry.h"
#include "../dbg.h"

#include <string>

void ItemLoader::init_items() {
    debug("Loading items....");
    Item *testItem = new Item(new std::string("base:testItem"), new std::string("testItem"));
    Item *testItem2 = new Item(new std::string("base:testItem2"), new std::string("testItem2"));

    ItemRegistry::register_item(testItem);
    ItemRegistry::register_item(testItem2);

    ItemRegistry::dump_items();

}
