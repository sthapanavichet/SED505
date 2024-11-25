// ControlModule.cpp - implementation of the ControlModule class

#include "ControlModule.h"
#include <iostream>

using namespace std;

// Adjust speed and direction based on sensor data and route planning; return true if simulation ended, false if not.
void ControlModule::adjustVehicle(CameraData &cameraData, LidarData &lidarData, double &speed, double &direction)
{
    switch (cameraData.object)
    {
    case CameraData::ObjectType::vehicle:
        std::cout << "Avoiding a vehicle ahead." << std::endl;
        speed -= 5; // Slow down for vehicle
        break;
    case CameraData::ObjectType::pedestrian:
        speed -= 10; // Slow down for pedestrian
        break;
    case CameraData::ObjectType::stopLight:
        speed = 0; // Stop for stop light
        break;
    default:
        speed = 100; // default speed
        break;
    }

    switch (lidarData.object)
    {
    case LidarData::ObjectType::smallObstruction:
        std::cout << "Route updated: Navigating around a small obstruction." << std::endl;
        direction += (rand() % 20) / 100.0;
        break;
    case LidarData::ObjectType::largeObstruction:
        std::cout << "Route updated: Rerouting to avoid a large obstruction." << std::endl;
        direction += (rand() % 100) / 100.0;
    default:
        break;
    }
}
