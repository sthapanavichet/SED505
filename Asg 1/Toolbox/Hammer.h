#ifndef HAMMER_H
#define HAMMER_H

#include <string>
#include <iostream>
#include "ToolIf.h"

class Hammer : public ToolIf
{
    std::string name;
    double cost;

public:
    Hammer(std::string name, double cost);
    double GetCost() const;
    void display(std::ostream &os);
};

#endif // HAMMER_H
