#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Toolbox/Toolbox.h"
#include "GroceryBag/GroceryBag.h"
#include "ShoppingCart.h"
#include "Customer.h"
#include "RetailStore.h"
#include "Toolbox/Hammer.h"
#include "Toolbox/Screwdriver.h"
#include "GroceryBag/Apple.h"
#include "GroceryBag/Orange.h"

RetailStore *RetailStore::instance = nullptr;

// Main function for simulation
int main()
{
    // Create store
    RetailStore *store;
    store = store->getInstance();

    // Create customers
    Customer customer1("Alice", 50.00);
    Customer customer2("Bob", 30.00);

    // Add items to their shopping carts
    ToolIf *hammer = new Hammer("Hammer", 15.00);
    ToolIf *screwdriver = new Screwdriver("Screwdriver", 10.00);

    GroceryIf *apple = new Apple("Apple", 1.00, 95);
    GroceryIf *orange = new Orange("Orange", 1.20, 80);

    // Fill customer1's cart
    customer1.AddToolToCart(hammer);
    customer1.AddGroceryToCart(apple);

    // Fill customer2's cart
    customer2.AddToolToCart(screwdriver);
    customer2.AddGroceryToCart(orange);

    // Checkout process
    store->AddCustomer(&customer1);
    store->CompletePurchase(&customer1);

    store->AddCustomer(&customer2);
    store->CompletePurchase(&customer2);

    // Display statistics
    store->DisplayStatistics();

    // Clean up dynamically allocated memory
    delete hammer;
    delete screwdriver;
    delete apple;
    delete orange;

    return 0;
}
