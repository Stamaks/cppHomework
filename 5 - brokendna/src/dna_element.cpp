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
        throw std::invalid_argument("Wrong arg in pos 0");

    if (!isdigit(description[1]))
        throw std::invalid_argument("Wrong arg in pos 1");

    if (description[2] != ':')
        throw std::invalid_argument("Wrong arg in pos 2");

    if (description[3] != 'A' && description[3] != 'C' && description[3] != 'G' && description[3] != 'T')
        throw std::invalid_argument("Wrong arg in pos 3");

    id = description[0];
    number = description[1] - '0'; // Дамми-способ перевести char в int
    base = description[3];
}


