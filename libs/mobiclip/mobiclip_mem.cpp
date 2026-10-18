#include "mobiclip/mobiclip.h"

// Work memory of the Mobiclip decoders. The decoder kernels are copied from ROM into fast RAM on first use.

extern "C" {

typedef struct MoCodeMem {
    /* 0x00 */ void *unk_00;
    /* 0x04 */ void *unk_04;
    /* 0x08 */ void *videoCode;
    /* 0x0c */ u32 smallSize;
    /* 0x10 */ u8 *smallMem;
    /* 0x14 */ u32 largeSize;
    /* 0x18 */ u8 *largeMem;
    /* 0x1c */ void *unk_1c;
} MoCodeMem;

extern MoCodeMem data_02097cbc;

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void *func_02043e1c(u32 size);
extern void func_02043e2c(void *ptr);

// Decoder kernels in ROM. dsd finds no relocations to these, so symbols.txt names them by hand.
extern u8 data_0207bcb8[];
extern u8 data_02077ab8[];
extern u8 data_020823d4[];
extern u8 data_02082254[];

#define MO_VIDEO_CODE ((void *)data_0207bcb8)
#define MO_CODE_04 ((void *)data_02077ab8)
#define MO_CODE_00 ((void *)data_020823d4)
#define MO_CODE_1C ((void *)data_02082254)

u32 func_02034600(void) {
    return 0x659c;
}

u32 func_0203460c(void) {
    return 0x2580;
}

int func_02034614(u8 *mem, u32 size) {
    data_02097cbc.largeMem = mem;
    data_02097cbc.largeSize = size & ~3;
    data_02097cbc.videoCode = NULL;
    return 0;
}

int func_02034634(u8 *mem, u32 size) {
    data_02097cbc.smallMem = mem;
    data_02097cbc.smallSize = size & ~3;
    data_02097cbc.unk_04 = NULL;
    data_02097cbc.unk_00 = NULL;
    data_02097cbc.unk_1c = NULL;
    return 0;
}

void *func_0203465c(void) {
    if (data_02097cbc.videoCode == NULL) {
        if (data_02097cbc.largeSize >= 0x659c) {
            data_02097cbc.videoCode = data_02097cbc.largeMem;
            MIi_CpuCopyFast(MO_VIDEO_CODE, data_02097cbc.largeMem, 0x659c);
            data_02097cbc.largeMem += 0x659c;
            data_02097cbc.largeSize -= 0x659c;
        } else {
            return MO_VIDEO_CODE;
        }
    }
    return data_02097cbc.videoCode;
}

void *func_020346d4(void) {
    if (data_02097cbc.unk_04 == NULL) {
        if (data_02097cbc.smallSize >= 0x2100) {
            data_02097cbc.unk_04 = data_02097cbc.smallMem;
            MIi_CpuCopyFast(MO_CODE_04, data_02097cbc.smallMem, 0x2100);
            data_02097cbc.smallMem += 0x2100;
            data_02097cbc.smallSize -= 0x2100;
        } else {
            return MO_CODE_04;
        }
    }
    return data_02097cbc.unk_04;
}

void *func_02034740(void) {
    if (data_02097cbc.unk_00 == NULL) {
        if (data_02097cbc.smallSize >= 0x300) {
            data_02097cbc.unk_00 = data_02097cbc.smallMem;
            MIi_CpuCopyFast(MO_CODE_00, data_02097cbc.smallMem, 0x300);
            data_02097cbc.smallMem += 0x300;
            data_02097cbc.smallSize -= 0x300;
        } else {
            return MO_CODE_00;
        }
    }
    return data_02097cbc.unk_00;
}

void *func_020347ac(void) {
    if (data_02097cbc.unk_1c == NULL) {
        if (data_02097cbc.smallSize >= 0x180) {
            data_02097cbc.unk_1c = data_02097cbc.smallMem;
            MIi_CpuCopyFast(MO_CODE_1C, data_02097cbc.smallMem, 0x180);
            data_02097cbc.smallMem += 0x180;
            data_02097cbc.smallSize -= 0x180;
        } else {
            return MO_CODE_1C;
        }
    }
    return data_02097cbc.unk_1c;
}

void *func_02034818(u32 size) {
    return func_02043e1c(size);
}

void func_02034824(void *ptr) {
    func_02043e2c(ptr);
}

}
