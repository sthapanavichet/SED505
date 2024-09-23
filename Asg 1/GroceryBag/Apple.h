#ifndef APPLE_H
#define APPLE_H

#include "GroceryIf.h"

class Apple : public GroceryIf
{
    std::string name;
    double cost;
    double calories;

public:
    Apple(std::string name, double cost, double calories);
    double GetCost() const;
    void display(std::ostream &os);
};

#endif // APPLE_H