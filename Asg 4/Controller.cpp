// Controller.cpp - Implements the Controller class
#include "Controller.h"
#include <cstdlib>
#include <iostream>

Controller::Controller(Model *m) : model(m) {}

void Controller::addView(View *v)
{
    views.push_back(v);
}

void Controller::runTrials()
{
    const int TRIALS = 5;
    const int NUM = 1000;

    for (int i = 0; i < TRIALS; ++i)
    {
        std::vector<double> inputData;
        for (int j = 0; j < NUM; ++j)
        {
            inputData.push_back((double)(rand() % 1000) / 1000);
        }

        double prediction = model->predict(inputData);
        for (auto view : views)
        {
            view->displayPrediction(prediction);
        }
        std::cout << std::endl;
    }
}
