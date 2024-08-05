#ifndef NODE_H
#define NODE_H

#include <iostream>
template<typename T>
class Node
{
public:    
    T data;
    Node* next;
    Node(T data);
    ~Node();
    
};
#endif // NODE_H