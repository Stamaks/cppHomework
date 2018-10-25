///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains pseudo-implementation part of bidirectional list structure 
/// template declared in the file's h-counterpart
///
/// © Sergey Shershakov 2015–2017.
///
/// This code is for educational purposes of the course "Algorithms and Data 
/// Structures" provided by the School of Software Engineering of the Faculty 
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>



//==============================================================================
// class BidiList<T>::Node
//==============================================================================


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::Node::insertAfterInternal(Node* insNode)
{
    // here we use "this" keyword for enhancing the fact we deal with curent node!
    Node* afterNode = this->_next;      // an element, which was after node

    this->_next = insNode;
    insNode->_prev = this;
    insNode->_next = afterNode;
    afterNode->_prev = insNode;

    return insNode;
}

//==============================================================================
// class BidiList<T>
//==============================================================================



template <typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}


template <typename T>
void BidiLinkedList<T>::clear()
{
    Node* currentNode = _head;

    while (currentNode != _tail)
    {
        currentNode = currentNode->_next;
        delete currentNode->_prev;
    }

    // Удаляем последний нод
    delete _tail;
}

template <typename T>
size_t BidiLinkedList<T>::getSize()
{
    if (_size == NO_SIZE)
        calculateSize();

    return _size;
}


template <typename T>
void BidiLinkedList<T>::calculateSize()
{
    _size = 0;
    Node* currentNode = _head;
    while (currentNode)
    {
        ++_size;
        currentNode = currentNode->_next;
    }
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::getLastNode() const
{
    // Const?..
    return _tail;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);

    // inserts after last node, size if going to e invalidated there
    return insertNodeAfter(_tail, newNode);
}


// возможно, этот метод даже не надо изменять
template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::insertNodeAfter(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    // check if a node is alone
    if (insNode->_next || insNode->_prev)
        throw std::invalid_argument("`insNode` has siblings. It seems it isn't free");

    // if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
    {
        _head = insNode;
        _tail = insNode;
    }
    else
    {
        node->insertAfterInternal(insNode);

        // If there is no one on the right from the inserted, update _tail.
         if (!insNode->_next)
            _tail = insNode;
    }

    invalidateSize();

    return insNode;
}

// Здесь должна быть реализация метода BidiLinkedList<T>::insertNodesAfter().
template<typename T>
void
BidiLinkedList<T>::insertNodesAfter(Node* node, Node* begNode, Node* endNode)
{
    if (!begNode || !endNode)
        throw std::invalid_argument("BegNode or endNode is nullptr");

    if (!begNode->_prev || !endNode->_next)
        throw std::invalid_argument("It seems nodes aren't free!");

    if (!node)
    {
        _head = begNode;
        _tail = endNode;
    }
    else
    {
        Node* nodeAfter = node->_next;

        node->_next = begNode;
        begNode->_prev = node;

        // Если надо добавлять не в конец
        if (nodeAfter)
        {
            endNode->_next = nodeAfter;
            nodeAfter->_prev = endNode;
        }

        if (!endNode->_next)
            _tail = endNode;
    }

    invalidateSize();
}


// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    // check if a node is alone
    if (insNode->_next || insNode->_prev)
        throw std::invalid_argument("`insNode` has siblings. It seems it isn't free");

    if (!node)
    {
        _head = insNode;
        _tail = insNode;
    }
    else
    {
        // Если нод, перед которым нужно вставить - это голова
        if (!node->_prev)
        {
            node->_prev = insNode;
            insNode->_next = node;
        }
        else
        {
            Node* nodePrev = node->_prev;

            nodePrev->_next = insNode;
            insNode->_prev = nodePrev;
        }

        if (!insNode->_prev)
            _head = insNode;
    }

    invalidateSize();
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* begNode, Node* endNode)
{
    if (!begNode || !endNode)
        throw std::invalid_argument("BegNode or endNode is nullptr");

    if (!begNode->_prev || !endNode->_next)
        throw std::invalid_argument("It seems nodes aren't free!");

    if (!node)
    {
        _head = begNode;
        _tail = endNode;
    }
    else
    {
        Node* nodeBef = node->_prev;

        node->_prev = endNode;
        endNode->_next = node;

        // Если надо добавлять не в начало
        if (nodeBef)
        {
            begNode->_prev = nodeBef;
            nodeBef->_next = begNode;
        }

        if (!begNode->_prev)
            _head = begNode;
    }
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* begNode, Node* endNode)
{
    if (!begNode || !endNode)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");

    // Если ноды не включают весь список
    if (begNode->getPrev() || endNode->getNext())
    {
        if (begNode->getPrev() && endNode->getNext())
        {
            // Предыдущий элемент у begNode указывает на следующий элемент у endNode
            begNode->getPrev()->getNext() = endNode->getNext();

            // Следующий элемент у endNode указывает на предыдущий элемент у begNode
            endNode->getNext()->getPrev() = begNode->getPrev();

            begNode->getPrev() = nullptr;
            endNode->getNext() = nullptr;
        }
        else if (!begNode->getPrev()) // Если begNode - начало списка
        {
            // Следующий нод после endNode имеет nullptr ссылку на предыдущий
            endNode->getNext()->getPrev() = nullptr;

            _head = endNode->getNext();
            endNode->getNext() = nullptr;
        }
        else // Если endNode - конец списка
        {
            begNode->getPrev()->getNext() = nullptr;

            _tail = begNode->getPrev();
            begNode->getPrev() = nullptr;
        }
    }

    invalidateSize();

}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
    // Используем уже написанное решение
    BidiLinkedList::cutNodes(node, node);

    return node;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    if (!startFrom)
        return nullptr;

    while (startFrom)
    {
        if (*(startFrom->getValue()) == *val)
            return startFrom;

        startFrom = startFrom->getNext();
    }

    return nullptr;     // not found
}



