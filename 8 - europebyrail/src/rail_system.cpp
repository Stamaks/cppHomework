#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "rail_system.h"
#include "string"
#include <iostream>
#include <fstream>

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

//TODO: REWRITE
RailSystem::RailSystem(const std::string &filename)
{
//    load_services(filename);

}

//TODO: REWRITE
RailSystem::~RailSystem()
{
}
