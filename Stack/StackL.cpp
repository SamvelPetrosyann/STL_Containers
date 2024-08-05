template <typename T>
StackL<T>::StackL() {}

template <typename T>
StackL<T>::~StackL() {}

template <typename T>
void StackL<T>::push(const T& elem)
{
    list.push_back(elem);
}

template <typename T>
void StackL<T>::pop()
{
    if(list.empty())
    {
        return;
    }
    list.pop_back();
}

template <typename T>
T StackL<T>::top() const
{
    if(list.empty())
    {
        std::cout << "stack is empty" << std::endl;
        return -1;
    }
    return list.back();
}

template <typename T>
bool StackL<T>::empty() const
{
    return list.empty();
}

template class StackL<int>;
template class StackL<double>;
template class StackL<char>;