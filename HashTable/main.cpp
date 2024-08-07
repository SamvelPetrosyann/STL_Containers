#include "HashTable.cpp"

int main()
{
    HashTable<std::string, int> ht;
    ht.Insert(std::make_pair("one", 10));
    ht.Insert(std::make_pair("two", 20));
    ht.Insert(std::make_pair("three", 30));
    ht.Insert(std::make_pair("four", 40));
    ht.Insert(std::make_pair("five", 50));
    ht.Insert(std::make_pair("six", 60));
    
    auto it = ht.Find("five");
    if(it == ht.end())
    {
        std::cout <<"not found" <<std::endl;
    }
    else
    {
        std::cout << "Found (" << it->first << "," << it->second << ")"<< std::endl;
    }
    ht.Remove("six");
    ht.Print();
    ht1.Print();
    return 0;
}