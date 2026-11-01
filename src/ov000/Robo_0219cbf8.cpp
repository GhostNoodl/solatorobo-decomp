#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb0219cbf8;

typedef struct {
    u16 lo : 6;
    u16 mode : 3;
    u16 b9 : 4;
    u16 b13 : 1;
    u16 hi : 2;
} B22_0219cbf8;

extern "C" {
extern Glb0219cbf8 NNS_G3dGlb;
extern u8 *data_ov000_021ccd6c;
void func_ov000_021bd300(void *p);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);
void func_ov000_02198d28(void *body, VecFx32 *pos, u32 angle);

struct Obj0219cbf8 : public VObj {
    u8 unk_04[0x58];
    void *unk_5c;
    u8 unk_60[0x10];
    VecFx32 unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x16];
    u16 unk_98;
    u8 unk_9a[0x282];
    s32 unk_31c;
    s32 unk_320;
    s32 unk_324;
    u8 unk_328[0x3e8];
    s32 unk_710;
    s32 unk_714;
    s32 unk_718;
    u8 unk_71c[0x40];
    VecFx32 unk_75c;
    u8 unk_768[0x4];
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772[0x23e];
    void *unk_9b0;
    u8 unk_9b4[0x13c];
    VecFx32 unk_af0;
    VecFx32 unk_afc;
    u8 unk_b08[0x1a];
    B22_0219cbf8 unk_b22;
};

void func_ov000_0219cbf8(Obj0219cbf8 *self, VecFx32 *pos, u16 *rot) {
    self->unk_70.x = pos->x;
    self->unk_70.y = pos->y;
    self->unk_70.z = pos->z;
    if (self->unk_b22.mode != 5) {
        self->unk_af0.x = pos->x;
        self->unk_af0.y = pos->y;
        self->unk_af0.z = pos->z;
    } else {
        self->unk_af0.x = self->unk_70.x - NNS_G3dGlb.camPos.x;
        self->unk_af0.y = self->unk_70.y - NNS_G3dGlb.camPos.y;
        self->unk_af0.z = self->unk_70.z - NNS_G3dGlb.camPos.z;
    }
    self->unk_afc.x = self->unk_af0.x;
    self->unk_afc.y = self->unk_af0.y;
    self->unk_afc.z = self->unk_af0.z;
    {
        u16 ry;
        self->unk_7c = rot[0];
        self->unk_7e = ry = rot[1];
        self->unk_80 = rot[2];
        self->unk_98 = ry;
    }
    if (LBIT(self, 0xb24).b1) {
        self->unk_75c.x = self->unk_70.x;
        self->unk_75c.y = self->unk_70.y;
        self->unk_75c.z = self->unk_70.z;
        self->unk_76c = self->unk_7c;
        self->unk_76e = self->unk_7e;
        self->unk_770 = self->unk_80;
    }
    if (self->unk_5c != NULL) {
        func_ov000_021bd300(self->unk_5c);
        func_ov000_021bd438(self->unk_5c, &self->unk_70, 0);
    }
    if (self->unk_9b0 != NULL) {
        func_ov000_021bd300(self->unk_9b0);
        func_ov000_021bd438(self->unk_9b0, &self->unk_75c, 0);
    }
    func_ov000_02198d28((u8 *)self + 0x2cc, &self->unk_70, self->unk_7e);
    self->unk_31c = 0;
    self->unk_320 = 0;
    self->unk_324 = 0;
    func_ov000_02198d28((u8 *)self + 0x6c0, &self->unk_75c, self->unk_76e);
    self->unk_710 = 0;
    self->unk_714 = 0;
    self->unk_718 = 0;
    self->vfunc_44();
    LBIT(self, 0xb24).b20 = 0;
    if (data_ov000_021ccd6c[9] == 0xff) {
        self->unk_b22.b13 = 1;
    }
}
}


typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 rest : 18;
} B24_0219cdb8;

typedef struct {
    u16 a : 3;
    u16 b3 : 8;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 rest : 2;
} B22_0219cdb8;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 2;
    u16 rest : 10;
} B2C_0219cdb8;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} H1_0219cdb8;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} C1_0219cdb8;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd6c;
extern void *data_02097e4c;
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_02191008(void *p);
void func_02049bb4(void *mgr, s32 id);
void func_ov000_021697dc(void *p, u16 a, u16 b);
void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218ef10(void *p, s32 a, s32 b, s32 c, s32 d);
void *NNS_G3dGetMdlSet(void *file);
void NNS_G3dReleaseMdlSet(void *mdl);

static inline u8 *GetObj0219cdb8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

