#include "miniitxmotherboardconfig.hpp"

Dot3D MiniITXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D MiniITXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

bool MiniITXMotherboardConfig::isRamSlotAvailable(int slot)
{
    return !ramSlotsOccupied[slot];
}

void MiniITXMotherboardConfig::occupyRamSlot(int slot)
{
    if (isRamSlotAvailable(slot))
    {
        ramSlotsOccupied[slot] = true;
    }
}

QList<int> MiniITXMotherboardConfig::getAvailableRamSlots()
{
    QList<int> availableSlots;
    for (auto& slot : ramSlotsOccupied)
    {
        if (!slot.second)
        {
            availableSlots.append(slot.first);
        }
    }
    return availableSlots;
}
