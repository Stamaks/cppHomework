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
    if (i >= this->size())
        throw std::out_of_range("Index out of range!");

    int k = -1;
    Node<T>* currentNode = _preHead;

    while (k < i)
    {
        currentNode = currentNode->next;
        k++;
    }

    if (currentNode != nullptr)
        return currentNode->value;
    else
        throw std::out_of_range("Что-то пошло не так ><");
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

    Node<T>* currentNode = _preHead;

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template<class T>
void LinkedList<T>::moveNodeToEnd(Node <T> *pNodeBefore)
{
    Node<T>* nodeToMove = pNodeBefore->next;

    // Удаляем нод из списка, чтобы вставить его в конец. Не боимся, потому что мы его запомнили
    deleteNextNode(pNodeBefore);

    // Добавляем в конец
    addElementToEnd(nodeToMove);
}

template<class T>
Node<T> LinkedList<T>::returnLastNode()
{
    Node<T>* currentNode = _preHead;

    if (_preHead->next == nullptr)
        throw std::out_of_range("There are no elements in list!");

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

template<class T>
void LinkedList<T>::deleteNextNode(Node <T> *pNodeBefore)
{
    Node<T>* nodeToDelete = pNodeBefore->next;

    // Перекладываем ссылку
    pNodeBefore->next = nodeToDelete->next;

    // Делаем так, чтобы этот узел уже ни на что не ссылался
    nodeToDelete->next = nullptr;
}

template<class T>
void LinkedList<T>::deleteNodes(Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    // Пока не натыкаемся на нод, следующий которого последний для удаления.
    while (pNodeBefore->next != pNodeLast)
    {
        if (pNodeBefore->next == nullptr)
            throw std::out_of_range("Null pointer while deleteNodes");

        deleteNextNode(pNodeBefore);
    }

    // Удаляем последний нод - NodeLast
    deleteNextNode(pNodeBefore);
}

template<class T>
void LinkedList<T>::moveNodeAfter(Node <T> *pNode, Node <T> *pNodeBefore)
{
    Node<T>* nodeToMove = pNodeBefore->next;

    // Меняем ссылку на след эл-т у предыдущего узла
    pNodeBefore->next = nodeToMove->next;

    // Меняем ссылку у нода, чтобы он ссылался на новый список
    nodeToMove->next = pNode->next;

    // Вставляем нод в новый список
    pNode->next = nodeToMove;
}

template<class T>
void LinkedList<T>::moveNodesAfter(Node <T> *pNode, Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    Node<T>* currentNodeToInsertAfter = pNode;

    // Пока не натыкаемся на нод, следующий которого последний для перемещения.
    while(pNodeBefore->next != pNodeLast)
    {
        if (pNodeBefore->next == nullptr)
            throw std::out_of_range("Null pointer while moveNodesAfter");

        moveNodeAfter(currentNodeToInsertAfter, pNodeBefore);
        currentNodeToInsertAfter = currentNodeToInsertAfter->next;
    }

    // Перемещаем nodeLast
    moveNodeAfter(pNodeBefore, currentNodeToInsertAfter);
}

template<class T>
void LinkedList<T>::moveNodesToEnd(Node <T> *pNodeBefore, Node <T> *pNodeLast)
{
    while (pNodeBefore->next != pNodeLast)
    {
        if (pNodeBefore->next == nullptr)
            throw std::out_of_range("Null pointer while moveNodesToEnd");

        moveNodeToEnd(pNodeBefore);
    }

    moveNodeToEnd(pNodeBefore);
}

} // namespace xi