#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <initializer_list>

template <typename Key, typename Value>
class HashTable
{
public:
    using vector_iterator = typename std::vector<std::list<std::pair<Key,Value>>>::iterator;
    using list_iterator = typename std::list<std::pair<Key,Value>>::iterator;
private:    
    std::vector<std::list<std::pair<Key,Value>>> table;
    
    std::size_t HashFunc(const Key& key, const std::vector<std::list<std::pair<Key,Value>>>& tab) const ;

    void Resize();

public:
    
    HashTable();

    ~HashTable();
    
    void Insert(const std::pair<Key,Value>& pair);
    
    void Print() const;
    
    void Remove(const Key& key);
    class Iterator
    {
    private:    
        vector_iterator vectorIt;
        list_iterator listIt;
        vector_iterator endIt;
        void GoToNext();
    public:
        Iterator();
        Iterator(vector_iterator vectorIt, list_iterator listIt, vector_iterator endIt);
        std::pair<Key,Value>& operator*();
        std::pair<Key,Value>* operator->();
        Iterator& operator++();
        Iterator operator++(int);
        
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        friend class HashTable<Key, Value>;
    };
    Iterator begin();
    Iterator end();
    Iterator Find(const Key& key);
    
    
};

#endif // HASHTABLE_H