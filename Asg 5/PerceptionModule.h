// PerceptionModule - declaration of a class that processes camera, lidar and GPS data

#ifndef PERCEPTIONMODULE_H
#define PERCEPTIONMODULE_H

#include "CameraData.h"
#include "LidarData.h"
#include "GPSData.h"

class PerceptionModule
{
    int timer = 0; // increments once per hour
    const int MAX_TIME = 6;

public:
    void processCameraData(CameraData &cameraData);
    void processLidarData(LidarData &lidarData);
    void processGPSData(GPSData &gpsData, double speed, double direction);
    void incrementTime();
};

#endif // PERCEPTIONMODULE_H
