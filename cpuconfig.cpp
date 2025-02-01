#include "cpuconfig.hpp"

void CPUConfig::applyMotherboardOffset(ComponentConfig &cpuBlock, Dot3D &motherboardOffset)
{
    for (auto &p : cpuBlock.parallelepipeds)
    {
        p.x += motherboardOffset.getXCoordinate();
        p.y += motherboardOffset.getYCoordinate();
        p.z += motherboardOffset.getZCoordinate();
    }
    for (auto &f : cpuBlock.frames)
    {
        f.x += motherboardOffset.getXCoordinate();
        f.y += motherboardOffset.getYCoordinate();
        f.z += motherboardOffset.getZCoordinate();
    }
}

void CPUConfig::applyMotherboardOffsetAcc(ComponentConfig &ramAccBlock, Dot3D &motherboardAccOffset, int splitIncrement)
{
    int coeff = 0;
    for (auto &p : ramAccBlock.parallelepipeds)
    {
        int currentShift = (coeff * p.height) + (coeff * splitIncrement);
        p.x += motherboardAccOffset.getXCoordinate();
        p.y += motherboardAccOffset.getYCoordinate() + currentShift;
        p.z += motherboardAccOffset.getZCoordinate();
        coeff++;
    }
    int yIncrementFr = 0;
    for (auto &f : ramAccBlock.frames)
    {
        f.x += motherboardAccOffset.getXCoordinate();
        f.y += motherboardAccOffset.getYCoordinate() + yIncrementFr;
        f.z += motherboardAccOffset.getZCoordinate();
        yIncrementFr += splitIncrement;
    }
}

ComponentConfig CPUConfig::getCPUConfig(ConfigManager::CPUType cpuType, Dot3D &motherboardOffset)
{
    ComponentConfig cpuBlock = cpuMappings.at(cpuType);
    applyMotherboardOffset(cpuBlock, motherboardOffset);
    return cpuBlock;
}

ComponentConfig CPUConfig::getCPUAccConfig(ConfigManager::CPUAccessoriesType cpuAccType, Dot3D &motherboardOffset, int splitIncrement)
{
    ComponentConfig cpuBlock = cpuAccessoriesMappings.at(cpuAccType);
    applyMotherboardOffsetAcc(cpuBlock, motherboardOffset, splitIncrement);
    return cpuBlock;
}
