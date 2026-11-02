#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

#define SIN_TABLE FX_SINCOS_TABLE

void func_ov002_021d91d8(Obj021efed4 *self);

void func_ov002_021d8fac(Obj021efed4 *self) {
    switch (self->unk_98) {
    case 0:
        func_ov002_021d91d8(self);
        self->unk_98 = 10;
    case 10:
        self->unk_88->frame = self->unk_ac << 12;
        if (self->unk_9c) {
            self->unk_a4 = FX_MUL(SIN_TABLE[((FIELD(self, 0xa0, s32) * 0x444) >> 4) * 2], 0xccd) + 0x333;
            if (--self->unk_a0 < 0) {
                self->unk_a0 = 30;
            }
        } else {
            self->unk_a4 = 0x1000;
            self->unk_a0 = 0;
        }
        break;
    }
}

static inline void ov002_setXY(Model *o, s32 x, s32 y) {
    o->x = x & ~0xfff;
    o->y = y << 12;
}

void func_ov002_021e3b6c(s32 *out, s32 *v, void *m);

void func_ov002_021d9070(Obj021efed4 *self) {
    s32 out[2];
    if (self->unk_80 == NULL) {
        return;
    }
    if (!func_0203e63c(self->unk_84)) {
        return;
    }
    NNS_G3dGlbSetBaseTrans(&self->trans);
    MI_Copy36B(&self->rot, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
    NNS_G3dGlbSetBaseScale(&self->scale);
    NNS_G3dGlbFlushVP();
    NNS_G3dDraw(self->unk_80);
    NNS_G3dGeFlushBuffer();
    if (!self->unk_94) {
        return;
    }
    {
    void *m = self->unk_b0;
    s32 v[3] = {0, 0, 0};
    v[0] = (self->unk_54 - 2) * 0x28f;
    v[1] = 0;
    v[2] = (self->unk_58 - 2) * 0x28f;
    func_ov002_021e3b6c(out, v, m);
    ov002_setXY((Model *)self->unk_90, out[0], out[1] >> 12);
    }
    Model_PlayPart((Model *)self->unk_90, 6);
}





u32 func_0203ebf8(const char *name);





void *func_02035de0(const char *file, const char *name);


void func_02041c34(void *a, int b, void *c, int d);



void *func_ov002_021d8d00(void);

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

void func_ov002_021d91d8(Obj021efed4 *self) {
    void *res;
    u8 *info;
    char buf[16];
    u32 *q;
    char *name;
    void *a;
    res = func_02035d5c((char *)data_ov002_021efdf6);
    info = func_0206ede8(self->unk_48);
    self->unk_78 = (u32 *)func_02034ec0(res, (char *)FIELD(info, 0x8, void *));
    ov002_strSet(buf, &FIELD(info, 0xc, void *), sizeof(buf));
    self->unk_7c = (NNSG3dResMdl *)ov002_findEntry((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*self->unk_78), buf);
    name = (char *)self->unk_78;
    if (self->unk_78 != NULL) {
        name = (char *)func_0203ed04(buf, (void *)*self->unk_78);
    }
    self->unk_84 = func_0203ebf8(name);
    self->unk_80 = (NNSG3dRenderObj *)Heap_Alloc(sizeof(NNSG3dRenderObj));
    NNS_G3dRenderObjInit(self->unk_80, self->unk_7c);
    NNS_G3dRenderObjSetCallBack(self->unk_80, (NNSG3dSbcCallBackFunc)func_ov002_021e0420, NULL, 4, NNS_G3D_SBC_CALLBACK_TIMING_B);
    self->unk_80->ptrUser = (u8 *)self + 0xa4;
    q = (u32 *)func_02034ff8(res, (char *)FIELD(info, 0x8, void *));
    STD_CopyLString(buf, (char *)FIELD(info, 0xc, void *), sizeof(buf));
    a = NNS_G3dGetAnmByName((void *)q[1], (NNSG3dResName *)buf);
    self->unk_88 = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, self->unk_7c), 4);
    NNS_G3dAnmObjInit(self->unk_88, a, self->unk_7c, (NNSG3dResTex *)(int)NNS_G3dGetTex((NNSG3dResFileHeader *)*self->unk_78));
    NNS_G3dRenderObjAddAnmObj(self->unk_80, self->unk_88);
    self->unk_88->frame = self->unk_ac << 12;
    if (self->unk_94) {
        Model *m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            const char *file = data_0208cc94;
            const char *nm = data_0208cc88;
            func_02041218(&m->pltt);
            func_02041440(m, nm, 0);
            STD_CopyString(m->name, file);
        }
        self->unk_90 = m;
        func_020417e0((Model *)self->unk_90, func_02035de0(data_0208cc94, data_0208cc88));
        ((Model *)self->unk_90)->flags |= 2;
        ((Model *)self->unk_90)->unk_150 = -0x2000;
        func_02041c20((Model *)self->unk_90, 6, self);
        func_02041c34(self->unk_90, 6, (void *)func_ov002_021d8d00, 0);
        func_02041d9c((Model *)self->unk_90, 0, 6);
    }
    self->trans.y = 0;
}

}
