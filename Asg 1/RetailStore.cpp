// RetailStore class
#include "RetailStore.h"
#include <iomanip>

void RetailStore::AddCustomer(Customer *customer)
{
    customers.push_back(customer);
}

void RetailStore::RetailStore::CompletePurchase(Customer *customer)
{
    double totalCost = customer->Checkout();
    if (totalCost > 0)
    {
        totalRevenue += totalCost;
        totalToolRevenue += customer->GetCart().GetToolCost();
        totalGroceryRevenue += customer->GetCart().GetGroceryCost();
    }
}

void RetailStore::DisplayStatistics()
{
    double averageSpending = totalRevenue / customers.size();
    double toolPercentage = (totalToolRevenue / totalRevenue) * 100;
    double groceryPercentage = (totalGroceryRevenue / totalRevenue) * 100;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    std::cout << "Average Customer Spending: $" << averageSpending << std::endl;
    std::cout << "Percentage of Revenue from Tools: " << toolPercentage << "%" << std::endl;
    std::cout << "Percentage of Revenue from Groceries: " << groceryPercentage << "%" << std::endl;
}
