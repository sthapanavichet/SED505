// LidarData.h - LidarData class declaration and implementation

#ifndef LIDARDATA_H
#define LIDARDATA_H

struct LidarData
{
    enum class ObjectType
    {
        roadCurvature,
        smallObstruction,
        largeObstruction,
    };
    ObjectType object;
};

#endif // LIDARDATA_H
