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
    insNode->_prev = this;
    insNode->_next = this->_next;

    if (this->_next)
    {
        this->_next->_prev = insNode;
    }

    this->_next = insNode;


    return insNode;
}

//==============================================================================
// class BidiList<T>
//==============================================================================

template <typename T>
BidiLinkedList<T>::BidiLinkedList(const BidiLinkedList& list)
{
    Node* currentNode = list.getHeadNode();
    Node* prevNewNode = nullptr;

    // Если нам передали не пустой список
    if (currentNode)
    {
        _head = new Node(currentNode->_val);
        _tail = _head;
        currentNode = currentNode->_next;
        prevNewNode = _head;
    }

    while (currentNode)
    {
        Node* newNode = new Node(currentNode->_val);
        newNode->_prev = prevNewNode;
        prevNewNode->_next = newNode;
        _tail = newNode;
        prevNewNode = newNode;
    }
}

template <typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}

template <typename T>
BidiLinkedList<T>& BidiLinkedList<T>::operator=(const BidiLinkedList<T>& list)
{
    BidiLinkedList<T> tmp(list);
    swap(*this, tmp);

    return *this;
}

template <typename T>
void BidiLinkedList<T>::swap(BidiLinkedList<T>& first, BidiLinkedList<T>& second)
{
    std::swap(first.getHeadNode(), second.getHeadNode());
    std::swap(first.getLastNode(), second.getLastNode());
    first.invalidateSize();
    second.invalidateSize();
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

    _tail = nullptr;
    _head = nullptr;
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
    return _tail;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);

    // Вставляем после последнего нода (это дефолтный путь)
    return insertNodeAfter(nullptr, newNode);
}

template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::insertNodeAfter(Node* node, Node* insNode)
{
    insertNodesAfter(node, insNode, insNode);

    return insNode;
}

template<typename T>
void
BidiLinkedList<T>::insertNodesAfter(Node* node, Node* begNode, Node* endNode)
{
    // Если на вход пришел nullptr вместо begNode или endNode
    if (!begNode || !endNode)
        throw std::invalid_argument("BegNode or endNode is nullptr");

    // Проверяем, что цепочка существует сама по себе
    if (begNode->_prev || endNode->_next)
        throw std::invalid_argument("It seems nodes aren't free!");

    // Если нод nullptr или он - хвост - вставляем в конец
    if (!node || node == _tail)
    {
        // Если список вообще пуст
        if (_head == nullptr)
        {
            _head = begNode;
            _tail = endNode;
        }
        else
        {
            _tail->_next = begNode;
            begNode->_prev = _tail;
            _tail = endNode;
        }
    }
    else // Если вставляем не в конец
    {
        Node* nodeAfter = node->_next;

        node->_next = begNode;
        begNode->_prev = node;
        endNode->_next = nodeAfter;
        nodeAfter->_prev = endNode;
    }

    invalidateSize();
}


#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    insertNodesBefore(node, insNode, insNode);

    return insNode;
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* begNode, Node* endNode)
{
    // Если на вход пришел nullptr вместо begNode или endNode
    if (!begNode || !endNode)
        throw std::invalid_argument("BegNode or endNode is nullptr");

    // Проверяем, что цепочка существует сама по себе
    if (begNode->_prev || endNode->_next)
        throw std::invalid_argument("It seems nodes aren't free!");

    // Если нод - nullptr или он - голова, вставляем в начало
    if (!node || node == _head)
    {
        // Если список вообще пустой
        if (_head == nullptr)
        {
            _head = begNode;
            _tail = endNode;
        }
        else
        {
            _head->_prev = endNode;
            endNode->_next = _head;
            _head = begNode;
        }
    }
    else  // Если надо добавлять не в начало
    {
        Node* nodeBef = node->_prev;

        node->_prev = endNode;
        endNode->_next = node;
        begNode->_prev = nodeBef;
        nodeBef->_next = begNode;
    }

    invalidateSize();
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* begNode, Node* endNode)
{
    // Если какой-нибудь из нодов - nullptr
    if (!begNode || !endNode)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");

    // Если цепочка, которую нужно вырезать, это весь лист
    if (!begNode->_prev && !endNode->_next)
    {
        _head = nullptr;
        _tail = nullptr;
    }

    // Если цепочка находится где-то внутри листа (не с какого-либо краю)
    if (begNode->_prev && endNode->_next)
    {
        // Предыдущий элемент у begNode указывает на следующий элемент у endNode
        begNode->_prev->_next = endNode->_next;

        // Следующий элемент у endNode указывает на предыдущий элемент у begNode
        endNode->_next->_prev = begNode->_prev;

        // Обнуляем ссылки по краям вырезанной цепочки
        begNode->_prev = nullptr;
        endNode->_next = nullptr;
    }

    // Если цепочка находится с левого края (begNode - начало списка)
    if (!begNode->_prev && endNode->_next)
    {
        // Теперь голова - следующий эл-т у endNode
        _head = endNode->_next;
        _head->_prev = nullptr;

        // Обнуляем ссылку с правого края вырезанной цепочки
        endNode->_next = nullptr;
    }

    // Если цепочка находится с правого края (endNode - конец списка)
    if (begNode->_prev && !endNode->_next)
    {
        // Теперь хвост - предыдущий эл-т у begNode
        _tail = begNode->_prev;
        _tail->_next = nullptr;

        // Обнуляем ссылку с левого края вырезанной цепочки
        begNode->_prev = nullptr;
    }

    invalidateSize();
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
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
        if (startFrom->_val == val)
            return startFrom;

        startFrom = startFrom->_next;
    }

    return nullptr;     // not found
}

