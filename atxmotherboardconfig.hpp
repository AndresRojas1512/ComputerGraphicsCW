#ifndef ATXMOTHERBOARDCONFIG_HPP
#define ATXMOTHERBOARDCONFIG_HPP

#include <vector>
#include "mathelems.hpp"
#include "config.hpp"
#include "motherboardprimitives.hpp"

// PERIPHERIA
#define ATX_HDMI_DP_OFFSET_X 0
#define ATX_HDMI_DP_OFFSET_Y 18
#define ATX_HDMI_DP_WIDTH 54
#define ATX_HDMI_DP_HEIGHT 66

#define ATX_BIOS_FLBK_OFFSET_X 0
#define ATX_BIOS_FLBK_OFFSET_Y 95
#define ATX_BIOS_FLBK_WIDTH 24
#define ATX_BIOS_FLBK_HEIGHT 24

#define ATX_U32G2_1_4_OFFSET_X 0
#define ATX_U32G2_1_4_OFFSET_Y 144
#define ATX_U32G2_1_4_WIDTH 72
#define ATX_U32G2_1_4_HEIGHT 42

#define ATX_LAN2_U32G2_56_OFFSET_X 0
#define ATX_LAN2_U32G2_56_OFFSET_Y 198
#define ATX_LAN2_U32G2_56_WIDTH 84
#define ATX_LAN2_U32G2_56_HEIGHT 54

#define ATX_U3252_C8_LAN1_U32G2_7_OFFSET_X 0
#define ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y 264
#define ATX_U3252_C8_LAN1_U32G2_7_WIDTH 84
#define ATX_U3252_C8_LAN1_U32G2_7_HEIGHT 54

#define ATX_M2_WIFI_OFFSET_X 0
#define ATX_M2_WIFI_OFFSET_Y 324
#define ATX_M2_WIFI_WIDTH 84
#define ATX_M2_WIFI_HEIGHT 36

#define ATX_AUDIO_OFFSET_X 0
#define ATX_AUDIO_OFFSET_Y 372
#define ATX_AUDIO_WIDTH 60
#define ATX_AUDIO_HEIGHT 72

// processor
#define ATX_socketM4_OFFSET_X
#define ATX_socketM4_OFFSET_Y

// RAM
#define ATX_DDR4_DIMM_WIDTH 24
#define ATX_DDR4_DIMM_HEIGHT 420
#define ATX_DDR4_DIMM_TOPFRAMEWIDTH 5
#define ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH 5
#define ATX_DDR4_DIMM_LEFTFRAMEWIDTH 9
#define ATX_DDR4_DIMM_RIGHTFRAMEWIDTH 9

#define ATX_DDR4_DIMM_B1_OFFSET_X 546
#define ATX_DDR4_DIMM_B1_OFFSET_Y 66

#define ATX_DDR4_DIMM_B2_OFFSET_X 576
#define ATX_DDR4_DIMM_B2_OFFSET_Y 66

#define ATX_DDR4_DIMM_A1_OFFSET_X 606
#define ATX_DDR4_DIMM_A1_OFFSET_Y 66

#define ATX_DDR4_DIMM_A2_OFFSET_X 636
#define ATX_DDR4_DIMM_A2_OFFSET_Y 66

// GPU
#define ATX_PCIEX16_WIDTH 270
#define ATX_PCIEX16_HEIGHT 24
#define ATX_PCIEX16_TOPFRAMEWIDTH 9
#define ATX_PCIEX16_BOTTOMFRAMEWIDTH 9
#define ATX_PCIEX16_LEFTFRAMEWIDTH 5
#define ATX_PCIEX16_RIGHTFRAMEWIDTH 5

#define ATX_PCIEX16_1_OFFSET_X 126
#define ATX_PCIEX16_1_OFFSET_Y 528

#define ATX_PCIEX16_2_OFFSET_X 126
#define ATX_PCIEX16_2_OFFSET_Y 708

#define ATX_PCIEX16_3_OFFSET_X 126
#define ATX_PCIEX16_3_OFFSET_Y 828

class ATXMotherboardConfig
{
public:
    ATXMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : startOfPlate(startOfPlate_), endOfPlate(endOfPlate_),
        // peripheria
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
        PCIEX16_3({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_3_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)})
    {
    }

    // peripheria
    BasePlateComponentConfig HDMI_DP;
    BasePlateComponentConfig BIOS_FLBK;
    BasePlateComponentConfig U32G2_1_4;
    BasePlateComponentConfig LAN2_U32G2_56;
    BasePlateComponentConfig U3252_C8_LAN1_U32G2_7;
    BasePlateComponentConfig M2_WIFI;
    BasePlateComponentConfig AUDIO;

    // processor
    BasePlateComponentConfig socketM4;

    // RAM
    BasePlateComponentConfig DDR4_DIMM_B1;
    BasePlateComponentConfig DDR4_DIMM_B2;
    BasePlateComponentConfig DDR4_DIMM_A1;
    BasePlateComponentConfig DDR4_DIMM_A2;

    // GPU
    BasePlateComponentConfig PCIEX16_1;
    BasePlateComponentConfig PCIEX16_2;
    BasePlateComponentConfig PCIEX16_3;

    Dot3D getStartOfPlate() const;
    Dot3D getEndOfPlate() const;

private:
    Dot3D startOfPlate;
    Dot3D endOfPlate;
};


#endif // ATXMOTHERBOARDCONFIG_HPP
