#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include "Node.h"
#include <initializer_list>

template<typename T>
class ForwardList
{
    Node<T>* head;
public:
    class Iterator
    {
    private:
        Node<T>* current;
    public: 
        Iterator(Node<T>* node);
        ~Iterator();
        T& operator*() const;
        T* operator->() const;
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
        Iterator operator++(int);
    };
    
    ForwardList();
      
    ~ForwardList();
    
    ForwardList(std::initializer_list<T> init);
    
    ForwardList(const ForwardList& other);
    
    ForwardList(ForwardList&& other);
    
    ForwardList& operator=(const ForwardList& other);
    
    ForwardList& operator=(ForwardList&& other);

    void push_front(const T& val);

    void pop_front();
    
    void Reverse();
    
    T front();
    
    bool empty();

    void Print() const;
    
    Iterator begin() const;

    Iterator end() const;

    
    
};

#endif // FORWARDLIST_H