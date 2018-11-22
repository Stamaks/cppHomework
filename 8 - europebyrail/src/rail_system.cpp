#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "rail_system.h"
#include "string"
#include <tgmath.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include "city_heap.h"

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
    find_shortest_route(from, to);

    // Не нашли пути(((                      не путю
    if (cities[to]->total_distance == INT_MAX)
        return std::make_pair(INT_MAX, INT_MAX);

    return std::make_pair(cities[to]->total_fee, cities[to]->total_distance);
}

std::vector<std::string> RailSystem::recover_route(const std::string& city)
{
    if (!is_valid_city(city))
        throw std::invalid_argument("There is no such city!");

    std::vector<std::string> route;
    std::string current_city = city;

    route.push_back(current_city);

    while (cities[current_city]->from_city != "")
    {
        route.push_back(cities[current_city]->from_city);
        current_city = cities[city]->from_city;
    }

    return route;
}

void RailSystem::output_cheapest_route(const std::string& from, const std::string& to)
{
    find_cheapest_route(from, to);

    if (cities[to]->total_distance == INT_MAX)
        std::cout << "There is no route from " << from << " to " << to << std::endl;
    else
    {
        std::cout << "The cheapest route from " << from << " to " << to <<
                     " costs " << cities[to]->total_fee << " euros and spans " <<
                     cities[to]->total_distance << " kilometers" << std::endl;

        // Восстанавливаем путь
        std::vector<std::string> route = recover_route(to);

        // Печатаем путь
        for (size_t i = route.size() - 1; i > 0; --i)
        {
            std::cout << route[i] << " to ";
        }

        std::cout << route[0] << std::endl;
    }
}

void RailSystem::find_shortest_route(const std::string &from, const std::string &to)
{
    if (!is_valid_city(from) || !is_valid_city(to))
        throw std::invalid_argument("There is no such city!");

    // Очищаем всю информацию о городах
    reset();

    std::priority_queue<City *, std::vector<City *>, Shortest> queue;

    // Расстояние от from до from, очевидно, равно 0
    cities[from]->total_distance = 0;

    // Заполняем очередь
    queue.push(cities[from]);

    for (std::pair<std::string, City*> pair : cities)
    {
        if (pair.first != from)
        {
            // Изначально расстояние до каждого города, который не from, равно условной бесконечности
            pair.second->total_distance = INT_MAX;
            queue.push(pair.second);
        }
    }

    bool have_to_rebuild = true;

    // Дейкстра!
    for (int i = 0; i < outgoing_services.size(); ++i) {
        City* current_city = queue.top();
        queue.pop();

        // Ищем не помеченный город с наименьшим до него расстоянием
        while (current_city->visited && !queue.empty())
        {
            current_city = queue.top();
            queue.pop();
        }

        // Останавливаемся, если пути нет
        if (current_city->total_distance == INT_MAX)
            break;

        current_city->visited = true;

        // Релаксируем
        for (Service* service : outgoing_services[current_city->name])
        {
            // Если текущее расстояние до города больше, обновляем
            if (cities[service->destination]->total_distance > current_city->total_distance + service->distance)
            {
                cities[service->destination]->total_distance = current_city->total_distance + service->distance;
                cities[service->destination]->total_fee = current_city->total_fee + service->fee;
                cities[service->destination]->from_city = current_city->name;
                have_to_rebuild = true;
            }
        }

        // Перестраиваем очередь, но только если были обновления
        if (have_to_rebuild)
        {
            // Очищаем очередь
            while (!queue.empty())
                queue.pop();

            for (std::pair<std::string, City*> pair : cities)
            {
                queue.push(pair.second);
            }
        }

        have_to_rebuild = false;
    }
}

void RailSystem::find_cheapest_route(const std::string& from, const std::string& to)
{
    if (!is_valid_city(from) || !is_valid_city(to))
        throw std::invalid_argument("There is no such city!");

    // Очищаем всю информацию о городах
    reset();

    std::priority_queue<City *, std::vector<City *>, Cheapest> queue;

    // Расстояние от from до from, очевидно, равно 0
    cities[from]->total_distance = 0;

    // Заполняем очередь
    queue.push(cities[from]);

    for (std::pair<std::string, City*> pair : cities)
    {
        if (pair.first != from)
        {
            // Изначально расстояние до каждого города, который не from, равно условной бесконечности
            pair.second->total_distance = INT_MAX;
            queue.push(pair.second);
        }
    }

    bool have_to_rebuild = true;

    // Дейкстра!
    for (int i = 0; i < outgoing_services.size(); ++i) {
        City* current_city = queue.top();
        queue.pop();

        // Ищем не помеченный город с наименьшим до него расстоянием
        while (current_city->visited && !queue.empty())
        {
            current_city = queue.top();
            queue.pop();
        }

        // Останавливаемся, если пути нет
        if (current_city->total_distance == INT_MAX)
            break;

        current_city->visited = true;

        // Релаксируем
        for (Service* service : outgoing_services[current_city->name])
        {
            // Если текущее стоимость пути до города больше, обновляем
            if (cities[service->destination]->total_fee > current_city->total_fee + service->fee)
            {
                cities[service->destination]->total_distance = current_city->total_distance + service->distance;
                cities[service->destination]->total_fee = current_city->total_fee + service->fee;
                cities[service->destination]->from_city = current_city->name;
                have_to_rebuild = true;
            }
        }

        // Перестраиваем очередь, но только если были обновления
        if (have_to_rebuild)
        {
            // Очищаем очередь
            while (!queue.empty())
                queue.pop();

            for (std::pair<std::string, City*> pair : cities)
            {
                queue.push(pair.second);
            }
        }

        have_to_rebuild = false;
    }
}

bool RailSystem::is_valid_city(const std::string &name)
{
    return cities.find(name) != cities.end();
}







