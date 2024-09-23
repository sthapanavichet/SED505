#include "ShoppingCart.h"

void ShoppingCart::AddTool(ToolIf *tool)
{
    tools.push_back(tool);
}

void ShoppingCart::AddGrocery(GroceryIf *grocery)
{
    groceries.push_back(grocery);
}

double ShoppingCart::CalculateTotalCost()
{
    double total = 0.0;

    // Calculate total cost for tools
    for (auto tool : tools)
    {
        total += tool->GetCost();
    }

    // Calculate total cost for groceries
    for (auto grocery : groceries)
    {
        total += grocery->GetCost();
    }

    return total;
}

void ShoppingCart::DisplayItems()
{
    std::cout << "Tools in Cart: " << std::endl;
    for (auto tool : tools)
    {
        tool->display(std::cout);
    }

    std::cout << "Groceries in Cart: " << std::endl;
    for (auto grocery : groceries)
    {
        grocery->display(std::cout);
    }
}

double ShoppingCart::GetToolCost()
{
    double total = 0.0;
    for (auto tool : tools)
    {
        total += tool->GetCost();
    }
    return total;
}

double ShoppingCart::GetGroceryCost()
{
    double total = 0.0;
    for (auto grocery : groceries)
    {
        total += grocery->GetCost();
    }
    return total;
}
