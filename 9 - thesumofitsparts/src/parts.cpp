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

    if (this == p)
        return 1;

    if (subparts.empty())
        return 0;

    for (std::pair<Part const*, int> el : subparts)
    {
        sum += el.first->count_howmany(p) * el.second;
    }

    return sum;
}

Part *NameContainer::lookup(std::string const &name)
{
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
    if (quantity <= 0)
        throw std::invalid_argument("Quantity should be > 0!");

    Part* part = lookup(part_name);
    Part* subpart = lookup(subpart_name);

    part->subparts[subpart] = quantity;
}

//TODO: destructor
NameContainer::~NameContainer()
{

}
