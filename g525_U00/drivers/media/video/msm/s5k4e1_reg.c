
/* Copyright (c) 2011, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#include "s5k4e1.h"

struct s5k4e1_i2c_reg_conf s5k4e1_mipi_settings[] = {
	{0x30BD, 0x00},/* SEL_CCP[0] */
	{0x3084, 0x15},/* SYNC Mode */
	{0x30BE, 0x1A},/* M_PCLKDIV_AUTO[4], M_DIV_PCLK[3:0] */
	{0x30C1, 0x01},/* pack video enable [0] */
	{0x30EE, 0x02},/* DPHY enable [ 1] */
	{0x3111, 0x86},/* Embedded data off [5] */
};

/* PLL Configuration */
struct s5k4e1_i2c_reg_conf s5k4e1_pll_preview_settings[] = {
	// PLL setting ...
	// input clock 24MHz
	// (3) MIPI 2-lane Serial(TST = 0000b or TST = 0010b), 15 fps
	{0x0305,0x06},//PLL P = 6
	{0x0306,0x00},//PLL M[8] = 0
	{0x0307,0x65},//PLL M = 101
	{0x30B5,0x01},//PLL S = 1 
	{0x30E2,0x02},//num lanes[1:0] = 2
	{0x30F1,0x70},//DPHY BANDCTRL 404MHz=40.4MHz
};

struct s5k4e1_i2c_reg_conf s5k4e1_pll_snap_settings[] = {
	{0x0305, 0x04},
	{0x0306, 0x00},
	{0x0307, 0x44},
	{0x30B5, 0x00},
	{0x30E2, 0x01},/* num lanes[1:0] = 2 */
	{0x30F1, 0xB0},
};

struct s5k4e1_i2c_reg_conf s5k4e1_prev_settings[] = {
	/* output size (1304 x 980) */
	{0x30A9, 0x02},/* Horizontal Binning On */
	{0x300E, 0xEB},/* Vertical Binning On */
	{0x0387, 0x03},/* y_odd_inc 03(10b AVG) */
	{0x0344, 0x00},/* x_addr_start 0 */
	{0x0345, 0x00},
	{0x0348, 0x0A},/* x_addr_end 2607 */
	{0x0349, 0x2F},
	{0x0346, 0x00},/* y_addr_start 0 */
	{0x0347, 0x00},
	{0x034A, 0x07},/* y_addr_end 1959 */
	{0x034B, 0xA7},
	{0x0380, 0x00},/* x_even_inc 1 */
	{0x0381, 0x01},
	{0x0382, 0x00},/* x_odd_inc 1 */
	{0x0383, 0x01},
	{0x0384, 0x00},/* y_even_inc 1 */
	{0x0385, 0x01},
	{0x0386, 0x00},/* y_odd_inc 3 */
	{0x0387, 0x03},
	{0x034C, 0x05},/* x_output_size 1304 */
	{0x034D, 0x18},
	{0x034E, 0x03},/* y_output_size 980 */
	{0x034F, 0xd4},
	{0x30BF, 0xAB},/* outif_enable[7], data_type[5:0](2Bh = bayer 10bit} */
	{0x30C0, 0xA0},/* video_offset[7:4] 3260%12 */
	{0x30C8, 0x06},/* video_data_length 1600 = 1304 * 1.25 */
	{0x30C9, 0x5E},
	/* Timing Configuration */
	{0x0202, 0x03},
	{0x0203, 0x14},
	{0x0204, 0x00},
	{0x0205, 0x80},
	{0x0340, 0x03},/* Frame Length */
	{0x0341, 0xE0},
	{0x0342, 0x0A},/* 2738  Line Length */
	{0x0343, 0xB2},

    /*preview lens shading*/
    {0x3096, 0x40},
    {0x3097, 0x52},
    {0x3098, 0x3e},
    //{0x3098, 0x7b},
    {0x3099, 0x03},
    {0x309a, 0x1f},
    {0x309b, 0x04},
    {0x309c, 0x21},
    //{0x309b, 0x02},
    //{0x309c, 0x15},
    {0x309d, 0x00},
    {0x309e, 0x00},
    {0x309f, 0x00},
    {0x30a0, 0x00},
    {0x30a1, 0x00},
    {0x30a2, 0x00},
    {0x30a3, 0x00},
    {0x30a4, 0x00},
    {0x30a5, 0x01},
    {0x30a6, 0x00},

};

