#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x68];
    u16 unk_68;
    u16 unk_6a;
    u8 unk_6c[0x4];
    u16 unk_70;
    u8 unk_72[0x8];
    u16 unk_7a;
} Shared02fe1534;

typedef struct {
    u8 unk_00[0x8];
    VObj *unk_08;
} Global021ccd24;

extern "C" {

extern u8 data_ov000_021ccd24[];
extern Shared02fe1534 data_02fe1534;
s32 func_0204c0e8(void *a, void *b);

u32 func_ov000_0214c01c(u16 arg) {
    data_02fe1534.unk_70 = 1;
    data_02fe1534.unk_7a = arg;
    ((Global021ccd24 *)data_ov000_021ccd24)->unk_08->vfunc_38(1);
    data_02fe1534.unk_7a = 0;
    return (data_02fe1534.unk_6a << 16) | data_02fe1534.unk_68;
}

s32 func_ov000_0214c064(void *arg) {
    return func_0204c0e8(*(void **)((u8 *)((void **)data_ov000_021ccd24)[2] + 0xbc), arg);
}

}
