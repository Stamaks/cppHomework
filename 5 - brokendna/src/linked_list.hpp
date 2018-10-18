////////////////////////////////////////////////////////////////////////////////
// Module Name:  linked_list.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
//
// Отделенная часть заголовка шаблона класса "Связанный список"
//
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>

namespace xi {

template <class T>
LinkedList<T>::LinkedList() 
{
    //Creation of the dummy/sentinel element
    _preHead = new Node<T>();
    _preHead->next = nullptr;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    Node<T>* currentNode = _preHead;
    Node<T>* currentNext = _preHead->next;

    while (currentNext != nullptr)
    {
        delete currentNode;
        currentNode = currentNext;
        currentNext = currentNode->next;
    }

    delete currentNode;
}


template<class T>
LinkedList<T>::LinkedList(const LinkedList &other)
{
    _preHead = new Node<T>();

    // Текущая нода на шаг позади, потому что к ней пристраеваем новый нод
    Node<T>* currentNode = _preHead;
    Node<T>* currentOtherNode = other.getPreHead()->next;

    while (currentOtherNode != nullptr)
    {
        // Создаем новую ноду
        Node<T>* newNode = new Node<T>();
        newNode->value = currentOtherNode->value;

        // Кидаем в конец
        currentNode->next = newNode;
        currentNode = currentNode->next;
        currentOtherNode = currentOtherNode->next;
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &list)
{
    LinkedList<T> tmp(list);
    swap(*this, tmp);

    return *this;
}

template<class T>
void LinkedList<T>::swap(LinkedList &first, LinkedList &second)
{
    std::swap(first.getPreHead(), second.getPreHead());
}

template<class T>
Node <T> *LinkedList<T>::getPreHead()
{
    return _preHead;
}

template<class T>
T &LinkedList<T>::operator[](int i)
{
    int k = -1;
    Node<T>* currentNode = _preHead;

    while (k < i)
    {
        if (currentNode->next == nullptr)
            throw std::out_of_range("Index out of range!");

        currentNode = currentNode->next;
        k++;
    }

    return currentNode->value;
}

template<class T>
int LinkedList<T>::size()
{
    int k = 0;
    Node<T>* currentNode = _preHead;

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        k++;
    }

    return k;
}

template<class T>
void LinkedList<T>::addElementToEnd(T &value)
{
    Node<T>* newNode = new Node<T>();  // next там изначально nullpointer в конструкторе
    newNode->value = value;

    Node<T>* lastNode = returnLastNode();
    lastNode->next = newNode;
}

template<class T>
void LinkedList<T>::moveNodeToEnd(Node <T> *pNodeBefore)
{
    Node<T>* nodeToMove = pNodeBefore->next;

    // Удаляем нод из списка, чтобы вставить его в конец.
    pNodeBefore->next = nodeToMove->next;

    nodeToMove->next = nullptr;

    // Добавляем в конец
    addElementToEnd(nodeToMove);
}

template<class T>
Node<T>* LinkedList<T>::returnLastNode()
{
    Node<T>* currentNode = _preHead;

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

template<class T>
void LinkedList<T>::deleteNextNode(Node <T> *pNodeBefore)
{
    if (pNodeBefore == nullptr)
        throw std::out_of_range("Got nullptr instead of pNodeBefore!");

    if (pNodeBefore->next == nullptr)
        throw std::out_of_range("Trying to delete node that doesn't exist!");

    Node<T>* nodeToDelete = pNodeBefore->next;

    // Перекладываем ссылку
    pNodeBefore->next = nodeToDelete->next;

    // Удаляем...
    delete nodeToDelete;
}

template<class T>
void LinkedList<T>::deleteNodes(Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    if (pNodeBefore == nullptr)
        throw std::out_of_range("Got nullptr instead of pNodeBefore!");

    // Пока не натыкаемся на нод, следующий которого последний для удаления.
    while (pNodeBefore->next != pNodeLast)
        deleteNextNode(pNodeBefore);

    // Удаляем последний нод - NodeLast
    deleteNextNode(pNodeBefore);
}

template<class T>
void LinkedList<T>::moveNodeAfter(Node <T> *pNode, Node <T> *pNodeBefore)
{
    if (pNode == nullptr)
        throw std::out_of_range("Got nullptr instead of pNode!");

    if (pNodeBefore == nullptr)
        throw std::out_of_range("Got nullptr instead of pNodeBefore!");

    if (pNodeBefore->next == nullptr)
        throw std::out_of_range("Trying to move node that doesn't exist!");

    if (pNode != pNodeBefore)
    {
        Node<T> *nodeToMove = pNodeBefore->next;

        // Меняем ссылку на след эл-т у предыдущего узла
        pNodeBefore->next = nodeToMove->next;

        // Меняем ссылку у нода, чтобы он ссылался на новый список
        nodeToMove->next = pNode->next;

        // Вставляем нод в новый список
        pNode->next = nodeToMove;
    }
}

template<class T>
void LinkedList<T>::moveNodesAfter(Node <T> *pNode, Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    /* Тут бы конечно проверять, что pNodeBefore и pNodeLast  - это одна цепочка, но тогда сложность операции
     * будет O(k), где k - это кол-во узлов в между pNodeBefore и pNodeLast. Хотим ли мы максимально
     * безопасную структуру или делать все за O(1) - не понятно...
     */

    if (pNode == nullptr)
        throw std::out_of_range("Got nullptr instead of pNode!");

    if (pNodeBefore == nullptr)
        throw std::out_of_range("Got nullptr instead of pNodeBefore!");

    if (pNodeBefore->next == nullptr || pNodeLast == nullptr)
        throw std::out_of_range("Trying to move node that doesn't exist!");

    if (pNode == pNodeLast)
        throw std::out_of_range("pNode == pNodeLast!");

    if (pNode != pNodeBefore)
    {
        Node<T> *nodeToMove = pNodeBefore->next;

        // Меняем ссылку на след эл-т у предыдущего узла
        pNodeBefore->next = pNodeLast->next;

        // Меняем ссылку у последнего нода, чтобы он ссылался на новый список
        pNodeLast->next = pNode->next;

        // Вставляем нод в новый список
        pNode->next = nodeToMove;
    }
}

template<class T>
void LinkedList<T>::moveNodesToEnd(Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    Node<T>* lastNode = returnLastNode();

    if (lastNode != pNodeLast)
    {
        lastNode->next = pNodeBefore->next;
        pNodeBefore->next = pNodeLast->next;
        pNodeLast->next = nullptr;
    }
}

} // namespace xi