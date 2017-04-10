#include "Item.h"


Item::Item(std::string *modid, std::string *itemName){
    id = new std::string(modid) + ":" + itemName;
    name = itemName;
    /* ItemRegistry::register_item(this); */

}

Item::~Item(){}


