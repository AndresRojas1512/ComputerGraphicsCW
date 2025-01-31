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
        HDMI_DP({
                 // HDMI
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_LEFTWALL_DEPTH, ATX_HDMI_DP_LEFTWALL_WIDTH, ATX_HDMI_DP_LEFTWALL_HEIGHT, ATX_HDMI_DP_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_HDMI_DP_BOTTOM_DEPTH, ATX_HDMI_DP_BOTTOM_WIDTH, ATX_HDMI_DP_BOTTOM_HEIGHT, ATX_HDMI_DP_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y + WALL_DEPTH + ATX_HDMI_DP_BOTTOM_HEIGHT, BASE_Z + ATX_HDMI_DP_RIGHTWALL_DEPTH, ATX_HDMI_DP_RIGHTWALL_WIDTH, ATX_HDMI_DP_RIGHTWALL_HEIGHT, ATX_HDMI_DP_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_HDMI_DP_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_BACKWALL_DEPTH, ATX_HDMI_DP_BACKWALL_WIDTH, ATX_HDMI_DP_BACKWALL_HEIGHT, ATX_HDMI_DP_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_BACKWALL_DEPTH + ATX_HDMI_DP_TOP_DEPTH, ATX_HDMI_DP_TOP_WIDTH, ATX_HDMI_DP_TOP_HEIGHT, ATX_HDMI_DP_TOP_DEPTH),
                 // DP
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * ATX_HDMI_DP_LEFTWALL_DEPTH), ATX_HDMI_DP_LEFTWALL_WIDTH, ATX_HDMI_DP_LEFTWALL_HEIGHT, ATX_HDMI_DP_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_HDMI_DP_BOTTOM_DEPTH) + ATX_HDMI_DP_LEFTWALL_DEPTH, ATX_HDMI_DP_BOTTOM_WIDTH, ATX_HDMI_DP_BOTTOM_HEIGHT, ATX_HDMI_DP_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y + WALL_DEPTH + ATX_HDMI_DP_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_HDMI_DP_RIGHTWALL_DEPTH), ATX_HDMI_DP_RIGHTWALL_WIDTH, ATX_HDMI_DP_RIGHTWALL_HEIGHT, ATX_HDMI_DP_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_HDMI_DP_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * ATX_HDMI_DP_BACKWALL_DEPTH), ATX_HDMI_DP_BACKWALL_WIDTH, ATX_HDMI_DP_BACKWALL_HEIGHT, ATX_HDMI_DP_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * (ATX_HDMI_DP_BACKWALL_DEPTH + ATX_HDMI_DP_TOP_DEPTH)), ATX_HDMI_DP_TOP_WIDTH, ATX_HDMI_DP_TOP_HEIGHT, ATX_HDMI_DP_TOP_DEPTH)},
                {}, {}),
        BIOS_FLBK({
                     // FLBK
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y, BASE_Z + ATX_BIOS_FLBK_LEFTWALL_DEPTH, ATX_BIOS_FLBK_LEFTWALL_WIDTH, ATX_BIOS_FLBK_LEFTWALL_HEIGHT, ATX_BIOS_FLBK_LEFTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_BIOS_FLBK_BOTTOM_DEPTH, ATX_BIOS_FLBK_BOTTOM_WIDTH, ATX_BIOS_FLBK_BOTTOM_HEIGHT, ATX_BIOS_FLBK_BOTTOM_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y + WALL_DEPTH + ATX_BIOS_FLBK_BOTTOM_HEIGHT, BASE_Z + ATX_BIOS_FLBK_RIGHTWALL_DEPTH, ATX_BIOS_FLBK_RIGHTWALL_WIDTH, ATX_BIOS_FLBK_RIGHTWALL_HEIGHT, ATX_BIOS_FLBK_RIGHTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_BIOS_FLBK_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y, BASE_Z + ATX_BIOS_FLBK_BACKWALL_DEPTH, ATX_BIOS_FLBK_BACKWALL_WIDTH, ATX_BIOS_FLBK_BACKWALL_HEIGHT, ATX_BIOS_FLBK_BACKWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_BIOS_FLBK_OFFSET_Y, BASE_Z + ATX_BIOS_FLBK_BACKWALL_DEPTH + ATX_BIOS_FLBK_TOP_DEPTH, ATX_BIOS_FLBK_TOP_WIDTH, ATX_BIOS_FLBK_TOP_HEIGHT, ATX_BIOS_FLBK_TOP_DEPTH)},
                    {}, {}),
        // peripheria
        U32G2_1_4({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + 20, ATX_U32G2_1_4_WIDTH, ATX_U32G2_1_4_HEIGHT, 20)}, {}, {}),
        // peripheria
        LAN2_U32G2_56({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + 20, ATX_LAN2_U32G2_56_WIDTH, ATX_LAN2_U32G2_56_HEIGHT, 20)}, {}, {}),
        // peripheria
        U3252_C8_LAN1_U32G2_7({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + 20, ATX_U3252_C8_LAN1_U32G2_7_WIDTH, ATX_U3252_C8_LAN1_U32G2_7_HEIGHT, 20)}, {}, {}),
        // peripheria
        M2_WIFI({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + 20, ATX_M2_WIFI_WIDTH, ATX_M2_WIFI_HEIGHT, 20)}, {}, {}),
        // peripheria
        AUDIO({ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_OFFSET_Y, BASE_Z + 20, ATX_AUDIO_WIDTH, ATX_AUDIO_HEIGHT, 20)}, {}, {}),
        // processor
        socketAM4({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_socketAM4_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_socketAM4_OFFSET_Y, BASE_Z + ATX_socketAM4_BASE_DEPTH, ATX_socketAM4_BASE_WIDTH, ATX_socketAM4_BASE_HEIGHT, ATX_socketAM4_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_socketAM4_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_socketAM4_OFFSET_Y, BASE_Z + ATX_socketAM4_FRAME_DEPTH + ATX_socketAM4_BASE_DEPTH, ATX_socketAM4_FRAME_WIDTH, ATX_socketAM4_FRAME_HEIGHT, ATX_socketAM4_FRAME_DEPTH, ATX_socketAM4_TOPFRAME_WIDTH, ATX_socketAM4_BOTTOMFRAME_WIDTH, ATX_socketAM4_LEFTFRAME_WIDTH, ATX_socketAM4_RIGHTFRAME_WIDTH)}, {}), // TODO
        // RAM
        DDR4_DIMM_B1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B1_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        DDR4_DIMM_B2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_B2_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        DDR4_DIMM_A1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A1_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        DDR4_DIMM_A2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_DDR4_DIMM_A2_OFFSET_Y, BASE_Z + 40, ATX_DDR4_DIMM_WIDTH, ATX_DDR4_DIMM_HEIGHT, 40, ATX_DDR4_DIMM_TOPFRAMEWIDTH, ATX_DDR4_DIMM_BOTTOMFRAMEWIDTH, ATX_DDR4_DIMM_LEFTFRAMEWIDTH, ATX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        // GPU
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}, {}),
        PCIEX16_2({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_2_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}, {}),
        PCIEX16_3({}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_PCIEX16_3_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y, BASE_Z + 40, ATX_PCIEX16_WIDTH, ATX_PCIEX16_HEIGHT, 40, ATX_PCIEX16_TOPFRAMEWIDTH, ATX_PCIEX16_BOTTOMFRAMEWIDTH, ATX_PCIEX16_LEFTFRAMEWIDTH, ATX_PCIEX16_RIGHTFRAMEWIDTH)}, {}),
        // CAPACITORS
        C22110_1({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C22110_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C22110_1_OFFSET_Y, BASE_Z, ATX_C22110_1_RADIUS, ATX_C22110_1_HEIGHT, ATX_C22110_1_SEGMENTS)}),
        C2280_1({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2280_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2280_1_OFFSET_Y, BASE_Z, ATX_C2280_1_RADIUS, ATX_C2280_1_HEIGHT, ATX_C2280_1_SEGMENTS)}),
        C2260_1({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2260_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2260_1_OFFSET_Y, BASE_Z, ATX_C2260_1_RADIUS, ATX_C2260_1_HEIGHT, ATX_C2260_1_SEGMENTS)}),
        C2242_1({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2242_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2242_1_OFFSET_Y, BASE_Z, ATX_C2242_1_RADIUS, ATX_C2242_1_HEIGHT, ATX_C2242_1_SEGMENTS)}),
        C22110_2({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C22110_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C22110_2_OFFSET_Y, BASE_Z, ATX_C22110_2_RADIUS, ATX_C22110_2_HEIGHT, ATX_C22110_2_SEGMENTS)}),
        C2280_2({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2280_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2280_2_OFFSET_Y, BASE_Z, ATX_C2280_2_RADIUS, ATX_C2280_2_HEIGHT, ATX_C2280_2_SEGMENTS)}),
        C2260_2({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2260_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2260_2_OFFSET_Y, BASE_Z, ATX_C2260_2_RADIUS, ATX_C2260_2_HEIGHT, ATX_C2260_2_SEGMENTS)}),
        C2242_2({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_C2242_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_C2242_2_OFFSET_Y, BASE_Z, ATX_C2242_2_RADIUS, ATX_C2242_2_HEIGHT, ATX_C2242_2_SEGMENTS)}),
        // BATTERY
        BATTERY({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + ATX_BATTERY_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_BATTERY_OFFSET_Y, BASE_Z, ATX_BATTERY_RADIUS, ATX_BATTERY_HEIGHT, ATX_BATTERY_SEGMENTS)}),
        // AMD X570
        AMDX570({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AMDX570_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_AMDX570_OFFSET_Y, BASE_Z + ATX_AMDX570_DEPTH, ATX_AMDX570_WIDTH, ATX_AMDX570_HEIGHT, ATX_AMDX570_DEPTH)}, {}, {}),

        SATA6G_1({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                    ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                    ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                    ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                    ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                   {}, {}),
        SATA6G_2({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_3({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_4({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_3_4_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_5({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_6({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_5_6_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_7({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
        SATA6G_8({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y + ATX_SATA6G_RIGHTWALL_HEIGHT, BASE_Z + ATX_SATA6G_BOTTOM_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BOTTOM_WIDTH, ATX_SATA6G_BOTTOM_HEIGHT - ATX_SATA6G_RIGHTWALL_HEIGHT - ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_BACKWALL_WIDTH, ATX_SATA6G_BACKWALL_HEIGHT, ATX_SATA6G_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_RIGHTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_RIGHTWALL_WIDTH, ATX_SATA6G_RIGHTWALL_HEIGHT, ATX_SATA6G_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X + ATX_SATA6G_BACKWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y - ATX_SATA6G_RIGHTWALL_HEIGHT + ATX_SATA6G_BOTTOM_HEIGHT, BASE_Z + ATX_SATA6G_LEFTWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_LEFTWALL_WIDTH, ATX_SATA6G_LEFTWALL_HEIGHT, ATX_SATA6G_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SATA6G_1_2_BASE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SATA6G_7_8_BASE_OFFSET_Y, BASE_Z + ATX_SATA6G_TOP_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BACKWALL_DEPTH + ATX_SATA6G_BOTTOM_DEPTH, ATX_SATA6G_TOP_WIDTH, ATX_SATA6G_TOP_HEIGHT, ATX_SATA6G_TOP_DEPTH)},
                 {}, {}),
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
        PCIEX16_1_ACC_offset(startOfPlate_.getXCoordinate() + 70, startOfPlate_.getYCoordinate() + ATX_PCIEX16_1_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH + 150),
        PCIEX16_2_ACC_offset(startOfPlate_.getXCoordinate() + 70, startOfPlate_.getYCoordinate() + ATX_PCIEX16_2_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH + 150),
        PCIEX16_3_ACC_offset(startOfPlate_.getXCoordinate() + 70, startOfPlate_.getYCoordinate() + ATX_PCIEX16_3_OFFSET_Y + ATX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH + 150),
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
    ComponentConfig socketAM4;
    // RAM
    ComponentConfig DDR4_DIMM_B1;
    ComponentConfig DDR4_DIMM_B2;
    ComponentConfig DDR4_DIMM_A1;
    ComponentConfig DDR4_DIMM_A2;
    // GPU
    ComponentConfig PCIEX16_1;
    ComponentConfig PCIEX16_2;
    ComponentConfig PCIEX16_3;

    // capacitors
    ComponentConfig C22110_1;
    ComponentConfig C2280_1;
    ComponentConfig C2260_1;
    ComponentConfig C2242_1;

    ComponentConfig C22110_2;
    ComponentConfig C2280_2;
    ComponentConfig C2260_2;
    ComponentConfig C2242_2;

    // battery
    ComponentConfig BATTERY;

    // microchip AMD
    ComponentConfig AMDX570;

    // // sata
    ComponentConfig SATA6G_1;
    ComponentConfig SATA6G_2;
    ComponentConfig SATA6G_3;
    ComponentConfig SATA6G_4;
    ComponentConfig SATA6G_5;
    ComponentConfig SATA6G_6;
    ComponentConfig SATA6G_7;
    ComponentConfig SATA6G_8;
    // // superio
    // ComponentConfig SuperIO; // new
    // // intel I2211AT
    // ComponentConfig IntelI22AT; // new
    // // microchip RTLRTL8125_CG
    // ComponentConfig RTL8125_CG; // new
    // // EATX ports
    // ComponentConfig EATX12V_1; // new
    // ComponentConfig EATX12V_2; // new
    // ComponentConfig EATXPWR; // new
    // // CPU_FAN / CPU_OPT / RGB_HEADER
    // ComponentConfig CPU_FAN; // new
    // ComponentConfig CPU_OPT; // new
    // ComponentConfig RGB_HEADER1; // new

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
