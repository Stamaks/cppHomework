////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Реализация классов красно-черного дерева
/// \author    Sergey Shershakov
/// \version   0.1.0
/// \date      01.05.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// "Реализация" (шаблонов) методов, описанных в файле rbtree.h
///
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>        // std::invalid_argument


namespace xi {


//==============================================================================
// class RBTree::node
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::Node::~Node()
{
    if (_left)
        delete _left;
    if (_right)
        delete _right;
}



template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setLeft(Node* lf)
{
    // предупреждаем повторное присвоение
    if (_left == lf)
        return nullptr;

    // если новый левый — действительный элемент
    if (lf)
    {
        // если у него был родитель
        if (lf->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (lf->_parent->_left == lf)
                lf->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                lf->_parent->_right = nullptr;      
        }

        // задаем нового родителя
        lf->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevLeft = _left;
    _left = lf;

    if (prevLeft)
        prevLeft->_parent = nullptr;

    return prevLeft;
}


template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setRight(Node* rg)
{
    // предупреждаем повторное присвоение
    if (_right == rg)
        return nullptr;

    // если новый правый — действительный элемент
    if (rg)
    {
        // если у него был родитель
        if (rg->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (rg->_parent->_left == rg)
                rg->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                rg->_parent->_right = nullptr;
        }

        // задаем нового родителя
        rg->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevRight = _right;
    _right = rg;

    if (prevRight)
        prevRight->_parent = nullptr;

    return prevRight;
}


//==============================================================================
// class RBTree
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::RBTree()
{
    _root = nullptr;
    _dumper = nullptr;
}

template <typename Element, typename Compar >
RBTree<Element, Compar>::~RBTree()
{
    // грохаем пока что всех через корень
    if (_root)
        delete _root;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::deleteNode(Node* nd)
{
    // если переданный узел не существует, просто ничего не делаем, т.к. в вызывающем проверок нет
    if (nd == nullptr)
        return;

    // потомков убьет в деструкторе
    delete nd;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::insert(const Element& key)
{
    // этот метод можно оставить студентам целиком
    Node* newNode = insertNewBstEl(key);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_BST_INS, this, newNode);

    rebalance(newNode);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_INSERT, this, newNode);

}




template <typename Element, typename Compar>
const typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::find(const Element& key)
{
    if (!_root)
        return nullptr;

    Node* currentNode = _root;

    while (currentNode->_left || currentNode->_right)
    {
        if (currentNode->_key == key)
            return currentNode;

        if (key < currentNode->_key)
        {
            if (currentNode->_left)
                currentNode = currentNode->_left;
            else
                return nullptr;
        }
        else
        {
            if (currentNode->_right)
                currentNode = currentNode->_right;
            else
                return nullptr;
        }
    }

    if (currentNode->_key == key)
        return currentNode;

    return nullptr;
}

template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
        RBTree<Element, Compar>::insertNewBstEl(const Element& key)
{
    if (!_root)
    {
        _root = new Node(key);
        return _root;
    }

    Node* currentNode = _root;
    while (currentNode->_left || currentNode->_right)
    {
        if (currentNode->_key == key)
            throw std::invalid_argument("Key is already in the tree!");

         if (key < currentNode->_key)
        {
            // Идем влево, если можно
            if (currentNode->_left)
                currentNode = currentNode->_left;
            else
            {
                Node *newNode = new Node(key, nullptr, nullptr, currentNode, RED);
                currentNode->_left = newNode;
                return newNode;
            }
        }
        else
        {
            // Идем вправо, если можно
            if (currentNode->_right)
                currentNode = currentNode->_right;
            else
            {
                Node *newNode = new Node(key, nullptr, nullptr, currentNode, RED);
                currentNode->_right = newNode;
                return newNode;
            }
        }
    }

    if (key < currentNode->_key)
    {
        Node *newNode = new Node(key, nullptr, nullptr, currentNode, RED);
        currentNode->_left = newNode;
        return newNode;
    }

    Node *newNode = new Node(key, nullptr, nullptr, currentNode, RED);
    currentNode->_right = newNode;
    return newNode;
}


template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
    RBTree<Element, Compar>::rebalanceDUG(Node* nd)
{
    // попадание в этот метод уже означает, что папа есть (а вот про дедушку пока не известно)
    //TODO: Пока кидаем ошибку, если нет дедушки или дяди ИСПРАВИТЬ

    if (!nd->_parent->_parent)
        throw std::invalid_argument("No grandDaddy");

    if (!nd->_parent->_parent->_right || !nd->_parent->_parent->_left)
        throw std::invalid_argument("No uncle!");

    Node* uncle; // для левого случая нужен правый дядя и наоборот.

    if (nd->isLeftChild())
        uncle = nd->_parent->_parent->_right;
    else
        uncle = nd->_parent->_parent->_left;

    // если дядя такой же красный, как сам нод и его папа...
    if (uncle->isRed() && nd->isLeftChild())
    {
        // дядю и папу красим в черное
        // а дедушку — в коммунистические цвета
        uncle->setBlack();
        nd->_parent->setBlack();
        nd->_parent->_parent->setRed();

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR1, this, nd);

        // теперь чередование цветов "узел-папа-дедушка-дядя" — К-Ч-К-Ч, но надо разобраться, что там
        // с дедушкой и его предками, поэтому продолжим с дедушкой
        return nd->_parent->_parent;
    }

    // дядя черный
    // смотрим, является ли узел "правильно-правым" у папочки
    if (uncle->isBlack() && nd->isLeftChild())      // для левого случая нужен правый узел
    {                                               // CASE2 в действии
        nd->_parent->setBlack();
        nd->_parent->_parent->setRed();

        // при вращении будет вызвано отладочное событие
        rotRight(nd->_parent->_parent);

        return nullptr;
    }

    if (uncle->isRed() && nd->isRightChild())
    {
        nd->_parent->setBlack();
        nd->_parent->_parent->setRed();
        uncle->setBlack();

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR1, this, nd);

        return nd->_parent->_parent;
    }

    if (uncle->isBlack() && nd->isRightChild())
    {
        rotLeft(nd->_parent);

        return nd->_left;
    }

    return nullptr;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::rebalance(Node* nd)
{
    if (nd == _root)
        nd->setBlack();
    else
    {
        // TODO: delete
        int num_of_iter = 0;
        while (nd->_parent->isRed())
        {
            // локальная перебалансировка семейства "папа, дядя, дедушка" и повторная проверка
//            rebalanceDUG(nd);

            ++num_of_iter;

            if (num_of_iter == 100)
                std::cout << "Ушли в бесконечный цикл!!!";


            if (nd->_parent->isLeftChild())
            {
                // если дядя есть
                if (nd->_parent->_parent->_right)
                {
                    rebalanceDUG(nd);
                }
                else
                {
                    if (nd->isRightChild())
                        rotLeft(nd->_parent);
                    else
                        rotRight(nd->_parent);
//                    nd->_parent->setBlack();
//                    nd->_parent->_parent->setRed();
//                    rotRight(nd->_parent->_parent);
                }
            }
            else
            {
                // если дядя есть
                if (nd->_parent->_parent->_left)
                {
                    rebalanceDUG(nd);
                }
                else
                {
                    if (nd->isLeftChild())
                        rotRight(nd->_parent);
                    else
                        rotLeft(nd->_parent);
//                    nd->_parent->setBlack();
//                    nd->_parent->_parent->setRed();
//                    rotLeft(nd->_parent->_parent);
                }
            }
        }

        _root->setBlack();
    }
}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotLeft(typename RBTree<Element, Compar>::Node* nd)
{

    // правый потомок, который станет после левого поворота "выше"
    Node* right = nd->_right;
    
    if (!right)
        throw std::invalid_argument("Can't rotate left since the right child is nil");

    if (right->_left)
    {
        nd->_right = right->_left;
        right->_left->_parent = nd;
        right->_left = nullptr;
    }
    else
        nd->_right = nullptr;

    right->_parent = nd->_parent;

    if (nd->_parent)
    {
        if (nd->isLeftChild())
            nd->_parent->_left = right;
        else
            nd->_parent->_right = right;
    }

    nd->_parent = right;
    right->_left = nd;

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_LROT, this, nd);
}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotRight(typename RBTree<Element, Compar>::Node* nd)
{

    // левый потомок, который станет после правого поворота "выше"
    Node* left = nd->_left;

    if (!left)
        throw std::invalid_argument("Can't rotate right since the left child is nil");

    if (left->_right)
    {
        nd->_left = left->_right;
        left->_right->_parent = nd;
        left->_right = nullptr;
    }
    else
        nd->_left = nullptr;

    left->_parent = nd->_parent;

    if (nd->_parent)
    {
        if (nd->isLeftChild())
            nd->_parent->_left = left;
        else
            nd->_parent->_right = left;
    }

    nd->_parent = left;
    left->_right = nd;

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
}


} // namespace xi

