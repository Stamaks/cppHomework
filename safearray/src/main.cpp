////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         30.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "safearray.h"


using namespace std;
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();

int main()
{
    using namespace xi;

    cout << "1";
    Test1();
    cout << "2";
    Test2();
    cout << "3";
    Test3();
    cout << "4";
    Test4();
    cout << "5";
    Test5();
    cout << "6";
    Test6();






}

void Test1(){
    xi::SafeArray<int> sa;
    cout << (sa.getRawPtr() == nullptr);
    cout << (sa.getCapacity() == 0);
}

void Test2(){
    xi::SafeArray<int> sa(3);
    cout << (sa.getRawPtr() != nullptr);
    cout << (sa.getCapacity() == 3);
}

void Test3(){
    using namespace xi;

    SafeArray<int> sa(3);
    cout << (sa.getRawPtr() != nullptr);
    cout << (sa.getCapacity() == 3);

    sa[0] = 0;
    sa[1] = 1;
    sa[2] = 2;

    try{
        sa[3] = 3;
    }
    catch (std::out_of_range){
        cout << "cool";
    }
}

void Test4() {
    using namespace xi;

    SafeArray<int> sa(1);
    cout << (sa.getRawPtr() != nullptr);
    cout << (sa.getCapacity() == 1);

    sa[0] = 0;
    cout << (sa[0] == 0);

    const int el0 = sa[0];
    cout << (el0 == sa[0]);

    try{
        sa[1];
    }
    catch (std::out_of_range){
        cout << "cool";
    }
}

void Test5() {
    using namespace xi;

    SafeArray<int> sa(1);
    cout << (sa.getRawPtr() != nullptr);
    cout << (sa.getCapacity() == 1);

    SafeArray<int> sb = sa;
    cout << (sb.getRawPtr() != nullptr);
    cout << (sb.getCapacity() == 1);

    // корректность конструктора копирования
    cout << (sa.getRawPtr() == sb.getRawPtr());
}

void Test6() {
    using namespace xi;

    SafeArray<int> sa(1);
    cout << (sa.getRawPtr() != nullptr);
    cout << (sa.getCapacity() == 1);

    SafeArray<int> sb;
    cout << (sb.getRawPtr() == nullptr);
    cout << (sb.getCapacity() == 0);

    // копируем
    sb = sa;

    cout << (sb.getRawPtr() != nullptr);
    cout << (sb.getCapacity() == 1);

    // корректность операции копирования
    cout << (sa.getRawPtr() == sb.getRawPtr());
}