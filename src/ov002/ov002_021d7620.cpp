#include "ov002/ov002.h"

extern "C" {





void *func_0203ebf8(char *name);




static inline void ov002_strSet(char *dst, void **src, u32 n) {
    MIi_CpuClear32(0, dst, n);
    STD_CopyLString(dst, (char *)*src, n);
}

static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)NNS_G3dGetResDataByName((NNSG3dResDict *)(d + 8), (NNSG3dResName *)name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void func_ov002_021d7620(void *self) {
    void *res;
    char buf[16];
    u32 *q;
    char *name;
    res = func_02035d5c((char *)FIELD(self, 0x4, void *));
    FIELD(self, 0x18, void *) = Heap_Alloc(0x54);
    FIELD(self, 0x10, u32 *) = (u32 *)func_02034ec0(res, (char *)FIELD(self, 0x8, void *));
    ov002_strSet(buf, &FIELD(self, 0x8, void *), sizeof(buf));
    FIELD(self, 0x14, void *) = ov002_findEntry((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*FIELD(self, 0x10, u32 *)), buf);
    name = FIELD(self, 0x8, char *);
    if (FIELD(self, 0x10, u32 *) != NULL) {
        name = (char *)func_0203ed04(name, (void *)*FIELD(self, 0x10, u32 *));
    }
    FIELD(self, 0x1c, void *) = func_0203ebf8(name);
    NNS_G3dRenderObjInit((NNSG3dRenderObj *)FIELD(self, 0x18, void *), (NNSG3dResMdl *)FIELD(self, 0x14, void *));
    q = (u32 *)func_02034ff8(res, (char *)FIELD(self, 0xc, void *));
    ov002_strSet(buf, &FIELD(self, 0xc, void *), sizeof(buf));
    if (q[0] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[0], (NNSG3dResName *)buf);
        FIELD(self, 0x20, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)FIELD(self, 0x14, void *)), 4);
        NNS_G3dAnmObjInit((NNSG3dAnmObj *)FIELD(self, 0x20, void *), a, (NNSG3dResMdl *)FIELD(self, 0x14, void *), (NNSG3dResTex *)0);
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)FIELD(self, 0x18, void *), (NNSG3dAnmObj *)FIELD(self, 0x20, void *));
    }
    if (q[1] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[1], (NNSG3dResName *)buf);
        FIELD(self, 0x24, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)FIELD(self, 0x14, void *)), 4);
        NNS_G3dAnmObjInit((NNSG3dAnmObj *)FIELD(self, 0x24, void *), a, (NNSG3dResMdl *)FIELD(self, 0x14, void *), (NNSG3dResTex *)0);
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)FIELD(self, 0x18, void *), (NNSG3dAnmObj *)FIELD(self, 0x24, void *));
    }
    if (q[2] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[2], (NNSG3dResName *)buf);
        FIELD(self, 0x28, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)FIELD(self, 0x14, void *)), 4);
        NNS_G3dAnmObjInit((NNSG3dAnmObj *)FIELD(self, 0x28, void *), a, (NNSG3dResMdl *)FIELD(self, 0x14, void *), (NNSG3dResTex *)0);
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)FIELD(self, 0x18, void *), (NNSG3dAnmObj *)FIELD(self, 0x28, void *));
    }
    if (FIELD(self, 0x20, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x20, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x24, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x24, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x28, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x28, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    }
}

}
