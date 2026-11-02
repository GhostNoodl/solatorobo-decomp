#include "ov007/ov007.h"

struct Ov007Light {
    s16 x;
    s16 y;
    s16 z;
};

struct Ov007Lights {
    Ov007Light v[3];
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
void *func_02070dcc(int kind);
Ov007SprSeq *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

}

#define OV007_SINCOS ((const s16 *)((const u8 *)func_02070dcc + 0x294))

static inline s32 Ov007_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ov007_DrawMdl(Ov007Sprite *m) {
    Ov007SprAnim *anim;
    Ov007SprRes *res = m->unk_28;
    void *arg;
    Ov007SprFrame *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (m->unk_80 > 0) {
        anim = m->unk_78;
    }
    if (anim != NULL && (t = anim->unk_04) != NULL) {
        arg = t->unk_30;
    } else {
        Ov007SprSeq *e = NNS_G2dGetAnimSequenceByIdx(res->unk_0c, 0);
        arg = NNS_G2dGetCellDataByIdx(res->unk_04, **e->unk_0c);
    }
    func_02042628(m, arg, anim, 0);
}

static inline void Ov007_SetOfs(Ov007Sprite *m, s32 x, s32 y) {
    m->unk_fc = x;
    m->unk_100 = y;
}

static inline void Ov007_SetToon(Ov007G3 *st, const u16 *tbl) {
    st->unk_38 = 0;
    *(vu16 *)0x4000060 = *(vu16 *)0x4000060 & ~0x3002;
    if (tbl != NULL) {
        MIi_CpuCopyFast(tbl, st->unk_3c, 0x40);
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
    Ov007G3 *st;
    s32 y;
    if (Ov007_FadeDone()) {
        return;
    }
    if (s->unk_3c == NULL) {
        return;
    }
    st = &data_02097d48->unk_8b0;
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
        s->unk_28->unk_150 = -0x3000;
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
                s->unk_2c->flags |= 0x80000;
                s->unk_2c->attr.pid = Gfx3DState_NextPolyId(st);
                s->unk_2c->attr.alpha = alpha;
                Ov007_SetOfs(s->unk_2c, off, y);
                s->unk_2c->unk_150 = -0x2ccd;
                Ov007_DrawMdl(s->unk_2c);
            }
            {
                s32 w = s->unk_5c[i]->unk_44;
                s->unk_5c[i]->v14();
                s->unk_5c[i]->attr.pid = Gfx3DState_NextPolyId(st);
                s->unk_5c[i]->attr.alpha = alpha;
                s->unk_5c[i]->v20(0x80 - (w >> 1) + (off >> 12), x);
                s->unk_5c[i]->v90();
            }
        }
        x += 0x10;
    }
}

}