template <typename T>
typename BidiLinkedList<T>::Node** 
    BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    Node** res = nullptr;
    size = 0;
    int nodesPassed = 0;
    
    while (startFrom)
    {
        if (startFrom->_val == val)
        {
            if (!res)
            {
                res = new Node*[this->getSize() - nodesPassed];
            }

            res[size] = startFrom;
            ++size;
        }

        startFrom = startFrom->_next;
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
        if (startFrom->_val == val)
        {
            if (!res)
            {
                res = new Node*[this->getSize() - nodesPassed];
            }

            Node* next = startFrom->_next;
            res[size] = cutNode(startFrom);
            ++size;
            startFrom = next;
        }
        else
        {
            startFrom = startFrom->getNext();
            ++nodesPassed;
        }
    }

    invalidateSize();

    return res;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::begin()
{
    iterator it(_head, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::end()
{
    if (_tail)
    {
        iterator it(_tail->_next, this);
        return it;
    }

    iterator it(nullptr, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cbegin()
{
    const_iterator it(_head, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cend()
{
    if (_tail)
    {
        const_iterator it(_tail->_next, this);
        return it;
    }

    const_iterator it(nullptr, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rbegin()
{
    reverse_iterator it(_tail, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rend()
{
    if (_head)
    {
        reverse_iterator it(_head->_prev, this);
        return it;
    }

    reverse_iterator it(nullptr, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::crbegin()
{
    const_reverse_iterator it(_tail, this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::crend()
{
    if (_head)
    {
        const_reverse_iterator it(_head->_prev, this);
        return it;
    }

    const_reverse_iterator it(nullptr, this);
    return it;
}


//==============================================================================
// class iterator<T>
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::iterator& BidiLinkedList<T>::iterator::operator++()
{
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::iterator::operator++(int)
{
    iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::iterator& BidiLinkedList<T>::iterator::operator--()
{
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    // Если нам надо декрементировать указатель на пост-последний элемент
    if (pointer == nullptr)
    {
        pointer = list->_tail;
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
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::const_iterator::operator++(int)
{
    const_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator& BidiLinkedList<T>::const_iterator::operator--()
{
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    // Если нам надо декрементировать указатель на пост-последний элемент
    if (pointer == nullptr)
    {
        pointer = list->_tail;
        return *this;
    }

    if (pointer->_prev == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::const_iterator::operator--(int)
{
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
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::reverse_iterator::operator++(int)
{
    reverse_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator& BidiLinkedList<T>::reverse_iterator::operator--()
{
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
    {
        pointer = list->_head;
        return *this;
    }

    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::reverse_iterator::operator--(int)
{
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
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_prev;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::const_reverse_iterator::operator++(int)
{
    const_reverse_iterator it(*this);
    ++(*this);
    return it;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator& BidiLinkedList<T>::const_reverse_iterator::operator--()
{
    if (list->_head == nullptr)
        throw std::logic_error("Iterator out of range!");

    if (pointer == nullptr)
    {
        pointer = list->_head;
        return *this;
    }

    if (pointer->_next == nullptr)
        throw std::logic_error("Iterator out of range!");

    pointer = pointer->_next;
    return *this;
}

template<typename T>
typename BidiLinkedList<T>::const_reverse_iterator BidiLinkedList<T>::const_reverse_iterator::operator--(int)
{
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
