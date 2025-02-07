#ifndef POLYGONMODEL_H
#define POLYGONMODEL_H

#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"
#include "vertex.hpp"
#include "facet.hpp"
#include "mathelems.hpp"
#include "placeobjects.hpp"
#include "configmanager.hpp"

class PolygonModel
{
public:
    PolygonModel()
    {
    }
    PolygonModel(std::vector<Vertex> vertices_, std::vector<Facet> facets_)
        : vertices(vertices_), facets(facets_)
    {
    }

    PolygonModel(std::vector<Vertex> vertices_, std::vector<Facet> facets_, QString name_)
        : vertices(vertices_), facets(facets_), modelName(name_)
    {
    }

    PolygonModel(std::vector<Vertex> vertices_, std::vector<Facet> facets_, QString name_, int slot_)
        : vertices(vertices_), facets(facets_), modelName(name_), slot(slot_)
    {
    }

    ~PolygonModel() {}

    const std::vector<Vertex> getVertices();
    const std::vector<Facet> getFacets();


    void setUsedCell(int xCell_, int yCell_, double zCell_);
    int getUsedXCell();
    int getUsedYCell();
    int getUsedZCell();

    void setLengthModel(int widthModel_);
    int  getLengthModel();
    void setWidthModel(int heightModel_);
    int  getWidthModel();

    void setModelNum(size_t modelNum_);
    size_t getModelNum();

    QString getName();
    void setName(QString modelName_);

