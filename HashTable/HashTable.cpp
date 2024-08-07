#include "HashTable.h"

//Constructor
template <typename Key, typename Value>
HashTable<Key,Value>::HashTable() : table(2)
{
    
}

//Destructor
template <typename Key, typename Value>  
HashTable<Key,Value>::~HashTable() {}

//HashFunc()
template <typename Key, typename Value>
std::size_t HashTable<Key,Value>::HashFunc(const Key& key, const std::vector<std::list<std::pair<Key,Value>>>& tab) const
{
    return std::hash<Key>{}(key) % tab.size();
}

//Resize()
template <typename Key, typename Value>
void HashTable<Key,Value>::Resize()
{
  
    std::vector<std::list<std::pair<Key,Value>>> newTable(table.size() * 2);
    for(auto& list : table)
    {
        for(auto& node : list)
        {
            int newId = HashFunc(node.first, newTable);
            newTable[newId].emplace_back(node);
        }
    }
    table = std::move(newTable);
}

//Insert()
template <typename Key, typename Value>
void HashTable<Key,Value>::Insert(const std::pair<Key,Value>& pair)
{
    int id = HashFunc(pair.first, table);
    for(auto it = table[id].begin(); it != table[id].end(); ++it)
    {
        if(pair.first == it -> first)
        {
            it->second = pair.second;
            return;
        }
    }
    table[id].emplace_back(pair);
    if(table[id].size() > table.size())
    {
        Resize();
    }
}

//Find
template <typename Key, typename Value>
typename HashTable<Key, Value>::Iterator HashTable<Key,Value>::Find(const Key& key)
{
    int id = HashFunc(key, table);
    auto vecIt = table.begin() + id;
    auto listIt = std::find_if(vecIt->begin(),vecIt->end(),[&key](const std::pair<Key,Value>& elem)
                                                        {
                                                           return elem.first == key;  
                                                        });
    if(listIt != vecIt->end())
    {
        return Iterator(vecIt, listIt, table.end());
    }
    return Iterator(table.end(), vecIt->end(), table.end());
}

//Remove
template <typename Key, typename Value>
void HashTable<Key,Value>::Remove(const Key& key)
{
    int id = HashFunc(key, table);
    for(auto it = table[id].begin(); it != table[id].end(); ++it)
    {
        if(it->first == key)
        {
            table[id].erase(it);
            return;
        }
    }
}

//Print
template <typename Key, typename Value>
void HashTable<Key,Value>::Print() const
{
    for(auto list : table)
    {
        for(auto node : list)
        {
            std::cout << node.second << "  ";
        }
        std::cout << std::endl;
    }
}

//begin()
template <typename Key, typename Value>
typename HashTable<Key, Value>::Iterator HashTable<Key, Value>::begin() 
{
    auto vecIt = table.begin();
    while (vecIt != table.end() && vecIt->empty()) 
    {
        ++vecIt;
    }

    if (vecIt == table.end()) 
    {
        return Iterator(table.end(), table.end()->end(), table.end());
    }

    auto listIt = vecIt->begin();
    return Iterator(vecIt, listIt, table.end());
}

//end
template <typename Key, typename Value>
typename HashTable<Key, Value>::Iterator HashTable<Key, Value>::end()
{
    return Iterator(table.end(), table.end()->end(), table.end());
}


//Default constructor for Iterator
template<typename Key, typename Value>
HashTable<Key,Value>::Iterator::Iterator() : vectorIt(), listIt(), endIt() {}

//Param constructor for Iterator
template<typename Key, typename Value>
HashTable<Key,Value>::Iterator::Iterator(vector_iterator vectorIt,list_iterator listIt, vector_iterator endIt):
                                    vectorIt(vectorIt), listIt(listIt),endIt(endIt) {}
                                    
//GoToNext()                    
template <typename Key,typename Value>
void HashTable<Key,Value>::Iterator::GoToNext()
{
    while(vectorIt != endIt && listIt == vectorIt->end())
    {
        ++vectorIt;
        if(vectorIt != endIt)
        {
            listIt = vectorIt->begin();
        }
    }
}

//operator* for Iterator
template <typename Key,typename Value>
std::pair<Key,Value>& HashTable<Key,Value>::Iterator::operator*()
{
    return *listIt;
}

//operator-> for Iterator
template <typename Key,typename Value>
std::pair<Key,Value>* HashTable<Key,Value>::Iterator::operator->()
{
    return &(*listIt);
}

//prefix operator++ for Iterator
template <typename Key,typename Value>
typename HashTable<Key,Value>::Iterator& HashTable<Key,Value>::Iterator::operator++()
{
    ++listIt;
    GoToNext();
    return *this;
}

//postfix operator++ for Iterator
template <typename Key,typename Value>
typename HashTable<Key,Value>::Iterator HashTable<Key,Value>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

//operator== for Iterator
template <typename Key,typename Value>
bool HashTable<Key,Value>::Iterator::operator==(const Iterator& other) const
{
    return vectorIt == other.vectorIt && listIt == other.listIt;
}

//operator!= for Iterator
template <typename Key,typename Value>
bool HashTable<Key,Value>::Iterator::operator!=(const Iterator& other) const
{
    return vectorIt != other.vectorIt || listIt != other.listIt;
}

template class HashTable<int, int>;
template class HashTable<std::string, int>;
template class HashTable<std::string, double>;


