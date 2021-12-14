//PlainBag.h

#ifndef PLAINBAG
#define PLAINBAG
#include "BagInterface.h"
#include <iostream>


template<class ItemType>
class PlainBag : public BagInterface<ItemType> {

private:
    //count of the items inside the bag 
    int count;
    // set the max number of items inside the bag to 20
    ItemType data[20]; 

public:
    PlainBag() { // constructor
        count = 0;
    }
    // gets the number of items in the bag
    // and returns it 
     virtual int size() { 
        return count;
    }

     // checks if there is an item inside the bag
     // if true, return true. if not, return false 
     virtual bool contains(const ItemType &anItem) { // access current capacity
         for (int i = 0; i < count; i++) {
             if (data[i] == anItem) {
                 return false;
             }
         }
     }

     //counts how many times numbers appear in the bag and returns it
     //num of ones and twos 
     virtual int itemCount(const ItemType& anItem) {
         int num = 0;
         for (int i = 0; i < count; i++)
             if (data[i] == anItem) num++;
         return num;
     }

     // insert an item inside the bag 
     // if the count of the bag is < 20 
     virtual bool insert(const ItemType& newItem) { 
         if (count < 20) {
             data[count] = newItem;
             count++;
             return true;
         }
         else {
             return false;
         }
     }

     //remove an item from the bag
    virtual bool remove(const ItemType& anItem) {      
        if (itemCount(anItem) == 0)
            return false; 
        int i = 0;
        while (data[i] != anItem) {
            i++;
        }
        for (;i < count; i++)
            data[i] = data[i + 1];
        count--;
    
    }

    //clear the bag from all items 
    virtual void clear() {                  
        count = 0;
    }

    // check of the bag is empty
    //if empty, return true, if not, return false 
     virtual bool isEmpty() {                
        if (count == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // check if the bag is full
    // if full, return true. if not, return false 
    virtual bool isFull() {  
        if (count == 20) {
            return true;
        }
        else {               
            return false; 
        }
    }

    //it prints out "Bag contains: " 
    virtual void print() {
        std::cout << "\nBag contains: ";
        for (int i = 0; i < count; i++) {
            std::cout << data[i] << " ";
        }
    }



}; // end PlainBox

#endif