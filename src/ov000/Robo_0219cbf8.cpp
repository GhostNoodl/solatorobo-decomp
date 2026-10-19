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

void func_ov000_0219cbf8(VObj *self, VecFx32 *pos, u16 *rot) {
    LFLD(VecFx32, self, 0x70).x = pos->x;
    LFLD(VecFx32, self, 0x70).y = pos->y;
    LFLD(VecFx32, self, 0x70).z = pos->z;
    if (LFLD(B22_0219cbf8, self, 0xb22).mode != 5) {
        LFLD(VecFx32, self, 0xaf0).x = pos->x;
        LFLD(VecFx32, self, 0xaf0).y = pos->y;
        LFLD(VecFx32, self, 0xaf0).z = pos->z;
    } else {
        LFLD(VecFx32, self, 0xaf0).x = LFLD(VecFx32, self, 0x70).x - NNS_G3dGlb.camPos.x;
        LFLD(VecFx32, self, 0xaf0).y = LFLD(VecFx32, self, 0x70).y - NNS_G3dGlb.camPos.y;
        LFLD(VecFx32, self, 0xaf0).z = LFLD(VecFx32, self, 0x70).z - NNS_G3dGlb.camPos.z;
    }
    LFLD(VecFx32, self, 0xafc).x = LFLD(VecFx32, self, 0xaf0).x;
    LFLD(VecFx32, self, 0xafc).y = LFLD(VecFx32, self, 0xaf0).y;
    LFLD(VecFx32, self, 0xafc).z = LFLD(VecFx32, self, 0xaf0).z;
    {
        u16 ry;
        LFLD(u16, self, 0x7c) = rot[0];
        LFLD(u16, self, 0x7e) = ry = rot[1];
        LFLD(u16, self, 0x80) = rot[2];
        LFLD(u16, self, 0x98) = ry;
    }
    if (LBIT(self, 0xb24).b1) {
        LFLD(VecFx32, self, 0x75c).x = LFLD(VecFx32, self, 0x70).x;
        LFLD(VecFx32, self, 0x75c).y = LFLD(VecFx32, self, 0x70).y;
        LFLD(VecFx32, self, 0x75c).z = LFLD(VecFx32, self, 0x70).z;
        LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
        LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
        LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
    }
    if (LFLD(void *, self, 0x5c) != NULL) {
        func_ov000_021bd300(LFLD(void *, self, 0x5c));
        func_ov000_021bd438(LFLD(void *, self, 0x5c), &LFLD(VecFx32, self, 0x70), 0);
    }
    if (LFLD(void *, self, 0x9b0) != NULL) {
        func_ov000_021bd300(LFLD(void *, self, 0x9b0));
        func_ov000_021bd438(LFLD(void *, self, 0x9b0), &LFLD(VecFx32, self, 0x75c), 0);
    }
    func_ov000_02198d28((u8 *)self + 0x2cc, &LFLD(VecFx32, self, 0x70), LFLD(u16, self, 0x7e));
    LFLD(s32, self, 0x31c) = 0;
    LFLD(s32, self, 0x320) = 0;
    LFLD(s32, self, 0x324) = 0;
    func_ov000_02198d28((u8 *)self + 0x6c0, &LFLD(VecFx32, self, 0x75c), LFLD(u16, self, 0x76e));
    LFLD(s32, self, 0x710) = 0;
    LFLD(s32, self, 0x714) = 0;
    LFLD(s32, self, 0x718) = 0;
    self->vfunc_44();
    LBIT(self, 0xb24).b20 = 0;
    if (data_ov000_021ccd6c[9] == 0xff) {
        LFLD(B22_0219cbf8, self, 0xb22).b13 = 1;
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

static inline void Reset0219cdb8(u8 *self) {
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_0219cdb8, self, 0xb24).b5 = 0;
    LFLD(B24_0219cdb8, self, 0xb24).b7 = LFLD(B24_0219cdb8, self, 0xb24).b9;
}

void func_ov000_0219cdb8(u8 *self) {
    if (LFLD(B24_0219cdb8, self, 0xb24).b12 == 3) {
        u8 *o = GetObj0219cdb8(LFLD(u16, self, 0xb20));
        if (o != NULL) {
            LFLD(C1_0219cdb8, o, 0x16).b0 = 1;
        }
        LFLD(u16, self, 0xb20) = 0xffff;
        LFLD(u16, self, 0x7c) = 0;
        LFLD(B24_0219cdb8, self, 0xb24).b12 = 0;
    }
    if (LFLD(B24_0219cdb8, self, 0xb24).b5 != 0) {
        u8 *o = GetObj0219cdb8(LFLD(u16, self, 0xb1c));
        u8 *p = NULL;
        if (o != NULL) {
            p = LFLD(u8 *, o, 0x4c);
        }
        if (p == NULL || LFLD(u16, p, 0x1c) != LFLD(u16, self, 0xc)) {
            if (p != NULL) {
                LFLD(u16, p, 0x1c) = 0xffff;
            }
            Reset0219cdb8(self);
        }
    }
    LFLD(u16, self, 0x90) = 0xffff;
    LFLD(u8, self, 0xb2f) = 0;
    LFLD(B24_0219cdb8, self, 0xb24).b2 = 0;
    if (LFLD(B22_0219cdb8, self, 0xb22).a != 0) {
        if (LFLD(void *, self, 0x998) != NULL) {
            func_ov000_02191008(LFLD(void *, self, 0x998));
        }
        if (LFLD(s16, self, 0xb64) >= 0) {
            func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
            LFLD(s16, self, 0xb64) = -1;
        }
        if (LFLD(B22_0219cdb8, self, 0xb22).a > 1) {
            LFLD(B22_0219cdb8, self, 0xb22).a = 1;
            LFLD(u16, self, 0x7c) = 0;
            LFLD(u16, self, 0x80) = 0;
            LFLD(u16, self, 0x9a6) = 0;
            LFLD(u16, self, 0x9a8) = 0;
            LFLD(u16, self, 0x9aa) = 0;
            LFLD(u16, self, 0x9a0) = 0;
            LFLD(u16, self, 0x9a2) = 0;
            LFLD(u16, self, 0x9a4) = 0;
        }
    }
    LFLD(u16, self, 0xb32) = 0;
    LFLD(u16, self, 0xbac) = 0xffff;
    LFLD(C1_0219cdb8, self, 0x93).b0 = 0;
    LFLD(u16, self, 0xb36) = 0;
    LFLD(u16, self, 0xb38) = 0;
    LFLD(B2C_0219cdb8, self, 0xb2c).b4 = 0;
    {
        u16 *v = LFLD(u16 *, self, 0x54);
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    if (data_ov000_021ccd54[0xc9] != 0) {
        u16 *w = LFLD(u16 *, self, 0x50);
        u8 *a;
        u16 v;
        w[0] = v = w[1];
        a = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (a != NULL && LFLD(u8 *, a, 0x58) != NULL) {
            func_ov000_021697dc(LFLD(u8 *, a, 0x58), v, v);
            LFLD(u32, LFLD(u8 *, a, 0x58), 0xc) |= 0x80;
        }
        LFLD(u16, LFLD(u8 *, self, 0x50), 0xa) = 0;
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
    if (LFLD(B22_0219cdb8, self, 0xb22).b12) {
        u8 *c = data_ov000_021ccd54;
        if (c[0xca] != c[0xd0] || c[0xcb] != c[0xd1]) {
            s32 *t;
            void **res;
            LFLD(B22_0219cdb8, self, 0xb22).b12 = 0;
            LFLD(H1_0219cdb8, self, 0x42a).b0 = 0;
            t = LFLD(s32 *, self, 0xba0);
            func_ov000_02191008(self + 0x368);
            if (LFLD(u8 *, self, 0x998) != NULL) {
                LFLD(H1_0219cdb8, LFLD(u8 *, self, 0x998), 0xc2).b0 = 0;
            }
            LFLD(H1_0219cdb8, self, 0x16e).b0 = 0;
            res = LFLD(void **, LFLD(u8 *, self, 0xac), 0xc);
            NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
            func_ov000_0218ec60(self + 0x450, t[0], t[1], 1, 1);
            func_ov000_0218edf0(self + 0x450, t[2], t[3], 1, 1);
            func_ov000_0218ef10(self + 0x450, t[4], t[5], 1, 1);
            if (LFLD(u8, t, 0x18) != 0) {
                func_ov000_0218edf0(self + 0x588, t[0], t[1], 1, 1);
            }
            LFLD(B22_0219cdb8, self, 0xb22).b11 = 1;
        }
    }
    if (data_ov000_021ccd6c[0xb] == 0xff) {
        LFLD(B22_0219cdb8, self, 0xb22).b13 = 1;
    }
}
}
