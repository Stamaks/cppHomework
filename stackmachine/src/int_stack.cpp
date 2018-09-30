////////////////////////////////////////////////////////////////////////////////
// Module Name:  int_stack.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include <stdexcept>
#include "int_stack.h"

namespace xi {

    IntStack::IntStack(size_t sz) : _ssize(sz)
    {
        _stack = new int[sz];
        _ssize = sz;
        _head = 0;
    }

    IntStack::~IntStack()
    {
        delete [] _stack;
        _stack = nullptr;
        _ssize = 0;
        _head = 0;
    }

    void IntStack::push(int el)
    {
        if (this->_head == this->_ssize)
        {
            throw std::logic_error("No more elements can be placed onto the stack!");
        }

        this->_stack[this->_head] = el;
        ++this->_head;
    }

    int IntStack::pop()
    {
        if (this->_head == 0)
        {
            throw std::logic_error("No elements stored in the stack!");
        }

        --this->_head;
        return this->_stack[this->_head];
    }

    int IntStack::top()
    {
        if (this->_head == 0)
        {
            throw std::logic_error("No elements stored in the stack!");
        }

        return this->_stack[this->_head - 1];
    }

    void IntStack::clear()
    {
        this->_head = 0;
    }

    bool IntStack::isEmpty() const
    {
        return !this->_head;
    }

    bool IntStack::isFull() const
    {
        return this->_head != 0;
    }


} // namespace xi

