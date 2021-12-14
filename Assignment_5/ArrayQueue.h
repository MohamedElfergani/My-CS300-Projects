
/** ADT queue: Circular array-based implementation.
   @file ArrayQueue.h */
#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueADT.h"

template <class T>
class ArrayQueue : public QueueADT<T>
{
private:
    static const int DEFAULT_CAPACITY = 100;
    T items[DEFAULT_CAPACITY]; // Array of queue items
    int front;                 // Index to front of queue
    int back;                  // Index to back of queue
    int count;                 // Number of items currently in the queue

public:
    ArrayQueue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const T &newEntry);
    void dequeue();
    T qfront() const;
    int getCount() const;
}; // end ArrayQueue

template <class T>
ArrayQueue<T>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY - 1), count(0)
{
} // end default constructor

template <class T>
bool ArrayQueue<T>::isEmpty() const
{
    return count == 0;
} // end isEmpty

template <class T>
bool ArrayQueue<T>::isFull() const
{
    return count == (sizeof(items[DEFAULT_CAPACITY]) / sizeof(int));
}

template <class T>
void ArrayQueue<T>::enqueue(const T &newEntry)
{
    bool result = false;
    if (count < DEFAULT_CAPACITY)
    {
        // Queue has room for another item
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        count++;
    } // end if
} // end enqueue

template <class T>
void ArrayQueue<T>::dequeue()
{
    bool result = false;
    if (!isEmpty())
    {
        front = (front + 1) % DEFAULT_CAPACITY;
        count--;
        result = true;
    } // end if
} // end dequeue

template <class T>
T ArrayQueue<T>::qfront() const
{
    return items[front];
}

template <class T>
int ArrayQueue<T>::getCount() const
{
    return count;
}
// End of implementation file.
#endif