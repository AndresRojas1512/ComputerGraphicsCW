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

struct ComponentConfig
{
    std::vector<ParallelepipedConfig> parallelepipeds;
    std::vector<FrameConfig> frames;

    ComponentConfig(std::initializer_list<ParallelepipedConfig> pConfigs, std::initializer_list<FrameConfig> fConfigs)
        : parallelepipeds(pConfigs), frames(fConfigs) {}

    friend std::ostream& operator<<(std::ostream& os, const ComponentConfig& config);
};

#endif // COMPONENTPRIMITIVES_H
