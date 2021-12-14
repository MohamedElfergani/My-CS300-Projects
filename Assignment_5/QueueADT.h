#ifndef QUEUE_ADT
#define QUEUE_ADT
#include <iostream>

using namespace std;

template <class T>
class QueueADT
{
public:
    virtual void enqueue(const T &newEntry) = 0;
    virtual void dequeue() = 0;
    virtual T qfront() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};
#endif