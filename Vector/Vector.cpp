#include "Vector.h"

//default constructor
template <typename T>
Vector<T>::Vector() :m_size(0), m_cap(2), m_arr(new T[m_cap])
{

}

//Init List Constructor
template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : m_size(init.size()), m_cap(init.size() * 2), m_arr(new T[m_cap])
{
    int i = 0;
    for(auto elem: init)
    {
        m_arr[i++] = elem;
    }
}

//Destructor
template <typename T>
Vector<T>::~Vector()
{
    delete[] m_arr;
}

//Copy Constructor
template<typename T>
Vector<T>::Vector(const Vector& other):m_size(other.m_size),m_cap(other.m_cap),m_arr(new T[m_cap])
{
    for (int i = 0; i < m_size; ++i)
    {
        m_arr[i] = other.m_arr[i];
    }
}

//move Constructor
template<typename T>
Vector<T>::Vector(Vector&& other) :m_size(other.m_size), m_cap(other.m_cap), m_arr(other.m_arr)
{
    other.m_arr = nullptr;
    other.m_cap = 0;
    other.m_size = 0;
}

//push_back
template<typename T>
void Vector<T>::push_back(const T& elem)
{
    if (m_size < m_cap)
    {
        m_arr[m_size++] = elem;
    }
    else
    {
        T* new_arr = new T[m_cap * 2];
        for (int i = 0; i < m_size; ++i)
        {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        new_arr = nullptr;
        m_cap *= 2;
        m_arr[m_size++] = elem;
    }
}

//push_front()
template<typename T>
void Vector<T>::push_front(const T& elem)
{
    if (m_size == 0)
    {
        m_arr[m_size] = elem;
    }
    else if (m_size < m_cap)
    {
        m_arr[m_size++] = 0;
        for (int i = m_size; i > 0; --i)
        {
            std::swap(m_arr[i], m_arr[i - 1]);
        }
        m_arr[0] = elem;
    }
    else
    {
        T* new_arr = new T[m_cap * 2];
        for (int i = 0; i < m_size; ++i)
        {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        new_arr = nullptr;
        m_cap *= 2;
        m_arr[m_size++] = 0;
        for (int i = m_size; i > 0; --i)
        {
            std::swap(m_arr[i], m_arr[i - 1]);
        }
        m_arr[0] = elem;
    }
}

//pop_back()
template <typename T>
void Vector<T>::pop_back()
{
    T* temp = new T[m_cap];
    for(int i = 0; i < m_size - 1; ++i)
    {
        temp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_size--;
    if(m_size <= m_cap/2)
    {
        m_cap /= 2;
    }
    m_arr = temp;
    temp = nullptr;
}

//pop_front()
template<typename T>
void Vector<T>::pop_front()
{
    T* temp = new T[m_cap];
    for(int i = 0; i < m_size - 1; ++i)
    {
        temp[i] = m_arr[i + 1];
    }
    delete[] m_arr;
    m_size--;
    if(m_size <= m_cap/2)
    {
        m_cap /= 2;
    }
    m_arr = temp;

    temp = nullptr;
}

 //insert()
template <typename T>
void Vector<T>::insert(const T& elem, int position)
{
    if(position > m_size)
    {

        std::cerr << std::endl << "position number greather than size" << std::endl;
    }
    else
    {
        if (m_size < m_cap)
        {
            m_arr[m_size++] = 0;
            for (int i = m_size; i > position; --i)
            {
                std::swap(m_arr[i], m_arr[i - 1]);
            }
            m_arr[position] = elem;
        }
        else
        {
            T* new_arr = new T[m_cap * 2];
            for (int i = 0; i < m_size; ++i)
            {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
            new_arr = nullptr;
            m_cap *= 2;
            m_arr[m_size++] = 0;
            for (int i = m_size; i > position; --i)
            {
                std::swap(m_arr[i], m_arr[i - 1]);
            }
            m_arr[position] = elem;
        }
    }
}

// copy operator=
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) 
{
    if (this != &other) 
    {
        delete[] m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = new T[m_cap];
        for (int i = 0; i < m_size; ++i) 
        {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    if (this != &other)
    {

        delete[] m_arr;

        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = other.m_arr;

        other.m_cap = 0;
        other.m_size = 0;
        other.m_arr = nullptr;
    }
    return *this;
}

//PrintVector()
template <typename T>
void Vector<T>::PrintVector() const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_arr[i] << '\t';
    }
}

//resize()
template <typename T>
void Vector<T>::resize(int n)
{
    if(n < m_size)
    {
        T* temp = new T[n];

        for(int i = 0; i < n; ++i)
        {
            temp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
        m_size = n;
        temp = nullptr;
    }
    else if (n > m_size)
    {
        if(n <= m_cap)
        {
            for(int i = m_size + 1; i < n; ++i)
            {
                m_arr[i] = 0;
            }
            m_size = n;
        }
        else
        {
            m_cap = n;
            T* temp = new T[m_cap];
            for(int i = 0; i < m_size; ++i)
            {
                temp[i] = m_arr[i];
            }

            for(int i = m_size + 1; i < n; ++i)
            {
                temp[i] = 0;
            }

            delete[] m_arr;
            m_arr = temp;
            m_size = n;
            temp = nullptr;
        }
    }
}

//reserve()
template<typename T>
void Vector<T>::reserve(int n)
{
    if(n < m_cap)
    {
        if(n < m_size)
        {
            T* temp = new T[n];

            for(int i = 0; i < n; ++i)
            {
                temp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = temp;
            m_size = n;
            m_cap = n;
            temp = nullptr;
        }
        else
        {
            m_cap = n;
        }
    }
    else
    {
        m_cap = n;
    }
}

//at()
template <typename T>
T Vector<T>::at(int index) const 
{
    try
    {
        if(index < 0 || index >= m_size)
        {
            throw std::out_of_range("index out of range ");
        }
        return m_arr[index];
    } 
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << index << std::endl;
        throw;
    }
}

//operator [] for Vector
template <typename T>
T& Vector<T>::operator[](int index)
{
    return m_arr[index];
}

//empty()
template <typename T>
bool Vector<T>::empty()
{
    return m_size == 0;
}

 //size()
template <typename T>
int Vector<T>::size()
{
    return m_size;
}

//capacity()
template <typename T>
int Vector<T>::capacity()
{
    return m_cap;
}

//method erase()
template <typename T>
void Vector<T>::erase(Iterator position)
{
    if (position.m_ptr < m_arr || position.m_ptr >= m_arr + m_size)
    {
        throw std::out_of_range("Iterator out of range");
    }

   
    int index = position.m_ptr - m_arr;

    
    for (int i = index; i < m_size - 1; ++i)
    {
        m_arr[i] = m_arr[i + 1];
    }
    m_arr[m_size - 1].~T();
    --m_size;
}

//Constructor for Iterator
template <typename T>
Vector<T>::Iterator::Iterator(T* ptr) : m_ptr(ptr)
{
    
}

//operator* for Iterator
template <typename T>
T& Vector<T>::Iterator::operator*() const
{
    return *m_ptr;
}

//operator -> for Iterator
template <typename T>
T* Vector<T>::Iterator::operator->() const
{
    return m_ptr;
}

//prefix operator ++ for Iterator
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() 
{
    ++m_ptr;
    return *this;
}

//postfix operator ++ for Iterator
template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int) 
{
    Iterator temp = *this;
    ++m_ptr;
    return temp;
}

//prefix operator -- for Iterator
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--() 
{
    --m_ptr;
    return *this;
}

//postfix operator -- for Iterator
template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int) 
{
    Iterator temp = *this;
    --m_ptr;
    return temp;
}

//operator == for Iterator
template <typename T>
bool Vector<T>::Iterator::operator==(const Iterator& other) const
{
    return m_ptr == other.m_ptr;
}

//operator != for Iterator
template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other) const
{
    return m_ptr != other.m_ptr;
}

//begin() method
template<typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return Iterator(m_arr);
}

//end() method
template<typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return Iterator(m_arr + m_size);
}

//operator+ for Iterator
template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int n) const 
{
    return Iterator(m_ptr + n);
}

//operator- for Iterator
template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int n) const
{
    return Iterator(m_ptr - n);
}

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
template class Vector<char>;