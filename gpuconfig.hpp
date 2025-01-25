#ifndef GPUCONFIG_HPP
#define GPUCONFIG_HPP

#include <map>
#include "configmanager.hpp"
#include "componentprimitives.hpp"
#include "mathelems.hpp"
#include "atxmotherboardconfig.hpp"
#include "microatxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"

class GPUConfig
{
public:
    GPUConfig()
    {
        gpuMappings = {
           {ConfigManager::GPUType::GPU_4GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, 1, 1, 1)}, {})},
           {ConfigManager::GPUType::GPU_6GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, 2, 2, 2)}, {})},
           {ConfigManager::GPUType::GPU_8GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, 3, 3, 3)}, {})},
           {ConfigManager::GPUType::GPU_16GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, 4, 4, 4)}, {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &gpuBlock, Dot3D &motherboardOffset);
    ComponentConfig getGPUConfig(ConfigManager::GPUType gpuType, Dot3D &motherboardOffSet);

private:
    std::map<ConfigManager::GPUType, ComponentConfig> gpuMappings;
};

#endif // GPUCONFIG_HPP
