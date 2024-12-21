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

    componentConfig GTX_1050;
    componentConfig GTX_1060;
    componentConfig GTX_1070;
    componentConfig RTX_2060;
    componentConfig RTX_2070;
    componentConfig RTX_2080;
    componentConfig RTX_3060;
    componentConfig RTX_3070;
    componentConfig RTX_3080;
};

#endif // GPUCONFIG_H
