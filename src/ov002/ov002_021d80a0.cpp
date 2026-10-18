#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d80a0(void *self) {
    if (FIELD(self, 0x80, void *) == NULL) {
        return;
    }
    if (!func_0203e63c(FIELD(self, 0x84, void *)) || FIELD(self, 0xac, s32) == 0) {
        return;
    }
    func_ov002_021d83f0(self);
    if (FIELD(self, 0x9c, s32) != 0x1000) {
        NNS_G3dMdlSetMdlPolygonIDAll(FIELD(self, 0x7c, void *), func_02043d48(data_02097d48 + 0x8b0));
    }
    NNS_G3dGlbSetBaseTrans((u8 *)self + 0x4);
    MI_Copy36B((u8 *)self + 0x18, data_020928b4);
    NNS_G3dGlb.fc &= ~0xa4;
    NNS_G3dGlbSetBaseScale((u8 *)self + 0x3c);
    NNS_G3dGlbFlushVP();
    NNS_G3dDraw(FIELD(self, 0x80, void *));
    NNS_G3dGeFlushBuffer();
}

void *func_02035d5c(void *a);

void *func_02034ec0(void *a, void *b);

void *NNS_G3dGetResDataByName(void *a, char *name);

char *func_0203ed04(char *name, u32 a);

void *func_0203ebf8(char *name);

u32 NNS_G3dAnmObjCalcSizeRequired(void *a, void *b);

void NNS_G3dAnmObjInit(void *a, void *b, void *c, int d);

void NNS_G3dRenderObjAddAnmObj(void *a, void *b);

void NNS_G3dRenderObjSetCallBack(void *a, void *fn, int b, int c, int d);

void NNS_G3dMdlSetMdlCullModeAll(void *a, int b);

void NNS_G3dMdlSetMdlXLDepthUpdateAll(void *a, int b);

void func_ov002_021e0420(void);

static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)NNS_G3dGetResDataByName(d + 8, name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void func_ov002_021d8148(void *self) {
    void *res;
    char *name;
    void *n8;
    void *nc;
    u32 *q;
    char buf[16];
    u8 *info;
    info = func_0206ede8(FIELD(self, 0x48, u16));
    n8 = FIELD(info, 0x8, void *);
    nc = FIELD(info, 0xc, void *);
    res = func_02035d5c(data_ov002_021efdf6);
    FIELD(self, 0x78, u32 *) = (u32 *)func_02034ec0(res, n8);
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, nc, sizeof(buf));
    FIELD(self, 0x7c, void *) = ov002_findEntry((u8 *)NNS_G3dGetMdlSet((void *)*FIELD(self, 0x78, u32 *)), buf);
    name = FIELD(info, 0x8, char *);
    if (FIELD(self, 0x78, u32 *) != NULL) {
        name = func_0203ed04(name, *FIELD(self, 0x78, u32 *));
    }
    FIELD(self, 0x84, void *) = func_0203ebf8(name);
    FIELD(self, 0x80, void *) = func_0203dd9c(0x54);
    NNS_G3dRenderObjInit(FIELD(self, 0x80, void *), FIELD(self, 0x7c, void *));
    NNS_G3dMdlSetMdlCullModeAll(FIELD(self, 0x7c, void *), 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(FIELD(self, 0x7c, void *), 0);
    NNS_G3dRenderObjSetCallBack(FIELD(self, 0x80, void *), (void *)func_ov002_021e0420, 0, 4, 2);
    FIELD(FIELD(self, 0x80, void *), 0x2c, void *) = (u8 *)self + 0x9c;
    q = (u32 *)func_02034ff8(res, n8);
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, nc, sizeof(buf));
    if (q[0] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[0], buf);
        if (a != NULL) {
            FIELD(self, 0x88, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, FIELD(self, 0x7c, void *)), 4);
            NNS_G3dAnmObjInit(FIELD(self, 0x88, void *), a, FIELD(self, 0x7c, void *), 0);
            NNS_G3dRenderObjAddAnmObj(FIELD(self, 0x80, void *), FIELD(self, 0x88, void *));
        }
    }
    if (q[1] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[1], buf);
        if (a != NULL) {
            FIELD(self, 0x8c, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, FIELD(self, 0x7c, void *)), 4);
            NNS_G3dAnmObjInit(FIELD(self, 0x8c, void *), a, FIELD(self, 0x7c, void *), 0);
            NNS_G3dRenderObjAddAnmObj(FIELD(self, 0x80, void *), FIELD(self, 0x8c, void *));
        }
    }
    if (q[2] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[2], buf);
        if (a != NULL) {
            FIELD(self, 0x90, void *) = func_0203de84(NNS_G3dAnmObjCalcSizeRequired(a, FIELD(self, 0x7c, void *)), 4);
            NNS_G3dAnmObjInit(FIELD(self, 0x90, void *), a, FIELD(self, 0x7c, void *), (int)NNS_G3dGetTex((void *)*FIELD(self, 0x78, u32 *)));
            NNS_G3dRenderObjAddAnmObj(FIELD(self, 0x80, void *), FIELD(self, 0x90, void *));
        }
    }
    if (FIELD(self, 0x88, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x88, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x8c, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x8c, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x90, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x90, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    }
}

}
