#include "Item.h"


Item::Item(std::string const& modid, std::string const& itemName){
    id = new std::string(modid + ":" + itemName);
    name = new std::string(itemName);
    /* ItemRegistry::register_item(this); */

}

Item::~Item(){}


