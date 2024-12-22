#include "atxmotherboardconfig.hpp"

Dot3D ATXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D ATXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

bool ATXMotherboardConfig::isRamSlotAvailable(int slot)
{
    return !ramSlotsOccupied[slot];
}

void ATXMotherboardConfig::occupyRamSlot(int slot)
{
    if (isRamSlotAvailable(slot))
    {
        ramSlotsOccupied[slot] = true;
    }
}

QList<int> ATXMotherboardConfig::getAvailableRamSlots()
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

std::string atxRamSlotToString(ATXMotherboardConfig::RAMSlot slot)
{
    switch (slot)
    {
    case ATXMotherboardConfig::RAMSlot::B1:
        return "B1";
    case ATXMotherboardConfig::RAMSlot::B2:
        return "B2";
    case ATXMotherboardConfig::RAMSlot::A1:
        return "A1";
    case ATXMotherboardConfig::RAMSlot::A2:
        return "A2";
    }
}
