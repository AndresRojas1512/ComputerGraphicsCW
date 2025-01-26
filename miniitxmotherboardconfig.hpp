#ifndef MINIITXMOTHERBOARDCONFIG_HPP
#define MINIITXMOTHERBOARDCONFIG_HPP

#include <vector>
#include "mathelems.hpp"
#include "config.hpp"
#include "componentprimitives.hpp"
#include "basemotherboardconfig.hpp"

class MiniITXMotherboardConfig : public BaseMotherboardConfig
{
public:

    enum class RAMSlot
    {
        A1,
        B1
    };

    MiniITXMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : BaseMotherboardConfig(startOfPlate_, endOfPlate_),
        // peripheria
        USB3_5({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + 20, MINIITX_USB3_5_WIDTH, MINIITX_USB3_5_HEIGHT, 20)}, {}),
        USB7_10({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + 20, MINIITX_USB7_10_WIDTH, MINIITX_USB7_10_HEIGHT, 20)}, {}),
        HDMI_DP({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + 20, MINIITX_HDMI_DP_WIDTH, MINIITX_HDMI_DP_HEIGHT, 20)}, {}),
        LAN_USB3_34({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + 20, MINIITX_LAN_USB3_34_WIDTH, MINIITX_LAN_USB3_34_HEIGHT, 20)}, {}),
        M2_WIFI({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + 20, MINIITX_M2_WIFI_WIDTH, MINIITX_M2_WIFI_HEIGHT, 20)}, {}),
        AUDIO({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_OFFSET_Y, BASE_Z + 20, MINIITX_AUDIO_WIDTH, MINIITX_AUDIO_HEIGHT, 20)}, {}),
        // RAM
        DDR4_DIMM_A1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_Y, BASE_Z + 40, MINIITX_DDR4_DIMM_WIDTH, MINIITX_DDR4_DIMM_HEIGHT, 40, MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, MINIITX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, MINIITX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_B1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_Y, BASE_Z + 40, MINIITX_DDR4_DIMM_WIDTH, MINIITX_DDR4_DIMM_HEIGHT, 40, MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, MINIITX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, MINIITX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        // GPU
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, MINIITX_PCIEX16_WIDTH, MINIITX_PCIEX16_HEIGHT, 40, MINIITX_PCIEX16_TOPFRAMEWIDTH, MINIITX_PCIEX16_BOTTOMFRAMEWIDTH, MINIITX_PCIEX16_LEFTFRAMEWIDTH, MINIITX_PCIEX16_RIGHTFRAMEWIDTH)}),
        // RAM slots offset
        DDR4_DIMM_A1_offset(1, 2, 3),
        DDR4_DIMM_B1_offset(11, 22, 33),
        DDR4_DIMM_A1_ACC_offset(10, 20, 30),
        DDR4_DIMM_B1_ACC_offset(100, 200, 300),
        // GPU slots offset
        PCIEX16_1_offset(1, 2, 3),
        // CPU slot offset
        CPU_offset(1, 2, 3)
    {
        std::cout << "MiniITXMotherboardConfig::MiniITXMotherboardConfig" << std::endl;
        ramSlotsOccupied = {{static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::B1), false}};
    }

    Dot3D getRamSlotPosition(int slot) const override;
    Dot3D getRamAccSlotPosition(int slot) const override;

    Dot3D getGpuSlotPosition(int slot) const override;
    Dot3D getCpuSlotPosition(void) const override;

    // peripheria
    ComponentConfig USB3_5;
    ComponentConfig USB7_10;
    ComponentConfig HDMI_DP;
    ComponentConfig LAN_USB3_34;
    ComponentConfig M2_WIFI;
    ComponentConfig AUDIO;
    //RAM
    ComponentConfig DDR4_DIMM_A1;
    ComponentConfig DDR4_DIMM_B1;
    // GPU
    ComponentConfig PCIEX16_1;

    // offset for placing the RAM block in the DDR4 socket
    Dot3D DDR4_DIMM_A1_offset;
    Dot3D DDR4_DIMM_B1_offset;
    Dot3D DDR4_DIMM_A1_ACC_offset;
    Dot3D DDR4_DIMM_B1_ACC_offset;
    // offset for placing the GPU block in the PCIEX16 socket
    Dot3D PCIEX16_1_offset;
    // offset for placing the CPU block int the CPU socket
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

#endif // MINIITXMOTHERBOARDCONFIG_HPP
