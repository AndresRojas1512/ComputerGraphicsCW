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
            {ConfigManager::CPUType::Intel, ComponentConfig({ParallelepipedConfig(0, 0, 0, 1, 1, 1)}, {}, {})},
            {ConfigManager::CPUType::AMD, ComponentConfig({ParallelepipedConfig(0, 0, 0, 2, 2, 2)}, {}, {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &cpuBlock, Dot3D &motherboardOffset);
    ComponentConfig getCPUConfig(ConfigManager::CPUType cpuType, Dot3D &motherboardOffset);
private:
    std::map<ConfigManager::CPUType, ComponentConfig> cpuMappings;
};

#endif // CPUCONFIG_H
