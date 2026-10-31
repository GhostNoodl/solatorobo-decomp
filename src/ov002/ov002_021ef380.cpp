#include "ov002/ov002.h"

// The staff-roll configuration read by ov002_021ec6a8.cpp .. ov002_021ee1a8.cpp. The original TU
// also held those functions and the string pool at 0x021f0ddc; here the strings stay extern.
// Ov002StaffCfg is in ov002/ov002.h (round dtB), so the readers use its fields instead of a
// void *[] view and per-file prefix structs.
extern "C" {
extern char data_ov002_021f0ddc[];
extern char data_ov002_021f0df6[];
extern char data_ov002_021f0de9[];
}



static const char *const data_ov002_021ef11c[2] = { data_ov002_021f0d88.photo1, data_ov002_021f0d88.photo0 };

Ov002StaffCfg data_ov002_021f0d88 = {
    0x3c000, 0x3c000, data_ov002_021f0ddc, data_ov002_021ef11c[0], -0x800, data_ov002_021f0df6, data_ov002_021f0de9,
    0x12c, 0x80000, 0xd0000, 4, 4, 0x12c, 0x3c000, 0x78000, "photo00", "photo01", data_ov002_021ef11c[1], data_ov002_021ef11c[0],
};
