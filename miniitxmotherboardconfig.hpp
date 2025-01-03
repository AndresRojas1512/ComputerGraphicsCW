#ifndef MINIITXMOTHERBOARDCONFIG_HPP
#define MINIITXMOTHERBOARDCONFIG_HPP

#include <vector>
#include "mathelems.hpp"
#include "config.hpp"
#include "motherboardprimitives.hpp"
#include "basemotherboardconfig.hpp"

// PERIPHERIA
#define MINIITX_USB3_5_OFFSET_X 0
#define MINIITX_USB3_5_OFFSET_Y 54
#define MINIITX_USB3_5_WIDTH 48
#define MINIITX_USB3_5_HEIGHT 42

#define MINIITX_USB7_10_OFFSET_X 0
#define MINIITX_USB7_10_OFFSET_Y 108
#define MINIITX_USB7_10_WIDTH 72
#define MINIITX_USB7_10_HEIGHT 48

#define MINIITX_HDMI_DP_OFFSET_X 0
#define MINIITX_HDMI_DP_OFFSET_Y 166
#define MINIITX_HDMI_DP_WIDTH 54
#define MINIITX_HDMI_DP_HEIGHT 66

#define MINIITX_LAN_USB3_34_OFFSET_X 0
#define MINIITX_LAN_USB3_34_OFFSET_Y 241
#define MINIITX_LAN_USB3_34_WIDTH 72
#define MINIITX_LAN_USB3_34_HEIGHT 54

#define MINIITX_M2_WIFI_OFFSET_X 0
#define MINIITX_M2_WIFI_OFFSET_Y 306
#define MINIITX_M2_WIFI_WIDTH 90
#define MINIITX_M2_WIFI_HEIGHT 24

#define MINIITX_AUDIO_OFFSET_X 0
#define MINIITX_AUDIO_OFFSET_Y 402
#define MINIITX_AUDIO_WIDTH 66
#define MINIITX_AUDIO_HEIGHT 72


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
#define MINIITX_DDR4_DIMM_WIDTH 24
#define MINIITX_DDR4_DIMM_HEIGHT 420
#define MINIITX_DDR4_DIMM_TOPFRAMEWIDTH 5
#define MINIITX_DDR4_DIMM_BOTTOMFRAMEWIDTH 5
#define MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH 9
#define MINIITX_DDR4_DIMM_RIGHTFRAMEWIDTH 9

#define MINIITX_DDR4_DIMM_A1_OFFSET_X 414
#define MINIITX_DDR4_DIMM_A1_OFFSET_Y 24

#define MINIITX_DDR4_DIMM_B1_OFFSET_X 444
#define MINIITX_DDR4_DIMM_B1_OFFSET_Y 24

// GPU
#define MINIITX_PCIEX16_WIDTH 270
#define MINIITX_PCIEX16_HEIGHT 24
#define MINIITX_PCIEX16_TOPFRAMEWIDTH 9
#define MINIITX_PCIEX16_BOTTOMFRAMEWIDTH 9
#define MINIITX_PCIEX16_LEFTFRAMEWIDTH 5
#define MINIITX_PCIEX16_RIGHTFRAMEWIDTH 5

#define MINIITX_PCIEX16_1_OFFSET_X 126
#define MINIITX_PCIEX16_1_OFFSET_Y 474

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
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, MINIITX_PCIEX16_WIDTH, MINIITX_PCIEX16_HEIGHT, 40, MINIITX_PCIEX16_TOPFRAMEWIDTH, MINIITX_PCIEX16_BOTTOMFRAMEWIDTH, MINIITX_PCIEX16_LEFTFRAMEWIDTH, MINIITX_PCIEX16_RIGHTFRAMEWIDTH)})
    {
        std::cout << "MiniITXMotherboardConfig::MiniITXMotherboardConfig" << std::endl;
        ramSlotsOccupied = {{static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::B1), false}};
    }

    // peripheria
    componentConfig USB3_5;
    componentConfig USB7_10;
    componentConfig HDMI_DP;
    componentConfig LAN_USB3_34;
    componentConfig M2_WIFI;
    componentConfig AUDIO;
    //RAM
    componentConfig DDR4_DIMM_A1;
    componentConfig DDR4_DIMM_B1;
    // GPU
    componentConfig PCIEX16_1;

    Dot3D getStartOfPlate() const override;
    Dot3D getEndOfPlate() const override;

    bool isRamSlotAvailable(int slot) override;
    void occupyRamSlot(int slot) override;
    QList<int> getAvailableRamSlots() override;
};

#endif // MINIITXMOTHERBOARDCONFIG_HPP
