#include <iostream>

#include "Vector.h"

int main()
{
    Vector<int> v = {1, 2, 3, 4, 5};

    std::cout << v.at(3) << std::endl;
    v.erase(v.begin() + 3);
    v.PrintVector();


    return 0;
}