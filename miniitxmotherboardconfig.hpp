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

    enum class GPUSlot
    {
        A1
    };

    MiniITXMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : BaseMotherboardConfig(startOfPlate_, endOfPlate_),
        // peripheria
        USB3_5({
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                 // U32G2_2
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB3_5_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
               {}, {}),
        USB7_10({
                 // U32G2_1
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                 // U32G2_2
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                 // U32G2_3
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_1_4_DEPTH) + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (3 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                 // U32G2_3
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (3 * ATX_U32G2_1_4_DEPTH) + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (4 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_USB7_10_OFFSET_Y, BASE_Z + (4 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
                {}, {}),

        HDMI_DP({
                  // HDMI
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_LEFTWALL_DEPTH, ATX_HDMI_DP_LEFTWALL_WIDTH, ATX_HDMI_DP_LEFTWALL_HEIGHT, ATX_HDMI_DP_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_HDMI_DP_BOTTOM_DEPTH, ATX_HDMI_DP_BOTTOM_WIDTH, ATX_HDMI_DP_BOTTOM_HEIGHT, ATX_HDMI_DP_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y + WALL_DEPTH + ATX_HDMI_DP_BOTTOM_HEIGHT, BASE_Z + ATX_HDMI_DP_RIGHTWALL_DEPTH, ATX_HDMI_DP_RIGHTWALL_WIDTH, ATX_HDMI_DP_RIGHTWALL_HEIGHT, ATX_HDMI_DP_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_HDMI_DP_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_BACKWALL_DEPTH, ATX_HDMI_DP_BACKWALL_WIDTH, ATX_HDMI_DP_BACKWALL_HEIGHT, ATX_HDMI_DP_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + ATX_HDMI_DP_BACKWALL_DEPTH + ATX_HDMI_DP_TOP_DEPTH, ATX_HDMI_DP_TOP_WIDTH, ATX_HDMI_DP_TOP_HEIGHT, ATX_HDMI_DP_TOP_DEPTH),
                  // DP
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * ATX_HDMI_DP_LEFTWALL_DEPTH), ATX_HDMI_DP_LEFTWALL_WIDTH, ATX_HDMI_DP_LEFTWALL_HEIGHT, ATX_HDMI_DP_LEFTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_HDMI_DP_BOTTOM_DEPTH) + ATX_HDMI_DP_LEFTWALL_DEPTH, ATX_HDMI_DP_BOTTOM_WIDTH, ATX_HDMI_DP_BOTTOM_HEIGHT, ATX_HDMI_DP_BOTTOM_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y + WALL_DEPTH + ATX_HDMI_DP_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_HDMI_DP_RIGHTWALL_DEPTH), ATX_HDMI_DP_RIGHTWALL_WIDTH, ATX_HDMI_DP_RIGHTWALL_HEIGHT, ATX_HDMI_DP_RIGHTWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_HDMI_DP_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * ATX_HDMI_DP_BACKWALL_DEPTH), ATX_HDMI_DP_BACKWALL_WIDTH, ATX_HDMI_DP_BACKWALL_HEIGHT, ATX_HDMI_DP_BACKWALL_DEPTH),
                  ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_HDMI_DP_OFFSET_Y, BASE_Z + (2 * (ATX_HDMI_DP_BACKWALL_DEPTH + ATX_HDMI_DP_TOP_DEPTH)), ATX_HDMI_DP_TOP_WIDTH, ATX_HDMI_DP_TOP_HEIGHT, ATX_HDMI_DP_TOP_DEPTH)},
                 {}, {}),
        LAN_USB3_34({
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + ATX_U32G2_BOTTOM_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + ATX_U32G2_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + ATX_U32G2_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                       // U32G2_2
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_U32G2_LEFTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + ATX_U32G2_LEFTWALL_DEPTH, ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH), ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_U32G2_RIGHTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH), ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_U32G2_BACKWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH),
                       // LAN
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_LEFTWALL_DEPTH) + ATX_LAN_LEFTWALL_DEPTH, ATX_U32G2_LEFTWALL_WIDTH, ATX_U32G2_LEFTWALL_HEIGHT, ATX_LAN_LEFTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT, BASE_Z + (2 * ATX_U32G2_BOTTOM_DEPTH) + (2 * ATX_U32G2_LEFTWALL_DEPTH), ATX_U32G2_BOTTOM_WIDTH, ATX_U32G2_BOTTOM_HEIGHT, ATX_U32G2_BOTTOM_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y + ATX_U32G2_LEFTWALL_HEIGHT + ATX_U32G2_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_U32G2_RIGHTWALL_DEPTH) + ATX_LAN_RIGHTWALL_DEPTH, ATX_U32G2_RIGHTWALL_WIDTH, ATX_U32G2_RIGHTWALL_HEIGHT, ATX_LAN_RIGHTWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_U32G2_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH, ATX_U32G2_BACKWALL_WIDTH, ATX_U32G2_BACKWALL_HEIGHT, ATX_LAN_BACKWALL_DEPTH),
                     ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_LAN_USB3_34_OFFSET_Y, BASE_Z + (2 * ATX_U32G2_BACKWALL_DEPTH) + ATX_LAN_BACKWALL_DEPTH + ATX_U32G2_TOP_DEPTH, ATX_U32G2_TOP_WIDTH, ATX_U32G2_TOP_HEIGHT, ATX_U32G2_TOP_DEPTH)},
                      {}, {}),

        M2_WIFI({
                 // port 1
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_LEFTWALL_DEPTH, ATX_M2_WIFI_LEFTWALL_WIDTH, ATX_M2_WIFI_LEFTWALL_HEIGHT, ATX_M2_WIFI_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_M2_WIFI_BOTTOM_DEPTH, ATX_M2_WIFI_BOTTOM_WIDTH, ATX_M2_WIFI_BOTTOM_HEIGHT, ATX_M2_WIFI_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y + WALL_DEPTH + ATX_M2_WIFI_BOTTOM_HEIGHT, BASE_Z + ATX_M2_WIFI_RIGHTWALL_DEPTH, ATX_M2_WIFI_RIGHTWALL_WIDTH, ATX_M2_WIFI_RIGHTWALL_HEIGHT, ATX_M2_WIFI_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_M2_WIFI_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_BACKWALL_DEPTH, ATX_M2_WIFI_BACKWALL_WIDTH, ATX_M2_WIFI_BACKWALL_HEIGHT, ATX_M2_WIFI_BACKWALL_DEPTH),
                 // separator
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + ATX_M2_WIFI_BACKWALL_DEPTH + ATX_M2_WIFI_SEP_DEPTH, ATX_M2_WIFI_SEP_WIDTH, ATX_M2_WIFI_SEP_HEIGHT, ATX_M2_WIFI_SEP_DEPTH),
                 // port 2
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_LEFTWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_LEFTWALL_WIDTH, ATX_M2_WIFI_LEFTWALL_HEIGHT, ATX_M2_WIFI_LEFTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_M2_WIFI_LEFTWALL_DEPTH + ATX_M2_WIFI_SEP_DEPTH + ATX_M2_WIFI_BOTTOM_DEPTH, ATX_M2_WIFI_BOTTOM_WIDTH, ATX_M2_WIFI_BOTTOM_HEIGHT, ATX_M2_WIFI_BOTTOM_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y + WALL_DEPTH + ATX_M2_WIFI_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_M2_WIFI_RIGHTWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_RIGHTWALL_WIDTH, ATX_M2_WIFI_RIGHTWALL_HEIGHT, ATX_M2_WIFI_RIGHTWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_M2_WIFI_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_BACKWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH - WALL_DEPTH, ATX_M2_WIFI_BACKWALL_WIDTH, ATX_M2_WIFI_BACKWALL_HEIGHT, ATX_M2_WIFI_BACKWALL_DEPTH),
                 ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_M2_WIFI_OFFSET_Y, BASE_Z + (2 * ATX_M2_WIFI_BACKWALL_DEPTH) + ATX_M2_WIFI_SEP_DEPTH, ATX_M2_WIFI_TOP_WIDTH, ATX_M2_WIFI_TOP_HEIGHT, ATX_M2_WIFI_TOP_DEPTH)},
                {}, {}),
        AUDIO({
               // AUDIO_1
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH, ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_1_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_BOTTOM_DEPTH, ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_1_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + ATX_AUDIO_RIGHTWALL_DEPTH, ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH, ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_1_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO_2
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH, ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_2_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_BOTTOM_DEPTH, ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_2_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + ATX_AUDIO_RIGHTWALL_DEPTH, ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH, ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_2_OFFSET_Y, BASE_Z + ATX_AUDIO_BACKWALL_DEPTH + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 3
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_3_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_3_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_3_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 4
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_4_OFFSET_Y + WALL_DEPTH, BASE_Z + ATX_AUDIO_LEFTWALL_DEPTH + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_4_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (2 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_4_OFFSET_Y, BASE_Z + (2 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 5
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_5_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH) + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_5_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_5_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH),
               // AUDIO 6
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_LEFTWALL_DEPTH), ATX_AUDIO_LEFTWALL_WIDTH, ATX_AUDIO_LEFTWALL_HEIGHT, ATX_AUDIO_LEFTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_6_OFFSET_Y + WALL_DEPTH, BASE_Z + (2 * ATX_AUDIO_LEFTWALL_DEPTH) + (2 * ATX_AUDIO_BOTTOM_DEPTH), ATX_AUDIO_BOTTOM_WIDTH, ATX_AUDIO_BOTTOM_HEIGHT, ATX_AUDIO_BOTTOM_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_6_OFFSET_Y + WALL_DEPTH + ATX_AUDIO_BOTTOM_HEIGHT, BASE_Z + (3 * ATX_AUDIO_RIGHTWALL_DEPTH), ATX_AUDIO_RIGHTWALL_WIDTH, ATX_AUDIO_RIGHTWALL_HEIGHT, ATX_AUDIO_RIGHTWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate() + ATX_AUDIO_LEFTWALL_WIDTH, startOfPlate_.getYCoordinate() + MINIITX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH), ATX_AUDIO_BACKWALL_WIDTH, ATX_AUDIO_BACKWALL_HEIGHT, ATX_AUDIO_BACKWALL_DEPTH),
               ParallelepipedConfig(startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + MINIITX_AUDIO_6_OFFSET_Y, BASE_Z + (3 * ATX_AUDIO_BACKWALL_DEPTH) + ATX_AUDIO_TOP_DEPTH, ATX_AUDIO_TOP_WIDTH, ATX_AUDIO_TOP_HEIGHT, ATX_AUDIO_TOP_DEPTH)},
              {}, {}),
        // RAM
        DDR4_DIMM_A1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_Y, BASE_Z + 40, MINIITX_DDR4_DIMM_WIDTH, MINIITX_DDR4_DIMM_HEIGHT, 40, MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, MINIITX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, MINIITX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        DDR4_DIMM_B1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_Y, BASE_Z + 40, MINIITX_DDR4_DIMM_WIDTH, MINIITX_DDR4_DIMM_HEIGHT, 40, MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, MINIITX_DDR4_DIMM_BOTTOMFRAMEWIDTH, MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, MINIITX_DDR4_DIMM_RIGHTFRAMEWIDTH)}, {}),
        // GPU
        PCIEX16_1({}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_PCIEX16_1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_PCIEX16_1_OFFSET_Y, BASE_Z + 40, MINIITX_PCIEX16_WIDTH, MINIITX_PCIEX16_HEIGHT, 40, MINIITX_PCIEX16_TOPFRAMEWIDTH, MINIITX_PCIEX16_BOTTOMFRAMEWIDTH, MINIITX_PCIEX16_LEFTFRAMEWIDTH, MINIITX_PCIEX16_RIGHTFRAMEWIDTH)}, {}),
        // capacitors
        C2280({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + MINIITX_C2280_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_C2280_OFFSET_Y, BASE_Z + MINIITX_C2280_HEIGHT, MINIITX_C2280_RADIUS, MINIITX_C2280_HEIGHT, MINIITX_C2280_SEGMENTS)}),
        C2260({}, {}, {CylinderConfig(startOfPlate_.getXCoordinate() + MINIITX_C2260_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_C2260_OFFSET_Y, BASE_Z + MINIITX_C2260_HEIGHT, MINIITX_C2260_RADIUS, MINIITX_C2260_HEIGHT, MINIITX_C2260_SEGMENTS)}),
        // sata
        SATA6G_1({ParallelepipedConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_1_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH, MINIITX_SATA6G_BASE_WIDTH, MINIITX_SATA6G_BASE_HEIGHT, MINIITX_SATA6G_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_1_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_1_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH + MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_FRAME_WIDTH, MINIITX_SATA6G_FRAME_HEIGHT, MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_TOPFRAME_WIDTH, MINIITX_SATA6G_BOTTOMFRAME_WIDTH, MINIITX_SATA6G_LEFTFRAME_WIDTH, MINIITX_SATA6G_RIGHTFRAME_WIDTH)}, {}),
        SATA6G_2({ParallelepipedConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_2_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_2_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH, MINIITX_SATA6G_BASE_WIDTH, MINIITX_SATA6G_BASE_HEIGHT, MINIITX_SATA6G_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_2_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_2_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH + MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_FRAME_WIDTH, MINIITX_SATA6G_FRAME_HEIGHT, MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_TOPFRAME_WIDTH, MINIITX_SATA6G_BOTTOMFRAME_WIDTH, MINIITX_SATA6G_LEFTFRAME_WIDTH, MINIITX_SATA6G_RIGHTFRAME_WIDTH)}, {}),
        SATA6G_3({ParallelepipedConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_3_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_3_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH, MINIITX_SATA6G_BASE_WIDTH, MINIITX_SATA6G_BASE_HEIGHT, MINIITX_SATA6G_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_3_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_3_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH + MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_FRAME_WIDTH, MINIITX_SATA6G_FRAME_HEIGHT, MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_TOPFRAME_WIDTH, MINIITX_SATA6G_BOTTOMFRAME_WIDTH, MINIITX_SATA6G_LEFTFRAME_WIDTH, MINIITX_SATA6G_RIGHTFRAME_WIDTH)}, {}),
        SATA6G_4({ParallelepipedConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_4_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_4_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH, MINIITX_SATA6G_BASE_WIDTH, MINIITX_SATA6G_BASE_HEIGHT, MINIITX_SATA6G_BASE_DEPTH)}, {FrameConfig(startOfPlate_.getXCoordinate() + MINIITX_SATA6G_4_OFFSET_X, startOfPlate_.getYCoordinate() + MINIITX_SATA6G_4_OFFSET_Y, BASE_Z + MINIITX_SATA6G_BASE_DEPTH + MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_FRAME_WIDTH, MINIITX_SATA6G_FRAME_HEIGHT, MINIITX_SATA6G_FRAME_DEPTH, MINIITX_SATA6G_TOPFRAME_WIDTH, MINIITX_SATA6G_BOTTOMFRAME_WIDTH, MINIITX_SATA6G_LEFTFRAME_WIDTH, MINIITX_SATA6G_RIGHTFRAME_WIDTH)}, {}),
        // RAM slots offset
        DDR4_DIMM_A1_offset(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_X + MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_Y + MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_B1_offset(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_X + MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_Y + MINIITX_DDR4_DIMM_TOPFRAMEWIDTH, BASE_Z + RAM_4GB_DEPTH),
        DDR4_DIMM_A1_ACC_offset(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_X + MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_A1_OFFSET_Y + MINIITX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        DDR4_DIMM_B1_ACC_offset(startOfPlate_.getXCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_X + MINIITX_DDR4_DIMM_LEFTFRAMEWIDTH - 2, startOfPlate_.getYCoordinate() + MINIITX_DDR4_DIMM_B1_OFFSET_Y + MINIITX_DDR4_DIMM_TOPFRAMEWIDTH + 25, BASE_Z + RAM_4GB_DEPTH - 5),
        // GPU slots offset
        PCIEX16_1_offset(startOfPlate_.getXCoordinate() + MINIITX_PCIEX16_1_OFFSET_X + MINIITX_PCIEX16_LEFTFRAMEWIDTH, startOfPlate_.getYCoordinate() + MINIITX_PCIEX16_1_OFFSET_Y + MINIITX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH),
        PCIEX16_1_ACC_offset(startOfPlate_.getXCoordinate() + 70, startOfPlate_.getYCoordinate() + MINIITX_PCIEX16_1_OFFSET_Y + MINIITX_PCIEX16_TOPFRAMEWIDTH, BASE_Z + GPU_4GB_DEPTH + 150),
        // CPU slot offset
        CPU_offset(1, 2, 3)
    {
        std::cout << "MiniITXMotherboardConfig::MiniITXMotherboardConfig" << std::endl;
        ramSlotsOccupied = {{static_cast<int>(RAMSlot::A1), false}, {static_cast<int>(RAMSlot::B1), false}};
        gpuSlotsOccupied = {{static_cast<int>(GPUSlot::A1), false}};
    }

    Dot3D getRamSlotPosition(int slot) const override;
    Dot3D getRamAccSlotPosition(int slot) const override;

    Dot3D getGpuSlotPosition(int slot) const override;
    Dot3D getGPuAccSlotPosition(int slot) const override;

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
    // capacitors
    ComponentConfig C2280;
    ComponentConfig C2260;
    // sata
    ComponentConfig SATA6G_1;
    ComponentConfig SATA6G_2;
    ComponentConfig SATA6G_3;
    ComponentConfig SATA6G_4;
    // offset for placing the RAM block in the DDR4 socket
    Dot3D DDR4_DIMM_A1_offset;
    Dot3D DDR4_DIMM_B1_offset;
    Dot3D DDR4_DIMM_A1_ACC_offset;
    Dot3D DDR4_DIMM_B1_ACC_offset;
    // offset for placing the GPU block in the PCIEX16 socket
    Dot3D PCIEX16_1_offset;
    Dot3D PCIEX16_1_ACC_offset;
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
