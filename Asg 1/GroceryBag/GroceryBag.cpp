// GroceryBag.cpp - full code for the grocery bag. This needs to be broken into the appropriate files

#include <string> //getline
#include <vector>

#include "GroceryBag.h"

GroceryBag::GroceryBag(std::string name)
{
	this->name = name;
	numItems = 0;
	totalCost = 0.0;
}
bool GroceryBag::AddGrocery(GroceryIf &grocery)
{
	int ret = true;
	if (numItems < MAX_GROCERIES)
	{
		item.push_back(&grocery);
		++numItems;
		totalCost += grocery.GetCost();
	}
	else
	{
		ret = false;
	}
	return ret;
}
void GroceryBag::display(std::ostream &os)
{
	os.setf(std::ios::fixed);
	os.precision(2);
	os << std::endl;
	os << name << " is a grocery bag with the following items:" << std::endl;
	for (int i = 0; i < numItems; ++i)
	{
		item[i]->display(os);
	}
	os << "The total cost of these items is $" << totalCost << std::endl
	   << std::endl;
}