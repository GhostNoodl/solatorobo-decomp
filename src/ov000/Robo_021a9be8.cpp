#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 rest : 12;
} B24_021a9be8;

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021a9be8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 2;
    u16 rest : 12;
} H22_021a9be8;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_021a9be8;

typedef struct {
    u16 st;
    u16 timer;
} State_021a9be8;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a9be8;

typedef struct {
    u16 a;
    u16 b;
    u16 c[4];
    s16 d;
} Desc_021a9be8;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern char data_ov000_021cc68a[];
extern char data_ov000_021ca12c[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
s32 **func_ov000_02190a30(void *a, int b);
void *func_ov000_0219122c(void *a, s32 frame);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_0218dd8c(void *self, u16 base, s32 turn, void *p);
u16 func_ov000_0218d8f4(void *self, void *target);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
u8 *func_ov000_0218bf1c(void *mgr, Desc_021a9be8 *d, void *pos, void *rot, u16 a);
void *func_0204a028(void *a, s32 b, void *c, s32 d);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u8 *func_02065f88(s32 id, void *pos);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
u16 func_0204bfa8(void *cam);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);

static inline u8 *FindActor_021a9be8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Both_021a9be8(u8 *c) {
    return (LFLD(H22_021a9be8, c, 0x22).b0 == 1 && LFLD(H22_021a9be8, c, 0x22).b1 == 1) ? TRUE : FALSE;
}

static inline BOOL Has_021a9be8(u8 *c) {
    return LFLD(H22_021a9be8, c, 0x22).b2 != 0 ? TRUE : FALSE;
}

static inline u16 AngleTo_021a9be8(u8 *self, u8 *other) {
    if (other == NULL || other == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, other, 0x78) - LFLD(s32, self, 0x78));
}

