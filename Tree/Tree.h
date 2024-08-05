#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <queue>

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;
public:
    Tree();
   
    
    ~Tree();
  
    
    void Insert(int val);
  
    void InorderTrav();

    void PostorderTrav();

    void PreorderTrav();
    
    void Levelorder();

private:

    TreeNode<T>* InsertR(TreeNode<T>* node, int val);
    
    void Inorder(TreeNode<T>* node);
    
    void Preorder(TreeNode<T>* node);

    void Postorder(TreeNode<T>* node);
   
    void DelTree(TreeNode<T>* node);
   
};


#endif //TREE_H