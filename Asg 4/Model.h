// Model.h - Defines the Model class for generating predictions
#include <vector>

class Model
{
public:
    Model();
    int train();
    double predict(const std::vector<double> &inputData);

private:
    int ErrorAnalysis();
    std::vector<double> weights;
    const double freq = 50.0;
    const int steps = 360;
    const double PI = 3.141592653589793238;
};
