#include <iostream>

#include "Tree.h"

int main()
{
    Tree<int> tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(8);
    tree.Insert(1);
    tree.Insert(9);
    tree.InorderTrav();
    tree.PreorderTrav();
    tree.PostorderTrav();
    tree.Levelorder();
    return 0;
}