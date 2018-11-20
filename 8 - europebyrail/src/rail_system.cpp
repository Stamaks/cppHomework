#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "rail_system.h"
#include "string"
#include <tgmath.h>
#include <iostream>
#include <fstream>
#include "city_heap.h"

//TODO: REWRITE
RailSystem::RailSystem(const std::string &filename)
{
    load_services(filename);
}

RailSystem::~RailSystem()
{
    for (std::pair<std::string, City*> pair : cities)
    {
        delete pair.second;
    }

    for (std::pair<std::string, std::list<Service*>> pair : outgoing_services)
    {
        for (Service* service : pair.second)
        {
            delete service;
        }
    }
}


void RailSystem::load_services(const std::string &filename)
{
    std::string line;
    std::ifstream services_file (filename);

    // Индекс, означающий на каком слове текущей строки мы находимся
    int index = 0;
    std::string city_from;
    std::string city_to;
    int fee = -1;
    int distance = -1;

    // Файл мог не загрузиться
    if (services_file.is_open())
    {
        while (services_file >> line)
        {
            // Проверяем, что строка на входе не пустая
            if (!line.empty())
            {

                // В зависимости от положения считанного слова в строке
                switch (index)
                {
                    case 0: // Город из
                        city_from = line;

                        // Если еще ни разу не встречали такой город, добавляем в словарь
                        if (cities.find(city_from) == cities.end())
                        {
                            cities[city_from] = new City(city_from);
                        }

                        ++index;

                        break;

                    case 1: // Город в
                        city_to = line;

                        // Если еще ни разу не встречали такой город, добавляем в словарь
                        if (cities.find(city_to) == cities.end())
                        {
                            cities[city_to] = new City(city_to);
                        }

                        ++index;

                        break;

                    case 2: // Стоимость
                        fee = std::stoi(line);

                        // Такого быть не может!
                        if (fee <= 0)
                            throw std::logic_error("The file is invalid!");

                        ++index;

                        break;

                    case 3: // Расстояние
                        distance = std::stoi(line);

                        // Такого быть не может!
                        if (distance <= 0)
                            throw std::logic_error("The file is invalid!");

                        // Добавляем ребро в словарь
                        outgoing_services[city_from].push_back(new Service(city_to, fee, distance));

                        // Обнуляем переменные
                        index = 0;
                        city_from = "";
                        city_to = "";
                        fee = -1;
                        distance = -1;

                        break;

                    default:
                        throw std::logic_error("The file is invalid!");
                }
            }
            else
                throw std::logic_error("The file is invalid!");
        }
    }
    else
        throw std::logic_error("Couldn't load the file!");

}

void RailSystem::reset()
{
    for (std::pair<std::string, City*> pair : cities)
    {
        pair.second->from_city = "";
        pair.second->total_distance = 0;
        pair.second->total_fee = 0;
        pair.second->visited = 0;
    }
}

std::pair<int, int> RailSystem::calc_route(std::string from, std::string to)
{
    // Создаем вектор дистанций и инициализируем его максимальным значением
    std::map<std::string, int> current_distances;
    std::map<std::string, int> current_fees;
    std::map<std::string, bool> used;

    // Сообщаем мапам, какие у нас есть вершины
    for (std::pair<std::string, City*> pair : cities)
    {
        current_distances[pair.first] = INT_MAX;
        current_fees[pair.first] = 0;
        used[pair.first] = false;
    }


    current_distances[from] = 0;
    for (int i = 0; i < outgoing_services.size(); ++i) {
        std::string current_city = "";

        // Ищем не помеченный город с наименьшим до него расстоянием
        for (std::pair<std::string, std::list<Service*>> pair : outgoing_services)
        {
            if (!used[pair.first] && (current_city == "" || current_distances[pair.first] < current_distances[current_city]))
                current_city = pair.first;
        }

        // Не нашли путь до вершины
        if (current_distances[current_city] == INT_MAX)
            break;

        used[current_city] = true;

//        for (size_t j=0; j < outgoing_services[current_city].size(); ++j) {
//            int to = outgoing_services[current_city].,
//                    len = g[v][j].second;
//            if (d[v] + len < d[to]) {
//                d[to] = d[v] + len;
//                p[to] = v;
//            }
//        }




    }


    CityHeap heap(cities);

    // Заполняем кучу. Наверх ставим город, из которого идем
    heap.add_city_to_heap(cities[from], false);
    cities[from]->total_distance = 0;

    for (std::pair<std::string, City*> pair : cities)
    {
        if (pair.first == from)
            continue;

        heap.add_city_to_heap(pair.second);
        pair.second->total_distance = INT_MAX;
    }

    int num_of_iterations = 0;
    while (true)
    {
        City* current_city = heap[0];


        ++num_of_iterations;
        if (num_of_iterations == INT_MAX)
        {
            std::cout << "REACHED MAX NUM OF ITERATIONS!";
            break;
        }
    }

}



//TODO: написать
std::vector<std::string> RailSystem::recover_route(const std::string &city)
{
    return std::vector<std::string>();
}

//TODO: написать
void RailSystem::output_cheapest_route(const std::string &from, const std::string &to)
{
    std::pair<int, int> result = calc_route(from, to);

    if (result.first == INT_MAX && result.second == INT_MAX)
        std::cout << "There is no route from " << from << " to " << to << std::endl;
    else
    {
        std::cout << "The cheapest route from " << from << " to " << to <<
                     " costs " << result.first << " euros and spans " << result.second << " kilometers" << std::endl;
//        recover_route();
    }
}








