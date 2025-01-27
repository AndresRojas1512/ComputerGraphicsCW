#ifndef RAMCONFIG_HPP
#define RAMCONFIG_HPP

#include <map>
#include <vector>
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
        // RAM MAPPINGS
        ramMappings = {
                       {ConfigManager::RAMType::RAM_4GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_4GB_WIDTH, RAM_4GB_HEIGHT, RAM_4GB_DEPTH)}, {}, {})},
            {ConfigManager::RAMType::RAM_8GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_8GB_WIDTH, RAM_8GB_HEIGHT, RAM_8GB_DEPTH)}, {}, {})},
            {ConfigManager::RAMType::RAM_16GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_16GB_WIDTH, RAM_16GB_HEIGHT, RAM_16GB_DEPTH)}, {}, {})},
            {ConfigManager::RAMType::RAM_32GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_32GB_WIDTH, RAM_32GB_HEIGHT, RAM_32GB_DEPTH)}, {}, {})}
        };
        // RAM ACCESSORIES MAPPINGS
        ramAccessoriesMappings = {
            {ConfigManager::RAMAccessoriesType::RAM_4GB_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_4GB_ACC_WIDTH, RAM_4GB_ACC_HEIGHT, RAM_4GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_4GB_ACC_WIDTH, RAM_4GB_ACC_HEIGHT, RAM_4GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_4GB_ACC_WIDTH, RAM_4GB_ACC_HEIGHT, RAM_4GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_4GB_ACC_WIDTH, RAM_4GB_ACC_HEIGHT, RAM_4GB_ACC_DEPTH)},
                                                                             {}, {})},
            {ConfigManager::RAMAccessoriesType::RAM_8GB_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, 0, 0, RAM_8GB_ACC_WIDTH, RAM_8GB_ACC_HEIGHT, RAM_8GB_ACC_DEPTH)},
                                                                             {}, {})},
            {ConfigManager::RAMAccessoriesType::RAM_16GB_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_16GB_ACC_WIDTH, RAM_16GB_ACC_HEIGHT, RAM_16GB_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, 0, 0, RAM_16GB_ACC_WIDTH, RAM_16GB_ACC_HEIGHT, RAM_16GB_ACC_DEPTH)},
                                                                              {}, {})},
            {ConfigManager::RAMAccessoriesType::RAM_32GB_ACC, ComponentConfig({ParallelepipedConfig(0, 0, 0, RAM_32GB_ACC_WIDTH, RAM_32GB_ACC_HEIGHT, RAM_32GB_ACC_DEPTH)}, {}, {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &ramBlock, Dot3D &motherboardOffset);
    void applyMotherboardOffsetAcc(ComponentConfig &ramAccBlock, Dot3D &motherboardAccOffset, int splitIncrement);

    ComponentConfig getRAMConfig(ConfigManager::RAMType ramType, Dot3D &motherboardOffSet);
    ComponentConfig getRAMAccConfig(ConfigManager::RAMAccessoriesType ramAccType, Dot3D &motherboardOffset, int splitIncrement);

private:
    std::map<ConfigManager::RAMType, ComponentConfig> ramMappings;
    std::map<ConfigManager::RAMAccessoriesType, ComponentConfig> ramAccessoriesMappings;
};

#endif // RAMCONFIG_HPP
