#ifndef MICROATXMOTHERBOARDCONFIG_H
#define MICROATXMOTHERBOARDCONFIG_H

#include <vector>
#include <map>
#include "mathelems.hpp"
#include "config.hpp"
#include "motherboardprimitives.hpp"
#include "basemotherboardconfig.hpp"

// PERIPHERIA
#define MICROATX_HDMI1_DP_OFFSET_X 0
#define MICROATX_HDMI1_DP_OFFSET_Y 18
#define MICROATX_HDMI1_DP_WIDTH 48
#define MICROATX_HDMI1_DP_HEIGHT 54

#define MICROATX_HDMI2_OFFSET_X 0
#define MICROATX_HDMI2_OFFSET_Y 90
#define MICROATX_HDMI2_WIDTH 42
#define MICROATX_HDMI2_HEIGHT 48

#define MICROATX_KBMS_USB_E34_OFFSET_X 0
#define MICROATX_KBMS_USB_E34_OFFSET_Y 162
#define MICROATX_KBMS_USB_E34_WIDTH 60
#define MICROATX_KBMS_USB_E34_HEIGHT 48

#define MICROATX_U32G2_C2_OFFSET_X 0
#define MICROATX_U32G2_C2_OFFSET_Y 228
#define MICROATX_U32G2_C2_WIDTH 48
#define MICROATX_U32G2_C2_HEIGHT 48

#define MICROATX_LAN_USB_E12_OFFSET_X 0
#define MICROATX_LAN_USB_E12_OFFSET_Y 294
#define MICROATX_LAN_USB_E12_WIDTH 84
#define MICROATX_LAN_USB_E12_HEIGHT 54

#define MICROATX_AUDIO_OFFSET_X 0
#define MICROATX_AUDIO_OFFSET_Y 426
#define MICROATX_AUDIO_WIDTH 66
#define MICROATX_AUDIO_HEIGHT 48

#define MICROATX_AUDIO_OFFSET_X 0
#define MICROATX_AUDIO_OFFSET_Y 426
#define MICROATX_AUDIO_WIDTH 66
#define MICROATX_AUDIO_HEIGHT 48

// Processor slot
#define MICROATX_LGA1200_PARALLELEPIPED_OFFSET_X 270
#define MICROATX_LGA1200_PARALLELEPIPED_OFFSET_Y 174
#define MICROATX_LGA1200_PARALLELEPIPED_WIDTH 144
#define MICROATX_LGA1200_PARALLELEPIPED_HEIGHT 162

#define MICROATX_LGA1200_FRAME_OFFSET_X 288
#define MICROATX_LGA1200_FRAME_OFFSET_Y 192
#define MICROATX_LGA1200_FRAME_WIDTH 108
#define MICROATX_LGA1200_FRAME_HEIGHT 120
#define MICROATX_LGA1200_FRAME_TOPFRAMEWIDTH 12
#define MICROATX_LGA1200_FRAME_BOTTOMFRAMEWIDTH 18
#define MICROATX_LGA1200_FRAME_LEFTFRAMEWIDTH 12
#define MICROATX_LGA1200_FRAME_RIGHTFRAMEWIDTH 12

// RAM
#define MICROATX_DDR4_DIMM_WIDTH 24
#define MICROATX_DDR4_DIMM_HEIGHT 420
#define MICROATX_DDR4_DIMM_TOPFRAMEWIDTH 5
#define MICROATX_DDR4_DIMM_BOTTOMFRAMEWIDTH 5
#define MICROATX_DDR4_DIMM_LEFTFRAMEWIDTH 9
#define MICROATX_DDR4_DIMM_RIGHTFRAMEWIDTH 9

#define MICROATX_DDR4_DIMM_A1_OFFSET_X 498
#define MICROATX_DDR4_DIMM_A1_OFFSET_Y 42

#define MICROATX_DDR4_DIMM_A2_OFFSET_X 528
#define MICROATX_DDR4_DIMM_A2_OFFSET_Y 42

#define MICROATX_DDR4_DIMM_B1_OFFSET_X 558
#define MICROATX_DDR4_DIMM_B1_OFFSET_Y 42

#define MICROATX_DDR4_DIMM_B2_OFFSET_X 588
#define MICROATX_DDR4_DIMM_B2_OFFSET_Y 42

// GPU
#define MICROATX_PCIEX16_WIDTH 270
#define MICROATX_PCIEX16_HEIGHT 24
#define MICROATX_PCIEX16_TOPFRAMEWIDTH 9
#define MICROATX_PCIEX16_BOTTOMFRAMEWIDTH 9
#define MICROATX_PCIEX16_LEFTFRAMEWIDTH 5
#define MICROATX_PCIEX16_RIGHTFRAMEWIDTH 5


#define MICROATX_PCIEX16_1_OFFSET_X 126
#define MICROATX_PCIEX16_1_OFFSET_Y 474

#define MICROATX_PCIEX16_2_OFFSET_X 126
#define MICROATX_PCIEX16_2_OFFSET_Y 660

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
        PCIEX16_2({}, {FrameConfig(startOfPlate_.getXCoordinate() + MICROATX_PCIEX16_2_OFFSET_X, startOfPlate_.getYCoordinate() + MICROATX_PCIEX16_2_OFFSET_Y, BASE_Z + 40, MICROATX_PCIEX16_WIDTH, MICROATX_PCIEX16_HEIGHT, 40, MICROATX_PCIEX16_TOPFRAMEWIDTH, MICROATX_PCIEX16_BOTTOMFRAMEWIDTH, MICROATX_PCIEX16_LEFTFRAMEWIDTH, MICROATX_PCIEX16_RIGHTFRAMEWIDTH)})
    {
        std::cout << "MicroATXMotherboardConfig::MicroATXMotherboardConfig" << std::endl;
        ramSlotsOccupied = {{static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::A2), false}, {static_cast<int>(RAMSlot::B1), false}, {static_cast<int>(RAMSlot::B2), false}};
    }

    // peripheria
    componentConfig HDMI1_DP;
    componentConfig HDMI2;
    componentConfig KBMS_USB_E32;
    componentConfig U32G2_C2;
    componentConfig LAN_USB_E12;
    componentConfig AUDIO;
    // processor
    componentConfig LGA1200;

    // RAM
    componentConfig DDR4_DIMM_A1;
    componentConfig DDR4_DIMM_A2;
    componentConfig DDR4_DIMM_B1;
    componentConfig DDR4_DIMM_B2;

    // GPU
    componentConfig PCIEX16_1;
    componentConfig PCIEX16_2;

    Dot3D getStartOfPlate() const override;
    Dot3D getEndOfPlate() const override;

    bool isRamSlotAvailable(int slot) override;
    void occupyRamSlot(int slot) override;
    QList<int> getAvailableRamSlots() override;
};

#endif // MICROATXMOTHERBOARDCONFIG_H
