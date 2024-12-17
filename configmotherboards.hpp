#ifndef CONFIGMOTHERBOARDS_H
#define CONFIGMOTHERBOARDS_H

#include <vector>
#include "mathelems.hpp"
#include "config.hpp"

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
    double frameWidth;

    FrameConfig(double x_, double y_, double z_, double width_, double height_, double depth_, double frameWidth_)
        : x(x_), y(y_), z(z_), width(width_), height(height_), depth(depth_), frameWidth(frameWidth_) {}
};

class MicroATXMotherboardConfig
{
public:
    MicroATXMotherboardConfig(Dot3D &startOfPlate_, Dot3D &endOfPlate_) : startOfPlate(startOfPlate_), endOfPlate(endOfPlate_)
    {
        HDMI1_DP.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 10, BASE_Z + 60, 50, 60, 60));
        HDMI2.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 70, BASE_Z + 20, 20, 60, 20));
        KBMS_USB_E32.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 140, BASE_Z + 30, 20, 60, 30));
        U32G2_C2.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 210, BASE_Z + 30, 20, 60, 30));
        LAN_USB_E12.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 280, BASE_Z + 30, 20, 60, 30));
        AUDIO.push_back(ParallelepipedConfig(startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate() + 350, BASE_Z + 30, 20, 60, 30));
    }

    std::vector<ParallelepipedConfig> HDMI1_DP;
    std::vector<ParallelepipedConfig> HDMI2;
    std::vector<ParallelepipedConfig> KBMS_USB_E32;
    std::vector<ParallelepipedConfig> U32G2_C2;
    std::vector<ParallelepipedConfig> LAN_USB_E12;
    std::vector<ParallelepipedConfig> AUDIO;

private:
    Dot3D startOfPlate;
    Dot3D endOfPlate;
};

#endif // CONFIGMOTHERBOARDS_H
