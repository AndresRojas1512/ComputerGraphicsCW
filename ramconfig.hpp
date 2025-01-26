#ifndef RAMCONFIG_HPP
#define RAMCONFIG_HPP

#include <map>
#include "configmanager.hpp"
#include "componentprimitives.hpp"
#include "mathelems.hpp"
#include "atxmotherboardconfig.hpp"
#include "microatxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"
#include "config.hpp"

class RAMConfig
{
public:
    RAMConfig()
    {
        ramMappings = {
            {ConfigManager::RAMType::RAM_4GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_4GB_WIDTH, RAM_4GB_HEIGHT, RAM_4GB_DEPTH)}, {})},
            {ConfigManager::RAMType::RAM_8GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_8GB_WIDTH, RAM_8GB_HEIGHT, RAM_8GB_DEPTH)}, {})},
            {ConfigManager::RAMType::RAM_16GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_16GB_WIDTH, RAM_16GB_HEIGHT, RAM_16GB_DEPTH)}, {})},
            {ConfigManager::RAMType::RAM_32GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_32GB_WIDTH, RAM_32GB_HEIGHT, RAM_32GB_DEPTH)}, {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &ramBlock, Dot3D &motherboardOffset);
    ComponentConfig getRAMConfig(ConfigManager::RAMType ramType, Dot3D &motherboardOffSet);

private:
    std::map<ConfigManager::RAMType, ComponentConfig> ramMappings;
};

#endif // RAMCONFIG_HPP
