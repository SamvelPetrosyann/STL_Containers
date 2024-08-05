#include "ForwardList.h"

//Constructor
template<typename T>
ForwardList<T>::ForwardList() :head(nullptr)
{
    
}

//Constructor initializer_list
template<typename T>
ForwardList<T>::ForwardList(std::initializer_list<T> init) : head(nullptr)
{
    for(auto elem : init)
    {
        push_front(elem);
    }
    Reverse();
}

template<typename T>
ForwardList<T>::~ForwardList()
{
    while (head != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

//Copy Constructor
template<typename T>
ForwardList<T>::ForwardList(const ForwardList& other)
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
    }
}

//operator=
template<typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other)
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
        }
    }
    return *this;
}

//Move Constructor
template <typename T>
ForwardList<T>::ForwardList(ForwardList&& other) : head(other.head)
{
    other.head = nullptr;
}

//Move operator=
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList&& other)
{
    if(this != &other)
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

//push_front
template<typename T>
void ForwardList<T>::push_front(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

//push_back
template<typename T>
void ForwardList<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

//Reverse
template<typename T>
void ForwardList<T>::Reverse() 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return;
    }
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* foll = nullptr;
    
    while(curr != nullptr)
    {
        foll = curr->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }
    head = prev;

}

//empty()
template <typename T>
bool ForwardList<T>::empty()
{
    return head == nullptr;
}

//front()
template <typename T>
T ForwardList<T>::front()
{
    return head->data;
}

//Print
template<typename T>
void ForwardList<T>::Print() const
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << '\t';
        current = current->next;
    }
}

//Constructor for Iterator
template <typename T>
ForwardList<T>::Iterator::Iterator(Node<T>* node) : current(node)
{
    
}

//operator* for Iterator
template <typename T>
T& ForwardList<T>::Iterator::operator*() const
{
    return current->data;
}

//operator -> for Iterator
template <typename T>
T* ForwardList<T>::Iterator::operator->() const
{
    return &(current->data);
}

//prefix operator ++ for Iterator
template <typename T>
typename ForwardList<T>::Iterator& ForwardList<T>::Iterator::operator++() 
{
    current = current->next; 
    return *this;
}

//postfix operator ++ for Iterator
template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::Iterator::operator++(int) 
{
    Node<T>* temp = current;
    current = current->next; 
    return temp;
}

//operator == for Iterator
template <typename T>
bool ForwardList<T>::Iterator::operator==(const Iterator& other) const
{
    return current == other.current;
}

//operator != for Iterator
template <typename T>
bool ForwardList<T>::Iterator::operator!=(const Iterator& other) const
{
    return current != other.current;
}

//begin()
template<typename T>
typename ForwardList<T>::Iterator ForwardList<T>::begin() const
{
    return Iterator(head);
}

//end()
template<typename T>
typename ForwardList<T>::Iterator ForwardList<T>::end() const 
{
    return Iterator(nullptr);
}

template class ForwardList<int>;
template class ForwardList<float>;
template class ForwardList<double>;
template class ForwardList<char>;