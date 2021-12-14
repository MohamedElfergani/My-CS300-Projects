//BagInterface.h

#ifndef BAGINTERFACE
#define BAGINTERFACE
#include "PlainBag.h"

template <class ItemType>

class BagInterface {


public:
    virtual int size() = 0;            // get the number of items inside the bag
    virtual bool contains(const ItemType& anItem) = 0;        //  checks if the bag has items inside 
    virtual int itemCount(const ItemType& anItem) = 0;          // counts how many times a number appears in the bag 
    virtual bool insert(const ItemType& newItem) = 0; // inserts an item inside the bag
    virtual bool remove(const ItemType& anItem) = 0;       // remove an item for the bag 
    virtual void clear() = 0;                  // clear the bag from all items
    virtual bool isEmpty() = 0;                  // check of the bag is empty
    virtual bool isFull() = 0;                 // check if the bag is full
    virtual void print() = 0;


}; // end Bag Interface
#endif
