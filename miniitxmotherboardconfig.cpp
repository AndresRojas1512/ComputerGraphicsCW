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

Dot3D MiniITXMotherboardConfig::getGpuSlotPosition(int slot) const
{
    return PCIEX16_1_offset;
}

Dot3D MiniITXMotherboardConfig::getCpuSlotPosition(void) const
{
    return CPU_offset;
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

bool MiniITXMotherboardConfig::isGpuSlotAvailable(int slot)
{
    return !gpuSlotsOccupied[slot];
}

void MiniITXMotherboardConfig::occupyGpuSlot(int slot)
{
    if (isGpuSlotAvailable(slot))
    {
        gpuSlotsOccupied[slot] = true;
    }
}

bool MiniITXMotherboardConfig::isCpuSlotAvailable(void)
{
    return !cpuSlotOccupied;
}

QList<int> MiniITXMotherboardConfig::getAvailableGpuSlots()
{
    QList<int> availableSlots;
    for (auto& slot : gpuSlotsOccupied)
    {
        if (!slot.second)
        {
            availableSlots.append(slot.first);
        }
    }
    return availableSlots;
}
