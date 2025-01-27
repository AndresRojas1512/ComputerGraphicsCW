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
        // GPU MAPPINGS
        gpuMappings = {
           {ConfigManager::GPUType::GPU_4GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, GPU_4GB_WIDTH, GPU_4GB_HEIGHT, GPU_4GB_DEPTH),
                                                              ParallelepipedConfig(-ATX_PCIEX16_1_OFFSET_X - ATX_PCIEX16_LEFTFRAMEWIDTH, 0, GPU_16GB_BOARD_DEPTH, GPU_4GB_BOARD_WIDTH, GPU_4GB_BOARD_HEIGHT, GPU_4GB_BOARD_DEPTH)},
                                                              {})},
           {ConfigManager::GPUType::GPU_6GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, GPU_6GB_WIDTH, GPU_6GB_HEIGHT, GPU_6GB_DEPTH),
                                                              ParallelepipedConfig(-ATX_PCIEX16_1_OFFSET_X - ATX_PCIEX16_LEFTFRAMEWIDTH, 0, GPU_16GB_BOARD_DEPTH, GPU_6GB_BOARD_WIDTH, GPU_6GB_BOARD_HEIGHT, GPU_6GB_BOARD_DEPTH)},
                                                              {})},
           {ConfigManager::GPUType::GPU_8GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, GPU_8GB_WIDTH, GPU_8GB_HEIGHT, GPU_8GB_DEPTH),
                                                              ParallelepipedConfig(-ATX_PCIEX16_1_OFFSET_X - ATX_PCIEX16_LEFTFRAMEWIDTH, 0, GPU_16GB_BOARD_DEPTH, GPU_8GB_BOARD_WIDTH, GPU_8GB_BOARD_HEIGHT, GPU_8GB_BOARD_DEPTH)},
                                                              {})},
           {ConfigManager::GPUType::GPU_16GB, ComponentConfig({ParallelepipedConfig(0, 0, 0, GPU_16GB_WIDTH, GPU_16GB_HEIGHT, GPU_16GB_DEPTH),
                                                               ParallelepipedConfig(-ATX_PCIEX16_1_OFFSET_X - ATX_PCIEX16_LEFTFRAMEWIDTH, 0, GPU_16GB_BOARD_DEPTH, GPU_16GB_BOARD_WIDTH, GPU_16GB_BOARD_HEIGHT, GPU_16GB_BOARD_DEPTH)},
                                                               {})}
        };
        // GPU ACCESSORIES MAPPINGS
        gpuAccessoriesMappings = {
            {ConfigManager::GPUAccessoriesType::GPU_4GB_ACC, ComponentConfig({ParallelepipedConfig(0, -GPU_4GB_CHIPSET_ACC_HEIGHT, 0, GPU_4GB_CHIPSET_ACC_WIDTH, GPU_4GB_CHIPSET_ACC_HEIGHT, GPU_4GB_CHIPSET_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_4GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_4GB_MEMBLOCK_ACC_WIDTH, GPU_4GB_MEMBLOCK_ACC_HEIGHT, GPU_4GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_4GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_4GB_MEMBLOCK_ACC_WIDTH, GPU_4GB_MEMBLOCK_ACC_HEIGHT, GPU_4GB_MEMBLOCK_ACC_DEPTH)},
                                                                              {})},
            {ConfigManager::GPUAccessoriesType::GPU_6GB_ACC, ComponentConfig({ParallelepipedConfig(0, -GPU_6GB_CHIPSET_ACC_HEIGHT, 0, GPU_6GB_CHIPSET_ACC_WIDTH, GPU_6GB_CHIPSET_ACC_HEIGHT, GPU_6GB_CHIPSET_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_6GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_6GB_MEMBLOCK_ACC_WIDTH, GPU_6GB_MEMBLOCK_ACC_HEIGHT, GPU_6GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_6GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_6GB_MEMBLOCK_ACC_WIDTH, GPU_6GB_MEMBLOCK_ACC_HEIGHT, GPU_6GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_6GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_6GB_MEMBLOCK_ACC_WIDTH, GPU_6GB_MEMBLOCK_ACC_HEIGHT, GPU_6GB_MEMBLOCK_ACC_DEPTH)},
                                                                              {})},
            {ConfigManager::GPUAccessoriesType::GPU_8GB_ACC, ComponentConfig({ParallelepipedConfig(0, -GPU_8GB_CHIPSET_ACC_HEIGHT, 0, GPU_8GB_CHIPSET_ACC_WIDTH, GPU_8GB_CHIPSET_ACC_HEIGHT, GPU_8GB_CHIPSET_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_8GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_8GB_MEMBLOCK_ACC_WIDTH, GPU_8GB_MEMBLOCK_ACC_HEIGHT, GPU_8GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_8GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_8GB_MEMBLOCK_ACC_WIDTH, GPU_8GB_MEMBLOCK_ACC_HEIGHT, GPU_8GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_8GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_8GB_MEMBLOCK_ACC_WIDTH, GPU_8GB_MEMBLOCK_ACC_HEIGHT, GPU_8GB_MEMBLOCK_ACC_DEPTH),
                                                                              ParallelepipedConfig(0, -GPU_8GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_8GB_MEMBLOCK_ACC_WIDTH, GPU_8GB_MEMBLOCK_ACC_HEIGHT, GPU_8GB_MEMBLOCK_ACC_DEPTH)},
                                                                              {})},
            {ConfigManager::GPUAccessoriesType::GPU_16GB_ACC, ComponentConfig({ParallelepipedConfig(0, -GPU_16GB_CHIPSET_ACC_HEIGHT, 0, GPU_16GB_CHIPSET_ACC_WIDTH, GPU_16GB_CHIPSET_ACC_HEIGHT, GPU_16GB_CHIPSET_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH),
                                                                               ParallelepipedConfig(0, -GPU_16GB_MEMBLOCK_ACC_HEIGHT, -15, GPU_16GB_MEMBLOCK_ACC_WIDTH, GPU_16GB_MEMBLOCK_ACC_HEIGHT, GPU_16GB_MEMBLOCK_ACC_DEPTH)},
                                                                               {})}
        };
    }

    void applyMotherboardOffset(ComponentConfig &gpuBlock, Dot3D &motherboardOffset);
    void applyMotherboardOffsetAcc(ComponentConfig &gpuAccBlock, Dot3D &motherboardAccOffset, int splitIncrement);

    ComponentConfig getGPUConfig(ConfigManager::GPUType gpuType, Dot3D &motherboardOffSet);
    ComponentConfig getGPUAccConfig(ConfigManager::GPUAccessoriesType gpuAccType, Dot3D &motherboardOffset, int splitIncrement);

private:
    std::map<ConfigManager::GPUType, ComponentConfig> gpuMappings;
    std::map<ConfigManager::GPUAccessoriesType, ComponentConfig> gpuAccessoriesMappings;
};

#endif // GPUCONFIG_HPP
