#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <iostream>
#include <string>
#include <vector>
#include "ToolIf.h"

class Toolbox
{
    const int MAX_TOOLS = 4;
    std::string name;
    double totalCost;
    std::vector<ToolIf *> item;
    int numItems;

public:
    Toolbox(std::string name);
    bool AddTool(ToolIf &tool);
    void display(std::ostream &os);
};

#endif // TOOLBOX_H
