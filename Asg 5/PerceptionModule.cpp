// PerceptionModule.cpp - implementation of the PerceptionModule class

#define _USE_MATH_DEFINES
#include "PerceptionModule.h"
#include <math.h>

const double EARTH_CIRCUMFERENCE = 40040.0;

void PerceptionModule::processCameraData(CameraData &cameraData)
{
    switch (timer)
    {
    case 0:
        cameraData.object = CameraData::ObjectType::none;
        break;
    case 1:
        cameraData.object = CameraData::ObjectType::vehicle;
        break;
    case 2:
        cameraData.object = CameraData::ObjectType::pedestrian;
        break;
    case 3:
        cameraData.object = CameraData::ObjectType::bicycle;
        break;
    case 4:
        cameraData.object = CameraData::ObjectType::stopLight;
        break;
    case 5:
        cameraData.object = CameraData::ObjectType::speedLimit;
        break;
    default:
        cameraData.object = CameraData::ObjectType::none;
    }
}

void PerceptionModule::processLidarData(LidarData &lidarData)
{
    switch (timer)
    {
    case 0:
    case 3:
        lidarData.object = LidarData::ObjectType::roadCurvature;
        break;
    case 1:
    case 4:
        lidarData.object = LidarData::ObjectType::smallObstruction;
        break;
    case 2:
    case 5:
        lidarData.object = LidarData::ObjectType::largeObstruction;
        break;
    default:
        lidarData.object = LidarData::ObjectType::roadCurvature;
    }
}

void PerceptionModule::processGPSData(GPSData &gpsData, double speed, double direction)
{
    // Process GPS data for localization, mapping, etc.
    gpsData.curr_longitude += 180.0 * speed * sin(M_PI / 180.0 * direction) / EARTH_CIRCUMFERENCE;
    gpsData.curr_latitude += 180.0 * speed * cos(M_PI / 180.0 * direction) / EARTH_CIRCUMFERENCE;
}

void PerceptionModule::incrementTime()
{
    ++timer;
    timer = timer % MAX_TIME;
}