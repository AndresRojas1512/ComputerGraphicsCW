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

ComponentConfig GPUConfig::getGPUConfig(ConfigManager::GPUType gpuType, Dot3D &motherboardOffset)
{
    ComponentConfig gpuBlock = gpuMappings.at(gpuType);
    applyMotherboardOffset(gpuBlock, motherboardOffset);
    return gpuBlock;
}