struct Obj0219cdb8 {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x42];
    u16 *unk_50;
    u16 *unk_54;
    u8 unk_58[0x24];
    u16 unk_7c;
    u8 unk_7e[0x2];
    u16 unk_80;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0x1];
    C1_0219cdb8 unk_93;
    u8 unk_94[0x18];
    u8 *unk_ac;
    u8 unk_b0[0xbe];
    H1_0219cdb8 unk_16e;
    u8 unk_170[0x2ba];
    H1_0219cdb8 unk_42a;
    u8 unk_42c[0x56c];
    void *unk_998;
    u8 unk_99c[0x4];
    u16 unk_9a0;
    u16 unk_9a2;
    u16 unk_9a4;
    u16 unk_9a6;
    u16 unk_9a8;
    u16 unk_9aa;
    u8 unk_9ac[0x170];
    u16 unk_b1c;
    u16 unk_b1e;
    u16 unk_b20;
    B22_0219cdb8 unk_b22;
    B24_0219cdb8 unk_b24;
    u8 unk_b28[0x4];
    B2C_0219cdb8 unk_b2c;
    u8 unk_b2e[0x1];
    u8 unk_b2f;
    u8 unk_b30[0x2];
    u16 unk_b32;
    u8 unk_b34[0x2];
    u16 unk_b36;
    u16 unk_b38;
    u8 unk_b3a[0x2a];
    s16 unk_b64;
    u8 unk_b66[0x3a];
    s32 *unk_ba0;
    u8 unk_ba4[0x8];
    u16 unk_bac;
};

static inline void Reset0219cdb8(Obj0219cdb8 *self) {
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24.b5 = 0;
    self->unk_b24.b7 = self->unk_b24.b9;
}

void func_ov000_0219cdb8(Obj0219cdb8 *self) {
    if (self->unk_b24.b12 == 3) {
        u8 *o = GetObj0219cdb8(self->unk_b20);
        if (o != NULL) {
            LFLD(C1_0219cdb8, o, 0x16).b0 = 1;
        }
        self->unk_b20 = 0xffff;
        self->unk_7c = 0;
        self->unk_b24.b12 = 0;
    }
    if (self->unk_b24.b5 != 0) {
        u8 *o = GetObj0219cdb8(self->unk_b1c);
        u8 *p = NULL;
        if (o != NULL) {
            p = LFLD(u8 *, o, 0x4c);
        }
        if (p == NULL || LFLD(u16, p, 0x1c) != self->unk_0c) {
            if (p != NULL) {
                LFLD(u16, p, 0x1c) = 0xffff;
            }
            Reset0219cdb8(self);
        }
    }
    self->unk_90 = 0xffff;
    self->unk_b2f = 0;
    self->unk_b24.b2 = 0;
    if (self->unk_b22.a != 0) {
        if (self->unk_998 != NULL) {
            func_ov000_02191008(self->unk_998);
        }
        if (self->unk_b64 >= 0) {
            func_02049bb4(data_02097e4c, self->unk_b64);
            self->unk_b64 = -1;
        }
        if (self->unk_b22.a > 1) {
            self->unk_b22.a = 1;
            self->unk_7c = 0;
            self->unk_80 = 0;
            self->unk_9a6 = 0;
            self->unk_9a8 = 0;
            self->unk_9aa = 0;
            self->unk_9a0 = 0;
            self->unk_9a2 = 0;
            self->unk_9a4 = 0;
        }
    }
    self->unk_b32 = 0;
    self->unk_bac = 0xffff;
    self->unk_93.b0 = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b2c.b4 = 0;
    {
        u16 *v = self->unk_54;
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    if (data_ov000_021ccd54[0xc9] != 0) {
        u16 *w = self->unk_50;
        u8 *a;
        u16 v;
        w[0] = v = w[1];
        a = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (a != NULL && LFLD(u8 *, a, 0x58) != NULL) {
            func_ov000_021697dc(LFLD(u8 *, a, 0x58), v, v);
            LFLD(u32, LFLD(u8 *, a, 0x58), 0xc) |= 0x80;
        }
        LFLD(u16, self->unk_50, 0xa) = 0;
        Reset0219cdb8(self);
    }
    {
        u8 *a = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        u8 *m = a != NULL ? LFLD(u8 *, a, 0x58) : NULL;
        if (m != NULL) {
            LFLD(s32, m, 0x5c) = LFLD(s32, m, 0x64);
            LFLD(s32, m, 0x68) = LFLD(s32, m, 0x64);
        }
    }
    if (self->unk_b22.b12) {
        u8 *c = data_ov000_021ccd54;
        if (c[0xca] != c[0xd0] || c[0xcb] != c[0xd1]) {
            s32 *t;
            void **res;
            self->unk_b22.b12 = 0;
            self->unk_42a.b0 = 0;
            t = self->unk_ba0;
            func_ov000_02191008((u8 *)self + 0x368);
            if ((u8 *)self->unk_998 != NULL) {
                LFLD(H1_0219cdb8, self->unk_998, 0xc2).b0 = 0;
            }
            self->unk_16e.b0 = 0;
            res = LFLD(void **, self->unk_ac, 0xc);
            NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
            func_ov000_0218ec60((u8 *)self + 0x450, t[0], t[1], 1, 1);
            func_ov000_0218edf0((u8 *)self + 0x450, t[2], t[3], 1, 1);
            func_ov000_0218ef10((u8 *)self + 0x450, t[4], t[5], 1, 1);
            if (LFLD(u8, t, 0x18) != 0) {
                func_ov000_0218edf0((u8 *)self + 0x588, t[0], t[1], 1, 1);
            }
            self->unk_b22.b11 = 1;
        }
    }
    if (data_ov000_021ccd6c[0xb] == 0xff) {
        self->unk_b22.b13 = 1;
    }
}
}
