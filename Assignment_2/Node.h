#include <iostream>


class Node { //Node class

public:
    Node* nextNode;
    char data;

    Node(char _data, Node* _nextNode) { //points to next Node and shows the whole word
        nextNode = _nextNode;
        data = _data;
    }

};