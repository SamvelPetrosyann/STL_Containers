#include "List.h"


template<typename T>
List<T>::List() : head(nullptr), tail(nullptr)
{
    
}

template<typename T>
List<T>::List(std::initializer_list<T> init) : head(nullptr), tail(nullptr)
{
    for(auto elem : init)
    {
        push_back(elem);
    }
}


template<typename T>
List<T>::~List() 
{
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
        if (current == head) 
        {
            break; 
        }
    }
    head = nullptr;  
}

//Copy Constructor
template<typename T>
List<T>::List(const List& other) : head(nullptr), tail(nullptr)
{
    if(other.head)
    {
        head = new Node<T>(other.head->data);
        
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head;
        while(otherCurrent)
        {
            current->next = new Node<T>(otherCurrent->data);
            otherCurrent = otherCurrent->next;
            current = current->next;
        }
        tail = current;
    }
}

//copy operator=
template<typename T>
List<T>& List<T>::operator=(const List& other)
{
    if(this != &other)
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        if(other.head)
        {
            head = new Node<T>(other.head->data);
            
            Node<T>* current = head;
            Node<T>* otherCurrent = other.head;
            while(otherCurrent)
            {
                current->next = new Node<T>(otherCurrent->data);
                otherCurrent = otherCurrent->next;
                current = current->next;
            }
            
        tail = current;
            
        }
    }
    return *this;
}

// Move constructor
template<typename T>
List<T>::List(List&& other) : head(other.head), tail(other.tail)
{
    other.head = nullptr;
    other.tail = nullptr;
}

// Move operator=
template<typename T>
List<T>& List<T>::operator=(List&& other)
{
    if (this != &other) 
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}


template<typename T>
void List<T>::push_front(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) 
    {
        head = newNode;
        tail = head;
    } 
    else 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}   

template<typename T>
void List<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    temp = nullptr;
}

template<typename T>
void List<T>::push_back(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) 
    {
        head = newNode;
        tail = head;
    } 
    else 
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}    

template<typename T>
void List<T>::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    temp = nullptr;
}

//insert()
template<typename T>
void List<T>::insert(const T& val, int n) 
{
    if(n < 0)
    {
        return;
    }
    
    if(n == 0)
    {
        push_front(val);
        return;
    }
    
    Node<T>* temp = head;
    for(int i = 0; i < n - 1; ++i)
    {
        if(temp == nullptr)
        {
            return;
        }
        temp = temp->next;
    }
    if(temp == tail)
    {
        push_back(val);
        return;
    }
    
    Node<T>* newNode = new Node<T>(val);
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

//front()
template<typename T>
T& List<T>::front()
{
    if(!head)
    {
        throw std::out_of_range ("List is empty");
    }
    return head->data;
}

//back()
template<typename T>
T& List<T>::back()
{
    if(!tail)
    {
        throw std::out_of_range ("List is empty");
    }
    return tail->data;
}

//empty()
template<typename T>
bool List<T>::empty()
{
    return head == nullptr;
}


//Print()
template<typename T>
void List<T>::Print() const
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << '\t';
        current = current->next;
    }
}

//Iterator constructor
template<typename T>
List<T>::Iterator::Iterator(Node<T>* node) :current(node)
{
    
}

//Iterator destructor
template<typename T>
List<T>::Iterator::~Iterator() {}

//operator* for Iterator
template<typename T>
T& List<T>::Iterator::operator*() const
{
    return current-> data;
}

//operator-> for Iterator
template<typename T>
T* List<T>::Iterator::operator->() const
{
    return &(current -> data);
}

//prefix operator++ for Iterator
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
    if (current) current = current->next;
    return *this;
}

//postfix operator++ for Iterator
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

//prefix operator-- for Iterator
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
    if (current) current = current->prev;
    return *this;
}

//postfix operator-- for Iterator
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

//operator== for Iterator
template<typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{
    return current == other.current;
}

//operator!= for Iterator
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
    return current != other.current;
}

//begin()
template<typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(head);
}

//end()
template<typename T>
typename List<T>::Iterator List<T>::end() const
{
    return Iterator(nullptr);
}

template class List<int>;
template class List<float>;
template class List<double>;
template class List<char>;