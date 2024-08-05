template <typename T>
StackV<T>::StackV() {}

template <typename T>
StackV<T>::~StackV() {}

template <typename T>
void StackV<T>::push(const T& elem)
{
    vec.push_back(elem);
}

template <typename T>
void StackV<T>::pop()
{
    if(vec.empty())
    {
        return;
    }
    vec.pop_back();
}

template <typename T>
T StackV<T>::top() const
{
    if(vec.empty())
    {
        std::cout << "stack is empty" << std::endl;
        return -1;
    }
    return vec[vec.size() - 1];
}

template <typename T>
bool StackV<T>::empty() const
{
    return vec.empty();
}

template class StackV<int>;
template class StackV<double>;
template class StackV<char>;