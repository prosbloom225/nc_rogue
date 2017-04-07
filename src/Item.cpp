#include "Item.h"


Item::Item(std::string *itemId, std::string *itemName){
    id = itemId;
    name = itemName;
    /* ItemRegistry::register_item(this); */

}

Item::~Item(){}


