#include <algorithm>

#include "NiceStack.h"

template<class T>
NiceQueue<T>::NiceQueue(size_t capacity) : _inStack(capacity), _outStack(capacity)
{
    _capacity = capacity;
}

template<class T>
NiceQueue<T>::~NiceQueue() {}

template<class T>
size_t NiceQueue<T>::size() const
{
    return _inStack.size() + _outStack.size();
}

template<class T>
void NiceQueue<T>::enq(const T &newElement)
{
    if (this->size() == this->_capacity)
    {
        throw new std::out_of_range("Index out of range!");
    }

    _inStack.push(newElement);
}

template<class T>
T NiceQueue<T>::deq()
{
    if (this->size() == 0)
    {
        throw new std::out_of_range("Index out of range!");
    }

    if (_outStack.size() == 0)
    {
        for (int i = 0; i < _inStack.size(); i++)
        {
            _outStack.push(_inStack.pop());
        }
    }

    return _outStack.pop();
}

template<class T>
T NiceQueue<T>::getMinimum()
{
    return std::min(_inStack.getMinimum(), _outStack.getMinimum());
}


