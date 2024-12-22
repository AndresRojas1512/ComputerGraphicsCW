#ifndef GPUCONFIG_H
#define GPUCONFIG_H

#include <vector>
#include "mathelems.hpp"
#include "config.hpp"
#include "motherboardprimitives.hpp"
#include "atxmotherboardconfig.hpp"
#include "microatxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"

class GPUConfig
{
public:
    GPUConfig(Dot3D startOfPlate, Dot3D endOfPlate, Dot3D offset);

    componentConfig NVIDIA_GeForce_RTX_3080;
    componentConfig AMD_Radeon_RX_6800_XT;
    componentConfig NVIDIA_GeForce_GTX_1660_Ti;
    componentConfig NVIDIA_GeForce_RTX_3070;
    componentConfig AMD_Radeon_RX_6700_XT;
    componentConfig NVIDIA_GeForce_RTX_2060;
    componentConfig NVIDIA_GeForce_RTX_3060_Ti;
    componentConfig AMD_Radeon_RX_5600_XT;
    componentConfig NVIDIA_GeForce_GTX_1650_Super;
};

#endif // GPUCONFIG_H
