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

Dot3D MicroATXMotherboardConfig::getRamAccSlotPosition(int slot) const
{
    RAMSlot slotType = static_cast<RAMSlot>(slot);
    switch(slotType)
    {
    case RAMSlot::A1:
        return DDR4_DIMM_A1_ACC_offset;
    case RAMSlot::A2:
        return DDR4_DIMM_A2_ACC_offset;
    case RAMSlot::B1:
        return DDR4_DIMM_B1_ACC_offset;
    case RAMSlot::B2:
        return DDR4_DIMM_B2_ACC_offset;
    }
}

Dot3D MicroATXMotherboardConfig::getGpuSlotPosition(int slot) const
{
    GPUSlot slotType = static_cast<GPUSlot>(slot);
    switch(slotType)
    {
    case GPUSlot::A1:
        return PCIEX16_1_offset;
    case GPUSlot::A2:
        return PCIEX16_2_offset;
    }
}

Dot3D MicroATXMotherboardConfig::getGPuAccSlotPosition(int slot) const
{
    GPUSlot slotType = static_cast<GPUSlot>(slot);
    switch(slotType)
    {
    case GPUSlot::A1:
        return PCIEX16_1_ACC_offset;
    case GPUSlot::A2:
        return PCIEX16_2_ACC_offset;
    }
}

Dot3D MicroATXMotherboardConfig::getCpuSlotPosition(void) const
{
    return CPU_offset;
}

Dot3D MicroATXMotherboardConfig::getCpuAccSlotPosition(void) const
{
    return CPU_ACC_offset;
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
    std::cout << "MicroATXMotherboardConfig::getAvailableRamSlots" << std::endl;
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

bool MicroATXMotherboardConfig::isGpuSlotAvailable(int slot)
{
    return !gpuSlotsOccupied[slot];
}

void MicroATXMotherboardConfig::occupyGpuSlot(int slot)
{
    if (isGpuSlotAvailable(slot))
    {
        gpuSlotsOccupied[slot] = true;
    }
}

bool MicroATXMotherboardConfig::isCpuSlotAvailable(void)
{
    return !cpuSlotOccupied;
}

QList<int> MicroATXMotherboardConfig::getAvailableGpuSlots()
{
    std::cout << "MicroATXMotherboardConfig::getAvailableRamSlots" << std::endl;
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

std::string microAtxRamSlotToString(MicroATXMotherboardConfig::RAMSlot slot)
{
    switch (slot)
    {
    case MicroATXMotherboardConfig::RAMSlot::A1:
        return "A1";
    case MicroATXMotherboardConfig::RAMSlot::A2:
        return "A2";
    case MicroATXMotherboardConfig::RAMSlot::B1:
        return "A3";
    case MicroATXMotherboardConfig::RAMSlot::B2:
        return "A4";
    }
}

std::string microAtxGpuSlotToString(MicroATXMotherboardConfig::GPUSlot slot)
{
    switch (slot)
    {
    case MicroATXMotherboardConfig::GPUSlot::A1:
        return "A1";
    case MicroATXMotherboardConfig::GPUSlot::A2:
        return "A2";
    }
}
