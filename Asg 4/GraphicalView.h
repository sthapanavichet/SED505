// GraphicalView.h - Defines the GraphicalView class for displaying predictions
#include "View.h"

class GraphicalView : public View
{
public:
    void displayPrediction(double prediction) override;
};