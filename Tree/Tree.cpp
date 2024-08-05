#include "Tree.h"

template <typename T>
Tree<T>::Tree(): root(nullptr)
{
    
}

template <typename T>
Tree<T>::~Tree()
{
    DelTree(root);
}

template <typename T>
void Tree<T>::Insert(int val)
{
    root = InsertR(root, val);
}

template <typename T>
void Tree<T>::InorderTrav()
{
    Inorder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::PostorderTrav()
{
    Postorder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::PreorderTrav()
{
    Preorder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::Leveloreder()
{
    if(root == nullptr)
    {
        return;
    }
    std::queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<T>* curr = q.front();
        std::cout << curr->data << " ";
        q.pop();
        
        if(curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr) 
        {
            q.push(curr->right);
        }
    }
    std::cout << std::endl;
}

template <typename T>
TreeNode<T>* Tree<T>::InsertR(TreeNode<T>* node, int val)
{
    if(node == nullptr)
    {
        return new TreeNode<T>(val);
    }
    
    if(val < node->data)
    {
        node->left = InsertR(node->left, val);
    }
    
    else if (val > node->data)
    {
        node->right = InsertR(node->right, val);
    }
    
    return node;
}

template <typename T>
void Tree<T>::Inorder(TreeNode<T>* node)
{
    if(node == nullptr)
    {
        return;
    }
    Inorder(node->left);
    std::cout << node->data << " ";
    Inorder(node->right);
    
}

template <typename T>
void Tree<T>::Preorder(TreeNode<T>* node)
{
    if(node == nullptr)
    {
        return;
    }
    std::cout << node->data << " ";
    
    Preorder(node->left);
    
    Preorder(node->right);
    
}

template <typename T>
void Tree<T>::Postorder(TreeNode<T>* node)
{
    if(node == nullptr)
    {
        return;
    }
    
    Postorder(node->left);
    
    Postorder(node->right);
    
    std::cout << node->data << " ";
   
    
}

template <typename T>
void Tree<T>::DelTree(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    DelTree(node->left);
    DelTree(node->right);
    delete node;
}
    
template class Tree<int>;
template class Tree<double>;
template class Tree<char>;