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
    return this->_iHead;
}

template<class T>
void NiceStack<T>::push(const T &newelement)
{
    if (this->_iHead == this->_capacity)
    {
        throw new std::out_of_range("Index out of range!");
    }

    if (_iHead == 0) {
        this->_storage[_iHead] = std::make_pair(newelement, newelement);
    }
    else
    {
        if (newelement < this->_storage[_iHead-1].second)
        {
            this->_storage[_iHead] = std::make_pair(newelement, newelement);
        }
        else
        {
            this->_storage[_iHead] = std::make_pair(newelement, this->_storage[_iHead-1].second);
        }
    }

    ++this->_iHead;
}

template<class T>
T NiceStack<T>::pop()
{
    if (this->_iHead == 0)
    {
        throw new std::out_of_range("Index out of range!");
    }

    --this->_iHead;     
    return this->_storage[this->_iHead].first;
}

template<class T>
const T &NiceStack<T>::top() const
{
    return this->_storage[this->_iHead].first;
}

template<class T>
const T &NiceStack<T>::getMinimum() const
{
    return this->_storage[this->_iHead].second;
}



