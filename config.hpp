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


/*
 * ======================= ATX CONFIG =======================
*/

// PERIPHERIA SOCKETS
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

// CPU SOCKET
#define ATX_socketM4_OFFSET_X
#define ATX_socketM4_OFFSET_Y

// RAM SOCKETS
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

// GPU SOCKETS
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


/*
 * ======================= MICRO-ATX CONFIG =======================
*/





/*
 * ======================= MINI-ITX CONFIG =======================
*/





/*
 * ======================= RAM 4G DIMENSIONS =======================
*/
#define RAM_4GB_DEPTH 30 * SIZE_SC
#define RAM_4GB_WIDTH 6
#define RAM_4GB_HEIGHT 410

/*
 * ======================= RAM 8G DIMENSIONS =======================
*/
#define RAM_8GB_DEPTH 30 * SIZE_SC
#define RAM_8GB_WIDTH 6
#define RAM_8GB_HEIGHT 410

/*
 * ======================= RAM 16G DIMENSIONS =======================
*/
#define RAM_16GB_DEPTH 30 * SIZE_SC
#define RAM_16GB_WIDTH 6
#define RAM_16GB_HEIGHT 410

/*
 * ======================= RAM 32G DIMENSIONS =======================
*/
#define RAM_32GB_DEPTH 30 * SIZE_SC
#define RAM_32GB_WIDTH 6
#define RAM_32GB_HEIGHT 410

/*
 * ======================= ATX COLORS =======================
*/

// Peripheria
#define ATX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define ATX_MOTHERBOARD_COLOR_SHADOW 0, 100, 0 // dark green

#define ATX_HDMI_DP_COLOR 192, 192, 192 // silver
#define ATX_HDMI_DP_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_BIOS_FLBK_COLOR 192, 192, 192 // silver
#define ATX_BIOS_FLBK_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_U32G2_1_4_COLOR 192, 192, 192 // silver
#define ATX_U32G2_1_4_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_LAN2_U32G2_56_COLOR 192, 192, 192 // silver
#define ATX_LAN2_U32G2_56_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_U3252_C8_LAN1_U32G2_7_COLOR 192, 192, 192 // silver
#define ATX_U3252_C8_LAN1_U32G2_7_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_M2_WIFI_COLOR 192, 192, 192 // silver
#define ATX_M2_WIFI_COLOR_SHADOW 128, 128, 128 // gray

#define ATX_AUDIO_COLOR 192, 192, 192 // silver
#define ATX_AUDIO_COLOR_SHADOW 128, 128, 128 // gray

// Processor socket
#define ATX_SOCKET_M4_COLOR 128, 128, 128 // gray
#define ATX_SOCKET_M4_COLOR_SHADOW 105, 105, 105 // dimgray

// RAM
#define ATX_DDR4_DIMM_B1_COLOR 0, 0, 255 // blue
#define ATX_DDR4_DIMM_B1_COLOR_SHADOW 0, 0, 139 // dark blue

#define ATX_DDR4_DIMM_B2_COLOR 255, 255, 0 // yellow
#define ATX_DDR4_DIMM_B2_COLOR_SHADOW 128, 128, 0 // olive

#define ATX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue
#define ATX_DDR4_DIMM_A1_COLOR_SHADOW 0, 0, 139 // dark blue

#define ATX_DDR4_DIMM_A2_COLOR 255, 255, 0 // yellow
#define ATX_DDR4_DIMM_A2_COLOR_SHADOW 128, 128, 0 // olive

#define ATX_PCIEX16_1_COLOR 240, 230, 140 // khaki
#define ATX_PCIEX16_1_COLOR_SHADOW 189, 183, 107 // dark khaki

#define ATX_PCIEX16_2_COLOR 240, 230, 140 // khaki
#define ATX_PCIEX16_2_COLOR_SHADOW 189, 183, 107 // dark khaki

#define ATX_PCIEX16_3_COLOR 240, 230, 140 // khaki
#define ATX_PCIEX16_3_COLOR_SHADOW 189, 183, 107 // dark khaki

/*
 * ======================= MICRO-ATX COLORS =======================
*/

// Peripheria
#define MICROATX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define MICROATX_MOTHERBOARD_COLOR_SHADOW 0, 100, 0 // dark green

#define MICROATX_HDMI1_DP_COLOR 192, 192, 192 // silver
#define MICROATX_HDMI1_DP_COLOR_SHADOW 128, 128, 128 // gray

