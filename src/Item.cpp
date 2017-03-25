#include "Item.h"

Item::Item(){}

Item::Item(int itemId, std::string *itemName){
    id = itemId;
    name = itemName;
    /* ItemRegistry::register_item(this); */

}

Item::~Item(){}


