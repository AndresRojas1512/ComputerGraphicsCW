#ifndef COMPONENTPRIMITIVES_H
#define COMPONENTPRIMITIVES_H

#include <iostream>
#include <vector>

struct ParallelepipedConfig
{
    double x, y, z;
    double width, height, depth;

    ParallelepipedConfig(double x_, double y_, double z_, double width_, double height_, double depth_)
        : x(x_), y(y_), z(z_), width(width_), height(height_), depth(depth_) {}

    friend std::ostream& operator<<(std::ostream& os, const ParallelepipedConfig& p);
};

struct FrameConfig
{
    double x, y, z;
    double width, height, depth;
    double topFrameWidth, bottomFrameWidth, leftFrameWidth, rightFrameWidth;

    FrameConfig(double x_, double y_, double z_,
                double width_, double height_, double depth_,
                double topFrameWidth_, double bottomFrameWidth_,
                double leftFrameWidth_, double rightFrameWidth_)
        : x(x_), y(y_), z(z_), width(width_), height(height_), depth(depth_),
        topFrameWidth(topFrameWidth_), bottomFrameWidth(bottomFrameWidth_),
        leftFrameWidth(leftFrameWidth_), rightFrameWidth(rightFrameWidth_) {}

    friend std::ostream& operator<<(std::ostream& os, const FrameConfig& f);
};

struct CylinderConfig
{
    double x, y, z;
    double radius, height;
    int segments;

    CylinderConfig(double x_, double y_, double z_, double radius_, double height_, int segments_)
        : x(x_), y(y_), z(z_), radius(radius_), height(height_), segments(segments_) {}

    friend std::ostream& operator<<(std::ostream& os, const CylinderConfig& c);
};


struct ComponentConfig
{
    std::vector<ParallelepipedConfig> parallelepipeds;
    std::vector<FrameConfig> frames;
    std::vector<CylinderConfig> cylinders;

    ComponentConfig(std::initializer_list<ParallelepipedConfig> pConfigs, std::initializer_list<FrameConfig> fConfigs, std::initializer_list<CylinderConfig> cConfigs)
        : parallelepipeds(pConfigs), frames(fConfigs), cylinders(cConfigs) {}

    // ComponentConfig(std::initializer_list<ParallelepipedConfig> pConfigs, std::initializer_list<FrameConfig> fConfigs)
    //     : parallelepipeds(pConfigs), frames(fConfigs) {}

    friend std::ostream& operator<<(std::ostream& os, const ComponentConfig& config);
};

#endif // COMPONENTPRIMITIVES_H
