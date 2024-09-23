// Customer class
#include "Customer.h"

Customer::Customer(const std::string &name, double cash) : name(name), cash(cash) {}

void Customer::AddToolToCart(ToolIf *tool)
{
    cart.AddTool(tool);
}

void Customer::AddGroceryToCart(GroceryIf *grocery)
{
    cart.AddGrocery(grocery);
}

double Customer::Checkout()
{
    double totalCost = cart.CalculateTotalCost();
    if (cash >= totalCost)
    {
        cash -= totalCost;
        return totalCost;
    }
    else
    {
        std::cout << "Insufficient funds to complete the purchase!" << std::endl;
        return 0.0;
    }
}

void Customer::DisplayCart()
{
    cart.DisplayItems();
}

ShoppingCart &Customer::GetCart()
{
    return cart;
}

std::string Customer::GetName()
{
    return name;
}