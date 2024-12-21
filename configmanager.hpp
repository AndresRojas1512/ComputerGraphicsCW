#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <unordered_map>
#include <vector>
#include <string>

class ConfigManager
{
public:
    enum class MotherboardType
    {
        ATX,
        MicroATX,
        MiniITX
    };

    enum class GPUType
    {
        NVIDIA_GeForce_RTX_3080,
        AMD_Radeon_RX_6800_XT,
        NVIDIA_GeForce_GTX_1660_Ti,
        NVIDIA_GeForce_RTX_3070,
        AMD_Radeon_RX_6700_XT,
        NVIDIA_GeForce_RTX_2060,
        NVIDIA_GeForce_RTX_3060_Ti,
        AMD_Radeon_RX_5600_XT,
        NVIDIA_GeForce_GTX_1650_Super
    };

    enum class CPUType
    {
        AMD_Ryzen_9_5950X,
        AMD_Ryzen_7_3700X,
        AMD_Ryzen_5_3600,
        Intel_Core_i9_11900K,
        Intel_Core_i7_10700K,
        Intel_Core_i5_10400F,
        Intel_Core_i7_9700K,
        Intel_Core_i5_9600K,
        Intel_Core_i3_9100F
    };

    enum class RAMType
    {
        Corsair_Vengeance_LPX_16GB_DDR4_3200,
        G_Skill_Ripjaws_V_32GB_DDR4_3600,
        Crucial_Ballistix_16GB_DDR4_3000,
        Kingston_HyperX_Fury_16GB_DDR4_2666,
        Teamgroup_T_Force_Vulcan_Z_32GB_DDR4_3200,
        Corsair_Vengeance_RGB_Pro_16GB_DDR4_3600,
        G_Skill_Aegis_16GB_DDR4_2400,
        Corsair_Vengeance_LPX_8GB_DDR4_2133,
        Patriot_Viper_Elite_16GB_DDR4_2666
    };

    ConfigManager()
    {
        // GPU compatibility
        gpuCompatibility[MotherboardType::ATX] ={
            GPUType::NVIDIA_GeForce_RTX_3080,
            GPUType::AMD_Radeon_RX_6800_XT,
            GPUType::NVIDIA_GeForce_GTX_1660_Ti
        };
        gpuCompatibility[MotherboardType::MicroATX] = {
            GPUType::NVIDIA_GeForce_RTX_3070,
            GPUType::AMD_Radeon_RX_6700_XT,
            GPUType::NVIDIA_GeForce_RTX_2060
        };
        gpuCompatibility[MotherboardType::MiniITX] = {
            GPUType::NVIDIA_GeForce_RTX_3060_Ti,
            GPUType::AMD_Radeon_RX_5600_XT,
            GPUType::NVIDIA_GeForce_GTX_1650_Super
        };

        // CPU compatibility
        cpuCompatibility[MotherboardType::ATX] = {
            CPUType::AMD_Ryzen_9_5950X,
            CPUType::AMD_Ryzen_7_3700X,
            CPUType::AMD_Ryzen_5_3600
        };
        cpuCompatibility[MotherboardType::MicroATX] = {
            CPUType::Intel_Core_i9_11900K,
            CPUType::Intel_Core_i7_10700K,
            CPUType::Intel_Core_i5_10400F
        };
        cpuCompatibility[MotherboardType::MiniITX] = {
            CPUType::Intel_Core_i7_9700K,
            CPUType::Intel_Core_i5_9600K,
            CPUType::Intel_Core_i3_9100F
        };

        // RAM compatibility
        ramCompatibility[MotherboardType::ATX] = {
            RAMType::Corsair_Vengeance_LPX_16GB_DDR4_3200,
            RAMType::G_Skill_Ripjaws_V_32GB_DDR4_3600,
            RAMType::Crucial_Ballistix_16GB_DDR4_3000
        };
        ramCompatibility[MotherboardType::MicroATX] = {
            RAMType::Kingston_HyperX_Fury_16GB_DDR4_2666,
            RAMType::Teamgroup_T_Force_Vulcan_Z_32GB_DDR4_3200,
            RAMType::Corsair_Vengeance_RGB_Pro_16GB_DDR4_3600
        };
        ramCompatibility[MotherboardType::MiniITX] = {
            RAMType::G_Skill_Aegis_16GB_DDR4_2400,
            RAMType::Corsair_Vengeance_LPX_8GB_DDR4_2133,
            RAMType::Patriot_Viper_Elite_16GB_DDR4_2666
        };
    }

    const std::vector<GPUType> &getCompatibleGPUs(MotherboardType type) const;

    const std::vector<CPUType>& getCompatibleCPUs(MotherboardType type) const;

    const std::vector<RAMType>& getCompatibleRAMs(MotherboardType type) const;

private:
    std::unordered_map<MotherboardType, std::vector<GPUType>> gpuCompatibility;
    std::unordered_map<MotherboardType, std::vector<CPUType>> cpuCompatibility;
    std::unordered_map<MotherboardType, std::vector<RAMType>> ramCompatibility;

};

std::string gpuTypeToString(ConfigManager::GPUType type);
std::string cpuTypeToString(ConfigManager::CPUType type);
std::string ramTypeToString(ConfigManager::RAMType type);

#endif // CONFIGMANAGER_H
