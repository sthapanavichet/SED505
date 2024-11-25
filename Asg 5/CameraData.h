// CameraData.h - CameraData class declaration and implementation

#ifndef CAMERADATA_H
#define CAMERADATA_H

struct CameraData
{
    enum class ObjectType
    {
        none,
        vehicle,
        pedestrian,
        bicycle,
        stopLight,
        speedLimit
    };
    ObjectType object;
};

#endif // CAMERADATA_H
