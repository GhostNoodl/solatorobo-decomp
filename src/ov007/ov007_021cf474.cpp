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
void *SndMgr_PlayVolume(void *a, int b, int c, int d, int e);
BOOL Model021903b4_Draw(void *a);
void *func_02070dcc(int kind);

}

#define OV007_SINCOS ((const s16 *)((const u8 *)func_02070dcc + 0x294))

static inline s32 Ov007_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ov007_DrawMdl(Model *m) {
    ModelPart *anim;
    ModelRes *res = m->res;
    void *arg;
    ModelPartRes *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (m->numParts > 0) {
        anim = m->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        Ov007SprSeq *e = (Ov007SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **e->unk_0c);
    }
    TexObj_DrawCell(m, arg, anim, 0);
}

static inline void Ov007_SetOfs(Model *m, s32 x, s32 y) {
    m->x = x;
    m->y = y;
}

static inline void Ov007_SetToon(Gfx3DState *st, const u16 *tbl) {
    st->shading = 0;
    *(vu16 *)0x4000060 = *(vu16 *)0x4000060 & ~0x3002;
    if (tbl != NULL) {
        MIi_CpuCopyFast(tbl, st->toonTable, 0x40);
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
    Gfx3DState *st;
    s32 y;
    if (Ov007_FadeDone()) {
        return;
    }
    if (s->cam == NULL) {
        return;
    }
    st = (Gfx3DState *)data_02097d48->unk_8b0;
    {
        Ov007Lights l = data_ov007_021cfa3c;
        Ov007Light *v = &l.v[s->unk_4c - 1];
        Ov007_SetToon(st, data_ov007_021cfa98[s->unk_4c - 1]);
        NNS_G3dGlbLightVector(GX_LIGHTID_0, v->x, v->y, v->z);
    }
    s->cam->v00();
    Model021903b4_Draw(s->unk_30);
    Model021903b4_Draw(s->unk_34);
    if (s->unk_38 != NULL) {
        Model021903b4_Draw(s->unk_38);
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
                    SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
                }
            } else if (snd == 2) {
                if (s->unk_4f & (1 << i)) {
                    s->unk_4f &= (u8)~(1 << i);
                    SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
                }
            }
        }
        if (alpha != 0) {
            if (i == s->unk_64) {
                s->unk_2c->flags |= 0x80000;
                MODEL_FLAGS(s->unk_2c)->polygon_id = Gfx3DState_NextPolyId(st);
                MODEL_FLAGS(s->unk_2c)->alpha = alpha;
                Ov007_SetOfs(s->unk_2c, off, y);
                s->unk_2c->unk_150 = -0x2ccd;
                Ov007_DrawMdl(s->unk_2c);
            }
            {
                s32 w = s->wins[i]->width;
                s->wins[i]->unk_vf14();
                s->wins[i]->unk_4_13 = Gfx3DState_NextPolyId(st); // polygon id
                s->wins[i]->unk_4_8 = alpha;
                s->wins[i]->unk_vf20(0x80 - (w >> 1) + (off >> 12), x);
                s->wins[i]->Render();
            }
        }
        x += 0x10;
    }
}

}
