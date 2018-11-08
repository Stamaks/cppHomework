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
    std::srand(time(NULL));
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::insert(const Value &val, const Key &key)
{
    Node* newNode = new Node(key, val);
    Node* prevNode;

    std::cout << "doing INS of key " << key << std::endl;
    if (this->_preHead->next == this->_preHead)
    {
        this->_preHead->next = newNode;
        newNode->next = this->_preHead;
    }
    else
    {
        prevNode = findLastLessThan(key);
        std::cout << (prevNode == this->_preHead) << std::endl;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    int currentLevel = -1;

    // std::rand() генерирует числа [0, RAND_MAX]. Превращаем их в отрезок от 0 до 1 и радуемся.
    // Высчитываем, на каком уровне у нас впервые встретится элемент
    float prob = (float) std::rand() / RAND_MAX;

    std::cout << "Prob is " << prob << "\n";
    while (currentLevel < numLevels && prob < _probability)
    {
        ++currentLevel;
        prob = (float) std::rand() / RAND_MAX;
        std::cout << "And now prob is " << prob << "\n";
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
void SkipList<Value, Key, numLevels>::removeNext(SkipList::Node *nodeBefore)
{
    if (nodeBefore == nullptr)
        throw std::invalid_argument("Node is nullptr!");

    if (nodeBefore->next == nullptr)
        throw std::invalid_argument("Node is broken! Next is nullptr!");

    if (nodeBefore->next == this->_preHead)
        throw std::invalid_argument("Trying to remove preHead!");

    if (this->_preHead->next == this->_preHead)
        throw std::invalid_argument("The list is empty!");

    //TODO: Спуском переставляем все ссылки с этого эл-та нa следующий
    Node* nodeToRemove = nodeBefore->next;
    Node* currentNode = this->_preHead;
    int currentLevel = numLevels - 1;

    while (currentLevel != -1)
    {
        if (currentNode->nextJump[currentLevel] == this->_preHead)
        {
            std::cout << currentLevel << " meow" << std::endl;
            --currentLevel;
            continue;
        }

        if (currentNode->nextJump[currentLevel] == nodeToRemove)
        {
            std::cout << "removing link from " << currentNode->key << std::endl;
            currentNode->nextJump[currentLevel] = nodeToRemove->nextJump[currentLevel];
            --currentLevel;
            continue;
        }

        if (currentNode->nextJump[currentLevel]->key < nodeToRemove->key)
        {
            std::cout << currentLevel << " jump to " << currentNode->nextJump[currentLevel]->key << std::endl;
            currentNode = currentNode->nextJump[currentLevel];
            --currentLevel;
        }
    }

    delete[](nodeBefore->next->nextJump[0]);
    delete nodeBefore->next;
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::Node *SkipList<Value, Key, numLevels>::findLastLessThan(const Key &key) const
{
    Node* currentNode = this->_preHead;
    bool found = 0;
    int currentLevel = numLevels - 1;

    std::cout << "key " << key << std::endl;

    while (!found)
    {
        if (currentLevel != -1)
        {
            if (currentNode->nextJump[currentLevel] == this->_preHead)
            {
                std::cout << currentLevel << " meow" << std::endl;
                --currentLevel;
            }
            else if (currentNode->nextJump[currentLevel]->key < key)
            {
                std::cout << currentLevel << " move to " << currentNode->nextJump[currentLevel]->key << std::endl;
                currentNode = currentNode->nextJump[currentLevel];
            }
            else
            {
                std::cout << currentLevel << " bark" << std::endl;
                --currentLevel;
            }
        }
        else
        {
            if (currentNode->next == this->_preHead)
            {
                std::cout << "went to _preHead\n";
                return currentNode;
            }

            if (currentNode->next->key < key)
            {
                std::cout << currentLevel << " move to " << currentNode->next->key << std::endl;
                currentNode = currentNode->next;
            }
            else
            {
                std::cout << currentLevel << " found " << currentNode->next->key << "\n";
                found = 1;
            }
        }
    }

    std::cout << "found: " << found << "\n" << std::endl;
    if (found)
        return currentNode;

    throw std::invalid_argument("Your key is awful! It broke something!");
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::Node *SkipList<Value, Key, numLevels>::findFirst(const Key &key) const
{
    // Может, юзать findLastLessThan? И просто возвращать следующий?
    Node* tryToFind = findLastLessThan(key);

    if (tryToFind->next != this->_preHead && tryToFind->next->key == key)
        return tryToFind->next;

    throw std::invalid_argument("There is no such key!");
}

template<class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::~SkipList()
{
    // Если тут что-то писать, все рушится, так что пусть родитель удаляет :)
}

