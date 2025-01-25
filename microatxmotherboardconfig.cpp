#include "microatxmotherboardconfig.hpp"

Dot3D MicroATXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D MicroATXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

Dot3D MicroATXMotherboardConfig::getRamSlotPosition(int slot) const
{
    RAMSlot slotType = static_cast<RAMSlot>(slot);
    switch(slotType)
    {
    case RAMSlot::A1:
        return DDR4_DIMM_A1_offset;
    case RAMSlot::A2:
        return DDR4_DIMM_A2_offset;
    case RAMSlot::B1:
        return DDR4_DIMM_B1_offset;
    case RAMSlot::B2:
        return DDR4_DIMM_B2_offset;
    }
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
