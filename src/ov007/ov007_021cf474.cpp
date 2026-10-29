#include "ov007/ov007.h"

struct Ov007Light {
    s16 x;
    s16 y;
    s16 z;
};

struct Ov007Lights {
    Ov007Light v[3];
};

struct Ov007Mdl6c2 {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 pid : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 rest : 12;
};

struct Ov007Spr4 {
    u32 b0 : 8;
    u32 alpha : 5;
    u32 pid : 8;
    u32 rest : 11;
};

extern "C" {

extern const Ov007Lights data_ov007_021cfa3c;
extern const u16 data_ov007_021cfa98[][0x20];
extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
void G3X_SetToonTable(const void *p);
void NNS_G3dGlbLightVector(int light, int x, int y, int z);
BOOL func_ov000_021903b4(void *a);
s32 FX_Div(s32 a, s32 b);
void *func_02070dcc(void);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

}

#define OV007_SINCOS ((const s16 *)((const u8 *)func_02070dcc + 0x294))

static inline s32 Ov007_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ov007_DrawMdl(void *m) {
    void *anim;
    void *res = FLD(void *, m, 0x28);
    void *arg;
    void *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, m, 0x80) > 0) {
        anim = FLD(void *, m, 0x78);
    }
    if (anim != NULL && (t = FLD(void *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(m, arg, anim, 0);
}

static inline void Ov007_SetOfs(void *m, s32 x, s32 y) {
    FLD(s32, m, 0xfc) = x;
    FLD(s32, m, 0x100) = y;
}

static inline void Ov007_SetToon(u8 *st, const u16 *tbl) {
    FLD(s32, st, 0x38) = 0;
    *(vu16 *)0x4000060 = *(vu16 *)0x4000060 & ~0x3002;
    if (tbl != NULL) {
        MIi_CpuCopyFast(tbl, st + 0x3c, 0x40);
        G3X_SetToonTable(tbl);
    }
}

extern "C" {

void func_ov007_021cf474(Ov007Scene *s) {
    int snd;
    u8 alpha;
    s32 i;
    s32 off;
    s32 x;
    u8 *st;
    s32 y;
    if (Ov007_FadeDone()) {
        return;
    }
    if (s->unk_3c == NULL) {
        return;
    }
    st = data_02097d48 + 0x8b0;
    {
        Ov007Lights l = data_ov007_021cfa3c;
        Ov007Light *v = &l.v[s->unk_4c - 1];
        Ov007_SetToon(st, data_ov007_021cfa98[s->unk_4c - 1]);
        NNS_G3dGlbLightVector(0, v->x, v->y, v->z);
    }
    s->unk_3c->v00();
    func_ov000_021903b4(s->unk_30);
    func_ov000_021903b4(s->unk_34);
    if (s->unk_38 != NULL) {
        func_ov000_021903b4(s->unk_38);
    }
    if (s->unk_28 != NULL) {
        FLD(s32, s->unk_28, 0x150) = -0x3000;
        Ov007_DrawMdl(s->unk_28);
    }
    if (s->unk_2c == NULL) {
        return;
    }
    y = ((s->unk_64 << 4) + 0x3c) << 12;
    snd = -1;
    x = 0x96;
    alpha = 0;
    for (i = 0; i < 2; i++) {
        s32 t = FX_Div(s->unk_54 - (i << 15), 0x18000);
        s32 v;
        if (t <= 0) {
            t = 0;
        } else if (t >= 0x1000) {
            t = 0x1000;
        }
        v = OV007_SINCOS[((t << 14) >> 16) * 2];
        if (s->unk_50 == 1) {
            snd = 1;
            alpha = Ov007_FxMul(v, 0x1f000) >> 12;
            off = Ov007_FxMul(0x1000 - v, 0x30000);
        } else if (s->unk_50 == 2) {
            snd = 2;
            alpha = Ov007_FxMul(0x1000 - v, 0x1f000) >> 12;
            off = Ov007_FxMul(v, -0x30000);
        } else if (s->unk_50 == 3) {
            snd = 1;
            alpha = Ov007_FxMul(v, 0x1f000) >> 12;
            off = Ov007_FxMul(0x1000 - v, -0x30000);
        } else {
            off = 0;
        }
        if ((s->unk_4f & 0x80) && v > 0) {
            if (snd == 1) {
                if (!(s->unk_4f & (1 << i))) {
                    s->unk_4f |= (u8)(1 << i);
                    func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
                }
            } else if (snd == 2) {
                if (s->unk_4f & (1 << i)) {
                    s->unk_4f &= (u8)~(1 << i);
                    func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
                }
            }
        }
        if (alpha != 0) {
            if (i == s->unk_64) {
                FLD(u32, s->unk_2c, 0x6c) |= 0x80000;
                FLD(Ov007Mdl6c2, s->unk_2c, 0x6c).pid = func_02043d48(st);
                FLD(Ov007Mdl6c2, s->unk_2c, 0x6c).alpha = alpha;
                Ov007_SetOfs(s->unk_2c, off, y);
                FLD(s32, s->unk_2c, 0x150) = -0x2ccd;
                Ov007_DrawMdl(s->unk_2c);
            }
            {
                s32 w = FLD(s32, s->unk_5c[i], 0x44);
                s->unk_5c[i]->v14();
                FLD(Ov007Spr4, s->unk_5c[i], 0x4).pid = func_02043d48(st);
                FLD(Ov007Spr4, s->unk_5c[i], 0x4).alpha = alpha;
                s->unk_5c[i]->v20(0x80 - (w >> 1) + (off >> 12), x);
                s->unk_5c[i]->v90();
            }
        }
        x += 0x10;
    }
}

}
