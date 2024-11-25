// PlanningModule.cpp - implementation of the PlanningModule class

#include "PlanningModule.h"
#include <iostream>
#include <math.h>

const double EARTH_CIRCUMFERENCE = 40040.0;

// Plan the route based on current and destination GPS data
void PlanningModule::planRoute(const GPSData &gpsData)
{
    distanceToDestination = calculateDistance(gpsData);
    std::cout << "Initial route planned. Distance to destination: " << distanceToDestination << " km" << std::endl;
}

// Update the route based on camera and LIDAR data
void PlanningModule::updateRoute(const CameraData &cameraData, const LidarData &lidarData, const GPSData &gpsData)
{
    switch (cameraData.object)
    {
    case CameraData::ObjectType::vehicle:
        std::cout << "Route updated: Avoiding a vehicle ahead." << std::endl;
        distanceToDestination += 0.5; // Slow down for a vehicle
        break;
    case CameraData::ObjectType::pedestrian:
        break;
    case CameraData::ObjectType::stopLight:
        break;
    default:
        break;
    }

    switch (lidarData.object)
    {
    case LidarData::ObjectType::smallObstruction:
        std::cout << "Route updated: Navigating around a small obstruction." << std::endl;
        distanceToDestination += 0.5;
        break;
    case LidarData::ObjectType::largeObstruction:
        std::cout << "Route updated: Rerouting to avoid a large obstruction." << std::endl;
        distanceToDestination += 2.0;
        break;
    default:
        break;
    }
    distanceToDestination = calculateDistance(gpsData);
}

// Calculate the distance between the current and destination GPS coordinates
double PlanningModule::calculateDistance(const GPSData &gpsData) const
{
    double latDiff = gpsData.dest_latitude - gpsData.curr_latitude;
    double lonDiff = gpsData.dest_longitude - gpsData.curr_longitude;
    return sqrt(latDiff * latDiff + lonDiff * lonDiff) * EARTH_CIRCUMFERENCE / 360.0;
}

// Get the current distance to the destination
double PlanningModule::getDistanceToDestination() const
{
    return distanceToDestination;
}