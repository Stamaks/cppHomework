#include <iostream>

template<class T>
NiceStack<T>::NiceStack(size_t capacity)
{
    _storage.reserve(capacity);
    _iHead = 0;
    _capacity = capacity;
}


template<class T>
NiceStack<T>::~NiceStack() {}

template<class T>
size_t NiceStack<T>::size() const
{
    return _iHead;
}

template<class T>
void NiceStack<T>::push(const T &newelement)
{
    if (_iHead == _capacity)
    {
        throw std::out_of_range("Index out of range!");
    }

    // If queue is empty or new new element is less than current minimum
    if (_iHead == 0 || newelement < _storage[_iHead-1].second)
    {
        _storage[_iHead] = std::make_pair(newelement, newelement);
    }
    else
    {
        _storage[_iHead] = std::make_pair(newelement, _storage[_iHead-1].second);
    }

    ++_iHead;
}

template<class T>
T NiceStack<T>::pop()
{
    if (_iHead == 0)
    {
        throw new std::out_of_range("Index out of range!");
    }

    --_iHead;
    return _storage[_iHead].first;
}

template<class T>
const T &NiceStack<T>::top() const
{
    return _storage[_iHead - 1].first;
}

template<class T>
const T &NiceStack<T>::getMinimum() const
{
    if (_iHead == 0)
        throw std::out_of_range("Can't get min!");

    return _storage[_iHead - 1].second;
}



