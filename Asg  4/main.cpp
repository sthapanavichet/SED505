// main.cpp - Modified main to align with desired output
#include "ConsoleView.h"
#include "GraphicalView.h"
#include "Controller.h"

int main()
{
    Model *model = new Model();
    View *graphicalView = new GraphicalView();
    View *consoleView = new ConsoleView();
    Controller controller(model);
    controller.addView(graphicalView);
    controller.addView(consoleView);

    // Train the model
    model->train();

    // Run the trials
    controller.runTrials();

    return 0;
}
