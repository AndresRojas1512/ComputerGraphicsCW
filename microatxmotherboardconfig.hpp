#ifndef MICROATXMOTHERBOARDCONFIG_H
#define MICROATXMOTHERBOARDCONFIG_H

#include <vector>
#include <map>
#include "mathelems.hpp"
#include "config.hpp"
#include "componentprimitives.hpp"
#include "basemotherboardconfig.hpp"

class MicroATXMotherboardConfig : public BaseMotherboardConfig
{
public:

    enum class RAMSlot
    {
        A1,
        A2,
        B1,
        B2
    };

    enum class GPUSlot
    {
        A1,
        A2,
    };

    MicroATXMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : BaseMotherboardConfig(startOfPlate_, endOfPlate_),
        // peripheria
        HDMI1_DP({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_HDMI1_DP_OFFSET_Y, BASE_Z + 60, MICROATX_HDMI1_DP_WIDTH, MICROATX_HDMI1_DP_HEIGHT, 60)}, {}),
        // peripheria
        HDMI2({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_HDMI2_OFFSET_Y, BASE_Z + 20, MICROATX_HDMI2_WIDTH, MICROATX_HDMI2_HEIGHT, 20)}, {}),
        // peripheria
        KBMS_USB_E32({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_KBMS_USB_E34_OFFSET_Y, BASE_Z + 30, MICROATX_KBMS_USB_E34_WIDTH, MICROATX_KBMS_USB_E34_HEIGHT, 30)}, {}),
        // peripheria
        U32G2_C2({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_U32G2_C2_OFFSET_Y, BASE_Z + 30, MICROATX_U32G2_C2_WIDTH, MICROATX_U32G2_C2_HEIGHT, 30)}, {}),
        // peripheria
        LAN_USB_E12({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_LAN_USB_E12_OFFSET_Y, BASE_Z + 30, MICROATX_LAN_USB_E12_WIDTH, MICROATX_LAN_USB_E12_HEIGHT, 30)}, {}),
        // peripheria
        AUDIO({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MICROATX_AUDIO_OFFSET_Y, BASE_Z + 30, MICROATX_AUDIO_WIDTH, MICROATX_AUDIO_HEIGHT, 30)}, {}),
        // processor
        LGA1200({ParallelepipedConfig(startOfPlate_.getXCoordinate() + MICROATX_LGA1200_PARALLELEPIPED_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_LGA1200_PARALLELEPIPED_OFFSET_Y, BASE_Z + 5, MICROATX_LGA1200_PARALLELEPIPED_WIDTH, MICROATX_LGA1200_PARALLELEPIPED_HEIGHT, 5)},
                {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_LGA1200_FRAME_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_LGA1200_FRAME_OFFSET_Y, BASE_Z + 10, MICROATX_LGA1200_FRAME_WIDTH, MICROATX_LGA1200_FRAME_HEIGHT, 5, MICROATX_LGA1200_FRAME_TOPFRAMEWIDTH, MICROATX_LGA1200_FRAME_BOTTOMFRAMEWIDTH, MICROATX_LGA1200_FRAME_LEFTFRAMEWIDTH, MICROATX_LGA1200_FRAME_RIGHTFRAMEWIDTH)}),
        // RAM
        DDR4_DIMM_A1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_Y, BASE_Z + 40, MICROATX_DDR4_DIMM_WIDTH, MICROATX_DDR4_DIMM_HEIGHT, 40, MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, MICROATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, MICROATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_A2({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_Y, BASE_Z + 40, MICROATX_DDR4_DIMM_WIDTH, MICROATX_DDR4_DIMM_HEIGHT, 40, MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, MICROATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, MICROATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_B1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_Y, BASE_Z + 40, MICROATX_DDR4_DIMM_WIDTH, MICROATX_DDR4_DIMM_HEIGHT, 40, MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, MICROATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, MICROATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        DDR4_DIMM_B2({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_Y, BASE_Z + 40, MICROATX_DDR4_DIMM_WIDTH, MICROATX_DDR4_DIMM_HEIGHT, 40, MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, MICROATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, MICROATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}),
        // GPU
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, MICROATX_PCIEX16_WIDTH, MICROATX_PCIEX16_HEIGHT, 40, MICROATX_PCIEX16_TOPFRAMEWIDTH, MICROATX_PCIEX16_BOTTOMFRAMEWIDTH, MICROATX_PCIEX16_LEFTFRAMEWIDTH, MICROATX_PCIEX16_RIGHTFRAMEWIDTH)}),
        PCIEX16_2({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_PCIEX16_2_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_PCIEX16_2_OFFSET_Y, BASE_Z + 40, MICROATX_PCIEX16_WIDTH, MICROATX_PCIEX16_HEIGHT, 40, MICROATX_PCIEX16_TOPFRAMEWIDTH, MICROATX_PCIEX16_BOTTOMFRAMEWIDTH, MICROATX_PCIEX16_LEFTFRAMEWIDTH, MICROATX_PCIEX16_RIGHTFRAMEWIDTH)}),
        // RAM slots offset
        DDR4_DIMM_A1_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_X + MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_Y + MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_A2_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_X + MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_Y + MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_B1_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_X + MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_Y + MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_B2_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_X + MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_Y + MICROATX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_A1_ACC_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_A2_ACC_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_A2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_B1_ACC_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B1_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_B2_ACC_offset(startOfPlate_.getXCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_X + ATX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MICROATX_DDR4_DIMM_B2_OFFSET_Y + ATX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        // GPU slots offset
        PCIEX16_1_offset(1, 2, 3), // TODO
        PCIEX16_2_offset(11, 22, 33), // TODO
        // CPU slot offset
        CPU_offset(1, 2, 3) // TODO
    {
        std::cout << "MicroATXMotherboardConfig::MicroATXMotherboardConfig" << std::endl;
        ramSlotsOccupied = {{static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::A2), false}, {static_cast<int>(RAMSlot::B1), false}, {static_cast<int>(RAMSlot::B2), false}};
        gpuSlotsOccupied = {{static_cast<int>(GPUSlot::A1), false}, {static_cast<int>(GPUSlot::A2), false}};
    }

    Dot3D getRamSlotPosition(int slot) const override;
    Dot3D getRamAccSlotPosition(int slot) const override;

    Dot3D getGpuSlotPosition(int slot) const override;

    Dot3D getCpuSlotPosition(void) const override;

    // peripheria
    ComponentConfig HDMI1_DP;
    ComponentConfig HDMI2;
    ComponentConfig KBMS_USB_E32;
    ComponentConfig U32G2_C2;
    ComponentConfig LAN_USB_E12;
    ComponentConfig AUDIO;
    // processor
    ComponentConfig LGA1200;

    // RAM
    ComponentConfig DDR4_DIMM_A1;
    ComponentConfig DDR4_DIMM_A2;
    ComponentConfig DDR4_DIMM_B1;
    ComponentConfig DDR4_DIMM_B2;

    // GPU
    ComponentConfig PCIEX16_1;
    ComponentConfig PCIEX16_2;

    // offset for placing the RAM block in the DDR4 socket
    Dot3D DDR4_DIMM_A1_offset;
    Dot3D DDR4_DIMM_A2_offset;
    Dot3D DDR4_DIMM_B1_offset;
    Dot3D DDR4_DIMM_B2_offset;
    Dot3D DDR4_DIMM_A1_ACC_offset;
    Dot3D DDR4_DIMM_A2_ACC_offset;
    Dot3D DDR4_DIMM_B1_ACC_offset;
    Dot3D DDR4_DIMM_B2_ACC_offset;


    // offset for placing the GPU block in the PCIEX16 socket
    Dot3D PCIEX16_1_offset;
    Dot3D PCIEX16_2_offset;

    // offset for placing the CPU in the CPU socket
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

#endif // MICROATXMOTHERBOARDCONFIG_H
