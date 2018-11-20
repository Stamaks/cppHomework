//
// Created by stamaks on 20.11.18.
//

#ifndef EUROPEBYRAIL_CITY_HEAP_H
#define EUROPEBYRAIL_CITY_HEAP_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <assert.h>
#include <climits>      // INT_MAX
#include <algorithm>    // std::find

#include "service.h"
#include "city.h"

class CityHeap
{
public:
    CityHeap(std::map<std::string, City*> cities);

    void delete_city(int index);

    void add_city_to_heap(City *city, bool need_rebuilding=true);

    void change_distance(City* city, int new_distance);

private:

    void rebuild_heap(int index_to_look_at, bool down_to_up=true);

    std::vector<City *> heap;
    size_t current_size;
};

#endif //EUROPEBYRAIL_CITY_HEAP_H