struct s5k4e1_i2c_reg_conf s5k4e1_snap_settings[] = {
	/*Output Size (2608x1960)*/
	{0x30A9, 0x03},/* Horizontal Binning Off */
	{0x300E, 0xE8},/* Vertical Binning Off */
	{0x0387, 0x01},/* y_odd_inc */
	{0x034C, 0x0A},/* x_output size */
	{0x034D, 0x30},
	{0x034E, 0x07},/* y_output size */
	{0x034F, 0xA8},
	{0x30BF, 0xAB},/* outif_enable[7], data_type[5:0](2Bh = bayer 10bit} */
	{0x30C0, 0x80},/* video_offset[7:4] 3260%12 */
	{0x30C8, 0x0C},/* video_data_length 3260 = 2608 * 1.25 */
	{0x30C9, 0xBC},
	/*Timing configuration*/
	{0x0202, 0x06},
	{0x0203, 0x28},
	{0x0204, 0x00},
	{0x0205, 0x80},
	{0x0340, 0x07},/* Frame Length */
	{0x0341, 0xB4},
	{0x0342, 0x0A},/* 2738 Line Length */
	{0x0343, 0xB2},

    {0x3096, 0x40},
    {0x3097, 0x52},
    //{0x3098, 0x3e},
    {0x3098, 0x7b},
    {0x3099, 0x03},
    {0x309a, 0x1f},
    //{0x309b, 0x04},
    //{0x309c, 0x21},
    {0x309b, 0x02},
    {0x309c, 0x15},
    {0x309d, 0x00},
    {0x309e, 0x00},
    {0x309f, 0x00},
    {0x30a0, 0x00},
    {0x30a1, 0x00},
    {0x30a2, 0x00},
    {0x30a3, 0x00},
    {0x30a4, 0x00},
    {0x30a5, 0x01},
    {0x30a6, 0x00},

};

struct s5k4e1_i2c_reg_conf s5k4e1_recommend_settings[] = {

	{0x3000,0x05},
	{0x3001,0x03},
	{0x3002,0x08},
	{0x3003,0x09},
	{0x3004,0x2E},
	{0x3005,0x06},
	{0x3006,0x34},
	{0x3007,0x00},
	{0x3008,0x3C},
	{0x3009,0x3C},
	{0x300A,0x28},
	{0x300B,0x04},
	{0x300C,0x0A},
	{0x300D,0x02},
	{0x300E,0xE8},
	{0x300F,0x82},
	{0x3010,0x00},
	{0x3011,0x4C},
	{0x3012,0x30},
	{0x3013,0xC0},
	{0x3014,0x00},
	{0x3015,0x00},
	{0x3016,0x2C},
	{0x3017,0x94},
	{0x3018,0x78},
	{0x301B,0x83},
	{0x301C,0x04},
	{0x301D,0xD4},
	{0x3021,0x02},
	{0x3022,0x24},
	{0x3024,0x40},
	{0x3027,0x08},
	{0x3029,0xC6},
	{0x30BC,0xB0},
	{0x302B,0x01},
	{0x30D8,0x3F},
	{0x3070, 0x5F},
	{0x3071, 0x00},
	{0x3080, 0x04},
	{0x3081, 0x38},

};
struct s5k4e1_i2c_reg_conf s5k4e1_lc_tbl[] = {
	{0x3096, 0x40},
	
	{0x3097, 0x52}, 	
	{0x3098, 0x3e}, 	
	//{0x3098, 0x7b}, 	
	{0x3099, 0x03}, 	
	{0x309a, 0x1f}, 	
	{0x309b, 0x04}, 	
	{0x309c, 0x21}, 	
	//{0x309b, 0x02}, 	
	//{0x309c, 0x15}, 	
	{0x309d, 0x00}, 	
	{0x309e, 0x00}, 	
	{0x309f, 0x00}, 	
	{0x30a0, 0x00}, 	
	{0x30a1, 0x00}, 	
	{0x30a2, 0x00}, 	
	{0x30a3, 0x00}, 	
	{0x30a4, 0x00}, 	
	
