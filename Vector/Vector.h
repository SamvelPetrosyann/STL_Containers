#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <exception>

template <typename T>
class Vector
{
private:
    int m_size;
    int m_cap;
    T* m_arr;
public:
    class Iterator
    {
    private:
        T* m_ptr;
    public:
        Iterator(T* ptr);
        T& operator*() const;
        T* operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Iterator operator+(int n) const;
        Iterator operator-(int n) const;
        friend class Vector;
    };
    Vector();
    Vector(std::initializer_list<T> init);
    ~Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    void push_back(const T& elem);
    void push_front(const T& elem);
    void pop_back();
    void pop_front();
    void resize(int n);
    void reserve(int n);
    void insert(const T& elem, int position);
    void erase(Iterator position);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    T& operator[](int index);
    void PrintVector() const;
    T at(int index) const;
    bool empty();
    int size();
    int capacity();
    Iterator begin();
    Iterator end();
};

#endif // VECTOR_H