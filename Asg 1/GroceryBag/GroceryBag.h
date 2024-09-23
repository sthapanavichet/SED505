// GroceryBag.h

#ifndef GROCERYBAG_H
#define GROCERYBAG_H

#include <string>
#include <vector>
#include <iostream>
#include "GroceryIf.h"

class GroceryBag
{
    const int MAX_GROCERIES = 4;
    std::string name;
    double totalCost;
    std::vector<GroceryIf *> item;
    int numItems;

public:
    GroceryBag(std::string name);
    bool AddGrocery(GroceryIf &grocery);
    void display(std::ostream &os);
};

#endif // GROCERYBAG_H