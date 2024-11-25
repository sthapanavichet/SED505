// PlanningModule.h - declaration of a class that plans a route based on GPS data and obstacle information

#ifndef PLANNINGMODULE_H
#define PLANNINGMODULE_H

#include "GPSData.h"
#include "CameraData.h"
#include "LidarData.h"

class PlanningModule
{
    double distanceToDestination = 0.0;
    // Utility function to calculate the distance between two GPS coordinates
    double calculateDistance(const GPSData &gpsData) const;

public:
    void planRoute(const GPSData &gpsData);
    void updateRoute(const CameraData &cameraData, const LidarData &lidarData, const GPSData &gpsData);
    double getDistanceToDestination() const;
};

#endif // PLANNINGMODULE_H
