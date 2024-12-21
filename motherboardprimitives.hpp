#ifndef MOTHERBOARDPRIMITIVES_HPP
#define MOTHERBOARDPRIMITIVES_HPP

#include <vector>

struct ParallelepipedConfig
{
    double x, y, z;
    double width, height, depth;

    ParallelepipedConfig(double x_, double y_, double z_, double width_, double height_, double depth_)
        : x(x_), y(y_), z(z_), width(width_), height(height_), depth(depth_) {}
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
};

struct componentConfig
{
    std::vector<ParallelepipedConfig> parallelepipeds;
    std::vector<FrameConfig> frames;

    componentConfig(std::initializer_list<ParallelepipedConfig> pConfigs, std::initializer_list<FrameConfig> fConfigs)
        : parallelepipeds(pConfigs), frames(fConfigs) {}
};

#endif // MOTHERBOARDPRIMITIVES_HPP
