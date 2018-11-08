////////////////////////////////////////////////////////////////////////////////
// Module Name:  skip_list.h/hpp
// Authors:      Leonid Dworzanski, Sergey Shershakov
// Version:      2.0.0
// Date:         28.10.2018
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

// !!! DO NOT include skip_list.h here, 'cause it leads to circular refs. !!!

#include <cstdlib>

//==============================================================================
// class NodeSkipList
//==============================================================================

template <class Value, class Key, int numLevels>
void NodeSkipList<Value, Key, numLevels>::clear(void)
{
    for (int i = 0; i < numLevels; ++i)
        Base::nextJump[i] = 0;

    Base::levelHighest = -1;
}

//------------------------------------------------------------------------------

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(void)
{
    clear();
}

//------------------------------------------------------------------------------

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(const Key& tkey)
{
    clear();

    Base::Base::key = tkey;
}

//------------------------------------------------------------------------------

template <class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(const Key& tkey, const Value& val)
{
    clear();

    Base::Base::key = tkey;
    Base::Base::value = val;
}


//==============================================================================
// class SkipList
//==============================================================================

template <class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::SkipList(double probability)
{
    _probability = probability;

    // Lets use m_pPreHead as a final sentinel element
    for (int i = 0; i < numLevels; ++i)
        Base::_preHead->nextJump[i] = Base::_preHead;

    Base::_preHead->levelHighest = numLevels - 1;
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::append(const Value &val, const Key &key)
{
    Node* newNode = new Node(key, val);
    Node* prevNode;

    if (this->_preHead->next == this->_preHead)
    {
        this->_preHead->next = newNode;
        newNode->next = this->_preHead;
    }
    else
    {
        prevNode = findLastLessThan(key);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    int currentLevel = -1;

    // std::rand() генерирует числа [0, RAND_MAX]. Превращаем их в отрезок от 0 до 1 и радуемся.
    // Высчитываем, на каком уровне у нас впервые встретится элемент
    while (currentLevel < numLevels && (float) std::rand() / RAND_MAX < _probability)
    {
        ++currentLevel;
    }

    newNode->levelHighest = currentLevel;

    Node* currentNode = this->_preHead;

    while (currentNode->next != this->_preHead && currentLevel != -1)
    {
        if (currentNode->nextJump[currentLevel] == this->_preHead)
        {
            currentNode->nextJump[currentLevel] = newNode;
            newNode->nextJump[currentLevel] = this->_preHead;

            --currentLevel;
        }
        else if (currentNode->nextJump[currentLevel]->key < key)
        {
            currentNode = currentNode->nextJump[currentLevel];
        }
        else
        {
            newNode->nextJump[currentLevel] = currentNode->nextJump[currentLevel];
            currentNode->nextJump[currentLevel] = newNode;
            --currentLevel;
        }
    }

}

template<class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::~SkipList()
{
    Node* currentNode = this->_preHead->next;
    Node* prevNode;

    while (currentNode != this->_preHead)
    {
        prevNode = currentNode;
        currentNode->next = currentNode;

        delete prevNode;
    }

    delete this->_preHead;
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::removeNext(SkipList::Node *node)
{
    if (node == nullptr)
        throw std::invalid_argument("Node is nullptr!");

    if (node->next == nullptr)
        throw std::invalid_argument("Node is broken! Next is nullptr!");

    if (node->next == this->_preHead)
        throw std::invalid_argument("Trying to remove preHead!");

    if (this->_preHead->next == this->_preHead)
        throw std::invalid_argument("The list is empty!");

    //TODO: Спуском переставляем все ссылки с этого эл-та не следующий

    delete[](node->nextJump[0]);
    delete node;
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::Node *SkipList<Value, Key, numLevels>::findLastLessThan(const Key &key) const
{
    Node* currentNode = this->_preHead;
    bool found = 0;
    int currentLevel = numLevels - 1;

    while (currentNode->next != this->_preHead && !found)
    {
        if (currentLevel != -1)
        {
            if (currentNode->nextJump[currentLevel] == this->_preHead)
            {
                --currentLevel;
            }
            else if (currentNode->nextJump[currentLevel]->key < key)
            {
                currentNode = currentNode->nextJump[currentLevel];
            }
            else
            {
                --currentLevel;
            }
        }
        else
        {
            if (currentNode->next->key < key)
            {
                currentNode = currentNode->next;
            }
            else if (currentNode->next->key == key)
            {
                found = 1;
            }
            else {
                break;
            }
        }
    }

    if (found)
        return currentNode;

    return this->_preHead;

    //TODO: Спускаемся вниз до уровня и ищем на нем, спускаемся ступеньками. Если мы на -1 уровне и след эл-т больше - возвращаем текущий
    //TODO: если не нашли - кидать invalid arg
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::Node *SkipList<Value, Key, numLevels>::findFirst(const Key &key) const
{
    // Может, юзать findLastLessThan? И просто возвращать следующий?
    //TODO: Спускаемся вниз ступеньками. Если next.val больше ИЛИ РАВЕН текущ - идем вниз, если это -1 - идем вправо.
    //TODO: если не нашли - кидать invalid arg
}
