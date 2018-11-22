#include "rail_system.h"
#include "city_heap.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <assert.h>
#include <tgmath.h>
#include <climits>      // INT_MAX
#include <algorithm>    // std::find

#include "city.h"

CityHeap::CityHeap(std::map<std::string, City*> cities)
{
    // Не бейте, я объявляю кучу размером 2 ^ ceil(двоичный_лог(кол-во городов))
    // Пусть кол-во городов == 25. Тогда ceil(двоичный_лог(кол-во городов)) == 5, а 2^5 == 32
    heap.resize(pow(2, ceil(log2(cities.size()))), nullptr);
    current_size = 0;
}

// TODO: WRITE
void CityHeap::change_distance(City* city, int new_distance)
{
    int i = 0;
//    while (heap[i] !=)
}

// TODO: WRITE
void CityHeap::rebuild_heap(bool down_to_up)
{
    if (down_to_up)
    {

    }
}

// TODO: WRITE
void CityHeap::delete_city(City* city)
{

}

void CityHeap::add_city_to_heap(City *city, bool need_rebuilding)
{
    if (current_size == heap.size())
        throw std::logic_error("The heap is full!");

    if (current_size == INT_MAX)
        throw std::logic_error("Too many elements!");

    heap[current_size] = city;

    if (need_rebuilding)
        rebuild_heap(current_size);

    ++current_size;
}

City *CityHeap::get_city_with_min_dist()
{
    return heap[0];
}

int CityHeap::find_city_index(City* city)
{

}

