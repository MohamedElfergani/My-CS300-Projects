#ifndef TWOHASH
#define TWOHASH
#include "position.h"
#include "UPCEntry.h"
#include "list.cpp"
#include <cmath>
#include <fstream>

using namespace std;

class TwoHashTable
{
public:
    int tableSize; 
    int Size = 0; 
    list<UPCEntry> *arr; 
    int* length; 
    
    TwoHashTable(string filename, int tableSize);
    bool insert(UPCEntry &item); // returns true if successful, false otherwise.
    Position search(UPCEntry &item); // if not found, return the default position with both indices set as -1
    float getStdDev();
    int size();
    int FindNode(); 
private:
    float stddev(int *binLengths, int tableSize)
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};

TwoHashTable::TwoHashTable(string filename, int tableSize) {
    string myLine; 
    UPCEntry start;
    fstream file; 

    Size = tableSize;
    arr = new list<UPCEntry>[tableSize];
   
    length = new int[tableSize];

    file.open(filename); 
    getline(file, myLine);
    
    while(getline(file, myLine)){
        start = UPCEntry(myLine);
        insert(start);
    }
    for(int i = 0; i < tableSize; i++){
        length[i] = arr[i].size();
    }
}

bool TwoHashTable::insert(UPCEntry &item) {
    /* made two new integers named num2 and num2 
    *  add them to the hashes with the sizes 
    */
    int num1 = item.hash1(Size);  
    int num2 = item.hash2(Size);

    /* if the array size of num1 is <= to the array size of num2
    * insert an item into num1
    * return true 
    */
    if(num1 < Size && num2 < Size) { 
        if(arr[num1].size() <= arr[num2].size()) {
            arr[num1].push_front(item);
            return true;
        }
                /* if the array size of num1 bigger than array size of 2 
                * insert into 2 and return true
                */
        else{
            arr[num2].push_front(item);
            return true;
        }
    }

}

Position TwoHashTable::search(UPCEntry &item) {
    Position spot;

    /* iterates through the whole table 
    * if after iterating is eqal to item, 
    * make the spot of indexInBin = i and spot of indexInTable = index
    * return spot
    */
   int num1 = item.hash1(Size);
   int num2 = item.hash2(Size);
   int i = 0;
    list<UPCEntry>::iterator myIterator;
        for (myIterator = arr[num1].begin(); myIterator != arr[num1].end(); ++myIterator) {
            if(*myIterator == item) {
                spot.indexInBin = i;
                spot.indexInTable = num1;
                return spot;
            }
            ++i;
        }
    int s = 0;
    list<UPCEntry>::iterator myIterator2;
    for (myIterator2 = arr[num2].begin(); myIterator2 != arr[num2].end(); ++myIterator2) {
            if(*myIterator2 == item) {
                spot.indexInBin = s;
                spot.indexInTable = num1;
                return spot;
            }
            ++s;
    }
    return spot;
}

float TwoHashTable::getStdDev() {
    return stddev(length, Size);
}

#endif