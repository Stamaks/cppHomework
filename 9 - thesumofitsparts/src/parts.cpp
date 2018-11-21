#include <iostream>
#include "parts.h"

void Part::describe()
{
    std::cout << "Part " << name << " subparts are:" << std::endl;

    if (subparts.empty())
        std::cout << "It has no subparts.";
    else
    {
        for (std::pair<Part const*, int> el : subparts)
        {
            std::cout << el.second << " " << el.first->name << std::endl;
        }
    }
}

int Part::count_howmany(Part const *p) const
{
    int sum = 0;

    // Если пришли в нужную вершину, возвращаем 1
    if (this == p)
        return 1;

    // Если пришли в лист и этот лист - не искомый нод, значит, в этой ветке ничего не нашли, возвращаем 0.
    if (subparts.empty())
        return 0;

    // Заходим в каждую ветку, идущую от текущей вершины
    for (std::pair<Part const*, int> el : subparts)
    {
        sum += el.first->count_howmany(p) * el.second;
    }

    return sum;
}

int Part::count_howmanyUp(Part const *p)
{
    int mult = 1;

    // Поднимаемся к предку и умножаем ответ на вес ребра
    while (p != this)
    {
        mult *= p->parent->subparts[p];
        p = p->parent;
    }

    return mult;
}

Part *NameContainer::lookup(std::string const &name)
{
    // Если не нашли имя части - создаем ее
    if (name_map.find(name) == name_map.end())
    {
        Part* part = new Part(name);
        name_map[name] = part;

        return part;
    }

    return name_map.find(name)->second;
}

void NameContainer::add_part(std::string const &part_name, int quantity, std::string const &subpart_name)
{
    // Принципиально не добавляем отрицательные и нулевые ребра
    if (quantity <= 0)
        throw std::invalid_argument("Quantity should be > 0!");

    Part* part = lookup(part_name);
    Part* subpart = lookup(subpart_name);

    // Запоминаем вес ребра
    part->subparts[subpart] = quantity;

    // Добавляем ссылку на родителя
    subpart->parent = part;
}

NameContainer::~NameContainer()
{
    for (std::pair<std::string, Part const*> el : name_map)
    {
        delete el.second;
    }
}
