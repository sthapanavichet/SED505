// Controller.h - Defines the Controller class
#include "Model.h"
#include "View.h"
#include <vector>

class Controller
{
public:
    Controller(Model *model);
    void addView(View *view);
    void runTrials();

private:
    Model *model;
    std::vector<View *> views;
};
