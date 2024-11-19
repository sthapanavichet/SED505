// ConsoleView.h - Defines the ConsoleView class for displaying predictions
#include "View.h"

class ConsoleView : public View
{
public:
    void displayPrediction(double prediction) override;
};