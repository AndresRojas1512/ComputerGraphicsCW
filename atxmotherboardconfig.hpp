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
        U32G2_1_4({
                   // U32G2_1
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                   // U32G2_2
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                   // U32G2_3
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_1_4_DEPTH) + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                   // U32G2_3
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (3 * ATX_U32G2_1_4_DEPTH) + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (4 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                   ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U32G2_1_4_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
                  {}, {}),
        // peripheria
        LAN2_U32G2_56({
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                          // U32G2_2
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                               // LAN
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH) + ATX_LAN_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_LAN_LEFTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH) + ATX_LAN_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_LAN_RIGHTWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_LAN_BACKWALL_DEPTH),
                       ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_LAN2_U32G2_56_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
                              {}, {}),
        U3252_C8_LAN1_U32G2_7({
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                               // U32G2_2
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                               // LAN
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH) + ATX_LAN_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_LAN_LEFTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH) + ATX_LAN_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_LAN_RIGHTWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_LAN_BACKWALL_DEPTH),
                               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_U3252_C8_LAN1_U32G2_7_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
                              {}, {}),
        M2_WIFI({
                 // port 1
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_LEFTWALL_DEPTH, ATX_M2_WIFI_LEFTWALL_WIDTH, ATX_M2_WIFI_LEFTWALL_HEIGHT, ATX_M2_WIFI_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_M2_WIFI_BOTTOM_DEPTH, ATX_M2_WIFI_BOTTOM_WIDTH, ATX_M2_WIFI_BOTTOM_HEIGHT, ATX_M2_WIFI_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y + WALL_DEPTH + ATX_M2_WIFI_BOTTOM_HEIGHT, BASE_Z + ATX_M2_WIFI_RIGHTWALL_DEPTH, ATX_M2_WIFI_RIGHTWALL_WIDTH, ATX_M2_WIFI_RIGHTWALL_HEIGHT, ATX_M2_WIFI_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_M2_WIFI_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_BACKWALL_DEPTH, ATX_M2_WIFI_BACKWALL_WIDTH, ATX_M2_WIFI_BACKWALL_HEIGHT, ATX_M2_WIFI_BACKWALL_DEPTH),
                 // separator
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_BACKWALL_DEPTH + ATX_M2_WIFI_SEP_DEPTH, ATX_M2_WIFI_SEP_WIDTH, ATX_M2_WIFI_SEP_HEIGHT, ATX_M2_WIFI_SEP_DEPTH),
                 // port 2
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_LEFTWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_LEFTWALL_WIDTH, ATX_M2_WIFI_LEFTWALL_HEIGHT, ATX_M2_WIFI_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_M2_WIFI_LEFTWALL_DEPTH + ATX_M2_WIFI_SEP_DEPTH + ATX_M2_WIFI_BOTTOM_DEPTH, ATX_M2_WIFI_BOTTOM_WIDTH, ATX_M2_WIFI_BOTTOM_HEIGHT, ATX_M2_WIFI_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y + WALL_DEPTH + ATX_M2_WIFI_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_M2_WIFI_RIGHTWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_RIGHTWALL_WIDTH, ATX_M2_WIFI_RIGHTWALL_HEIGHT, ATX_M2_WIFI_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_M2_WIFI_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_BACKWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_BACKWALL_WIDTH, ATX_M2_WIFI_BACKWALL_HEIGHT, ATX_M2_WIFI_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_BACKWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH, ATX_M2_WIFI_TOP_WIDTH, ATX_M2_WIFI_TOP_HEIGHT, ATX_M2_WIFI_TOP_DEPTH)},
                {}, {}),
        AUDIO({
               // AUDIO_1
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH, ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_1_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_BOTTOM_DEPTH, ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_1_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + ATX_AUDIO_RIGHTWALL_DEPTH, ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH, ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO_2
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH, ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_2_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_BOTTOM_DEPTH, ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_2_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + ATX_AUDIO_RIGHTWALL_DEPTH, ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH, ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 3
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_3_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_3_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 4
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_4_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_4_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 5
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_5_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH) + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_5_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 6
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_6_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH) + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_6_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + ATX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + ATX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH)},
              {}, {}),
        // processor
        socketAM4({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_socketAM4_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_socketAM4_OFFSET_Y, BASE_Z + ATX_socketAM4_BASE_DEPTH, ATX_socketAM4_BASE_WIDTH, ATX_socketAM4_BASE_HEIGHT, ATX_socketAM4_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_socketAM4_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_socketAM4_OFFSET_Y, BASE_Z + ATX_socketAM4_FRAME_DEPTH + ATX_socketAM4_BASE_DEPTH, ATX_socketAM4_FRAME_WIDTH, ATX_socketAM4_FRAME_HEIGHT, ATX_socketAM4_FRAME_DEPTH, ATX_socketAM4_TOPFRAME_WIDTH, ATX_socketAM4_BOTTOMFRAME_WIDTH, ATX_socketAM4_LEFTFRAME_WIDTH, ATX_socketAM4_RIGHTFRAME_WIDTH)}, {}),
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
        SuperIO({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SuperIO_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SuperIO_OFFSET_Y, BASE_Z + ATX_SuperIO_DEPTH, ATX_SuperIO_WIDTH, ATX_SuperIO_HEIGHT, ATX_SuperIO_DEPTH)}, {}, {}),
        IntelI22AT({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_IntelI22AT_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_IntelI22AT_OFFSET_Y, BASE_Z + ATX_IntelI22AT_DEPTH, ATX_IntelI22AT_WIDTH, ATX_IntelI22AT_HEIGHT, ATX_IntelI22AT_DEPTH)}, {}, {}),
        EATX12V_1({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_EATX12V_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATX12V_1_OFFSET_Y, BASE_Z + ATX_EATX12V_1_DEPTH, ATX_EATX12V_1_WIDTH, ATX_EATX12V_1_HEIGHT, ATX_EATX12V_1_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_EATX12V_1_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATX12V_1_OFFSET_Y, BASE_Z + ATX_EATX12V_1_FRAME_DEPTH, ATX_EATX12V_1_WIDTH, ATX_EATX12V_1_HEIGHT, ATX_EATX12V_1_FRAME_DEPTH, ATX_EATX12V_1_FRAME_WIDTH, ATX_EATX12V_1_FRAME_WIDTH, ATX_EATX12V_1_FRAME_WIDTH, ATX_EATX12V_1_FRAME_WIDTH)}, {}),
        EATX12V_2({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_EATX12V_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATX12V_2_OFFSET_Y, BASE_Z + ATX_EATX12V_2_DEPTH, ATX_EATX12V_2_WIDTH, ATX_EATX12V_2_HEIGHT, ATX_EATX12V_2_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_EATX12V_2_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATX12V_2_OFFSET_Y, BASE_Z + ATX_EATX12V_2_FRAME_DEPTH, ATX_EATX12V_2_WIDTH, ATX_EATX12V_2_HEIGHT, ATX_EATX12V_2_FRAME_DEPTH, ATX_EATX12V_2_FRAME_WIDTH, ATX_EATX12V_2_FRAME_WIDTH, ATX_EATX12V_2_FRAME_WIDTH, ATX_EATX12V_2_FRAME_WIDTH)}, {}),
        RTL8125_CG({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_RTL8125_CG_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_RTL8125_CG_OFFSET_Y, BASE_Z + ATX_RTL8125_CG_DEPTH, ATX_RTL8125_CG_WIDTH, ATX_RTL8125_CG_HEIGHT, ATX_RTL8125_CG_DEPTH)}, {}, {}),
        EATXPWR({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_EATXPWR_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATXPWR_OFFSET_Y, BASE_Z + ATX_EATXPWR_DEPTH, ATX_EATXPWR_WIDTH, ATX_EATXPWR_HEIGHT, ATX_EATXPWR_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_EATXPWR_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_EATXPWR_OFFSET_Y, BASE_Z + ATX_EATXPWR_FRAME_DEPTH, ATX_EATXPWR_WIDTH, ATX_EATXPWR_HEIGHT, ATX_EATXPWR_FRAME_DEPTH, ATX_EATXPWR_FRAME_WIDTH, ATX_EATXPWR_FRAME_WIDTH, ATX_EATXPWR_FRAME_WIDTH, ATX_EATXPWR_FRAME_WIDTH)}, {}),
        NODE({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_NODE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_NODE_OFFSET_Y, BASE_Z + ATX_NODE_DEPTH, ATX_NODE_WIDTH, ATX_NODE_HEIGHT, ATX_NODE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_NODE_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_NODE_OFFSET_Y, BASE_Z + ATX_NODE_FRAME_DEPTH, ATX_NODE_WIDTH, ATX_NODE_HEIGHT, ATX_NODE_FRAME_DEPTH, ATX_NODE_FRAME_WIDTH, ATX_NODE_FRAME_WIDTH, ATX_NODE_FRAME_WIDTH, ATX_NODE_FRAME_WIDTH)}, {}),
        USB34({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_USB34_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_USB34_OFFSET_Y, BASE_Z + ATX_USB34_DEPTH, ATX_USB34_WIDTH, ATX_USB34_HEIGHT, ATX_USB34_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_USB34_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_USB34_OFFSET_Y, BASE_Z + ATX_USB34_FRAME_DEPTH, ATX_USB34_WIDTH, ATX_USB34_HEIGHT, ATX_USB34_FRAME_DEPTH, ATX_USB34_FRAME_WIDTH, ATX_USB34_FRAME_WIDTH, ATX_USB34_FRAME_WIDTH, ATX_USB34_FRAME_WIDTH)}, {}),
        USB12({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_USB12_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_USB12_OFFSET_Y, BASE_Z + ATX_USB12_DEPTH, ATX_USB12_WIDTH, ATX_USB12_HEIGHT, ATX_USB12_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_USB12_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_USB12_OFFSET_Y, BASE_Z + ATX_USB12_FRAME_DEPTH, ATX_USB12_WIDTH, ATX_USB12_HEIGHT, ATX_USB12_FRAME_DEPTH, ATX_USB12_FRAME_WIDTH, ATX_USB12_FRAME_WIDTH, ATX_USB12_FRAME_WIDTH, ATX_USB12_FRAME_WIDTH)}, {}),
        U32G1_1011({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G1_1011_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_U32G1_1011_OFFSET_Y, BASE_Z + ATX_U32G1_1011_DEPTH, ATX_U32G1_1011_WIDTH, ATX_U32G1_1011_HEIGHT, ATX_U32G1_1011_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_U32G1_1011_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_U32G1_1011_OFFSET_Y, BASE_Z + ATX_U32G1_1011_FRAME_DEPTH, ATX_U32G1_1011_WIDTH, ATX_U32G1_1011_HEIGHT, ATX_U32G1_1011_FRAME_DEPTH, ATX_U32G1_1011_FRAME_WIDTH, ATX_U32G1_1011_FRAME_WIDTH, ATX_U32G1_1011_FRAME_WIDTH, ATX_U32G1_1011_FRAME_WIDTH)}, {}),
        BIOS({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_BIOS_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_BIOS_OFFSET_Y, BASE_Z + ATX_BIOS_DEPTH, ATX_BIOS_WIDTH, ATX_BIOS_HEIGHT, ATX_BIOS_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_BIOS_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_BIOS_OFFSET_Y, BASE_Z + ATX_BIOS_FRAME_DEPTH, ATX_BIOS_WIDTH, ATX_BIOS_HEIGHT, ATX_BIOS_FRAME_DEPTH, ATX_BIOS_FRAME_WIDTH, ATX_BIOS_FRAME_WIDTH, ATX_BIOS_FRAME_WIDTH, ATX_BIOS_FRAME_WIDTH)}, {}),
        SPI_TPM({ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_SPI_TPM_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SPI_TPM_OFFSET_Y, BASE_Z + ATX_SPI_TPM_DEPTH, ATX_SPI_TPM_WIDTH, ATX_SPI_TPM_HEIGHT, ATX_SPI_TPM_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + ATX_SPI_TPM_OFFSET_X, startOfPlate_.getYCoordinate() + ATX_SPI_TPM_OFFSET_Y, BASE_Z + ATX_SPI_TPM_FRAME_DEPTH, ATX_SPI_TPM_WIDTH, ATX_SPI_TPM_HEIGHT, ATX_SPI_TPM_FRAME_DEPTH, ATX_SPI_TPM_FRAME_WIDTH, ATX_SPI_TPM_FRAME_WIDTH, ATX_SPI_TPM_FRAME_WIDTH, ATX_SPI_TPM_FRAME_WIDTH)}, {}),
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
    ComponentConfig SuperIO;
    // // intel I2211AT
    ComponentConfig IntelI22AT;
    // EATX ports
    ComponentConfig EATX12V_1;
    ComponentConfig EATX12V_2;
    // // microchip RTLRTL8125_CG
    ComponentConfig RTL8125_CG;
    ComponentConfig EATXPWR;

    ComponentConfig NODE;
    ComponentConfig USB34;
    ComponentConfig USB12;
    ComponentConfig U32G1_1011;
    ComponentConfig BIOS;
    ComponentConfig SPI_TPM;

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
