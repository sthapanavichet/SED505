// Model.cpp - Implements the Model class
#include "Model.h"
#ifdef TEST_BUILD
#define _USE_MATH_DEFINES
#include <cmath>
#endif
#include <iostream>
#include <cmath>

Model::Model() {}

int Model::train()
{
    const double w = 2.0 * PI * freq;
    const double P = 1.0 / freq;
    double time;
    int maxTerms = 1;

    while (true)
    {
        weights.resize(steps);
        for (int i = 0; i <= steps / 4; ++i)
        {
            time = P * (double)i / steps; // from 0 to P seconds
            double x = w * time;
            weights[i] = x; // - x * x * x / fact3;// + x * x * x * x * x / fact5;// - x * x * x * x * x * x * x / fact7;// + x * x * x * x * x * x * x * x * x / fact9;
            double sign = -1.0;
            for (int term = 1; term < maxTerms; ++term)
            {
                double factorial = 1.0;
                for (int k = 2; k <= 2 * term + 1; ++k)
                {
                    factorial *= k;
                }
                double newTerm = pow(x, 2 * term + 1) / factorial;
                weights[i] += sign * newTerm;
                sign *= -1.0;
            }
#ifdef TEST_BUILD // define TEST_BUILD to visually see the accuracy of the Taylor Series
            std::cout.precision(6);
            std::cout.setf(std::ios::fixed);
            double trueValue = sin(x);
            std::cout << "i: " << i << " time: " << time << " weights:" << weights[i] << " trueValue: " << trueValue << std::endl;
            * /
#endif
        }

        // Generate the second quarter of the sine wave from the first quarter
        for (int i = steps / 4; i < steps / 2; ++i)
        {
            weights[i] = weights[steps / 2 - i];
        }

        // Generate the second half of the sine wave from the first half
        for (int i = steps / 2; i < steps; ++i)
        {
            weights[i] = -weights[i - steps / 2];
        }

        if (ErrorAnalysis() == 0)
        {
            break;
        }

        ++maxTerms;
    }

    return 0;
}

int Model::ErrorAnalysis()
{
    double stdDev = 0.0;
    const double TOLERANCE = 0.001;
    const double w = 2.0 * PI * freq;
    const double P = 1.0 / freq;
    double diffSum = 0.0;

    for (int i = 0; i < steps; ++i)
    {
        double time = P * (double)i / steps;
        double trueValue = sin(w * time);
        diffSum += (weights[i] - trueValue) * (weights[i] - trueValue);
    }

    stdDev = sqrt(diffSum / (steps - 1));

    // Output stdDev and indicate if it's above tolerance
    if (stdDev > TOLERANCE)
    {
        std::cout << "stdDev: " << stdDev << std::endl;
        std::cout << "ERROR: The training model is inaccurate!" << std::endl
                  << std::endl;
        return -1; // continue refining
    }
    else
    {
        std::cout << "The training model is accurate." << std::endl
                  << std::endl;
        return 0; // model is accurate
    }
}

double Model::predict(const std::vector<double> &inputData)
{
    double prediction = 0.0;

    // Check if the weights are empty
    if (weights.empty())
    {
        std::cout << "Model weights are empty!" << std::endl;
        return 0.0;
    }

    // Iterate through each input data point (representing time or x-values)
    for (const double &input : inputData)
    {
        // Map the input time (or x-value) to an index in the weights array
        int index = (int)((input * steps) / (1.0 / freq)) % steps;

        // Sum the predictions
        prediction += weights[index];
    }

    // Return the average prediction to get a reasonable output
    return prediction / inputData.size();
}
