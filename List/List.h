
#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <initializer_list>
#include <exception>

template<typename T>
class List
{
    Node<T>* head;
    Node<T>* tail;
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
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other)const;
        bool operator!=(const Iterator& other)const;
        
        
    };
    List();
      
    ~List();
    
    List(std::initializer_list<T> init);
    
    List(const List& other);
    
    List(List&& other);
    
    List& operator=(List&& other);
    
    List& operator=(const List& other);
   
    void push_front(const T& val);
    
    void push_back(const T& val);

    void pop_front();

    void pop_back();
    
    void insert(const T& val, int n);
    
    bool empty();
    
    T& back();
    
    T& front();
    
    Iterator begin() const;
    
    Iterator end() const;
    
    void Print() const;
    
};

#endif // LIST_H