	{0x30a5, 0x01},
	{0x30a6, 0x00}, 	
	
	{0x3200, 0x00},
	{0x3201, 0x74},
	{0x3202, 0xcf},
	{0x3203, 0x0f},
	{0x3204, 0xf1},
	{0x3205, 0x31},
	{0x3206, 0x0f},
	{0x3207, 0xff},
	{0x3208, 0xeb},
	{0x3209, 0x00},
	{0x320a, 0x0d},
	{0x320b, 0xed},
	{0x320c, 0x0f},
	{0x320d, 0xf3},
	{0x320e, 0x3c},
	{0x320f, 0x00},
	{0x3210, 0x06},
	{0x3211, 0x6b},
	{0x3212, 0x0f},
	{0x3213, 0xf4},
	{0x3214, 0xa5},
	{0x3215, 0x0f},
	{0x3216, 0xf7},
	{0x3217, 0xf0},
	{0x3218, 0x0f},
	{0x3219, 0xfd},
	{0x321a, 0xa9},
	{0x321b, 0x00},
	{0x321c, 0x0b},
	{0x321d, 0x28},
	{0x321e, 0x0f},
	{0x321f, 0xfd},
	{0x3220, 0xf8},
	{0x3221, 0x0f},
	{0x3222, 0xf7},
	{0x3223, 0x83},
	{0x3224, 0x0f},
	{0x3225, 0xef},
	{0x3226, 0xaf},
	{0x3227, 0x00},
	{0x3228, 0x04},
	{0x3229, 0x46},
	{0x322a, 0x00},
	{0x322b, 0x0a},
	{0x322c, 0x79},
	{0x322d, 0x0f},
	{0x322e, 0xe9},
	{0x322f, 0x08},
	{0x3230, 0x00},
	{0x3231, 0x03},
	{0x3232, 0xdc},
	{0x3233, 0x00},
	{0x3234, 0x14},
	{0x3235, 0x6d},
	{0x3236, 0x00},
	{0x3237, 0x1f},
	{0x3238, 0xb4},
	{0x3239, 0x00},
	{0x323a, 0x00},
	{0x323b, 0xaa},
	{0x323c, 0x0f},
	{0x323d, 0xfe},
	{0x323e, 0x85},
	{0x323f, 0x00},
	{0x3240, 0x0c},
	{0x3241, 0xbe},
	{0x3242, 0x0f},
	{0x3243, 0xff},
	{0x3244, 0x82},
	{0x3245, 0x0f},
	{0x3246, 0xe5},
	{0x3247, 0xe0},
	{0x3248, 0x0f},
	{0x3249, 0xf7},
	{0x324a, 0x6d},
	{0x324b, 0x0f},
	{0x324c, 0xf9},
	{0x324d, 0xd9},
	{0x324e, 0x0f},
	{0x324f, 0xef},
	{0x3250, 0xac},
	{0x3251, 0x00},
	{0x3252, 0x08},
	{0x3253, 0xbe},
	{0x3254, 0x00},
	{0x3255, 0x07},
	{0x3256, 0x6e},
	{0x3257, 0x00},
	{0x3258, 0x07},
	{0x3259, 0x1a},
	{0x325a, 0x0f},
	{0x325b, 0xf2},
	{0x325c, 0xf5},
	{0x325d, 0x00},
	{0x325e, 0x0a},
	{0x325f, 0x7c},
	{0x3260, 0x00},
	{0x3261, 0x0b},
	{0x3262, 0x9c},
	{0x3263, 0x0f},
	{0x3264, 0xf9},
	{0x3265, 0x5d},
	{0x3266, 0x0f},
	{0x3267, 0xec},
	{0x3268, 0x3b},
	{0x3269, 0x00},
	{0x326a, 0x0e},
	{0x326b, 0x97},
	{0x326c, 0x00},
	{0x326d, 0x84},
	{0x326e, 0x02},
	{0x326f, 0x0f},
	{0x3270, 0xef},
	{0x3271, 0x5e},
	{0x3272, 0x0f},
	{0x3273, 0xfb},
	{0x3274, 0xd5},
	{0x3275, 0x00},
	{0x3276, 0x18},
	{0x3277, 0x16},
	{0x3278, 0x0f},
	{0x3279, 0xe8},
	{0x327a, 0xde},
	{0x327b, 0x00},
	{0x327c, 0x0c},
	{0x327d, 0x01},
	{0x327e, 0x0f},
	{0x327f, 0xfa},
	{0x3280, 0x2c},
	{0x3281, 0x0f},
	{0x3282, 0xf2},
	{0x3283, 0xbd},
	{0x3284, 0x0f},
	{0x3285, 0xfa},
	{0x3286, 0x4e},
	{0x3287, 0x00},
	{0x3288, 0x15},
	{0x3289, 0xd5},
	{0x328a, 0x0f},
	{0x328b, 0xfa},
	{0x328c, 0xee},
	{0x328d, 0x0f},
	{0x328e, 0xf0},
	{0x328f, 0x0c},
	{0x3290, 0x0f},
	{0x3291, 0xdc},
	{0x3292, 0x7b},
	{0x3293, 0x00},
	{0x3294, 0x0a},
	{0x3295, 0x94},
	{0x3296, 0x00},
	{0x3297, 0x0b},
	{0x3298, 0x9a},
	{0x3299, 0x0f},
	{0x329a, 0xe0},
	{0x329b, 0x23},
	{0x329c, 0x0f},
	{0x329d, 0xfc},
	{0x329e, 0x51},
	{0x329f, 0x00},
	{0x32a0, 0x2e},
	{0x32a1, 0x03},
	{0x32a2, 0x00},
	{0x32a3, 0x38},
	{0x32a4, 0x37},
	{0x32a5, 0x0f},
	{0x32a6, 0xf8},
	{0x32a7, 0x46},
	{0x32a8, 0x00},
	{0x32a9, 0x03},
	{0x32aa, 0x5b},
	{0x32ab, 0x00},
	{0x32ac, 0x12},
	{0x32ad, 0xa4},
	{0x32ae, 0x00},
	{0x32af, 0x0a},
	{0x32b0, 0xe8},
	{0x32b1, 0x0f},
	{0x32b2, 0xc1},
	{0x32b3, 0x4d},
	{0x32b4, 0x0f},
	{0x32b5, 0xf0},
	{0x32b6, 0x45},
	{0x32b7, 0x00},
	{0x32b8, 0x04},
	{0x32b9, 0xe1},
	{0x32ba, 0x0f},
	{0x32bb, 0xe0},
	{0x32bc, 0xa6},
	{0x32bd, 0x00},
	{0x32be, 0x0b},
	{0x32bf, 0x33},
	{0x32c0, 0x00},
	{0x32c1, 0x02},
	{0x32c2, 0x63},
	{0x32c3, 0x00},
	{0x32c4, 0x20},
	{0x32c5, 0x67},
	{0x32c6, 0x0f},
	{0x32c7, 0xea},
	{0x32c8, 0x0d},
	{0x32c9, 0x00},
	{0x32ca, 0x02},
	{0x32cb, 0xf9},
	{0x32cc, 0x00},
	{0x32cd, 0x1c},
	{0x32ce, 0x1e},
	{0x32cf, 0x0f},
	{0x32d0, 0xee},
	{0x32d1, 0xad},
	{0x32d2, 0x0f},
	{0x32d3, 0xec},
	{0x32d4, 0xf2},
	{0x32d5, 0x00},
	{0x32d6, 0x0a},
	{0x32d7, 0x0b},
	{0x32d8, 0x00},
	{0x32d9, 0x63},
	{0x32da, 0x64},
	{0x32db, 0x0f},
	{0x32dc, 0xf4},
	{0x32dd, 0x9d},
	{0x32de, 0x00},
	{0x32df, 0x01},
	{0x32e0, 0xe5},
	{0x32e1, 0x00},
	{0x32e2, 0x07},
	{0x32e3, 0x69},
	{0x32e4, 0x0f},
	{0x32e5, 0xfa},
	{0x32e6, 0xd4},
	{0x32e7, 0x00},
	{0x32e8, 0x02},
	{0x32e9, 0x3f},
	{0x32ea, 0x0f},
	{0x32eb, 0xfe},
	{0x32ec, 0x5d},
	{0x32ed, 0x0f},
	{0x32ee, 0xf5},
	{0x32ef, 0x85},
	{0x32f0, 0x0f},
	{0x32f1, 0xff},
	{0x32f2, 0x56},
	{0x32f3, 0x00},
	{0x32f4, 0x0a},
	{0x32f5, 0x8b},
	{0x32f6, 0x0f},
	{0x32f7, 0xff},
	{0x32f8, 0xb2},
	{0x32f9, 0x0f},
	{0x32fa, 0xf4},
	{0x32fb, 0x33},
	{0x32fc, 0x0f},
	{0x32fd, 0xea},
	{0x32fe, 0xbf},
	{0x32ff, 0x00},
	{0x3300, 0x10},
	{0x3301, 0xfc},
	{0x3302, 0x0f},
	{0x3303, 0xfd},
	{0x3304, 0x4a},
	{0x3305, 0x0f},
	{0x3306, 0xf1},
	{0x3307, 0x4b},
	{0x3308, 0x0f},
	{0x3309, 0xfb},
	{0x330a, 0x1b},
	{0x330b, 0x00},
	{0x330c, 0x1f},
	{0x330d, 0x0c},
	{0x330e, 0x00},
	{0x330f, 0x20},
	{0x3310, 0x11},
	{0x3311, 0x0f},
	{0x3312, 0xee},
	{0x3313, 0x89},
	{0x3314, 0x00},
	{0x3315, 0x0b},
	{0x3316, 0x17},
	{0x3317, 0x00},
	{0x3318, 0x10},
	{0x3319, 0x16},
	{0x331a, 0x0f},
	{0x331b, 0xfa},
	{0x331c, 0x80},
	{0x331d, 0x0f},
	{0x331e, 0xde},
	{0x331f, 0xee},
	{0x3320, 0x0f},
	{0x3321, 0xfd},
	{0x3322, 0x71},
	{0x3323, 0x00},
	{0x3324, 0x03},
	{0x3325, 0xce},
	{0x3326, 0x0f},
	{0x3327, 0xea},
	{0x3328, 0xe4},
	{0x3329, 0x0f},
	{0x332a, 0xfd},
	{0x332b, 0x25},
	{0x332c, 0x00},
	{0x332d, 0x12},
	{0x332e, 0x8d},
	{0x332f, 0x00},
	{0x3330, 0x0c},
	{0x3331, 0xb2},
	{0x3332, 0x0f},
	{0x3333, 0xea},
	{0x3334, 0x9f},
	{0x3335, 0x00},
	{0x3336, 0x0a},
	{0x3337, 0xad},
	{0x3338, 0x00},
	{0x3339, 0x0d},
	{0x333a, 0xa9},
	{0x333b, 0x0f},
	{0x333c, 0xfa},
	{0x333d, 0x4a},
	{0x333e, 0x0f},
	{0x333f, 0xef},
	{0x3340, 0x00},
	{0x3341, 0x00},
	{0x3342, 0x05},
	{0x3343, 0xf9},
	{0x3344, 0x00},
	{0x3345, 0x72},
	{0x3346, 0x14},
	{0x3347, 0x0f},
	{0x3348, 0xf0},
	{0x3349, 0x88},
	{0x334a, 0x00},
	{0x334b, 0x07},
	{0x334c, 0x96},
	{0x334d, 0x00},
	{0x334e, 0x01},
	{0x334f, 0x8e},
	{0x3350, 0x00},
	{0x3351, 0x00},
	{0x3352, 0xc6},
	{0x3353, 0x0f},
	{0x3354, 0xfe},
	{0x3355, 0x9a},
	{0x3356, 0x0f},
	{0x3357, 0xf5},
	{0x3358, 0xc4},
	{0x3359, 0x0f},
	{0x335a, 0xf5},
	{0x335b, 0xf9},
	{0x335c, 0x00},
	{0x335d, 0x00},
	{0x335e, 0xb6},
	{0x335f, 0x00},
	{0x3360, 0x08},
	{0x3361, 0xdb},
	{0x3362, 0x0f},
	{0x3363, 0xfd},
	{0x3364, 0x52},
	{0x3365, 0x0f},
	{0x3366, 0xf9},
	{0x3367, 0x28},
	{0x3368, 0x0f},
	{0x3369, 0xed},
	{0x336a, 0xdd},
	{0x336b, 0x00},
	{0x336c, 0x0c},
	{0x336d, 0x59},
	{0x336e, 0x0f},
	{0x336f, 0xfa},
	{0x3370, 0x1a},
	{0x3371, 0x0f},
	{0x3372, 0xf9},
	{0x3373, 0x3e},
	{0x3374, 0x0f},
	{0x3375, 0xfc},
	{0x3376, 0xf1},
	{0x3377, 0x00},
	{0x3378, 0x14},
	{0x3379, 0x77},
	{0x337a, 0x00},
	{0x337b, 0x24},
	{0x337c, 0x02},
	{0x337d, 0x0f},
	{0x337e, 0xf5},
	{0x337f, 0x9d},
	{0x3380, 0x00},
	{0x3381, 0x0f},
	{0x3382, 0x9c},
	{0x3383, 0x00},
	{0x3384, 0x00},
	{0x3385, 0x06},
	{0x3386, 0x0f},
	{0x3387, 0xfe},
	{0x3388, 0x10},
	{0x3389, 0x0f},
	{0x338a, 0xec},
	{0x338b, 0x76},
	{0x338c, 0x0f},
	{0x338d, 0xf6},
	{0x338e, 0xd5},
	{0x338f, 0x0f},
	{0x3390, 0xfe},
	{0x3391, 0xba},
	{0x3392, 0x0f},
	{0x3393, 0xeb},
	{0x3394, 0x4f},
	{0x3395, 0x00},
	{0x3396, 0x0a},
	{0x3397, 0x3f},
	{0x3398, 0x00},
	{0x3399, 0x0a},
	{0x339a, 0x13},
	{0x339b, 0x00},
	{0x339c, 0x04},
	{0x339d, 0x4b},
	{0x339e, 0x0f},
	{0x339f, 0xef},
	{0x33a0, 0x1c},
	{0x33a1, 0x00},
	{0x33a2, 0x0c},
	{0x33a3, 0xf1},
	{0x33a4, 0x00},
	{0x33a5, 0x06},
	{0x33a6, 0xb5},
	{0x33a7, 0x0f},
	{0x33a8, 0xfa},
	{0x33a9, 0xe1},
	{0x33aa, 0x0f},
	{0x33ab, 0xf3},
	{0x33ac, 0x1b},
	{0x33ad, 0x00},
	{0x33ae, 0x06},
	{0x33af, 0xf4},
	
