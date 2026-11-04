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

extern MoCodeMem gMoMem;

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void *Gfx3D_AllocHi(u32 size);
extern void Gfx3D_FreeHi(void *ptr);

// Decoder kernels in ROM. dsd finds no relocations to these, so symbols.txt names them by hand.
extern u8 MoMem_VideoCode[];
extern u8 MoMem_Code04[];
extern u8 MoMem_Code00[];
extern u8 MoMem_Code1C[];

#define MO_VIDEO_CODE ((void *)MoMem_VideoCode)
#define MO_CODE_04 ((void *)MoMem_Code04)
#define MO_CODE_00 ((void *)MoMem_Code00)
#define MO_CODE_1C ((void *)MoMem_Code1C)

u32 MoMem_GetLargeSize(void) {
    return 0x659c;
}

u32 MoMem_GetSmallSize(void) {
    return 0x2580;
}

int MoMem_SetLargeMem(u8 *mem, u32 size) {
    gMoMem.largeMem = mem;
    gMoMem.largeSize = size & ~3;
    gMoMem.videoCode = NULL;
    return 0;
}

int MoMem_SetSmallMem(u8 *mem, u32 size) {
    gMoMem.smallMem = mem;
    gMoMem.smallSize = size & ~3;
    gMoMem.unk_04 = NULL;
    gMoMem.unk_00 = NULL;
    gMoMem.unk_1c = NULL;
    return 0;
}

void *MoMem_GetVideoCode(void) {
    if (gMoMem.videoCode == NULL) {
        if (gMoMem.largeSize >= 0x659c) {
            gMoMem.videoCode = gMoMem.largeMem;
            MIi_CpuCopyFast(MO_VIDEO_CODE, gMoMem.largeMem, 0x659c);
            gMoMem.largeMem += 0x659c;
            gMoMem.largeSize -= 0x659c;
        } else {
            return MO_VIDEO_CODE;
        }
    }
    return gMoMem.videoCode;
}

void *MoMem_GetCode04(void) {
    if (gMoMem.unk_04 == NULL) {
        if (gMoMem.smallSize >= 0x2100) {
            gMoMem.unk_04 = gMoMem.smallMem;
            MIi_CpuCopyFast(MO_CODE_04, gMoMem.smallMem, 0x2100);
            gMoMem.smallMem += 0x2100;
            gMoMem.smallSize -= 0x2100;
        } else {
            return MO_CODE_04;
        }
    }
    return gMoMem.unk_04;
}

void *MoMem_GetCode00(void) {
    if (gMoMem.unk_00 == NULL) {
        if (gMoMem.smallSize >= 0x300) {
            gMoMem.unk_00 = gMoMem.smallMem;
            MIi_CpuCopyFast(MO_CODE_00, gMoMem.smallMem, 0x300);
            gMoMem.smallMem += 0x300;
            gMoMem.smallSize -= 0x300;
        } else {
            return MO_CODE_00;
        }
    }
    return gMoMem.unk_00;
}

void *MoMem_GetCode1C(void) {
    if (gMoMem.unk_1c == NULL) {
        if (gMoMem.smallSize >= 0x180) {
            gMoMem.unk_1c = gMoMem.smallMem;
            MIi_CpuCopyFast(MO_CODE_1C, gMoMem.smallMem, 0x180);
            gMoMem.smallMem += 0x180;
            gMoMem.smallSize -= 0x180;
        } else {
            return MO_CODE_1C;
        }
    }
    return gMoMem.unk_1c;
}

void *MoMem_Alloc(u32 size) {
    return Gfx3D_AllocHi(size);
}

void MoMem_Free(void *ptr) {
    Gfx3D_FreeHi(ptr);
}

}
