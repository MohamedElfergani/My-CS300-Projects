//MagicChangeBag.h

#ifndef MAGICCHANGEBAG
#define MAGICCHANGEBAG
#include <iostream>
#include "PlainBag.h"
#include "BagInterface.h"



template <class ItemType>

class MagicChangeBag : public PlainBag<ItemType> {

private:
    int count; // count of the items 
    int index; //list of items 
    bool isHidden; // checks if the items are hidden 
    ItemType data[20]; // max to 20 


public:
    MagicChangeBag() {
       count = 0;
       isHidden = true;
       index = 0;

    }
    // if the items are hidden, return the count of items 
    // if not, return the list of items 
    int size() {
        if (isHidden)
            return count;
        else 
            return index;
        
    }
    
    //  if the items are hidden, return 0 
    // 
    int itemCount(const ItemType &anItem) {
        int num = 0;
        if (isHidden) {
            return num;
        }
        else {
            for (int i = 0; i < index; i++)
                if (data[i] == anItem) num++;
        }
        return num;
    }

    // insert an item of any type if the bag has < 20 items
    bool insert(const ItemType &newItem){
        if (index < 20) {
            data[index] = newItem;
            index++;
            count++;
            return true;
        } 
        return false;
    }

    //remove an item from the bag
    bool remove(const ItemType &anItem) {
        isHidden = false;
        print();
        int i = 0;
        while (data[i] != anItem) {
            i++;
        }
        for (; i < index; i++)
            data[i] = data[i + 1];
        index--;
        return isHidden;
    }

    // clear the bag
    // count of items is = to 0 
    void clear() {
        count = 0;
    }               
    
    //divide the size of data by the size od ItemType 
    bool isFull() {
        return count == sizeof(data) / sizeof(ItemType);
    }

    //if the bag's items are hidden, do not print any numbers 
    //if not, print the list 
    void print() {
        std::cout << "\nBag contains:";
        if (isHidden) {
            clear();
        }
        else {
            for (int i = 0; i < index; i++) {
                std::cout << data[i] << " ";
            }
        }
    }


}; // end MagicChangeBag




#endif