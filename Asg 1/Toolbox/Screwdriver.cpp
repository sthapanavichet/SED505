#include "Screwdriver.h"

Screwdriver::Screwdriver(std::string name, double cost)
{
    this->name = name;
    this->cost = cost;
}

double Screwdriver::GetCost() const
{
    return cost;
}

void Screwdriver::display(std::ostream &os)
{
    os << "Screwdriver: " << name << ", Cost: " << cost << std::endl;
}
