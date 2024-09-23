#ifndef ORANGE_H
#define ORANGE_H

#include "GroceryIf.h"

class Orange : public GroceryIf
{
    std::string name;
    double cost;
    double calories;

public:
    Orange(std::string name, double cost, double calories);
    double GetCost() const;
    void display(std::ostream &os);
};

#endif // ORANGE_H