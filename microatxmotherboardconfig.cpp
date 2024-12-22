#include "microatxmotherboardconfig.hpp"

Dot3D MicroATXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D MicroATXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

bool MicroATXMotherboardConfig::isRamSlotAvailable(int slot)
{
    return !ramSlotsOccupied[slot];
}

void MicroATXMotherboardConfig::occupyRamSlot(int slot)
{
    if (isRamSlotAvailable(slot))
    {
        ramSlotsOccupied[slot] = true;
    }
}

QList<int> MicroATXMotherboardConfig::getAvailableRamSlots()
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
