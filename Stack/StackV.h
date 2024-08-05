#ifndef STACKV_H
#define STACKV_H

#include <iostream>
#include <vector>

template <typename T>
class StackV 
{
private:
    std::vector<T> vec;
public:
    StackV();

    ~StackV();

    void push(const T& elem);
    
    void pop();
    
    T top() const;
    
    
    bool empty() const;
    
};

#endif //STACKV_H