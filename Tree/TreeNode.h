#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>

template <typename T>
class TreeNode
{
public:  
    T data;

    TreeNode* left;

    TreeNode* right;

    TreeNode(T val);
   
    ~TreeNode();
    
};

#endif //TREENODE_H