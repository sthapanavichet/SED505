#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

#include <string>
#include <iostream>
#include "ToolIf.h"

class Screwdriver : public ToolIf
{
    std::string name;
    double cost;

public:
    Screwdriver(std::string name, double cost);
    double GetCost() const;
    void display(std::ostream &os);
};

#endif // SCREWDRIVER_H