// TODO: удалить повторяющийся код?
template <typename T>
typename BidiLinkedList<T>::Node** 
    BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    // try not to use any standard containers. create an array only when found a first occurrence
    Node** res = nullptr;
    size = 0;
    int nodesPassed = 0;
    
    while (startFrom)
    {
        if (*(startFrom->getValue()) == *val)
        {
            if (!res)
            {
                res = new Node*[this->getSize() - nodesPassed];
            }

            res[size] = startFrom;
            ++size;
        }

        startFrom = startFrom->getNext();
        ++nodesPassed;
    }

    return res;
}

// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS

template <typename T>
typename BidiLinkedList<T>::Node**  
BidiLinkedList<T>::cutAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    Node** res = nullptr;
    size = 0;
    int nodesPassed = 0;

    while (startFrom)
    {
        if (*(startFrom->getValue()) == *val)
        {
            if (!res)
            {
                res = new Node*[this->getSize() - nodesPassed];
            }

            res[size] = cutNode(startFrom);
            ++size;
        }

        startFrom = startFrom->getNext();
        ++nodesPassed;
    }

    return res;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::begin()
{
    iterator it(_head);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::end()
{
    iterator it(_tail->_next);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cbegin() const
{
    const_iterator it(_head);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cend() const
{
    const_iterator it(_tail->_next);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rbegin()
{
    reverse_iterator it(_tail);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rend()
{
    reverse_iterator it(_head->_prev);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::crbegin() const
{
    const_reverse_iterator it(_tail);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::crend() const
{
    const_reverse_iterator it(_head->_prev);
    return it;
}


//==============================================================================
// class iterator<T>
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::iterator& BidiLinkedList<T>::iterator::operator++()
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::iterator::operator++(int)
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::iterator& BidiLinkedList<T>::iterator::operator--()
{
    // Если нам надо декрементировать указатель на пост-последний элемент
    if (pointer == nullptr)
    {
        pointer = _tail;
        return *this;
    }

    if (pointer->_prev == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::iterator::operator--(int)
{
    if (pointer->_prev == nullptr)
        throw std::logic_error("Iterator out of range!");

    iterator it(*this);
    --(*this);
    return it;
}

template<typename T>
bool BidiLinkedList<T>::iterator::operator==(const iterator& it) const
{
    return it.pointer == pointer;
}

template<typename T>
bool BidiLinkedList<T>::iterator::operator!=(const iterator& it) const
{
    return it.pointer != pointer;
}


//==============================================================================
// class const_iterator<T>
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::const_iterator& BidiLinkedList<T>::const_iterator::operator++()
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::const_iterator::operator++(int)
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    const_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator& BidiLinkedList<T>::const_iterator::operator--()
{
    if (pointer->_prev == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::const_iterator::operator--(int)
{
    if (pointer->_prev == nullptr)
        throw std::logic_error("Iterator out of range!");

    const_iterator it(*this);
    --(*this);
    return it;
}

template<typename T>
bool BidiLinkedList<T>::const_iterator::operator==(const const_iterator& it) const
{
    return it.pointer == pointer;
}

template<typename T>
bool BidiLinkedList<T>::const_iterator::operator!=(const const_iterator& it) const
{
    return it.pointer != pointer;
}


//==============================================================================
// class reverse_iterator<T>
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::reverse_iterator& BidiLinkedList<T>::reverse_iterator::operator++()
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::reverse_iterator::operator++(int)
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    reverse_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator& BidiLinkedList<T>::reverse_iterator::operator--()
{
    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::reverse_iterator::operator--(int)
{
    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    reverse_iterator it(*this);
    --(*this);
    return it;
}

template<typename T>
bool BidiLinkedList<T>::reverse_iterator::operator==(const BidiLinkedList::reverse_iterator& it) const
{
    return it.pointer == pointer;
}

template<typename T>
bool BidiLinkedList<T>::reverse_iterator::operator!=(const BidiLinkedList::reverse_iterator& it) const
{
    return it.pointer != pointer;
}


//==============================================================================
// class const_reverse_iterator<T>
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator& BidiLinkedList<T>::const_reverse_iterator::operator++()
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::const_reverse_iterator::operator++(int)
{
    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    const_reverse_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator& BidiLinkedList<T>::const_reverse_iterator::operator--()
{
    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::const_reverse_iterator::operator--(int)
{
    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    const_reverse_iterator it(*this);
    --(*this);
    return it;
}

template<typename T>
bool BidiLinkedList<T>::const_reverse_iterator::operator==(const BidiLinkedList::const_reverse_iterator& it) const
{
    return it.pointer == pointer;
}

template<typename T>
bool BidiLinkedList<T>::const_reverse_iterator::operator!=(const BidiLinkedList::const_reverse_iterator& it) const
{
    return it.pointer != pointer;
}
#endif // IWANNAGET10POINTS