	{0x3096, 0x60},
	{0x3096, 0x40},
	
	{0x0101, 0x03}, //mirror and flip
};

/* delete snapshot lc tab */
struct s5k4e1_reg s5k4e1_regs = {
	.reg_mipi = &s5k4e1_mipi_settings[0],
	.reg_mipi_size = ARRAY_SIZE(s5k4e1_mipi_settings),
	.rec_settings = &s5k4e1_recommend_settings[0],
	.rec_size = ARRAY_SIZE(s5k4e1_recommend_settings),

	
	.reg_lc = &s5k4e1_lc_tbl[0],
	.reg_lc_size = ARRAY_SIZE(s5k4e1_lc_tbl),	
	.reg_pll_p = &s5k4e1_pll_preview_settings[0],
	.reg_pll_p_size = ARRAY_SIZE(s5k4e1_pll_preview_settings),
	.reg_pll_s = &s5k4e1_pll_snap_settings[0],
	.reg_pll_s_size = ARRAY_SIZE(s5k4e1_pll_snap_settings),
	.reg_prev = &s5k4e1_prev_settings[0],
	.reg_prev_size = ARRAY_SIZE(s5k4e1_prev_settings),
	.reg_snap = &s5k4e1_snap_settings[0],
	.reg_snap_size = ARRAY_SIZE(s5k4e1_snap_settings),
};
