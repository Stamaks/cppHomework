////////////////////////////////////////////////////////////////////////////////
// Module Name:  stack_machine.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include "stack_machine.h"

#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <stdlib.h>

namespace xi {

//==============================================================================
// Free functions -- helpers
//==============================================================================

// TODO: if you need any free functions, add their definitions here.

//==============================================================================
// class PlusOp
//==============================================================================


int PlusOp::operation(char op, int a, int b, int /*c*/) // < just commented unused argument. This does not affect the code anyhow.
{
    if(op != '+')
        throw std::logic_error("Operation other than Plus (+) are not supported");

    // here we just ignore unused operands
    return a + b;
}

IOperation::Arity PlusOp::getArity() const
{
    return arDue;
}


//==============================================================================
// class MultOp
//==============================================================================


int MultOp::operation(char op, int a, int b, int /*c*/)
{
    if(op != '*')
        throw std::logic_error("Operation other than Mult (*) are not supported");

    return a * b;
}

IOperation::Arity MultOp::getArity() const
{
    return arDue;
}

//==============================================================================
// class MultOp
//==============================================================================


int ChoiceOp::operation(char op, int a, int b, int c)
{
    if(op != '?')
        throw std::logic_error("Operation other than ChoiceOp (?) are not supported");

    return a ? b : c;
}

IOperation::Arity ChoiceOp::getArity() const
{
    return arTre;
}


//==============================================================================
// class MultOp
//==============================================================================


int SigChangeOp::operation(char op, int a, int /*b*/, int /*c*/)
{
    if(op != '!')
        throw std::logic_error("Operation other than SigChangeOp (!) are not supported");

    return -a;
}

IOperation::Arity SigChangeOp::getArity() const
{
    return arUno;
}


//==============================================================================
// class StackMachine
//==============================================================================


void StackMachine::registerOperation(char symb, IOperation *oper)
{
    SymbolToOperMapConstIter iter = _opers.find(symb);
    if (iter != _opers.end())
        throw std::logic_error("An operation is already registered!");

    _opers[symb] = oper;
}

IOperation *StackMachine::getOperation(char symb)
{
    SymbolToOperMapConstIter iter = _opers.find(symb);
    if (iter == _opers.end())
        return nullptr;

    return _opers[symb];
}

int StackMachine::calculate(const std::string &expr, bool clearStack)
{
    std::string current = "";
    std::list<std::string> tokens;
    for (int i = 0; i < expr.length(); ++i)
    {
        if (expr[i] == ' ')
        {
            if (current != "")
                tokens.push_back(current);
            current = "";
        }
        else
        {
            current += expr[i];
        }
    }
    if (current != "")
        tokens.push_back(current);

    std::string currentToken = "";
    int currentNumber;
    for (int i = 0; i < tokens.size(); ++i)
    {
        currentToken = tokens.front();

        if (castToInt(currentToken, currentNumber))
        {
            _s.push(currentNumber);
        }
        else if (getOperation(currentToken[0]) != nullptr)
        {
            // Достаем операцию и операнды
            if (getOperation(currentToken[0])->getArity() == 0)
        }

    }

}

bool StackMachine::castToInt(std::string &token, int &out)
{
    try
    {
        out = std::stoi("");
    } catch (std::invalid_argument)
    {
        return false;
    }

    return true;
}
} // namespace xi
