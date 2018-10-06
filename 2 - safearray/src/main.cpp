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
#include <fstream>

#include "safearray.h"
#include "subject.h"


using namespace std;
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void Test9();

static const char* TEST_FNAME = "../../res/raw/subjects.txt";
//static const char* TEST_FNAME = "F:\\GitAlgo\\safearray\\res\\raw\\subjects.txt";

// число описаний курсов в файле
static const int SUBS_NUM = 10;



// для gcc нужно явно определять создание объекта, когда для MSVC и без этого прокатит:
// ошибке redefinition; multiple initialization
// http://www.stroustrup.com/bs_faq2.html#in-class
// Определение (создание) объекта должно встречаться строго только в одном модуле трансляции.
const int xi::Subject::MAX_LINES;




// Вспомогательный метод, загружающий список предметов из текстового файла, имя
// которого передается параметром
// Список загружается в передаваемый по ссылке объект ar
// Использование передачи объектов по значению в данном случае является дорогим и нерациональным
void loadSubjects(const char* fn, xi::SafeArray<xi::Subject>& subjs)
{
    using namespace std;

    // пытаемся открыть файл для чтения
    ifstream inf(fn);
    bool fileNotOpen = !inf;
    cout << (fileNotOpen) << endl;

    // пытаемся вычитать текстовый файл строку за строкой
    try
    {
        for (int i = 0; i < SUBS_NUM; i++)
        {
            inf >> subjs[i];
        }
    }
    catch (out_of_range e)
    {
        cerr << "Error reading file" << fn << endl;
    }

    inf.close();
}



int main()
{
    using namespace xi;

//    cout << "1";
//    Test1();
//    cout << "2";
//    Test2();
//    cout << "3";
//    Test3();
//    cout << "4";
//    Test4();
//    cout << "5";
//    Test5();
//    cout << "6";
//    Test6();
//
//
//    cout << endl;
//
//    cout << "7";
//    Test7();
//    cout << "8";
//    Test8();
//    cout << "9";
//    Test9();
//
//    string a = "";
//    cout << (a == "");


    ifstream inf(TEST_FNAME);
    bool fileNotOpen = !inf;
    cout << (fileNotOpen) << endl;

    xi::SafeArray<xi::Subject> subjs(SUBS_NUM);
    // пытаемся вычитать текстовый файл строку за строкой
    try
    {
        for (int i = 0; i < SUBS_NUM; i++)
        {
            inf >> subjs[i];

        }
    }
    catch (out_of_range e)
    {
        cerr << "Error reading file" << fn << endl;
    }

    inf.close();

}

void Test7(){
    using namespace xi;

    Subject s;
}

void Test8(){
    using namespace xi;

    xi::SafeArray<xi::Subject> subjs(SUBS_NUM);
    loadSubjects(TEST_FNAME, subjs);
}

void Test9(){
    using namespace xi;

    xi::SafeArray<xi::Subject> subjs(SUBS_NUM);

    cout << "desc[0]" << (subjs[1].description[0] == "") << endl;
    subjs[1].description[0] = "dfdfdfd";
    cout << subjs[1].description[0];

    loadSubjects(TEST_FNAME, subjs);

    cout << "9 test!" << endl;
    cout << (subjs[1].name == "SSD2");
    cout << subjs[1].name << endl;
    cout << (subjs[1].title == "Introduction to Computer Systems");

    // след. две строки эквивалентны
    cout << (subjs[1].description.getCapacity() == subjs[1].MAX_LINES);
    cout << (subjs[1].description.getCapacity() == xi::Subject::MAX_LINES);
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