#ifndef STACKL_H
#define STACKL_H

#include <iostream>
#include <list>

template <typename T>
class StackL 
{
private:
    std::list<T> list;
public:
    StackL();

    ~StackL();

    void push(const T& elem);

    void pop();
    
    T top() const;

    bool empty() const;
};

#endif //STACKL_H