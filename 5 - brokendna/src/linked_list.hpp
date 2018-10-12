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
    _preHead = new Node<T>;
    _preHead->next = nullptr;
}

template <class T> 
LinkedList<T>::~LinkedList()
{
    // TODO: Удалить все ноды

    delete _preHead;
    _preHead = nullptr;
    _preHead->next = nullptr;
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

    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
        k++;
    }

    return k;
}

template<class T>
void LinkedList<T>::addElementToEnd(T &value)
{
    Node<T>* newNode;  // next там изначально nullpointer в конструкторе
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

    // Удаляем нод из списка, чтобы вставить его в конец
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
    Node<T>* nodeBeforeCurrentDelete = pNodeBefore;

    // Пока не натыкаемся на нод, следующий которого последний для удаления.
    while (nodeBeforeCurrentDelete->next != pNodeLast)
    {
        deleteNextNode(nodeBeforeCurrentDelete);
    }

    // Удаляем последний нод - NodeLast
    deleteNextNode(nodeBeforeCurrentDelete);
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
    Node<T>* nodeBeforeCurrentMove = pNodeBefore;
    Node<T>* currentNodeToInsertAfter = pNode;

    // Пока не натыкаемся на нод, следующий которого последний для перемещения.
    while(nodeBeforeCurrentMove->next != pNodeLast)
    {
        moveNodeAfter(currentNodeToInsertAfter, nodeBeforeCurrentMove);
        currentNodeToInsertAfter = currentNodeToInsertAfter->next;
    }

    // Перемещаем nodeLast
    moveNodeAfter(nodeBeforeCurrentMove, currentNodeToInsertAfter);
}


} // namespace xi