#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d80a0(Obj021efe9c *self) {
    if (self->unk_80 == NULL) {
        return;
    }
    if (!func_0203e63c((unsigned int)self->unk_84) || self->unk_ac == 0) {
        return;
    }
    func_ov002_021d83f0(self);
    if (self->unk_9c != 0x1000) {
        NNS_G3dMdlSetMdlPolygonIDAll(self->unk_7c, Gfx3DState_NextPolyId(data_02097d48->unk_8b0));
    }
    NNS_G3dGlbSetBaseTrans((VecFx32 *)((u8 *)self + 0x4));
    MI_Copy36B((u8 *)self + 0x18, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
    NNS_G3dGlbSetBaseScale((VecFx32 *)((u8 *)self + 0x3c));
    NNS_G3dGlbFlushVP();
    NNS_G3dDraw((NNSG3dRenderObj *)self->unk_80);
    NNS_G3dGeFlushBuffer();
}





void *func_0203ebf8(char *name);





void NNS_G3dMdlSetMdlCullModeAll(void *a, int b);

void NNS_G3dMdlSetMdlXLDepthUpdateAll(void *a, int b);


static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)NNS_G3dGetResDataByName((NNSG3dResDict *)(d + 8), (NNSG3dResName *)name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void func_ov002_021d8148(Obj021efe9c *self) {
    void *res;
    char *name;
    void *n8;
    void *nc;
    u32 *q;
    char buf[16];
    u8 *info;
    info = func_0206ede8(self->unk_48);
    n8 = FIELD(info, 0x8, void *);
    nc = FIELD(info, 0xc, void *);
    res = func_02035d5c((char *)data_ov002_021efdf6);
    self->unk_78 = (void *)((u32 *)func_02034ec0(res, (char *)n8));
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, (char *)nc, sizeof(buf));
    self->unk_7c = ov002_findEntry((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*FIELD(self, 0x78, u32 *)), buf);
    name = FIELD(info, 0x8, char *);
    if (FIELD(self, 0x78, u32 *) != NULL) {
        name = (char *)func_0203ed04(name, (void *)*FIELD(self, 0x78, u32 *));
    }
    self->unk_84 = func_0203ebf8(name);
    self->unk_80 = Heap_Alloc(0x54);
    NNS_G3dRenderObjInit((NNSG3dRenderObj *)self->unk_80, (NNSG3dResMdl *)self->unk_7c);
    NNS_G3dMdlSetMdlCullModeAll(self->unk_7c, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(self->unk_7c, 0);
    NNS_G3dRenderObjSetCallBack((NNSG3dRenderObj *)self->unk_80, (NNSG3dSbcCallBackFunc)func_ov002_021e0420, NULL, 4, NNS_G3D_SBC_CALLBACK_TIMING_B);
    FIELD(self->unk_80, 0x2c, void *) = (u8 *)self + 0x9c;
    q = (u32 *)func_02034ff8(res, (char *)n8);
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, (char *)nc, sizeof(buf));
    if (q[0] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[0], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_88 = Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)self->unk_7c), 4);
            NNS_G3dAnmObjInit((NNSG3dAnmObj *)self->unk_88, a, (NNSG3dResMdl *)self->unk_7c, (NNSG3dResTex *)0);
            NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)self->unk_80, (NNSG3dAnmObj *)self->unk_88);
        }
    }
    if (q[1] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[1], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_8c = Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)self->unk_7c), 4);
            NNS_G3dAnmObjInit((NNSG3dAnmObj *)self->unk_8c, a, (NNSG3dResMdl *)self->unk_7c, (NNSG3dResTex *)0);
            NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)self->unk_80, (NNSG3dAnmObj *)self->unk_8c);
        }
    }
    if (q[2] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[2], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_90 = Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, (NNSG3dResMdl *)self->unk_7c), 4);
            NNS_G3dAnmObjInit((NNSG3dAnmObj *)self->unk_90, a, (NNSG3dResMdl *)self->unk_7c, (NNSG3dResTex *)(int)NNS_G3dGetTex((NNSG3dResFileHeader *)*FIELD(self, 0x78, u32 *)));
            NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *)self->unk_80, (NNSG3dAnmObj *)self->unk_90);
        }
    }
    if (self->unk_88 != NULL) {
        self->unk_98 = FIELD(FIELD(((u8 *)self->unk_88), 0x8, u8 *), 0x4, u16) << 12;
    } else if (self->unk_8c != NULL) {
        self->unk_98 = FIELD(FIELD(((u8 *)self->unk_8c), 0x8, u8 *), 0x4, u16) << 12;
    } else if (self->unk_90 != NULL) {
        self->unk_98 = FIELD(FIELD(((u8 *)self->unk_90), 0x8, u8 *), 0x4, u16) << 12;
    }
}

}
