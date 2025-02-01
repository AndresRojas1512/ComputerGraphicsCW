#ifndef CPUCONFIG_H
#define CPUCONFIG_H

#include <map>
#include "configmanager.hpp"
#include "componentprimitives.hpp"
#include "mathelems.hpp"
#include "atxmotherboardconfig.hpp"
#include "microatxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"

class CPUConfig
{
public:
    CPUConfig()
    {
        cpuMappings = {
            {ConfigManager::CPUType::Intel, ComponentConfig({ParallelepipedConfig(0, 0, 0, CPU_INTEL_WIDTH, CPU_INTEL_HEIGHT, CPU_INTEL_DEPTH)}, {}, {})},
            {ConfigManager::CPUType::AMD, ComponentConfig({ParallelepipedConfig(0, 0, 0, CPU_AMD_WIDTH, CPU_AMD_HEIGHT, CPU_AMD_DEPTH)}, {}, {})}
        };
        cpuAccessoriesMappings = {
            {ConfigManager::CPUAccessoriesType::Intel_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, CPU_INTEL_ACC_WIDTH, CPU_INTEL_ACC_HEIGHT, CPU_INTEL_ACC_DEPTH)}, {}, {})},
            {ConfigManager::CPUAccessoriesType::AMD_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, CPU_AMD_ACC_WIDTH, CPU_AMD_ACC_HEIGHT, CPU_AMD_ACC_DEPTH)}, {}, {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &cpuBlock, Dot3D &motherboardOffset);
    void applyMotherboardOffsetAcc(ComponentConfig &cpuAccBlock, Dot3D &motherboardAccOffset, int splitIncrement);

    ComponentConfig getCPUConfig(ConfigManager::CPUType cpuType, Dot3D &motherboardOffset);
    ComponentConfig getCPUAccConfig(ConfigManager::CPUAccessoriesType, Dot3D &motherboardOffset, int splitIncrement);
private:
    std::map<ConfigManager::CPUType, ComponentConfig> cpuMappings;
    std::map<ConfigManager::CPUAccessoriesType, ComponentConfig> cpuAccessoriesMappings;
};

#endif // CPUCONFIG_H
