////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Unit tests for TimeStamp class.
///
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      23.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// Gtest-based unit test.
/// The naming conventions imply the name of a unit-test module is the same as 
/// the name of the corresponding tested module with _test suffix
/// 
////////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>


#include "ordered_list.h"
#include "skip_list.h"

// псевдонимы для тестовых типов
typedef NodeWithKey<double, int> IntDblKeyNode;



TEST(NodeWithKey, nodeDef)
{
    IntDblKeyNode nd;
    EXPECT_EQ(nullptr, nd.next);

    //int a = 42;
}


TEST(NodeWithKey, nodeInit1)
{
    IntDblKeyNode nd1(0);
    EXPECT_EQ(nullptr, nd1.next);
    EXPECT_EQ(0, nd1.key);


    IntDblKeyNode nd2(0, 0);
    EXPECT_EQ(nullptr, nd2.next);
    EXPECT_EQ(0, nd2.key);
    EXPECT_EQ(0, nd2.value);

    //int a = 42;
}

TEST(LastLessThan, lastLess)
{
    SkipList<int, int, 8> list;

    EXPECT_EQ(list.getPreHead(), list.findLastLessThan(0));

    list.append(0, 0);
    list.append(1, 1);
    list.append(2, 2);
    list.append(3, 3);
    list.append(4, 4);

    EXPECT_EQ(3, list.findLastLessThan(4)->key);
    EXPECT_EQ(list.getPreHead(), list.findLastLessThan(0));
    EXPECT_EQ(list.getPreHead(), list.findLastLessThan(8));
    EXPECT_EQ(list.getPreHead(), list.findLastLessThan(-9));
}
