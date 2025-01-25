#include "miniitxmotherboardconfig.hpp"

Dot3D MiniITXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D MiniITXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

Dot3D MiniITXMotherboardConfig::getRamSlotPosition(int slot) const
{
    RAMSlot slotType = static_cast<RAMSlot>(slot);
    switch(slotType)
    {
    case RAMSlot::A1:
        return DDR4_DIMM_A1_offset;
    case RAMSlot::B1:
        return DDR4_DIMM_B1_offset;
    }
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
    std::cout << "MiniITXMotherboardConfig::getAvailableRamSlots" << std::endl;
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
