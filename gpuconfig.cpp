#include "gpuconfig.hpp"

void GPUConfig::applyMotherboardOffset(ComponentConfig &gpuBlock, Dot3D &motherboardOffset)
{
    for (auto &p : gpuBlock.parallelepipeds)
    {
        p.x += motherboardOffset.getXCoordinate();
        p.y += motherboardOffset.getYCoordinate();
        p.z += motherboardOffset.getZCoordinate();
    }
    for (auto &f : gpuBlock.frames)
    {
        f.x += motherboardOffset.getXCoordinate();
        f.y += motherboardOffset.getYCoordinate();
        f.z += motherboardOffset.getZCoordinate();
    }
}

void GPUConfig::applyMotherboardOffsetAcc(ComponentConfig &gpuAccBlock, Dot3D &motherboardAccOffset, int splitIncrement)
{
    int coeff = 0;
    for (auto &p : gpuAccBlock.parallelepipeds)
    {
        int currentShift = (coeff * p.width) + (coeff * splitIncrement);
        p.x += motherboardAccOffset.getXCoordinate() + currentShift;
        p.y += motherboardAccOffset.getYCoordinate();
        p.z += motherboardAccOffset.getZCoordinate();
        coeff++;
    }
    for (auto &f : gpuAccBlock.frames)
    {
        f.x += motherboardAccOffset.getXCoordinate();
        f.y += motherboardAccOffset.getYCoordinate();
        f.z += motherboardAccOffset.getZCoordinate();
    }
}

ComponentConfig GPUConfig::getGPUConfig(ConfigManager::GPUType gpuType, Dot3D &motherboardOffset)
{
    ComponentConfig gpuBlock = gpuMappings.at(gpuType);
    applyMotherboardOffset(gpuBlock, motherboardOffset);
    return gpuBlock;
}

ComponentConfig GPUConfig::getGPUAccConfig(ConfigManager::GPUAccessoriesType gpuAccType, Dot3D &motherboardOffset, int splitIncrement)
{
    ComponentConfig gpuBlock = gpuAccessoriesMappings.at(gpuAccType);
    applyMotherboardOffsetAcc(gpuBlock, motherboardOffset, splitIncrement);
    return gpuBlock;
}
