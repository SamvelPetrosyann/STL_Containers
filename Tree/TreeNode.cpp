#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(T val): data(val),left(nullptr),right(nullptr)
{
        
}

template <typename T>
TreeNode<T>::~TreeNode()
{
        
}
template class TreeNode<int>;
template class TreeNode<double>;
template class TreeNode<char>;