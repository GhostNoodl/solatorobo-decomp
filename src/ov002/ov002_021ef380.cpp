#include "types.h"

// The staff-roll configuration read by ov002_021ec6a8.cpp .. ov002_021ee1a8.cpp. The original TU
// also held those functions and the string pool at 0x021f0ddc; here the strings stay extern.
extern "C" {
extern char data_ov002_021f0ddc[];
extern char data_ov002_021f0df6[];
extern char data_ov002_021f0de9[];
}

struct Ov002StaffCfg {
    s32 w0, w4;
    const char *dir;
    const char *photo;
    s32 w10;
    const char *pathFmt;
    const char *dir2;
    s32 w1c, w20, w24, w28, w2c, w30, w34, w38;
    char photo0[8];
    char photo1[8];
    const char *photoB;
    const char *photoA;
};

extern "C" Ov002StaffCfg data_ov002_021f0d88;

static const char *const data_ov002_021ef11c[2] = { data_ov002_021f0d88.photo1, data_ov002_021f0d88.photo0 };

Ov002StaffCfg data_ov002_021f0d88 = {
    0x3c000, 0x3c000, data_ov002_021f0ddc, data_ov002_021ef11c[0], -0x800, data_ov002_021f0df6, data_ov002_021f0de9,
    0x12c, 0x80000, 0xd0000, 4, 4, 0x12c, 0x3c000, 0x78000, "photo00", "photo01", data_ov002_021ef11c[1], data_ov002_021ef11c[0],
};
