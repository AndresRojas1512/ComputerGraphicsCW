#ifndef CONFIG_HPP
#define CONFIG_HPP

#define ATX_WIDTH 244
#define ATX_HEIGHT 305

#define MICROATX_WIDTH 234
#define MICROATX_HEIGHT 244

#define MINIITX_WIDTH 170
#define MINIITX_HEIGHT 170

#define PI                      3.14159265
#define ROTATE_VAL              3.14159265358979323846 / 16
#define EPS 1e-3

// #define SIZE_SC                 50
#define SIZE_SC                 3
#define BRICK_TOP_HEIGHT        10
#define BRICK_TOP_SIZE_SC       0.3

// #define PLATE_HEIGHT            20
#define PLATE_HEIGHT            10
#define BASE_Z                  8000
#define BASE_START              10, 10, BASE_Z

// #define X_CENTER                500
#define X_CENTER                720
// #define Y_CENTER                390
#define Y_CENTER                470

#define SCALE_VAL               0.1

#define LIGHT_X                 1000
#define LIGHT_Y                 1000

#define MOVE_VAL                50

#define BLACK_COLOR            0, 0, 0

#define SHADOW_VAL              30

#define BASE_COLOR              220, 220, 220
#define BASE_COLOR_SHADOW       220 - SHADOW_VAL, 220 - SHADOW_VAL, 220 - SHADOW_VAL

#define BRICK_COLOR             255, 051, 051
#define BRICK_COLOR_SHADOW      255 - SHADOW_VAL, 051 - SHADOW_VAL, 051 - SHADOW_VAL

#define PLATE_COLOR             153, 255, 051
#define PLATE_COLOR_SHADOW      153 - SHADOW_VAL, 255 - SHADOW_VAL, 051 - SHADOW_VAL

#define TILE_COLOR              051, 255, 255
#define TILE_COLOR_SHADOW       051 - SHADOW_VAL, 255 - SHADOW_VAL, 255 - SHADOW_VAL

#define ARC_COLOR               255, 051, 255
#define ARC_COLOR_SHADOW        255 - SHADOW_VAL, 051 - SHADOW_VAL, 255 - SHADOW_VAL

#define CYLINDER_COLOR          255, 255, 051
#define CYLINDER_COLOR_SHADOW   255 - SHADOW_VAL, 255 - SHADOW_VAL, 051 - SHADOW_VAL

// ATX components colors
#define ATX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define ATX_MOTHERBOARD_COLOR_SHADOW 30, 128 - SHADOW_VAL, 30

#define ATX_HDMI_DP_COLOR 128, 128, 128 // gray

#define ATX_BIOS_FLBK_COLOR 128, 128, 128 // gray

#define ATX_U32G2_1_4_COLOR 128, 128, 128 // gray

#define ATX_LAN2_U32G2_56_COLOR 128, 128, 128 // gray

#define ATX_U3252_C8_LAN1_U32G2_7_COLOR 128, 128, 128 // gray

#define ATX_M2_WIFI_COLOR 128, 128, 128 // gray

#define ATX_AUDIO_COLOR 128, 128, 128 // gray

#define ATX_SOCKET_M4_COLOR 0, 0, 0 // black

#define ATX_DDR4_DIMM_B1_COLOR 0, 0, 255 // blue

#define ATX_DDR4_DIMM_B2_COLOR 255, 255, 50 // strong yellow

#define ATX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue

#define ATX_DDR4_DIMM_A2_COLOR 255, 255, 50 // strong yellow

#define ATX_PCIEX16_1_COLOR 255, 255, 224 // soft yellow

#define ATX_PCIEX16_2_COLOR 255, 255, 224 // soft yellow

#define ATX_PCIEX16_3_COLOR 255, 255, 224 // soft yellow

// Micro-ATX colors
#define MICROATX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define MICROATX_HDMI1_DP_COLOR 128, 128, 128 // gray
#define MICROATX_HDMI2_COLOR 128, 128, 128 // gray
#define MICROATX_KBMS_USB_E32_COLOR 128, 128, 128 // gray
#define MICROATX_U32G2_C2_COLOR 128, 128, 128 // gray
#define MICROATX_LAN_USB_E12_COLOR 128, 128, 128 // gray
#define MICROATX_AUDIO_COLOR 128, 128, 128 // gray
#define MICROATX_LGA1200_COLOR 0, 0, 0 // black
#define MICROATX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue
#define MICROATX_DDR4_DIMM_A2_COLOR 255, 255, 50 // strong yellow
#define MICROATX_DDR4_DIMM_B1_COLOR 0, 0, 255 // blue
#define MICROATX_DDR4_DIMM_B2_COLOR 255, 255, 50 // strong yellow
#define MICROATX_PCIEX16_1_COLOR 255, 255, 224 // soft yellow
#define MICROATX_PCIEX16_2_COLOR 255, 255, 224 // soft yellow

// Mini-ITX colors
#define MINIITX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define MINIITX_USB3_5_COLOR 128, 128, 128 // gray
#define MINIITX_USB7_10_COLOR 128, 128, 128 // gray
#define MINIITX_HDMI_DP_COLOR 128, 128, 128 // gray
#define MINIITX_LAN_USB_34_COLOR 128, 128, 128 // gray
#define MINIITX_M2_WIFI_COLOR 128, 128, 128 // gray
#define MINIITX_AUDIO_COLOR 128, 128, 128 // gray
#define MINIITX_SOCKET_M4_COLOR 0, 0, 0 // black
#define MINIITX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue
#define MINIITX_DDR4_DIMM_B1_COLOR 255, 255, 50 // strong yellow
#define MINIITX_PCIEX16_1_COLOR 255, 255, 224 // soft yellow

#endif
