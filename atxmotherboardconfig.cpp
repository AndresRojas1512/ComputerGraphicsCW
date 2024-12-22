#include "atxmotherboardconfig.hpp"

Dot3D ATXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D ATXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

Dot3D ATXMotherboardConfig::getRamSlotPosition(ATXMotherboardConfig::RAMSlot slot) const
{
    switch(slot)
    {
    case RAMSlot::B1:
        return DDR4_DIMM_B1_offset;
    case RAMSlot::B2:
        return DDR4_DIMM_B2_offset;
    case RAMSlot::A1:
        return DDR4_DIMM_A1_offset;
    case RAMSlot::A2:
        return DDR4_DIMM_A2_offset;
    }
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
