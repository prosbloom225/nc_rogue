#include "ItemLoader.h"
#include "ItemRegistry.h"
#include "../Item.h"
#include "../dbg.h"
#include "../lib/LibMisc.h"

#include <string>

void ItemLoader::init_items() {
    debug("Loading items....");
    Item *testItem = new Item(std::string(MODID), std::string("testItem"));
    Item *testItem2 = new Item(std::string(MODID), std::string("testItem2"));

    ItemRegistry::register_item(testItem);
    ItemRegistry::register_item(testItem2);

    ItemRegistry::dump_items();

}
