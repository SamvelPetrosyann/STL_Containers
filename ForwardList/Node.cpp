#include "Node.h"

template<typename T>
Node<T>::Node(T data) : data(data), next(nullptr)
{

}

template<typename T>
Node<T>::~Node()
{

}

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<char>;