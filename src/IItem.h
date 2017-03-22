#ifndef IITEM_H 
#define IITEM_H


#include <string>

class IItem {
    private:
        int itemId;
        std::string *name;


    public:
        virtual ~IItem() = default;


        // getters
        virtual std::string *get_name() { return name; };
        virtual int get_itemId() { return itemId; };
};


#endif
