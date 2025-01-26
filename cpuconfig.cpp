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

ComponentConfig CPUConfig::getCPUConfig(ConfigManager::CPUType cpuType, Dot3D &motherboardOffset)
{
    ComponentConfig cpuBlock = cpuMappings.at(cpuType);
    applyMotherboardOffset(cpuBlock, motherboardOffset);
    return cpuBlock;
}
