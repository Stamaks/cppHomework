#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "rail_system.h"
#include "string"
#include <iostream>
#include <fstream>

//TODO: REWRITE
RailSystem::RailSystem(const std::string &filename)
{
//    load_services(filename);

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
            if (!line.empty())
            {
                switch (index)
                {
                    case 0:
                        city_from = line;

                        if (cities.find(city_from) == cities.end())
                        {
                            cities[city_from] = new City(city_from);
                        }

                        break;

                    case 1:
                        city_to = line;

                        if (cities.find(city_to) == cities.end())
                        {
                            cities[city_to] = new City(city_to);
                        }

                        break;

                    case 2:
                        fee = std::stoi(line);

                        // Такого быть не может!
                        if (fee <= 0)
                            throw std::logic_error("The file is invalid!");

                        break;

                    case 3:
                        distance = std::stoi(line);

                        // Такого быть не может!
                        if (distance <= 0)
                            throw std::logic_error("The file is invalid!");

                        break;

                    default:
                        throw std::logic_error("The file is invalid!");
                }
            }
            else
                throw std::logic_error("The file is invalid!");

            if (index == 3)
            {
                outgoing_services[city_from].push_back(new Service(city_to, fee, distance));

                index = 0;
                city_from = "";
                city_to = "";
                fee = -1;
                distance = -1;
            }
            else
                ++index;
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

    for (int i = 0; i < outgoing_services.size(); ++i) {
        int v = -1;

        for (std::pair<std::string, std::list<Service*>> pair : outgoing_services)
        {
            if (!used[pair.first] && (v == -1 || current_distances[pair.first] < current_distances[pair.first]))
                v = j;
        }

        if (current_distances[v] == INT_MAX)
            break;

        used[v] = true;

        for (size_t j=0; j < g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }




}
