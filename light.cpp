#include "light.hpp"

Light::Light(Eigen::Matrix4f &transMatrix_)
{
    transMatrix = transMatrix_;
    for (size_t i = 0; i < LIGHT_X; i++)
    { shadowMap.push_back(std::vector<double>(LIGHT_Y, 0)); }
}

std::vector<std::vector<double>> &Light::getShadowMap()
{
    return shadowMap;
}

int Light::getXAngle()
{
    return xAngle;
}

int Light::getYAngle()
{
    return yAngle;
}

Eigen::Matrix4f &Light::getTransMat()
{
    return transMatrix;
}

void Light::setShadowMap(std::vector<std::vector<double>> &setShadowMap)
{
    shadowMap = setShadowMap;
}

void Light::clearShadowMap()
{
    for (size_t i = 0; i < shadowMap.size(); i++)
    {
        for (size_t j = 0; j < shadowMap.at(0).size(); j++)
            shadowMap.at(i).at(j) = 0;
    }
}

void Light::setAngles(int xAngle_, int yAngle_)
{
    xAngle = xAngle_;
    yAngle = yAngle_;
}

void Light::setTransMat(Eigen::Matrix4f &mat) { transMatrix = mat; }
