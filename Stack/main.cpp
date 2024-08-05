#include "StackL.h"
#include "StackV.h"

int main()
{
    StackV<int> stackv;
    stackv.push(7);
    stackv.push(5);
    stackv.push(4);
    stackv.push(11);
    std::cout << stackv.top() << std::endl;
    stackv.pop();
    std::cout << stackv.top() << std::endl;
    
    while(!stackv.empty())
    {
        std::cout << stackv.top() << " ";
        stackv.pop();
    }
    
    std::cout << std::endl << "=================" << std::endl;
    StackL<int> stackl;
    stackl.push(12);
    stackl.push(4);
    stackl.push(9);
    stackl.push(8);
    std::cout << stackl.top() << std::endl;
    stackl.pop();
    std::cout << stackl.top() << std::endl;
    
    while(!stackl.empty())
    {
        std::cout << stackl.top() << " ";
        stackl.pop();
    }
    
    
    return 0;
}