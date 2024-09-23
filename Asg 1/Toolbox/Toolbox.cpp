// Toolbox.cpp - full code for the toolbox. This needs to be broken into the appropriate files
#include "Toolbox.h"

#include <string> //getline
#include <vector>

using namespace std;

Toolbox::Toolbox(std::string name)
{
	this->name = name;
	numItems = 0;
	totalCost = 0.0;
}

bool Toolbox::AddTool(ToolIf &tool)
{
	int ret = true;
	if (numItems < MAX_TOOLS)
	{
		item.push_back(&tool);
		++numItems;
		totalCost += tool.GetCost();
	}
	else
	{
		ret = false;
	}
	return ret;
}

void Toolbox::display(std::ostream &os)
{
	os.setf(std::ios::fixed);
	os.precision(2);
	os << std::endl;
	os << name << " is a toolbox with the following items:" << std::endl;
	for (int i = 0; i < numItems; ++i)
	{
		item[i]->display(os);
	}
	os << "The total cost of these items is $" << totalCost << std::endl
	   << std::endl;
}