///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Defines the entry point for the demo application.
///
/// © Sergey Shershakov 2015–2017.
///
/// This code is for educational purposes of the course "Algorithms and Data 
/// Structures" provided by the School of Software Engineering of the Faculty 
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////


//#include "stdafx.h"
//#include "demos.hpp"


// uncomment this if you'd like to get the highest mark
 #define IWANNAGET10POINTS

#include "bidi_linked_list.h"


/** \brief Type alias for a list of integers. */
typedef BidiLinkedList<int> IntBidiLinkedList;
typedef BidiLinkedList<int> IntBidiList;
typedef IntBidiList::Node IntBidiListNode;


/** \brief Simple list creating. */
void demo1()
{
    IntBidiLinkedList lst;
}



//int _tmain(int argc, _TCHAR* argv[])
int main()
{
    demo1();

    IntBidiList lst;
    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);

    return 0;
}

