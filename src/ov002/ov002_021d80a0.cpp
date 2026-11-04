#include "ov002/ov002.h"

extern "C" {

void Ov002Vt_021efe9c_Draw(Obj021efe9c *self) {
    if (self->unk_80 == NULL) {
        return;
    }
    if (!Vram_IsTransferDone(self->unk_84) || self->unk_ac == 0) {
        return;
    }
    func_ov002_021d83f0(self);
    if (self->unk_9c != 0x1000) {
        NNS_G3dMdlSetMdlPolygonIDAll(self->unk_7c, Gfx3DState_NextPolyId(gGfxSys->unk_8b0));
    }
    NNS_G3dGlbSetBaseTrans(&self->trans);
    MI_Copy36B(&self->rot, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
    NNS_G3dGlbSetBaseScale(&self->scale);
    NNS_G3dGlbFlushVP();
    NNS_G3dDraw(self->unk_80);
    NNS_G3dGeFlushBuffer();
}





u32 Vram_GetTexTransferId(const char *name);





void NNS_G3dMdlSetMdlCullModeAll(void *a, int b);

void NNS_G3dMdlSetMdlXLDepthUpdateAll(void *a, int b);


static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)NNS_G3dGetResDataByName((NNSG3dResDict *)(d + 8), (NNSG3dResName *)name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void Obj021efe9c_LoadPartModel(Obj021efe9c *self) {
    void *res;
    char *name;
    void *n8;
    void *nc;
    u32 *q;
    char buf[16];
    u8 *info;
    info = Param_GetEntry(self->unk_48);
    n8 = FIELD(info, 0x8, void *);
    nc = FIELD(info, 0xc, void *);
    res = ResMgr_GetArcList((char *)data_ov002_021efdf6);
    self->unk_78 = (u32 *)ResList_FindType4(res, (char *)n8);
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, (char *)nc, sizeof(buf));
    self->unk_7c = (NNSG3dResMdl *)ov002_findEntry((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*self->unk_78), buf);
    name = FIELD(info, 0x8, char *);
    if (self->unk_78 != NULL) {
        name = (char *)G3dRes_SetupVram(name, (void *)*self->unk_78);
    }
    self->unk_84 = Vram_GetTexTransferId(name);
    self->unk_80 = (NNSG3dRenderObj *)Heap_Alloc(sizeof(NNSG3dRenderObj));
    NNS_G3dRenderObjInit(self->unk_80, self->unk_7c);
    NNS_G3dMdlSetMdlCullModeAll(self->unk_7c, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(self->unk_7c, 0);
    NNS_G3dRenderObjSetCallBack(self->unk_80, (NNSG3dSbcCallBackFunc)Ov002_ScaleAlphaMatCb, NULL, 4, NNS_G3D_SBC_CALLBACK_TIMING_B);
    self->unk_80->ptrUser = (u8 *)self + 0x9c;
    q = (u32 *)ResList_FindType6(res, (char *)n8);
    MIi_CpuClear32(0, buf, sizeof(buf));
    STD_CopyLString(buf, (char *)nc, sizeof(buf));
    if (q[0] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[0], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_88 = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->unk_7c), 4);
            NNS_G3dAnmObjInit(self->unk_88, a, self->unk_7c, (NNSG3dResTex *)0);
            NNS_G3dRenderObjAddAnmObj(self->unk_80, self->unk_88);
        }
    }
    if (q[1] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[1], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_8c = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->unk_7c), 4);
            NNS_G3dAnmObjInit(self->unk_8c, a, self->unk_7c, (NNSG3dResTex *)0);
            NNS_G3dRenderObjAddAnmObj(self->unk_80, self->unk_8c);
        }
    }
    if (q[2] != 0) {
        void *a = NNS_G3dGetAnmByName((void *)q[2], (NNSG3dResName *)buf);
        if (a != NULL) {
            self->unk_90 = Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->unk_7c), 4);
            NNS_G3dAnmObjInit((NNSG3dAnmObj *)self->unk_90, a, self->unk_7c, (NNSG3dResTex *)(int)NNS_G3dGetTex((NNSG3dResFileHeader *)*self->unk_78));
            NNS_G3dRenderObjAddAnmObj(self->unk_80, (NNSG3dAnmObj *)self->unk_90);
        }
    }
    if (self->unk_88 != NULL) {
        self->unk_98 = ((NNSG3dResAnmCommon *)self->unk_88->resAnm)->numFrame << 12;
    } else if (self->unk_8c != NULL) {
        self->unk_98 = ((NNSG3dResAnmCommon *)self->unk_8c->resAnm)->numFrame << 12;
    } else if (self->unk_90 != NULL) {
        self->unk_98 = ((NNSG3dResAnmCommon *)((NNSG3dAnmObj *)self->unk_90)->resAnm)->numFrame << 12;
    }
}

}
