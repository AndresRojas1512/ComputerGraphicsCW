#include "configmanager.hpp"

const std::vector<ConfigManager::GPUType> &ConfigManager::getCompatibleGPUs(ConfigManager::MotherboardType type) const
{
    return gpuCompatibility.at(type);
}

const std::vector<ConfigManager::CPUType>& ConfigManager::getCompatibleCPUs(ConfigManager::MotherboardType type) const
{
    return cpuCompatibility.at(type);
}

const std::vector<ConfigManager::RAMType>& ConfigManager::getCompatibleRAMs(ConfigManager::MotherboardType type) const
{
    return ramCompatibility.at(type);
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
    case ConfigManager::GPUType::NVIDIA_GeForce_RTX_3080:
        return "NVIDIA GeForce RTX 3080";
    case ConfigManager::GPUType::AMD_Radeon_RX_6800_XT:
        return "AMD Radeon RX 6800 XT";
    case ConfigManager::GPUType::NVIDIA_GeForce_GTX_1660_Ti:
        return "NVIDIA GeForce GTX 1660 Ti";
    case ConfigManager::GPUType::NVIDIA_GeForce_RTX_3070:
        return "NVIDIA GeForce RTX 3070";
    case ConfigManager::GPUType::AMD_Radeon_RX_6700_XT:
        return "AMD_Radeon_RX_6700_XT";
    case ConfigManager::GPUType::NVIDIA_GeForce_RTX_2060:
        return "NVIDIA_GeForce RTX 2060";
    case ConfigManager::GPUType::NVIDIA_GeForce_RTX_3060_Ti:
        return "NVIDIA GeForce RTX 3060 Ti";
    case ConfigManager::GPUType::AMD_Radeon_RX_5600_XT:
        return "AMD Radeon RX 5600 XT";
    case ConfigManager::GPUType::NVIDIA_GeForce_GTX_1650_Super:
        return "NVIDIA GeForce GTX 1650 Super";
    }
}

std::string cpuTypeToString(ConfigManager::CPUType type)
{
    switch (type)
    {
    case ConfigManager::CPUType::AMD_Ryzen_9_5950X:
        return "AMD Ryzen 9 5950X";
    case ConfigManager::CPUType::AMD_Ryzen_7_3700X:
        return "AMD Ryzen 7 3700X";
    case ConfigManager::CPUType::AMD_Ryzen_5_3600:
        return "AMD Ryzen 5 3600";
    case ConfigManager::CPUType::Intel_Core_i9_11900K:
        return "Intel Core i9 11900K";
    case ConfigManager::CPUType::Intel_Core_i7_10700K:
        return "Intel Core_i7 10700K";
    case ConfigManager::CPUType::Intel_Core_i5_10400F:
        return "Intel Core i5 10400F";
    case ConfigManager::CPUType::Intel_Core_i7_9700K:
        return "Intel Core i7 9700K";
    case ConfigManager::CPUType::Intel_Core_i5_9600K:
        return "Intel_Core_i5_9600K";
    case ConfigManager::CPUType::Intel_Core_i3_9100F:
        return "Intel_Core_i3_9100F";
    }
}

std::string ramTypeToString(ConfigManager::RAMType type)
{
    switch (type)
    {
    case ConfigManager::RAMType::Corsair_Vengeance_LPX_16GB_DDR4_3200:
        return "Corsair Vengeance LPX 16GB DDR4 3200";
    case ConfigManager::RAMType::G_Skill_Ripjaws_V_32GB_DDR4_3600:
        return "G Skill Ripjaws V 32GB DDR4 3600";
    case ConfigManager::RAMType::Crucial_Ballistix_16GB_DDR4_3000:
        return "Crucial Ballistix 16GB DDR4 3000";
    case ConfigManager::RAMType::Kingston_HyperX_Fury_16GB_DDR4_2666:
        return "Kingston HyperX Fury 16GB DDR4 2666";
    case ConfigManager::RAMType::Teamgroup_T_Force_Vulcan_Z_32GB_DDR4_3200:
        return "Teamgroup T Force Vulcan Z 32GB DDR4 3200";
    case ConfigManager::RAMType::Corsair_Vengeance_RGB_Pro_16GB_DDR4_3600:
        return "Corsair Vengeance RGB Pro 16GB DDR4 3600";
    case ConfigManager::RAMType::G_Skill_Aegis_16GB_DDR4_2400:
        return "G Skill Aegis 16GB DDR4 2400";
    case ConfigManager::RAMType::Corsair_Vengeance_LPX_8GB_DDR4_2133:
        return "Corsair Vengeance LPX 8GB DDR4 2133";
    case ConfigManager::RAMType::Patriot_Viper_Elite_16GB_DDR4_2666:
        return "Patriot Viper Elite 16GB DDR4 2666";
    }
}
