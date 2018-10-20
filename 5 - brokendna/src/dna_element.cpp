////////////////////////////////////////////////////////////////////////////////
// Module Name:  dna_repairer.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include <regex>
#include "dna_element.h"

DNAElement::DNAElement()
{
    id = ' ';
    number = -1;
    base = "";
}

DNAElement::DNAElement(const std::string &description)
{
    readFromString(description);
}

void DNAElement::readFromString(const std::string &description)
{
    if (isdigit(description[0]))
        throw std::invalid_argument("Wrong arg in position 0");

    std::string numberToParse;
    
    // Будем парсить number у ноды
    try
    {
        numberToParse = description.substr(1, description.size() - 3);
    }
    catch(std::out_of_range)
    {
        throw std::invalid_argument("Too big number!");
    }

    std::regex reg("[0-9]*");
    if (!std::regex_match(numberToParse.begin(), numberToParse.end(), reg))
        throw std::invalid_argument("Wrong number!");

    if (description[description.size() - 2] != ':')
        throw std::invalid_argument("Wrong arg! Needed ':'");

    if (description[description.size() - 1] != 'A' && description[description.size() - 1] != 'C' &&
            description[description.size() - 1] != 'G' && description[description.size() - 1] != 'T')
        throw std::invalid_argument("Wrong arg in the last position!");

    id = description[0];
    number = std::stoi(numberToParse);
    base = description[description.size() - 1];
}


