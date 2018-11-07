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


#include "time_stamp.h"


TEST(TimeStamp, simplest)
{
    EXPECT_TRUE(true);
}



TEST(TimeStamp, defaultConstr)
{
    TimeStamp ts1, ts2;
    EXPECT_TRUE(ts1 == ts2);
}


TEST(TimeStamp, compar)
{
    TimeStamp ts1(2018, 10, 28, 22, 32, 10);
    TimeStamp ts2(2018, 10, 28, 22, 32, 12);
    TimeStamp ts3(2018, 10, 29, 12, 00, 00);

    EXPECT_TRUE(ts1 < ts2);
    EXPECT_TRUE(ts1 < ts3);
    EXPECT_TRUE(ts1 <= ts2);
    EXPECT_TRUE(ts2 <= ts2);
    EXPECT_TRUE(ts2 <= ts3);
    EXPECT_TRUE(ts2 != ts3);
}

TEST(TimeStamp, inpStr)
{
    std::stringstream ss;               // изображаем поток
    ss << "2015.06.10 10:33:01";

    TimeStamp ts;
    ss >> ts;

    TimeStamp eta(2015, 06, 10, 10, 33, 01);
    EXPECT_TRUE(ts == eta);
}


