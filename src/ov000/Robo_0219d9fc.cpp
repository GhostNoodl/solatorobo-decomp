#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 3;
    u32 b12 : 2;
    u32 b14 : 6;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} B24_0219d9fc;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219d9fc;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 b6 : 1;
    u16 rest : 9;
} B2C_0219d9fc;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bit0_0219d9fc;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} H0_0219d9fc;

typedef struct {
    u16 b0 : 9;
    u16 b9 : 1;
    u16 rest : 6;
} Pad18_0219d9fc;

#define B24(self) LFLD(B24_0219d9fc, self, 0xb24)
#define B22(self) LFLD(B22_0219d9fc, self, 0xb22)
#define B2C(self) LFLD(B2C_0219d9fc, self, 0xb2c)
#define B93(self) LFLD(Bit0_0219d9fc, self, 0x93)
#define PAD18 LFLD(Pad18_0219d9fc, data_0214a424, 0x18)
#define VEC(p, off) LFLD(VecFx32, p, off)
#define SIN_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern u8 *data_0214a424;
extern u8 *data_02097d48;
extern u8 data_ov000_021ca320[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_ov000_02191ec4(void *a, s32 b, u32 c);
int func_02043d9c(void *p);
void func_ov000_02190758(void *model, void *rot, s32 a);
BOOL func_ov000_021903b4(void *model);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
void func_ov003_021ce9ac(void *p);
void func_ov000_021b4130(void *self, BOOL a);
void func_ov000_021bd7a0(void *p);
void func_ov000_02191c24(void *shadow, void *pos);
void func_ov000_02167fac(void *p, s32 a, s32 b);

static inline Actor *FindActor_0219d9fc(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL IsBusy_0219d9fc(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_0219d9fc(FieldState *g) {
    if (g != NULL) {
        if (IsBusy_0219d9fc(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u8 Begin_0219d9fc(void) {
    u8 a = LFLD(u8, data_02097d48, 0x8b3);
    func_02043d9c(data_02097d48 + 0x8b0);
    return a;
}

static inline BOOL HasD4_0219d9fc(FieldState *g) {
    return ((s32)g->unk_d4) != 0;
}

static inline BOOL HasD4B_0219d9fc(FieldState *g) {
    return HasD4_0219d9fc(g) ? TRUE : FALSE;
}

static inline BOOL PadB9_0219d9fc(void) {
    return PAD18.b9 ? TRUE : FALSE;
}

struct RgbEq_0219d9fcSelf {
    u8 unk_00[0x772];
    u8 unk_772;
    u8 unk_773;
    u8 unk_774;
};

static inline BOOL RgbEq_0219d9fc(FieldState *g, RgbEq_0219d9fcSelf *self) {
    BOOL e = FALSE;
    if (g->unk_ca.c[0] == self->unk_772 && g->unk_ca.c[1] == self->unk_773 && g->unk_ca.c[2] == self->unk_774) {
        e = TRUE;
    }
    return e;
}

static inline void Flash_0219d9fc(u8 *m, u16 a, u16 b, s32 n) {
    if (n != 0) {
        LFLD(u16, m, 0xb6) = a;
        LFLD(u16, m, 0xb8) = b;
        LFLD(u16, m, 0xba) = n + 1;
        LFLD(u16, m, 0xbc) = n;
    }
}

BOOL Robo021ca458_Draw(Robo021ca458 *self) {
    u32 fl;
    u8 *m;
    u8 v;
    s32 n;
    u8 *a;
    u8 lvl;
    u16 ca;
    u16 cb;
    s32 h;

    if (self->unk_b28_3) {
        return FALSE;
    }
    func_ov000_02191ec4(((void *)self->unk_3c), 1, self->unk_48->unk_54);
    m = ((u8 *)self->model);
    v = LFLD(u8, m, 0xbf);
    if (self->unk_48->unk_54 & 0x80000) {
        if (B24(self).b20) {
            if (v > 5) {
                LFLD(u8, m, 0xbf) = v - 3;
            }
        } else {
            LFLD(u8, m, 0xbf) = 5;
            B24(self).b20 = 1;
        }
    } else {
        if (B24(self).b20) {
            if (v < 0x1f) {
                LFLD(u8, m, 0xbf) = v + 1;
            }
        } else {
            LFLD(u8, m, 0xbf) = 0x1f;
            B24(self).b20 = 1;
        }
    }

    lvl = 0x1f;
    {
        u16 w = LFLD(u16, ((u8 *)self->hp), 0xa);
        n = 0;
        if (w != 0) {
            if (self->model->unk_ba == 0) {
                u16 k;
                n = 1;
                cb = ca = 0x53ff;
                if (w > 0x3c) {
                    k = w & 0xf;
                } else {
                    k = w & 7;
                    if (w <= 0x1e) {
                        k = w & 3;
                    }
                }
                lvl = 0x1e;
                if (k != 0) {
                    lvl = 0x14;
                }
            }
        } else if (B24(self).b0) {
            cb = ca = 0x3def;
            lvl = 0x1e;
            n = 1;
        } else if (B22(self).b3 && IsIdle_0219d9fc(data_ov000_021ccd54)) {
            if (!(LFLD(u16, data_ov000_021ccd68, 0xa) & 0x3f)) {
                ca = 0x63fc;
                cb = 0x5ad4;
                n = 0x40;
            }
        } else if (B2C(self).b6) {
            if (self->unk_40->current == 0x16) {
                cb = ca = 0x729c;
                n = 1;
            }
        } else if (B2C(self).b3) {
            cb = ca = 0x7e90;
            n = 1;
        }
    }
    if (n != 0) {
        u8 *fm = ((u8 *)self->model);
        LFLD(u16, fm, 0xb6) = ca;
        LFLD(u16, fm, 0xb8) = cb;
        LFLD(u16, fm, 0xba) = n + 1;
        LFLD(u16, fm, 0xbc) = n;
    }
    self->model->alpha = lvl;
    if (B24(self).b1) {
        if (B22(self).b0 && ((u8 *)self->unk_998) != NULL) {
            Flash_0219d9fc(((u8 *)self->unk_998), ca, cb, n);
            LFLD(u8, ((u8 *)self->unk_998), 0xbe) = lvl;
        }
    } else if (B24(self).b21) {
        if (n != 0) {
            self->unk_82e = ca;
            self->unk_830 = cb;
            self->unk_832 = n + 1;
            self->unk_834 = n;
        }
        self->unk_836 = lvl;
    }

    {
    s32 res = 0;
    s32 off = self->unk_64;
    u8 alpha = Begin_0219d9fc();
    if (B24(self).b2) {
        VEC(self, 0x3e0) = VEC(self, 0x75c);
        func_ov000_02190758((u8 *)self + 0x368, (u8 *)self + 0x76c, 1);
        self->unk_426 = 0x1f;
        self->unk_429 = alpha;
        if (func_ov000_021903b4((u8 *)self + 0x368)) {
            res = 1;
        }
        VEC(self, 0x124) = VEC(self, 0x70);
        func_ov000_02190758(&self->unk_ac, (u8 *)self + 0x7c, 1);
        self->unk_16d = alpha;
        func_ov000_021903b4(&self->unk_ac);
        h = self->unk_338;
    } else {
    if (B24(self).b1) {
        VecFx32 p;
        if ((u32)(B24(self).b5 - 1) <= 1) {
            s32 f = B24(self).b7;
            if (f == 1) {
                self->unk_ae4 |= 2;
            } else if (f == 0) {
                self->unk_ae4_0 = 1;
            } else {
                self->unk_ae4 |= 2;
                self->unk_ae4_0 = 1;
            }
        }
        if (B22(self).b0) {
            self->unk_ae4 |= 4;
        }
        if (self->unk_ae4 != 0) {
            self->unk_3b8 = (u8 *)self + 0xa50;
            NNS_G3dRenderObjSetInitFunc((u8 *)self + 0x38c, (void *)func_ov003_021ce9ac);
            LFLD(u16, self, 0x42a) |= 0x20;
        }
        p = VEC(self, 0x75c);
        if (B24(self).b12) {
            a = (u8 *)FindActor_0219d9fc(self->unk_b20);
            u8 *s;
            if (a != NULL && (s = LFLD(u8 *, a, 0x4c)) != NULL) {
                s16 *e = (s16 *)(data_ov000_021ca320 + LFLD(u16, s, 6) * 0x18);
                VecFx32 o;
                o.x = e[1];
                o.y = e[2];
                o.z = e[3];
                VEC_Add(&p, &o, &p);
            }
        }
        VEC(self, 0x3e0) = p;
        func_ov000_02190758((u8 *)self + 0x368, (u8 *)self + 0x76c, 1);
        self->unk_429 = alpha;
        if (func_ov000_021903b4((u8 *)self + 0x368)) {
            res = 1;
        }
        h = self->unk_72c;
        if (!B22(self).b3) {
            off = off * 2 - (off >> 2);
        } else {
            off <<= 1;
        }
        if (B24(self).b5) {
            func_ov000_021b4130(self, res != 0 ? TRUE : FALSE);
        }
    } else {
        if (!PadB9_0219d9fc() && RgbEq_0219d9fc(data_ov000_021ccd54, (RgbEq_0219d9fcSelf *)self)) {
            VEC(self, 0x3e0) = VEC(self, 0x75c);
            func_ov000_02190758((u8 *)self + 0x368, (u8 *)self + 0x76c, 1);
            self->unk_426 = 0x1f;
            self->unk_429 = alpha;
            if (B22(self).b0) {
                self->unk_ae4 |= 4;
                self->unk_3b8 = (u8 *)self + 0xa50;
                NNS_G3dRenderObjSetInitFunc((u8 *)self + 0x38c, (void *)func_ov003_021ce9ac);
                LFLD(u16, self, 0x42a) |= 0x20;
            }
            if (func_ov000_021903b4((u8 *)self + 0x368)) {
                res = 1;
            }
        } else {
            res = -1;
        }
        if (B24(self).b21) {
            LFLD(Bit0_0219d9fc, self, 0xa4c).b0 = 1;
            self->unk_fc = (u8 *)self + 0x9b8;
            NNS_G3dRenderObjSetInitFunc((u8 *)self + 0xd0, (void *)func_ov003_021ce9ac);
            LFLD(u16, self, 0x16e) |= 0x20;
        }
        if (!B93(self).b0) {
            VEC(self, 0x124) = VEC(self, 0x70);
            func_ov000_02190758(&self->unk_ac, (u8 *)self + 0x7c, 1);
        }
        self->unk_16d = alpha;
        if (func_ov000_021903b4(&self->unk_ac) && B24(self).b21) {
            VEC(self, 0x7f0) = VEC(self, 0x9dc);
            MI_Copy36B((u8 *)self + 0x9b8, (u8 *)self + 0x7fc);
            self->unk_839 = alpha;
            func_ov000_021903b4((u8 *)self + 0x778);
        }
        h = self->unk_338;
        if (B24(self).b5) {
            Actor *a = FindActor_0219d9fc(self->unk_b1c);
            if (a != NULL) {
                u8 *s = ((u8 *)a->unk_4c);
                s32 q[3];
                LFLD(u16, s, 0x1c) = self->id;
                q[0] = self->pos.x;
                q[1] = self->pos.y;
                q[2] = self->pos.z;
                q[1] += self->unk_6c;
                VEC(s, 0x44) = *(VecFx32 *)q;
            }
        }
    }
    {
        FieldState *g = data_ov000_021ccd54;
        if (IsIdle_0219d9fc(g) && !HasD4B_0219d9fc(g)) {
            func_ov000_021bd7a0(self->unk_5c);
            func_ov000_021bd7a0(self->unk_9b0);
            func_ov000_021bd7a0(self->unk_9b4);
        }
    }
    }
    fl = self->unk_48->unk_54;
    if ((fl & 0xf0f0f0) != 0xe0e000 && (fl & 0x20000) != 0x20000) {
        LFLD(s32, ((void *)self->unk_3c), 0x14) = off;
        LFLD(s32, ((void *)self->unk_3c), 0x10) = self->pos.y - h;
        LFLD(u8, ((void *)self->unk_3c), 0x1a) = alpha;
        if (B93(self).b0 && !B24(self).b1) {
            VecFx32 w;
            w.x = self->unk_124;
            w.y = self->unk_128;
            w.z = self->unk_12c;
            func_ov000_02191c24(((void *)self->unk_3c), &w);
        } else {
            func_ov000_02191c24(((void *)self->unk_3c), &self->pos);
        }
    }
    if (B22(self).b0 && ((u8 *)self->unk_998) != NULL && res >= 0 && self->unk_42a_0) {
        if (res != 0) {
            BOOL set;
            u16 rz;
            u16 ry;
            u16 rx;
            MtxFx33 mm;
            MtxFx33 mt;
            VEC(((u8 *)self->unk_998), 0x78) = VEC(self, 0xad4);
            ry = self->unk_9a8;
            rz = self->unk_9aa;
            rx = self->unk_9a6;
            set = FALSE;
            MTX_Identity33_(&mm);
            if (ry != 0) {
                MTX_RotY33_(&mm, SIN_0219d9fc(ry), COS_0219d9fc(ry));
                set = TRUE;
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&mt, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotX33_(&mm, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    set = TRUE;
                }
            }
            if (rz != 0) {
                if (set) {
                    MTX_RotZ33_(&mt, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotZ33_(&mm, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                }
            }
            MTX_Concat33(&mm, (const MtxFx33 *)((u8 *)self + 0xab0), &mm);
            MI_Copy36B(&mm, ((u8 *)self->unk_998) + 0x84);
            LFLD(u8, ((u8 *)self->unk_998), 0xc1) = alpha;
            func_ov000_021903b4(((u8 *)self->unk_998));
        }
        if (self->unk_9ac < self->unk_9ae) {
            if (B24(self).b1) {
                u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
                if (o != NULL && LFLD(void *, o, 0x6c) != NULL) {
                    func_ov000_02167fac(LFLD(void *, o, 0x6c), self->unk_9ac, self->unk_9ae);
                }
            }
        }
    }
    }
    return TRUE;
}
}
