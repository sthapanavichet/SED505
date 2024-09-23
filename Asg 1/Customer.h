// Customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "ShoppingCart.h"
#include "Toolbox/ToolIf.h"
#include "GroceryBag/GroceryIf.h"

// Customer class
class Customer
{
private:
    std::string name;
    double cash;
    ShoppingCart cart;

public:
    Customer(const std::string &name, double cash);
    void AddToolToCart(ToolIf *tool);
    void AddGroceryToCart(GroceryIf *grocery);
    double Checkout();
    void DisplayCart();
    ShoppingCart &GetCart();
    std::string GetName();
};

#endif // CUSTOMER_H