static inline u16 CamYaw_021a9be8(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

static inline s32 Frame_021a9be8(void *m) {
    s32 f = 0;
    s32 **a = func_ov000_02190a30(m, f);
    if (*a != NULL) {
        f = **a;
    }
    return f;
}

static inline void SetFx_021a9be8(u8 *self, u8 *o, s32 rz) {
    LFLD(s32, self, 0xb48) = LFLD(s32, o, 0x24);
    LFLD(s32, o, 0x3c) = 0x2000;
    LFLD(s32, self, 0xb4c) = LFLD(s32, self, 0xa74) - LFLD(s32, self, 0x70);
    LFLD(s32, self, 0xb50) = LFLD(s32, self, 0xa78) - LFLD(s32, self, 0x74);
    LFLD(s32, self, 0xb54) = LFLD(s32, self, 0xa7c) - LFLD(s32, self, 0x78);
    LFLD(u16, self, 0xb58) = 0;
    LFLD(u16, self, 0xb5a) = -LFLD(u16, self, 0x7e);
    LFLD(u16, self, 0xb5c) = 0;
    LFLD(s16, self, 0xb5e) = rz;
}

static inline void Bump_021a9be8(u8 *self) {
    if (LFLD(B24_021a9be8, self, 0xb24).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!LFLD(B24_021a9be8, self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(B24_021a9be8, self, 0xb24).b17 = 1;
    }
}

void func_ov000_021a9be8(u8 *self) {
    Desc_021a9be8 desc;
    VecFx32 z;
    Pose_021a9be8 m;
    VecFx32 t;
    u8 *tg;
    u8 *a;
    u8 *o;
    s32 lim;
    BOOL fall;
    State_021a9be8 *s;
    u16 tm;

    tg = FindActor_021a9be8(LFLD(u16, self, 0x90));
    if (tg != NULL) {
        u8 *c = LFLD(u8 *, tg, 0x44);
        if (!(c != NULL && Both_021a9be8(c) && (u16)(LFLD(u16, tg, 0xc) & 0xf000) == 0x5000 && Has_021a9be8(c))) {
            tg = NULL;
        } else if (LFLD(u8, self, 0xb2f) == 0) {
            LFLD(u8, self, 0xb2f)++;
        }
    }
    fall = FALSE;
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
        lim = -0xf000;
        if (LFLD(B22_021a9be8, self, 0xb22).b0 || LFLD(B24_021a9be8, self, 0xb24).b12 || LFLD(B24_021a9be8, self, 0xb24).b19) {
            lim = -0x2d000;
        }
        if (LFLD(s32, self, 0x74) - LFLD(s32, self, 0xb00) < lim) {
            fall = TRUE;
        }
    }
    if (fall) {
        LFLD(u16, self, 0xb36) = 0;
        LFLD(u32, self, 0xb24) |= 0x40000;
    }
    switch (LFLD(State_021a9be8 *, self, 0x40)->st) {
    case 0:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc68a, 0x555, 1);
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        if (LFLD(u16, self, 0xb36) != 0) {
            LFLD(u16, self, 0xb36) = 1;
        }
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0x29;
        LFLD(State_021a9be8 *, self, 0x40)->timer = 0;
        LFLD(State_021a9be8 *, self, 0x40)->st++;
        break;
    case 1:
        if (LFLD(u16, self, 0xb36) == 0) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
            break;
        }
        if (Frame_021a9be8(LFLD(void *, self, 0x38)) > 0x14000) {
            func_ov000_0219122c(LFLD(void *, self, 0x38), 0x14000);
            LFLD(B8_021a9be8, self, 0xae4).b0 = 1;
        }
        if (LFLD(State_021a9be8 *, self, 0x40)->timer == 0x14) {
            o = func_02065f88(0x640, self + 0xa74);
            if (o != NULL) {
                SetFx_021a9be8(self, o, 0);
            }
        }
        s = LFLD(State_021a9be8 *, self, 0x40);
        s->timer++;
        if (s->timer >= 0x20) {
            s32 i;
            LFLD(State_021a9be8 *, self, 0x40)->timer = 0x20;
            func_0204a028(data_02097e4c, 0x44, self + 0x70, 2);
            func_02049f44(data_02097e4c, 0x78, self + 0x70, 0);
            desc.a = 0x480c;
            desc.b = 0x4000;
            for (i = 0; i < 4; i++) {
                desc.c[i] = 0;
            }
            desc.d = -1;
            a = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, self + 0xa74, self + 0x7c, 0xffff);
            if (a != NULL) {
                u8 *p;
                LFLD(B8_021a9be8, a, 0x16).b0 = 1;
                LFLD(void *, a, 0x60) = data_ov000_021ca12c;
                p = LFLD(u8 *, a, 0x4c);
                if (p != NULL) {
                    LFLD(u16, p, 0x1c) = LFLD(u16, self, 0xc);
                    LFLD(u8, p, 0x18) |= 8;
                }
                func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 9);
                LFLD(B24_021a9be8, self, 0xb24).b5 = 1;
                LFLD(B24_021a9be8, self, 0xb24).b7 = 0;
                LFLD(u16, self, 0xb1c) = LFLD(u16, a, 0xc);
                o = func_02065f88(0x195, self + 0x70);
                if (o != NULL) {
                    SetFx_021a9be8(self, o, -0x7b);
                }
                LFLD(State_021a9be8 *, self, 0x40)->st++;
            }
        }
        break;
    case 2:
        if (Frame_021a9be8(LFLD(void *, self, 0x38)) > 0x14000) {
            func_ov000_0219122c(LFLD(void *, self, 0x38), 0x14000);
        }
        if (LFLD(u16, self, 0xb36) == 0) {
            a = FindActor_021a9be8(LFLD(u16, self, 0xb1c));
            if (a == NULL || (LFLD(u8 *, a, 0x40) != NULL ? LFLD(u8, LFLD(u8 *, a, 0x40), 0x13) : 0) == 9) {
                LFLD(State_021a9be8 *, self, 0x40)->timer = 0;
                LFLD(State_021a9be8 *, self, 0x40)->st = 10;
            }
        }
        break;
    case 10:
        a = FindActor_021a9be8(LFLD(u16, self, 0xb1c));
        if (a != NULL) {
            u16 ang;
            func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xb);
            if (a != NULL) {
                VecFx32 *q = LFLD(VecFx32 *, a, 0x48);
                if (q != NULL) {
                    t.x = q->x;
                    t.y = q->y;
                    t.z = q->z;
                } else {
                    t.x = LFLD(s32, a, 0x70);
                    t.y = LFLD(s32, a, 0x74);
                    t.z = LFLD(s32, a, 0x78);
                }
                if (func_01ffbd6c((VecFx32 *)(self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                    t.x -= LFLD(s32, self, 0x70);
                    t.y -= LFLD(s32, self, 0x74);
                    t.z -= LFLD(s32, self, 0x78);
                    VEC_MultAdd(0xc00, &t, (VecFx32 *)(self + 0x70), &t);
                    m.pos = t;
                    m.rx = LFLD(u16, a, 0x7c);
                    m.ry = LFLD(u16, a, 0x7e);
                    m.rz = LFLD(u16, a, 0x80);
                    m.unk = 0;
                    func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, 1, sizeof(Pose_021a9be8), &m);
                }
            }
            ang = LFLD(u16, self, 0x7e);
            if (tg != NULL) {
                if (LFLD(void *, tg, 0x44) != NULL) {
                    ang = func_ov000_0218d8f4(self, LFLD(void *, tg, 0x44));
                } else {
                    ang = AngleTo_021a9be8(self, tg);
                }
            }
            {
                VecFx32 p;
                p.x = LFLD(s32, a, 0x70);
                p.y = LFLD(s32, a, 0x74);
                p.z = LFLD(s32, a, 0x78);
                p.x += FX_SinCosTable_[(ang >> 4) * 2];
                p.z += FX_SinCosTable_[(ang >> 4) * 2 + 1];
                LFLD(VecFx32, a, 0x84) = p;
            }
            LFLD(u16, a, 0x7c) = 0;
            LFLD(u16, a, 0x7e) = ang;
            LFLD(u16, a, 0x80) = 0;
            LFLD(u16, a, 0x90) = LFLD(u16, self, 0x90);
            LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
            func_02049f44(data_02097e4c, 0x5c, self + 0x70, 0);
        }
        LFLD(u16, self, 0xb1c) = 0xffff;
        LFLD(u16, self, 0xb1e) = 0xffff;
        LFLD(B24_021a9be8, self, 0xb24).b5 = 0;
        LFLD(B24_021a9be8, self, 0xb24).b7 = LFLD(B24_021a9be8, self, 0xb24).b9;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(State_021a9be8 *, self, 0x40)->st++;
        break;
    case 11:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
            if (LFLD(u16, self, 0xb36) != 0) {
                LFLD(State_021a9be8 *, self, 0x40)->st = 0;
            } else {
                func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
            }
        }
        break;
    }
    if (LFLD(State_021a9be8 *, self, 0x40)->st >= 10) {
        return;
    }
    if (!LFLD(B24_021a9be8, self, 0xb24).b17) {
        u16 yaw = CamYaw_021a9be8(data_ov000_021ccd54 + 0xf4);
        u16 ang;
        if (LFLD(u16, self, 0xb68) & 0xf0) {
            LFLD(s32, self, 0x9c) = LFLD(s32, self, 0xb08) >> 2;
            func_ov000_0218dd8c(self, yaw, 0, self + 0xb70);
            ang = LFLD(u16, self, 0x98);
        } else {
            LFLD(s32, self, 0xa4) = 0x29;
            func_ov000_0218dbe0(self, 0);
            ang = LFLD(u16, self, 0x7e);
        }
        if (tg != NULL) {
            if (LFLD(void *, tg, 0x44) != NULL) {
                ang = func_ov000_0218d8f4(self, LFLD(void *, tg, 0x44));
            } else {
                ang = AngleTo_021a9be8(self, tg);
            }
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
    } else {
        func_ov000_0218dbe0(self, 0);
    }
    func_ov000_021987b8(LFLD(void *, self, 0x48), 1, 0, 0);
    if (LFLD(s32, self, 0xa0) < 0 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
        LFLD(s32, self, 0xa0) = 0;
        LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
        if (LFLD(B24_021a9be8, self, 0xb24).b17) {
            LFLD(B24_021a9be8, self, 0xb24).b17 = 0;
            LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
            LFLD(s32, self, 0x9c) = 0;
        }
    }
    Bump_021a9be8(self);
    tm = LFLD(State_021a9be8 *, self, 0x40)->timer;
    if (tm == 0) {
        return;
    }
    {
        u8 *p;
        u8 *x;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        p = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (p == NULL) return;
        x = LFLD(u8 *, p, 0x70);
        if (x == NULL) return;
        func_ov000_02168e18(x, tm, 0x20, &z);
    }
}
}
