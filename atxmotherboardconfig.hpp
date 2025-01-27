#ifndef ATXMOTHERBOARDCONFIG_HPP
#define ATXMOTHERBOARDCONFIG_HPP

#include <vector>
#include <map>
#include "mathelems.hpp"
#include "config.hpp"
#include "componentprimitives.hpp"
#include "basemotherboardconfig.hpp"

class ATXMotherboardConfig : public BaseMotherboardConfig
{
public:

    enum class RAMSlot
    {
        B1,
        B2,
        A1,
        A2
    };

    enum class GPUSlot
    {
        A1,
        A2,
        A3
    };

    ATXMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : BaseMotherboardConfig(startOfPlate_, endOfPlate_),
        HDMI_DP({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + 20, ATX_HDMI_DP_WIDTH, ATX_HDMI_DP_HEIGHT, 20)},{}),
        // peripheria
        BIOS_FLBK({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y, BASE_Z + 20, ATX_BIOS_FLBK_WIDTH, ATX_BIOS_FLBK_HEIGHT, 20)}, {}),
        // peripheria
        U32G2_1_4({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + 20, ATX_U32G2_1_4_WIDTH, ATX_U32G2_1_4_HEIGHT, 20)}, {}),
        // peripheria
        LAN2_U32G2_56({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + 20, ATX_LAN2_U32G2_56_WIDTH, ATX_LAN2_U32G2_56_HEIGHT, 20)}, {}),
        // peripheria
        U3252_C8_LAN1_U32G2_7({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + 20, ATX_U3252_C8_LAN1_U32G2_7_WIDTH, ATX_U3252_C8_LAN1_U32G2_7_HEIGHT, 20)}, {}),
        // peripheria
        M2_WIFI({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + 20, ATX_M2_WIFI_WIDTH, ATX_M2_WIFI_HEIGHT, 20)}, {}),
        // peripheria
        AUDIO({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_OFFSET_Y, BASE_Z + 20, ATX_AUDIO_WIDTH, ATX_AUDIO_HEIGHT, 20)}, {}),
        // processor
        socketM4({}, {}),
        // RAM
        DDR4_DIMM_B1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_B2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_A1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_A2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        // GPU
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}),
        PCIEX16_2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_2_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}),
        PCIEX16_3({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_3_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}),
        // RAM slots offset
        DDR4_DIMM_B1_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_B2_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_A1_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_A2_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_B1_ACC_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_B2_ACC_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_A1_ACC_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_A2_ACC_offset(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        // GPU slots offset
        PCIEX16_1_offset(startOfPlate_.getXCoordinate() + ATX_PCIEX16_1_OFFSET_X + ATX_PCIEX16_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_PCIEX16_1_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_2_offset(startOfPlate_.getXCoordinate() + ATX_PCIEX16_2_OFFSET_X + ATX_PCIEX16_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_PCIEX16_2_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_3_offset(startOfPlate_.getXCoordinate() + ATX_PCIEX16_3_OFFSET_X + ATX_PCIEX16_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_1_ACC_offset(startOfPlate_.getXCoordinate() + 30, startOfPlate_.getYCoordinate() + ATX_PCIEX16_1_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_2_ACC_offset(startOfPlate_.getXCoordinate() + 30, startOfPlate_.getYCoordinate() + ATX_PCIEX16_2_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_3_ACC_offset(startOfPlate_.getXCoordinate() + 30, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        // CPU slot offset
        CPU_offset(1, 2, 3) // TODO
    {
        std::cout << "ATXMotherboardConfig::ATXMotherboardConfig" << std::endl;

        ramSlotsOccupied = {{static_cast<int>(RAMSlot::B1), false}, {static_cast<int>(RAMSlot::B2), false}, {static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::A2), false}};
        gpuSlotsOccupied = {{static_cast<int>(GPUSlot::A1), false}, {static_cast<int>(GPUSlot::A2), false}, {static_cast<int>(GPUSlot::A3), false}};
    }

    Dot3D getRamSlotPosition(int slot) const override;
    Dot3D getRamAccSlotPosition(int slot) const override;

    Dot3D getGpuSlotPosition(int slot) const override;
    Dot3D getGPuAccSlotPosition(int slot) const override;

    Dot3D getCpuSlotPosition(void) const override;

    // peripheria
    ComponentConfig HDMI_DP;
    ComponentConfig BIOS_FLBK;
    ComponentConfig U32G2_1_4;
    ComponentConfig LAN2_U32G2_56;
    ComponentConfig U3252_C8_LAN1_U32G2_7;
    ComponentConfig M2_WIFI;
    ComponentConfig AUDIO;

    // processor
    ComponentConfig socketM4;
    // RAM
    ComponentConfig DDR4_DIMM_B1;
    ComponentConfig DDR4_DIMM_B2;
    ComponentConfig DDR4_DIMM_A1;
    ComponentConfig DDR4_DIMM_A2;
    // GPU
    ComponentConfig PCIEX16_1;
    ComponentConfig PCIEX16_2;
    ComponentConfig PCIEX16_3;

    // offset for placing the RAM block in the DDR4 socket
    Dot3D DDR4_DIMM_B1_offset;
    Dot3D DDR4_DIMM_B2_offset;
    Dot3D DDR4_DIMM_A1_offset;
    Dot3D DDR4_DIMM_A2_offset;
    Dot3D DDR4_DIMM_B1_ACC_offset;
    Dot3D DDR4_DIMM_B2_ACC_offset;
    Dot3D DDR4_DIMM_A1_ACC_offset;
    Dot3D DDR4_DIMM_A2_ACC_offset;

    // offset for placing the GPU block in the PCIEX16 socket
    Dot3D PCIEX16_1_offset;
    Dot3D PCIEX16_2_offset;
    Dot3D PCIEX16_3_offset;
    Dot3D PCIEX16_1_ACC_offset;
    Dot3D PCIEX16_2_ACC_offset;
    Dot3D PCIEX16_3_ACC_offset;

    // offset for placing the processor in the processor socket
    Dot3D CPU_offset;

    Dot3D getStartOfPlate() const override;
    Dot3D getEndOfPlate() const override;

    bool isRamSlotAvailable(int slot) override;
    void occupyRamSlot(int slot) override;
    QList<int> getAvailableRamSlots() override;

    bool isGpuSlotAvailable(int slot) override;
    void occupyGpuSlot(int slot) override;
    QList<int> getAvailableGpuSlots() override;

    bool isCpuSlotAvailable(void) override;
};

std::string atxRamSlotToString(ATXMotherboardConfig::RAMSlot slot);

#endif // ATXMOTHERBOARDCONFIG_HPP
