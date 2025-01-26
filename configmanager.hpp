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

    enum class CPUType
    {
        Intel,
        AMD
    };

    enum class GPUType
    {
        GPU_4GB,
        GPU_6GB,
        GPU_8GB,
        GPU_16GB
    };

    enum class GPUAccessoriesType
    {
        GPU_4GB_ACC,
        GPU_6GB_ACC,
        GPU_8GB_ACC,
        GPU_16GB_ACC
    };

    enum class RAMType
    {
        RAM_4GB,
        RAM_8GB,
        RAM_16GB,
        RAM_32GB
    };

    enum class RAMAccessoriesType
    {
        RAM_4GB_ACC,
        RAM_8GB_ACC,
        RAM_16GB_ACC,
        RAM_32GB_ACC
    };

    ConfigManager()
    {
        // GPU compatibility
        allGPUs = {
            GPUType::GPU_4GB,
            GPUType::GPU_6GB,
            GPUType::GPU_8GB,
            GPUType::GPU_16GB,
        };

        // RAM compatibility
        allRAMs = {
            RAMType::RAM_4GB,
            RAMType::RAM_8GB,
            RAMType::RAM_16GB,
            RAMType::RAM_32GB
        };

        // CPU compatibility
        cpuCompatibility[MotherboardType::ATX] = {
            CPUType::AMD
        };

        cpuCompatibility[MotherboardType::MicroATX] = {
            CPUType::Intel
        };

        cpuCompatibility[MotherboardType::MiniITX] = {
            CPUType::Intel
        };
    }

    const std::vector<GPUType> &getCompatibleGPUs(void) const;

    const std::vector<RAMType>& getCompatibleRAMs(void) const;

    const std::vector<CPUType>& getCompatibleCPUs(MotherboardType type) const;

    RAMAccessoriesType mapAccessoryRAM(RAMType type);

private:
    std::vector<GPUType> allGPUs;
    std::vector<RAMType> allRAMs;
    std::unordered_map<MotherboardType, std::vector<CPUType>> cpuCompatibility;
};

std::string gpuTypeToString(ConfigManager::GPUType type);

std::string cpuTypeToString(ConfigManager::CPUType type);

std::string ramTypeToString(ConfigManager::RAMType type);

std::string motherboardTypeToString(ConfigManager::MotherboardType type);

#endif // CONFIGMANAGER_H
