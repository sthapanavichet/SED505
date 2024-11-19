// View.h - Defines the View class for displaying predictions
#ifndef VIEW_H
#define VIEW_H

class View
{
public:
    virtual void displayPrediction(double prediction) = 0;
    virtual ~View() = default;
};

#endif
