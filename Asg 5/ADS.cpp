// ADS.cpp - implementation of the AutonomousDrivingSystem class

#define _USE_MATH_DEFINES
#include "ADS.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void AutonomousDrivingSystem::initGpsData(double currLat, double currLon, double destLat, double destLon)
{
    gpsData = {currLat, currLon, destLat, destLon};
    planning.planRoute(gpsData);
}

void AutonomousDrivingSystem::runSimulation()
{
    while (true)
    {
        double distance = planning.getDistanceToDestination();

        perception.processCameraData(cameraData);
        perception.processLidarData(lidarData);
        perception.processGPSData(gpsData, speed, direction);

        planning.updateRoute(cameraData, lidarData, gpsData);

        control.adjustVehicle(cameraData, lidarData, speed, direction);

        cout << fixed << setprecision(4);
        cout << "You are at " << gpsData.curr_longitude << " long, " << gpsData.curr_latitude << " lat." << endl;
        cout << "You want to be at " << gpsData.dest_longitude << " long, " << gpsData.dest_latitude << " lat." << endl;
        cout << "You are " << distance << "km away from your destination." << endl;
        cout << "You need to travel at " << direction << " degrees." << endl;

        if (distance <= 25.0 || hoursElapsed >= 24)
        {
            break;
        }
        perception.incrementTime();
        hoursElapsed++;
    }
}
