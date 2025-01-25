#include "ramconfig.hpp"

void RAMConfig::applyMotherboardOffset(ComponentConfig &ramBlock, Dot3D &motherboardOffset)
{
    for (auto &p : ramBlock.parallelepipeds)
    {
        p.x += motherboardOffset.getXCoordinate();
        p.y += motherboardOffset.getYCoordinate();
        p.z += motherboardOffset.getZCoordinate();
    }
    for (auto &f : ramBlock.frames)
    {
        f.x += motherboardOffset.getXCoordinate();
        f.y += motherboardOffset.getYCoordinate();
        f.z += motherboardOffset.getZCoordinate();
    }
}

ComponentConfig RAMConfig::getRAMConfig(ConfigManager::RAMType ramType, Dot3D &motherboardOffset)
{
    ComponentConfig ramBlock = ramMappings.at(ramType);
    applyMotherboardOffset(ramBlock, motherboardOffset);
    return ramBlock;
}
