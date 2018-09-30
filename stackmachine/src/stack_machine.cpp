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
        throw std::logic_error("Operation other than Mult (*) are not supported");

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
        throw std::logic_error("Operation other than Mult (*) are not supported");

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

}
} // namespace xi
