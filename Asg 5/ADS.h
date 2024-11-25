// ADS.h - declaration of the AutonomousDrivingSystem (ADS) class

#ifndef AUTONOMOUSDRIVINGSYSTEM_H
#define AUTONOMOUSDRIVINGSYSTEM_H

#include "PerceptionModule.h"
#include "PlanningModule.h"
#include "ControlModule.h"

class AutonomousDrivingSystem
{
public:
    void initGpsData(double currLat, double currLon, double destLat, double destLon);
    void runSimulation();

private:
    GPSData gpsData;
    CameraData cameraData;
    LidarData lidarData;
    PerceptionModule perception;
    PlanningModule planning;
    ControlModule control;

    double speed = 100.0;    // Default speed
    double direction = 45.0; // Default direction
    double hoursElapsed = 0.0;
};

#endif // AUTONOMOUSDRIVINGSYSTEM_H