    enum model_t
    {
        Brick,
        Plate,
        Tile,
        Arc41,
        Arc14,
        Cylinder1,
        Cylinder2,
        // ATX
        ATX_HDMI_DP,
        ATX_BIOS_FLBK,
        ATX_U32G2_1_4,
        ATX_LAN2_U32G2_56,
        ATX_U3252_C8_LAN1_U32G2_7,
        ATX_M2_WIFI,
        ATX_AUDIO,
        ATX_socketAM4,
        ATX_DDR4_DIMM_B1,
        ATX_DDR4_DIMM_B2,
        ATX_DDR4_DIMM_A1,
        ATX_DDR4_DIMM_A2,
        ATX_PCIEX16_1,
        ATX_PCIEX16_2,
        ATX_PCIEX16_3,
        ATX_C22110_1,
        ATX_C2280_1,
        ATX_C2260_1,
        ATX_C2242_1,
        ATX_C22110_2,
        ATX_C2280_2,
        ATX_C2260_2,
        ATX_C2242_2,
        ATX_BATTERY,
        ATX_AMDX570,
        ATX_SATA6G_1,
        ATX_SATA6G_2,
        ATX_SATA6G_3,
        ATX_SATA6G_4,
        ATX_SATA6G_5,
        ATX_SATA6G_6,
        ATX_SATA6G_7,
        ATX_SATA6G_8,
        ATX_SuperIO,
        ATX_IntelI22AT,
        ATX_EATX12V_1,
        ATX_EATX12V_2,
        ATX_RTL8125_CG,
        ATX_EATXPWR,
        ATX_NODE,
        ATX_USB34,
        ATX_USB12,
        ATX_U32G1_1011,
        ATX_BIOS,
        ATX_SPI_TPM,
        ATX_CPUFAN,
        // MICROATX
        MICROATX_HDMI1_DP,
        MICROATX_HDMI2,
        MICROATX_KBMS_USB_E32,
        MICROATX_U32G2_C2,
        MICROATX_LAN_USB_E12,
        MICROATX_AUDIO,
        MICROATX_LGA1200,
        MICROATX_DDR4_DIMM_A1,
        MICROATX_DDR4_DIMM_A2,
        MICROATX_DDR4_DIMM_B1,
        MICROATX_DDR4_DIMM_B2,
        MICROATX_PCIEX16_1,
        MICROATX_PCIEX16_2,
        MICROATX_C2242_1,
        MICROATX_C2260_1,
        MICROATX_C2280_1,
        MICROATX_C2242_2,
        MICROATX_C2260_2,
        MICROATX_C2280_2,
        MICROATX_BATTERY,
        MICROATX_SATA6G_1,
        MICROATX_SATA6G_2,
        MICROATX_SATA6G_3,
        MICROATX_SATA6G_4,
        MICROATX_ATXPWR,
        MICROATX_IntelB560,
        MICROATX_SuperIO,
        MICROATX_U32G1_34,
        MICROATX_U32G1_56,
        MICROATX_ATX_12V,
        MICROATX_M2_1,
        MICROATX_LPT,
        MICROATX_CHAFAN2,
        MICROATX_BIOS,
        MICROATX_CPUFAN,
        // MINIITX
        MINIITX_USB3_5,
        MINIITX_USB7_10,
        MINIITX_HDMI_DP,
        MINIITX_LAN_USB3_34,
        MINIITX_M2_WIFI,
        MINIITX_AUDIO,
        MINIITX_LGA1151,
        MINIITX_DDR4_DIMM_A1,
        MINIITX_DDR4_DIMM_B1,
        MINIITX_PCIEX16_1,
        MINIITX_C2280,
        MINIITX_C2260,
        MINIITX_SATA6G_1,
        MINIITX_SATA6G_2,
        MINIITX_SATA6G_3,
        MINIITX_SATA6G_4,
        MINIITX_IntelZ270,
        MINIITX_SuperIO,
        MINIITX_EATXPWR,
        MINIITX_EATX12V,
        MINIITX_BIOS,
        MINIITX_CHAFAN,
        MINIITX_M2_2,
        MINIITX_CPUFAN,
        MINIITX_BATTERY,
        // CPU type
        Intel_CPU,
        AMD_CPU,
        Intel_ACC_CPU,
        AMD_ACC_CPU,
        // RAM type
        RAM_4GB_BLOCK,
        RAM_8GB_BLOCK,
        RAM_16GB_BLOCK,
        RAM_32GB_BLOCK,
        RAM_4GB_ACC_BLOCK,
        RAM_8GB_ACC_BLOCK,
        RAM_16GB_ACC_BLOCK,
        RAM_32GB_ACC_BLOCK,
        // GPU type
        GPU_4GB_BLOCK,
        GPU_6GB_BLOCK,
        GPU_8GB_BLOCK,
        GPU_16GB_BLOCK,
        GPU_4GB_ACC_BLOCK,
        GPU_6GB_ACC_BLOCK,
        GPU_8GB_ACC_BLOCK,
        GPU_16GB_ACC_BLOCK,
    };

    void setModelType(model_t modelType_);
    model_t getModelType();

    void setSlot(int slotIndex);
    int getSlot() const;

    friend std::ostream &operator<<(std::ostream &os, const PolygonModel &model);

private:
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    QString modelName;
    int slot = -1;

    int xCell, yCell; // not used (deprecated)
    double zCell; // not used (deprecated)
    int lengthModel, widthModel;

    size_t modelNum;
    model_t modelType;
};

PolygonModel::model_t parseRAMModel(ConfigManager::RAMType RAMType);

PolygonModel::model_t parseGPUModel(ConfigManager::GPUType GPUType);

PolygonModel::model_t parseCPUModel(ConfigManager::CPUType CPUType);

PolygonModel::model_t parseRAMAccModel(ConfigManager::RAMAccessoriesType RAMAccType);

PolygonModel::model_t parseGPUAccModel(ConfigManager::GPUAccessoriesType GPUAccType);

PolygonModel::model_t parseCPUAccModel(ConfigManager::CPUAccessoriesType CPUAccType);

std::string mapModelName(PolygonModel::model_t type);

std::string mapAccessoryName(PolygonModel::model_t type);

PolygonModel::model_t mapModelAccessory(PolygonModel::model_t model);

bool isRamModel(PolygonModel::model_t modelType);

bool isGpuModel(PolygonModel::model_t modelType);

#endif // POLYGONMODEL_H
