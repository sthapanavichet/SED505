#ifndef RETAILSTORE_H
#define RETAILSTORE_H

#include <vector>
#include "Customer.h" // Assuming you have a Customer class defined in Customer.h

class RetailStore
{
private:
    std::vector<Customer *> customers;
    double totalRevenue;
    double totalToolRevenue;
    double totalGroceryRevenue;
    static RetailStore *instance;
    RetailStore() : totalRevenue(0), totalToolRevenue(0), totalGroceryRevenue(0) {}

public:
    static RetailStore *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new RetailStore();
        }
        return instance;
    }

    void AddCustomer(Customer *customer);
    void CompletePurchase(Customer *customer);
    void DisplayStatistics();
};
;

#endif // RETAILSTORE_H
