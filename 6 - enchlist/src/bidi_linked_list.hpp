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

        // If there is no one on the right (C'MON WE'VE ALREADY CHECKED IT!!!) from the inserted, update _tail.
        // if (!insNode->_next)
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
    }
}


// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");
    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...
    invalidateSize();

}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    if (!startFrom)
        return nullptr;

    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...

    return nullptr;     // not found
}



template <typename T>
typename BidiLinkedList<T>::Node** 
    BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    // try not to use any standard containers. create an array only when found a first occurence  
    Node** res = nullptr;
    size = 0;
    
    while (startFrom)
    {
        // !...
        // Здесь вырезана часть кода. Ее необходимо реализовать
        // !...
    }
    
    // recreates array if created
    if (res)
    {
        // !...
        // А здесь вырезана еще одна часть кода. И ее тоже необходимо реализовать
        // !...
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
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...
}

#endif // IWANNAGET10POINTS
