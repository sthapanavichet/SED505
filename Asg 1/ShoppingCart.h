#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Toolbox/Toolbox.h"
#include "GroceryBag/GroceryBag.h"

class ShoppingCart
{
private:
    std::vector<ToolIf *> tools;
    std::vector<GroceryIf *> groceries;

public:
    void AddTool(ToolIf *tool);
    void AddGrocery(GroceryIf *grocery);
    double CalculateTotalCost();
    void DisplayItems();
    double GetToolCost();
    double GetGroceryCost();
};

#endif // SHOPPINGCART_H