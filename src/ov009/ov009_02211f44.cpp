#include "ov009/ov009.h"

extern "C" {

extern void NNS_G3dGetCurrentMtx(void *p, s32 a);

void func_ov009_02211f44(Ov009Actor *self) {
    u8 *p = FLD(u8 *, FLD(void *, self, 0x4), 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    if (FLD(u32, self, 0x8) & 0x10) {
        v = FLD(u8, self, 0xae);
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        NNS_G3dGetCurrentMtx(p + 4, 0);
    }
}

void func_ov009_02211f84(Ov009Actor *self) {
    FLD(void *, self, 0x24) = (void *)func_ov009_02211f44;
    self->unk_92 = 3;
}

extern void *data_ov000_021ccd64;
extern char data_ov009_022179c0[];
extern char data_ov009_022179c7[];
extern char data_ov009_022179d1[];
extern char data_ov009_022179d8[];
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void MTX_Identity43_(void *p);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void func_0203f2b8(void *p);
extern u8 *func_0206fef8(void *res);
extern void func_0203f80c(void *p);
extern void func_0203f990(void *p, s32 v);
extern void func_0203f9b8(void *p, s32 v);
extern void MTX_RotX43_(void *m, s32 s, s32 c);
extern void MTX_RotY43_(void *m, s32 s, s32 c);
extern void MTX_RotZ43_(void *m, s32 s, s32 c);
extern void MTX_Concat43(void *a, void *b, void *out);
extern void func_0203f9dc(void *mesh, const void *mtx);
extern void func_0203f8d8(void *p);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
struct Ov009Mtx43b {
    s32 m[9];
    Ov009Vec t;
};

struct Ov009Bit8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_02211f9c(Ov009Actor *self) {
    Ov009Sub38 *m;
    u8 *c;
    u32 *o;
    u32 v;
    u32 saved;
    u8 *p;
    func_ov003_021d112c(self);
    switch (self->kind) {
    case 0x504f:
        FLD(s32, self, 0xf4) = func_ov000_021909a8(self->unk_38, data_ov009_022179c0, data_ov009_022179c7);
        break;
    case 0x5050:
        FLD(s32, self, 0xf4) = func_ov000_021909a8(self->unk_38, data_ov009_022179d1, data_ov009_022179d8);
        break;
    }
    MTX_Identity43_(&FLD(u8, self, 0xf8));
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov009_02211f84);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf4);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *d = self->unk_48;
        if (d != NULL) {
            func_0203f2b8(d);
            func_0203de1c(d);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    c = func_0206fef8((void *)self->kind);
    o = FLD(u32 *, FLD(u8 *, self, 0x34), 0x84);
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *q = func_0203dd9c(0x98);
        if (q != NULL) {
            func_0203f80c(q);
        }
        FLD(void *, self, 0x58) = q;
        o = FLD(u32 *, FLD(u8 *, self, 0x34), 0x84);
        func_0203f990(FLD(void *, self, 0x58), o != NULL ? *o : 0);
        func_0203f9b8(FLD(void *, self, 0x58), FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43b t;
            Ov009Mtx43b mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot[2];
            obj = FLD(void *, self, 0x58);
            ry = self->rot[1];
            rx = self->rot[0];
            MTX_Identity43_(&mt);
            if (rz != 0) {
                MTX_RotZ43_(&mt, OV009_SIN(rz), OV009_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_(&t, OV009_SIN(ry), OV009_COS(ry));
                    MTX_Concat43(&t, &mt, &mt);
                } else {
                    MTX_RotY43_(&mt, OV009_SIN(ry), OV009_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_(&t, OV009_SIN(rx), OV009_COS(rx));
                    MTX_Concat43(&t, &mt, &mt);
                } else {
                    MTX_RotX43_(&mt, OV009_SIN(rx), OV009_COS(rx));
                    set = TRUE;
                }
            }
            mt.t.x = self->pos.x;
            mt.t.y = self->pos.y;
            mt.t.z = self->pos.z;
            func_0203f9dc(obj, &mt);
        }
        func_0203f8d8(FLD(void *, self, 0x58));
    }
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Bit8 *)(p + 0xa2))->b0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    self->unk_b6 = 0x1e;
    self->unk_ea_0 = 0;
    FLD(Ov009Vec, self, 0x134).x = self->pos.x;
    FLD(Ov009Vec, self, 0x134).y = self->pos.y;
    FLD(Ov009Vec, self, 0x134).z = self->pos.z;
    FLD(u16, self, 0xf2) = 0;
}

}
