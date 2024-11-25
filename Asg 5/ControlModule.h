// ControlModule.h - declaration of a class that controls the vehicle based on sensor data and planning data

#ifndef CONTROLMODULE_H
#define CONTROLMODULE_H

#include "PerceptionModule.h"
#include "PlanningModule.h"
#include "GPSData.h"

class ControlModule
{
public:
    void adjustVehicle(CameraData &cameraData, LidarData &lidarData, double &speed, double &direction);
};

#endif // CONTROLMODULE_H
