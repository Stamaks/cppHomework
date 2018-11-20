#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

//**************** Part ****************
class Part 
{
public:
    std::string name;
    std::map<Part const*, int> subparts;

    //Дополнительное задание на звездочку(*), которое не отменяет основной реализации!
    //Можно ли сделать без обхода всего дерева вниз, а через указатель на parent...
    Part* parent;
    int count_howmanyUp(Part const* p);

    Part(std::string const& n) : name(n) {};
    void describe();
    int count_howmany(Part const* p) const;
};

//**************** NameContainer ****************
class NameContainer  
{
public:
    //Конструктор по умолчанию
    NameContainer() {};

    //Нужен ли тут деструктор?
    ~NameContainer();

    //Метод поиска части
    Part* lookup(std::string const &name);

    //Добавление элемента в контейнер
    void add_part(std::string const &part_name, int quantity, std::string const &subpart_name);

private:
    std::map<std::string, Part*> name_map;
};

#endif
