#ifndef NODE_H
#define NODE_H 

using namespace std; 

template <class T>
class Node {
public:
    T data; 
    Node *next = nullptr; 
};
#endif