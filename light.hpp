#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "mathelems.hpp"
#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"

class Light
{
public:
    Light(Eigen::Matrix4f &transMat);
    Light(){};

    void setShadowMap(std::vector<std::vector<double>> &setShadowMap);
    std::vector<std::vector<double>> &getShadowMap();
    void clearShadowMap();

    void setAngles(int xAngle_, int yAngle_);
    int getXAngle();
    int getYAngle();

    void setTransMat(Eigen::Matrix4f &mat);
    Eigen::Matrix4f &getTransMat();

private:
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transMatrix;
    int xAngle, yAngle;
};

#endif // LIGHT_HPP
