// ADSMain.cpp - main program file

#include "ADS.h"
#include <iostream>

using namespace std;

int main()
{
    // Create an autonomous driving system
    AutonomousDrivingSystem autonomousDrivingSystem;
    double latitude1, latitude2;
    double longitude1, longitude2;

    cout << "What is your initial location (latitude): ";
    cin >> latitude1;
    cout << "                             (longitude): ";
    cin >> longitude1;

    cout << "What is your destination location (latitude): ";
    cin >> latitude2;
    cout << "                                 (longitude): ";
    cin >> longitude2;

    autonomousDrivingSystem.initGpsData(latitude1, longitude1, latitude2, longitude2);

    // Process the sensor data
    autonomousDrivingSystem.runSimulation();

    cout << "You have arrived! (close enough)" << endl;

    return 0;
}
