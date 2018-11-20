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

    //�������������� ������� �� ���������(*), ������� �� �������� �������� ����������!
    //����� �� ������� ��� ������ ����� ������ ����, � ����� ��������� �� parent...
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
    //����������� �� ���������
    NameContainer() {};

    //����� �� ��� ����������?
    ~NameContainer();

    //����� ������ �����
    Part* lookup(std::string const &name);

    //���������� �������� � ���������
    void add_part(std::string const &part_name, int quantity, std::string const &subpart_name);

private:
    std::map<std::string, Part*> name_map;
};

#endif
