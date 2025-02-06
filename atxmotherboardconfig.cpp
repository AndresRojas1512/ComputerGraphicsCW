#include "atxmotherboardconfig.hpp"

Dot3D ATXMotherboardConfig::getStartOfPlate() const
{
    return startOfPlate;
}

Dot3D ATXMotherboardConfig::getEndOfPlate() const
{
    return endOfPlate;
}

Dot3D ATXMotherboardConfig::getRamSlotPosition(int slot) const
{
    RAMSlot slotType = static_cast<RAMSlot>(slot);
    switch(slotType)
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

Dot3D ATXMotherboardConfig::getRamAccSlotPosition(int slot) const
{
    RAMSlot slotType = static_cast<RAMSlot>(slot);
    switch(slotType)
    {
    case RAMSlot::B1:
        return DDR4_DIMM_B1_ACC_offset;
    case RAMSlot::B2:
        return DDR4_DIMM_B2_ACC_offset;
    case RAMSlot::A1:
        return DDR4_DIMM_A1_ACC_offset;
    case RAMSlot::A2:
        return DDR4_DIMM_A2_ACC_offset;
    }
}

Dot3D ATXMotherboardConfig::getGpuSlotPosition(int slot) const
{
    GPUSlot slotType = static_cast<GPUSlot>(slot);
    switch(slotType)
    {
    case GPUSlot::A1:
        return PCIEX16_1_offset;
    case GPUSlot::A2:
        return PCIEX16_2_offset;
    case GPUSlot::A3:
        return PCIEX16_3_offset;
    }
}

Dot3D ATXMotherboardConfig::getGPuAccSlotPosition(int slot) const
{
    GPUSlot slotType = static_cast<GPUSlot>(slot);
    switch(slotType)
    {
    case GPUSlot::A1:
        return PCIEX16_1_ACC_offset;
    case GPUSlot::A2:
        return PCIEX16_2_ACC_offset;
    case GPUSlot::A3:
        return PCIEX16_3_ACC_offset;
    }
}

Dot3D ATXMotherboardConfig::getCpuSlotPosition(void) const
{
    return CPU_offset;
}

Dot3D ATXMotherboardConfig::getCpuAccSlotPosition(void) const
{
    return CPU_ACC_offset;
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

bool ATXMotherboardConfig::isGpuSlotAvailable(int slot)
{
    return !gpuSlotsOccupied[slot];
}

void ATXMotherboardConfig::occupyGpuSlot(int slot)
{
    if (isGpuSlotAvailable(slot))
    {
        gpuSlotsOccupied[slot] = true;
    }
}

QList<int> ATXMotherboardConfig::getAvailableGpuSlots()
{
    std::cout << "ATXMotherboardConfig::getAvailableGpuSlots" << std::endl;
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

bool ATXMotherboardConfig::isCpuSlotAvailable(void)
{
    return !cpuSlotOccupied;
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

std::string atxGpuSlotToString(ATXMotherboardConfig::GPUSlot slot)
{
    switch (slot)
    {
    case ATXMotherboardConfig::GPUSlot::A1:
        return "A1";
    case ATXMotherboardConfig::GPUSlot::A2:
        return "A2";
    case ATXMotherboardConfig::GPUSlot::A3:
        return "A3";
    }
}