#define MICROATX_HDMI2_COLOR 192, 192, 192 // silver
#define MICROATX_HDMI2_COLOR_SHADOW 128, 128, 128 // gray

#define MICROATX_KBMS_USB_E32_COLOR 192, 192, 192 // silver
#define MICROATX_KBMS_USB_E32_COLOR_SHADOW 128, 128, 128 // gray

#define MICROATX_U32G2_C2_COLOR 192, 192, 192 // silver
#define MICROATX_U32G2_C2_COLOR_SHADOW 128, 128, 128 // gray

#define MICROATX_LAN_USB_E12_COLOR 192, 192, 192 // silver
#define MICROATX_LAN_USB_E12_COLOR_SHADOW 128, 128, 128 // gray

#define MICROATX_AUDIO_COLOR 192, 192, 192 // silver
#define MICROATX_AUDIO_COLOR_SHADOW 128, 128, 128 // gray

// Processor
#define MICROATX_LGA1200_COLOR 128, 128, 128 // gray
#define MICROATX_LGA1200_COLOR_SHADOW 105, 105, 105 // dimgray

// RAM
#define MICROATX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue
#define MICROATX_DDR4_DIMM_A1_COLOR_SHADOW 0, 0, 139 // dark blue

#define MICROATX_DDR4_DIMM_A2_COLOR 255, 255, 0 // yellow
#define MICROATX_DDR4_DIMM_A2_COLOR_SHADOW 128, 128, 0 // olive

#define MICROATX_DDR4_DIMM_B1_COLOR 0, 0, 255 // blue
#define MICROATX_DDR4_DIMM_B1_COLOR_SHADOW 0, 0, 139 // dark blue

#define MICROATX_DDR4_DIMM_B2_COLOR 255, 255, 0 // yellow
#define MICROATX_DDR4_DIMM_B2_COLOR_SHADOW 128, 128, 0 // olive

// GPU
#define MICROATX_PCIEX16_1_COLOR 240, 230, 140 // khaki
#define MICROATX_PCIEX16_1_COLOR_SHADOW 189, 183, 107 // dark khaki

#define MICROATX_PCIEX16_2_COLOR 240, 230, 140 // khaki
#define MICROATX_PCIEX16_2_COLOR_SHADOW 189, 183, 107 // dark khaki

/*
 * ======================= MINI-ITX COLORS =======================
*/

// Peripheria
#define MINIITX_MOTHERBOARD_COLOR 0, 128, 0 // green
#define MINIITX_MOTHERBOARD_COLOR_SHADOW 0, 100, 0 // dark green

#define MINIITX_USB3_5_COLOR 192, 192, 192 // silver
#define MINIITX_USB3_5_COLOR_SHADOW 128, 128, 128 // gray

#define MINIITX_USB7_10_COLOR 192, 192, 192 // silver
#define MINIITX_USB7_10_COLOR_SHADOW 128, 128, 128 // gray

#define MINIITX_HDMI_DP_COLOR 192, 192, 192 // silver
#define MINIITX_HDMI_DP_COLOR_SHADOW 128, 128, 128 // gray

#define MINIITX_LAN_USB3_34_COLOR 192, 192, 192 // silver
#define MINIITX_LAN_USB3_34_COLOR_SHADOW 128, 128, 128 // gray

#define MINIITX_M2_WIFI_COLOR 192, 192, 192 // silver
#define MINIITX_M2_WIFI_COLOR_SHADOW 128, 128, 128 // gray

#define MINIITX_AUDIO_COLOR 192, 192, 192 // silver
#define MINIITX_AUDIO_COLOR_SHADOW 128, 128, 128 // gray

// Processor
#define MINIITX_SOCKET_M4_COLOR 128, 128, 128 // gray
#define MINIITX_SOCKET_M4_COLOR_SHADOW 105, 105, 105 // dimgray

// RAM
#define MINIITX_DDR4_DIMM_A1_COLOR 0, 0, 255 // blue
#define MINIITX_DDR4_DIMM_A1_COLOR_SHADOW 0, 0, 139 // dark blue

#define MINIITX_DDR4_DIMM_B1_COLOR 255, 255, 0 // yellow
#define MINIITX_DDR4_DIMM_B1_COLOR_SHADOW 128, 128, 0 // olive

// GPU
#define MINIITX_PCIEX16_1_COLOR 230, 230, 140 // khaki
#define MINIITX_PCIEX16_1_COLOR_SHADOW 189, 183, 107 // dark khaki

#endif
