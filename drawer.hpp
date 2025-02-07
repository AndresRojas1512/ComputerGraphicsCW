#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include "placeobjects.hpp"
#include "config.hpp"
#include "sceneinf.hpp"
#include "colorconfig.hpp"

class Drawer
{
public:
    Drawer()
    {
    }
    void zBufferAlg(SceneInf *scene, size_t bufheight, size_t bufWidth);
    void zBufForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                      Eigen::Matrix4f &transMat, size_t color, SceneInf *scene, size_t bufWidth, size_t bufHeight);
    void shadowMapForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                           Eigen::Matrix4f &transMat, Light *light, size_t bufWidth, size_t bufHeight);


    QGraphicsScene *drawScene(SceneInf *scene, QRectF rect, Color cpuColor, Color cpuShadow, Color ramColor, Color ramShadow, Color gpuColor, Color gpuShadow);

    void applyDefaultColor(QImage *image, QRectF rect, std::vector<PolygonModel::model_t> models, Color color, Color shadow);

private:
    void interColIntoShadowMap();
    void interRowIntoShadowMap(std::vector<std::vector<double>> *map, int xA, int xB, double zA, double zB, int curY);
    void borderPut(int x, int y, double z);
    void bordersForPolygon(int xStart, int yStart, double zStart, int xEnd, int yEnd, double zEnd);

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> borderBuffer;

    // ATX color configuration vectors
    std::vector<PolygonModel::model_t> atxPeripheriaSockets = {
        PolygonModel::ATX_HDMI_DP,
        PolygonModel::ATX_BIOS_FLBK,
        PolygonModel::ATX_U32G2_1_4,
        PolygonModel::ATX_LAN2_U32G2_56,
        PolygonModel::ATX_U3252_C8_LAN1_U32G2_7,
        PolygonModel::ATX_M2_WIFI,
        PolygonModel::ATX_AUDIO
    };
    std::vector<PolygonModel::model_t> atxCpuSocket = {
        PolygonModel::ATX_socketAM4
    };
    std::vector<PolygonModel::model_t> atxRamSockets_01 = {
        PolygonModel::ATX_DDR4_DIMM_B1,
        PolygonModel::ATX_DDR4_DIMM_A1
    };
    std::vector<PolygonModel::model_t> atxRamSockets_02 = {
        PolygonModel::ATX_DDR4_DIMM_B2,
        PolygonModel::ATX_DDR4_DIMM_A2
    };
    std::vector<PolygonModel::model_t> atxGpuSockets = {
        PolygonModel::ATX_PCIEX16_1,
        PolygonModel::ATX_PCIEX16_2,
        PolygonModel::ATX_PCIEX16_3
    };
    std::vector<PolygonModel::model_t> atxCapacitors = {
        PolygonModel::ATX_C22110_1,
        PolygonModel::ATX_C2280_1,
        PolygonModel::ATX_C2260_1,
        PolygonModel::ATX_C2242_1,
        PolygonModel::ATX_C22110_2,
        PolygonModel::ATX_C2280_2,
        PolygonModel::ATX_C2260_2,
        PolygonModel::ATX_C2242_2
    };
    std::vector<PolygonModel::model_t> atxSataSockets = {
        PolygonModel::ATX_SATA6G_1,
        PolygonModel::ATX_SATA6G_2,
        PolygonModel::ATX_SATA6G_3,
        PolygonModel::ATX_SATA6G_4,
        PolygonModel::ATX_SATA6G_5,
        PolygonModel::ATX_SATA6G_6,
        PolygonModel::ATX_SATA6G_7,
        PolygonModel::ATX_SATA6G_8
    };
    std::vector<PolygonModel::model_t> atxEatxSockets = {
        PolygonModel::ATX_EATX12V_1,
        PolygonModel::ATX_EATX12V_2,
        PolygonModel::ATX_EATXPWR,
    };
    std::vector<PolygonModel::model_t> atxConnectors = {
        PolygonModel::ATX_CPUFAN,
        PolygonModel::ATX_BIOS,
        PolygonModel::ATX_SPI_TPM
    };
    std::vector<PolygonModel::model_t> atxMicrochips = {
        PolygonModel::ATX_SuperIO,
        PolygonModel::ATX_IntelI22AT,
        PolygonModel::ATX_AMDX570,
        PolygonModel::ATX_RTL8125_CG,
        PolygonModel::ATX_U32G1_1011,
        PolygonModel::ATX_USB12,
        PolygonModel::ATX_USB34,
        PolygonModel::ATX_NODE
    };
    std::vector<PolygonModel::model_t> atxBattery = {
        PolygonModel::ATX_BATTERY
    };



    // MicroATX color configuration vectors
    std::vector<PolygonModel::model_t> microAtxPeripheriaSockets = {
        PolygonModel::MICROATX_HDMI1_DP,
        PolygonModel::MICROATX_HDMI2,
        PolygonModel::MICROATX_KBMS_USB_E32,
        PolygonModel::MICROATX_U32G2_C2,
        PolygonModel::MICROATX_LAN_USB_E12,
        PolygonModel::MICROATX_AUDIO
    };
    std::vector<PolygonModel::model_t> microAtxCpuSocket = {
        PolygonModel::MICROATX_LGA1200
    };
    std::vector<PolygonModel::model_t> microAtxRamSockets_01 = {
        PolygonModel::MICROATX_DDR4_DIMM_A1,
        PolygonModel::MICROATX_DDR4_DIMM_B1
    };
    std::vector<PolygonModel::model_t> microAtxRamSockets_02 = {
        PolygonModel::MICROATX_DDR4_DIMM_A2,
        PolygonModel::MICROATX_DDR4_DIMM_B2
    };
    std::vector<PolygonModel::model_t> microAtxGpuSockets = {
        PolygonModel::MICROATX_PCIEX16_1,
        PolygonModel::MICROATX_PCIEX16_2,
    };
    std::vector<PolygonModel::model_t> microAtxCapacitors = {
        PolygonModel::MICROATX_C2242_1,
        PolygonModel::MICROATX_C2260_1,
        PolygonModel::MICROATX_C2280_1,
        PolygonModel::MICROATX_C2242_2,
        PolygonModel::MICROATX_C2260_2,
        PolygonModel::MICROATX_C2280_2
    };
    std::vector<PolygonModel::model_t> microAtxSataSockets = {
        PolygonModel::MICROATX_SATA6G_1,
        PolygonModel::MICROATX_SATA6G_2,
        PolygonModel::MICROATX_SATA6G_3,
        PolygonModel::MICROATX_SATA6G_4,
    };
    std::vector<PolygonModel::model_t> microAtxAtxSockets = {
        PolygonModel::MICROATX_ATXPWR,
        PolygonModel::MICROATX_ATX_12V
    };
    std::vector<PolygonModel::model_t> microAtxConnectors = {
        PolygonModel::MICROATX_CPUFAN,
        PolygonModel::MICROATX_CHAFAN2,
        PolygonModel::MICROATX_BIOS,
        PolygonModel::MICROATX_M2_1
    };
    std::vector<PolygonModel::model_t> microAtxMicrochips = {
        PolygonModel::MICROATX_SuperIO,
        PolygonModel::MICROATX_IntelB560,
        PolygonModel::MICROATX_U32G1_34,
        PolygonModel::MICROATX_U32G1_56,
        PolygonModel::MICROATX_LPT
    };
    std::vector<PolygonModel::model_t> microAtxBattery = {
        PolygonModel::MICROATX_BATTERY
    };


    // MiniITX color configuration vectors
    std::vector<PolygonModel::model_t> miniItxPeripheriaSockets = {
        PolygonModel::MINIITX_USB3_5,
        PolygonModel::MINIITX_USB7_10,
        PolygonModel::MINIITX_HDMI_DP,
        PolygonModel::MINIITX_LAN_USB3_34,
        PolygonModel::MINIITX_M2_WIFI,
        PolygonModel::MINIITX_AUDIO
    };
    std::vector<PolygonModel::model_t> miniItxCpuSocket = {
        PolygonModel::MINIITX_LGA1151
    };
    std::vector<PolygonModel::model_t> miniItxRamSockets_01 = {
        PolygonModel::MINIITX_DDR4_DIMM_A1,
    };
    std::vector<PolygonModel::model_t> miniItxRamSockets_02 = {
        PolygonModel::MINIITX_DDR4_DIMM_B1,
    };
    std::vector<PolygonModel::model_t> miniItxGpuSockets = {
        PolygonModel::MINIITX_PCIEX16_1,
    };
    std::vector<PolygonModel::model_t> miniItxCapacitors = {
        PolygonModel::MINIITX_C2280,
        PolygonModel::MINIITX_C2260,
    };
    std::vector<PolygonModel::model_t> miniItxSataSockets = {
        PolygonModel::MINIITX_SATA6G_1,
        PolygonModel::MINIITX_SATA6G_2,
        PolygonModel::MINIITX_SATA6G_3,
        PolygonModel::MINIITX_SATA6G_4,
    };
    std::vector<PolygonModel::model_t> miniItxAtxSockets = {
        PolygonModel::MINIITX_EATXPWR,
        PolygonModel::MINIITX_EATX12V
    };
    std::vector<PolygonModel::model_t> miniItxConnectors = {
        PolygonModel::MINIITX_CPUFAN,
        PolygonModel::MINIITX_CHAFAN,
        PolygonModel::MINIITX_M2_2,
        PolygonModel::MINIITX_BIOS
    };
    std::vector<PolygonModel::model_t> miniItxMicrochips = {
        PolygonModel::MINIITX_SuperIO,
        PolygonModel::MINIITX_IntelZ270,
    };
    std::vector<PolygonModel::model_t> miniItxBattery = {
        PolygonModel::MINIITX_BATTERY
    };

    // CPU blocks
    std::vector<PolygonModel::model_t> cpuIntelBlock = {
        PolygonModel::Intel_CPU
    };

    std::vector<PolygonModel::model_t> cpuAMDBlock = {
        PolygonModel::AMD_CPU
    };

    std::vector<PolygonModel::model_t> cpuAccBlocks = {
        PolygonModel::Intel_ACC_CPU,
        PolygonModel::AMD_ACC_CPU
    };

    // GPU block
    std::vector<PolygonModel::model_t> gpuBlocks = {
        PolygonModel::GPU_4GB_BLOCK,
        PolygonModel::GPU_6GB_BLOCK,
        PolygonModel::GPU_8GB_BLOCK,
        PolygonModel::GPU_16GB_BLOCK,
    };

    std::vector<PolygonModel::model_t> gpuAccBlocks = {
        PolygonModel::GPU_4GB_ACC_BLOCK,
        PolygonModel::GPU_6GB_ACC_BLOCK,
        PolygonModel::GPU_8GB_ACC_BLOCK,
        PolygonModel::GPU_16GB_ACC_BLOCK,
    };

    // RAM blocks
    std::vector<PolygonModel::model_t> ramBlocks = {
        PolygonModel::RAM_4GB_BLOCK,
        PolygonModel::RAM_8GB_BLOCK,
        PolygonModel::RAM_16GB_BLOCK,
        PolygonModel::RAM_32GB_BLOCK,
    };

    std::vector<PolygonModel::model_t> ramAccBlocks = {
        PolygonModel::RAM_4GB_ACC_BLOCK,
        PolygonModel::RAM_8GB_ACC_BLOCK,
        PolygonModel::RAM_16GB_ACC_BLOCK,
        PolygonModel::RAM_32GB_ACC_BLOCK,
    };
};

#endif // DRAWER_H
