#include "configmanager.hpp"

const std::vector<ConfigManager::GPUType> &ConfigManager::getCompatibleGPUs(void) const
{
    return allGPUs;
}

const std::vector<ConfigManager::RAMType>& ConfigManager::getCompatibleRAMs(void) const
{
    return allRAMs;
}

const std::vector<ConfigManager::CPUType>& ConfigManager::getCompatibleCPUs(ConfigManager::MotherboardType type) const
{
    return cpuCompatibility.at(type);
}

ConfigManager::RAMAccessoriesType ConfigManager::mapAccessoryRAM(ConfigManager::RAMType type)
{
    switch (type)
    {
    case (ConfigManager::RAMType::RAM_4GB):
        return ConfigManager::RAMAccessoriesType::RAM_4GB_ACC;
    case (ConfigManager::RAMType::RAM_8GB):
        return ConfigManager::RAMAccessoriesType::RAM_8GB_ACC;
    case (ConfigManager::RAMType::RAM_16GB):
        return ConfigManager::RAMAccessoriesType::RAM_16GB_ACC;
    case (ConfigManager::RAMType::RAM_32GB):
        return ConfigManager::RAMAccessoriesType::RAM_32GB_ACC;
    }
}

std::string motherboardTypeToString(ConfigManager::MotherboardType type)
{
    switch (type)
    {
    case ConfigManager::MotherboardType::ATX:
        return "ATX";
    case ConfigManager::MotherboardType::MicroATX:
        return "Micro-ATX";
    case ConfigManager::MotherboardType::MiniITX:
        return "Mini-ITX";
    }
}

std::string gpuTypeToString(ConfigManager::GPUType type)
{
    switch (type)
    {
    case ConfigManager::GPUType::GPU_4GB:
        return "GPU 4GB";
    case ConfigManager::GPUType::GPU_6GB:
        return "GPU 6GB";
    case ConfigManager::GPUType::GPU_8GB:
        return "GPU 8GB";
    case ConfigManager::GPUType::GPU_16GB:
        return "GPU 16GB";
    }
}

std::string ramTypeToString(ConfigManager::RAMType type)
{
    switch (type)
    {
    case ConfigManager::RAMType::RAM_4GB:
        return "RAM 4GB";
    case ConfigManager::RAMType::RAM_8GB:
        return "RAM 8GB";
    case ConfigManager::RAMType::RAM_16GB:
        return "RAM 16GB";
    case ConfigManager::RAMType::RAM_32GB:
        return "RAM 32GB";
    }
}

std::string cpuTypeToString(ConfigManager::CPUType type)
{
    switch (type)
    {
    case ConfigManager::CPUType::Intel:
        return "Intel";
    case ConfigManager::CPUType::AMD:
        return "AMD";
    }
}
