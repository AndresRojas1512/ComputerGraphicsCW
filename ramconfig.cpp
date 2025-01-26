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

void RAMConfig::applyMotherboardOffsetAcc(ComponentConfig &ramAccBlock, Dot3D &motherboardAccOffset, int splitIncrement)
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

ComponentConfig RAMConfig::getRAMConfig(ConfigManager::RAMType ramType, Dot3D &motherboardOffset)
{
    ComponentConfig ramBlock = ramMappings.at(ramType);
    applyMotherboardOffset(ramBlock, motherboardOffset);
    return ramBlock;
}

ComponentConfig RAMConfig::getRAMAccConfig(ConfigManager::RAMAccessoriesType ramAccType, Dot3D &motherboardOffset, int splitIncrement)
{
    ComponentConfig ramBlock = ramAccessoriesMappings.at(ramAccType);
    applyMotherboardOffsetAcc(ramBlock, motherboardOffset, splitIncrement);
    return ramBlock;
}
