#include <iostream>
#include "PlainBag.h"
#include "MagicChangeBag.h"

using namespace std;

template <class T>
void testBag(BagInterface<T>& bag)
{
    T value;
    T item1 = 1;
    T item2 = 2;
    for (int i = 0; i < 20; i++)
    {
        value = rand() % 6 + 1;
        // assume storing integers for sake of simplicity
        bag.insert(value);
    }
    bag.print();
    cout << "\nNumber of items:" << bag.size();
    cout << "\nNumber of ones:" << bag.itemCount(item1);
    bag.remove(item1);
    bag.print();
    cout << "\nNumber of items:" << bag.size();
    cout << "\nNumber of ones:" << bag.itemCount(item1);
    cout << "\nNumber of twos:" << bag.itemCount(item2);
};

int main()
{
    cout << "\n..............................." << endl;
    cout << "Testing Plain Bag" << endl;
    BagInterface<int>* bag = new PlainBag<int>;
    testBag(*bag);
    cout << "\n..............................." << endl; // 10/13 program works up to
    cout << "Testing Magic Change Bag" << endl;
    bag = new MagicChangeBag<int>;
    testBag(*bag);

    return 0;
}

