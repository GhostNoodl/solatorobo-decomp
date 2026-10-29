#include "types.h"

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))

class Ov003VObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
};

typedef struct {
    u8 unk_00[0x24];
    s32 unk_24;
    u8 unk_28[0x14];
    Ov003VObj *unk_3c;
    Ov003VObj *unk_40;
    void *unk_44;
    void *unk_48;
    void *unk_4c;
    u8 unk_50[0xc];
    s32 unk_5c;
    u8 unk_60[6];
    u16 unk_66;
    u8 unk_68;
    u8 unk_69;
} Ov003Menu2;

extern "C" {

void *NNS_G2dGetAnimSequenceByIdx(void *a, u16 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

static inline void *Ov003_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void Ov003_Model_PlayPart(void *model, u16 idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov003_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 1);
}

static inline void Ov003_Model_PlayPartChk(void *model, u16 idx) {
    void *res;
    void *part;
    void *anim;
    if (FIELD(model, 0x28, void *) == NULL) {
        return;
    }
    res = FIELD(model, 0x28, void *);
    part = Ov003_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 1);
}

void func_ov003_021cd744(Ov003Menu2 *self) {
    u16 i;
    u16 count;
    u16 mask;
    if (self->unk_24 == 0) {
        return;
    }
    self->unk_3c->v20();
    if (self->unk_40 != NULL) {
        self->unk_40->v20();
    }
    Ov003_Model_PlayPart(self->unk_44, (u16)self->unk_5c);
    mask = self->unk_66;
    count = (u32)self->unk_69;
    for (i = 0; i < count; i++) {
        if (i == self->unk_5c) {
            continue;
        }
        if (mask & (1 << i)) {
            Ov003_Model_PlayPartChk(self->unk_48, i);
        } else {
            Ov003_Model_PlayPartChk(self->unk_4c, i);
        }
    }
}

}

#ifdef NONMATCHING
// func_ov003_021cd91c (0x98c bytes, the result-card task's per-frame update): 44 raw (bgQ/pmC draft,
// first time in the tree, round bgY). This file's .text ends at 0x021cd91c, so the function belongs
// here once it matches. Ov003CdTask is the same object as Ov003Menu2 above (unk_3c..unk_69 agree).
// Of the 44 lines, 7 are bl/blx (Thumb MTX_ callees, a link-time difference). The real misses:
// - case 10: the alpha byte's register (ROM r0, ours sl) and the unk44 reload order around the two
//   bit-field stores (the spr local is the best form found: without it 48);
// - case 10: `state = timer = 0x14` stores vs `mov r1, #0x26` (round pmB: all 210 orders, pressure);
// - Ov003Cd_Color (twice): pressure-mode picks in the 64-bit products (round bgW). FX_Mul,
//   FX_SinIdx, GX_RGB, FX_Whole and either g/b order compile identically (round bgY).
// Round bgY: the window in case 0x28 written as an inline, or as `new` of a C++ class whose base and
// derived constructors each call the virtual at 0x28 (indirect, as in the ROM), gives 51: the result
// and the res pointer swap registers (ROM res r8 / w r6). Written in place it is 44.
#include "nitro/fx.h"
#include "ov000/VObj.h"

#define OV003_VCALL(obj, off, ...) (((VObj *)(obj))->vfunc_##off(__VA_ARGS__))

typedef struct Ov003CdPad {
    u8 unk0[0x12];
    u16 trig;
} Ov003CdPad;

typedef struct Ov003CdSprite {
    u8 unk0[0x6c];
    u32 unk6C_0 : 2;
    u32 alpha : 5;
    u32 unk6C_7 : 25;
    u8 unk70[0x8c];
    fx32 x;
    fx32 y;
    u8 unk104[0x10];
    MtxFx22 mtx;
} Ov003CdSprite;

typedef struct Ov003CdBits {
    u8 unk0[0xb8];
    u32 b0 : 1;
    u32 rest : 31;
} Ov003CdBits;

typedef struct Ov003CdScene {
    u8 unk0[0xc];
    u32 flags;
    u8 unk10[0x28];
    s32 unk38;
    u8 unk3C[0x48];
    Ov003CdBits *unk84;
} Ov003CdScene;

typedef struct Ov003CdWin {
    void *vtbl;
    int state;
    void *owner;
    u32 flags;
} Ov003CdWin;

typedef struct Ov003CdHeap {
    void *current;
    u8 unk4[4];
    void *unk8;
} Ov003CdHeap;

typedef struct Ov003CdTask {
    void *vtbl;
    u8 unk4[0x38];
    Ov003CdScene *unk3C;
    Ov003CdWin *unk40;
    Ov003CdSprite *unk44;
    Ov003CdSprite *unk48;
    Ov003CdSprite *unk4C;
    u8 unk50[0xc];
    s32 unk5C;
    u8 unk60[8];
    u8 unk68;
    u8 unk69;
    s32 state;
    s32 timer;
    VecFx32 pos;
    VecFx32 ofs;
} Ov003CdTask;

extern "C" {

extern Ov003CdPad *data_02097dc8;
extern void *data_02097e4c;
extern void *data_02149ef8;
extern Ov003CdHeap *data_02097dd0;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
s32 func_02049130(s32 t, s32 a, s32 b);
BOOL func_02049244(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist);
s32 func_02049bdc(void *a, s32 b, s32 c);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_02041c18(void *m, u16 c);
void func_02041c20(void *m, u16 a, u16 b);
void func_02041c5c(void *m, void *fn);
void *func_0203dd9c(u32 size);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov003_021cce20(void);

static inline void Ov003Cd_SetSprite(Ov003CdSprite *o, const VecFx32 *p, fx32 s, u16 ang) {
    MtxFx22 r;
    MTX_Identity22_(&o->mtx);
    o->x = p->x;
    o->y = p->y;
    MTX_ScaleApply22(&o->mtx, &o->mtx, s, s);
    MTX_Rot22_(&r, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    MTX_Concat22(&r, &o->mtx, &o->mtx);
}

static inline u16 Ov003Cd_Color(Ov003CdTask *self) {
    fx32 t = FX_Div(self->timer << 12, 0x28000);
    s32 s = FX_SinCosTable_[(FX_Mul(t, 0x7fff000) >> 16) * 2];
    fx64 pg = (fx64)s * 0xb000;
    u8 g;
    u8 b;
    g = ((fx32)((pg + 0x800) >> 12) + 0x14000) >> 12;
    b = FX_Mul(s, 0x1f000) >> 12;
    return g | (g << 5) | (b << 10);
}

void func_ov003_021cd91c(Ov003CdTask *self) {
    VecFx32 v1;
    VecFx32 zero;
    VecFx32 v2;
    u16 trig = data_02097dc8->trig;
    self->pos.x = func_02049130(self->unk3C->unk38, 0xff000, 0);
    self->pos.y = -0xe000;
    self->pos.z = 0;
    switch (self->state) {
    case 0:
        self->unk44->alpha = 0x1f;
        self->unk48->alpha = 0;
        self->unk4C->alpha = 0;
        self->ofs.x = self->unk5C % 2 != 0 ? -0x40000 : 0x40000;
        self->ofs.y = self->unk5C >= 2 ? -0x30000 : 0x30000;
        self->ofs.z = 0;
        self->timer = 0x3c;
        func_02049bdc(data_02097e4c, 0x87, 5);
        self->state++;
    case 1:
        Ov003Cd_SetSprite(self->unk48, &self->pos, 0x99a, 0);
        Ov003Cd_SetSprite(self->unk4C, &self->pos, 0x99a, 0);
        VEC_Add(&self->ofs, &self->pos, &v1);
        Ov003Cd_SetSprite(self->unk44, &v1, 0x1000, 0);
        if (--self->timer < 0) {
            self->timer = 0x14;
            self->state = 10;
        }
        break;
    case 10: {
        fx32 t = FX_Div(self->timer << 12, 0x14000);
        fx32 s;
        u8 a = func_02049130(t, 0x1f000, 0) >> 12;
        Ov003CdSprite *spr = self->unk44;
        self->unk48->alpha = a;
        self->unk4C->alpha = a;
        func_02041c5c(spr, (void *)func_ov003_021cce20);
        zero.x = 0;
        zero.y = 0;
        zero.z = 0;
        if (func_02049244(&self->ofs, 0x19a, &self->ofs, &zero, 0x19a)) {
            if (self->unk68 != self->unk69) {
                self->state = 0x1e;
                self->timer = 0x28;
            } else {
                self->state = 0x14;
                self->timer = 0x14;
                func_02049bdc(data_02097e4c, 0x26, -2);
            }
        }
        s = func_02049130(t, 0x99a, 0x1000);
        VEC_Add(&self->ofs, &self->pos, &v2);
        Ov003Cd_SetSprite(self->unk44, &v2, s, 0);
        if (--self->timer < 0) {
            self->timer = 0;
        }
        break;
    }
    case 0x14: {
        fx32 t = FX_Div(self->timer << 12, 0x14000);
        u8 a = func_02049130(t, 0, 0xa000) >> 12;
        u8 b = func_02049130(t, 0, 0xa000) >> 12;
        u16 c = b | (a << 8);
        func_02041c18(self->unk44, c);
        func_02041c18(self->unk48, c);
        func_02041c18(self->unk4C, c);
        if (--self->timer < 0) {
            self->state = 0x1e;
            self->timer = 0x28;
        }
        break;
    }
    case 0x1e:
        if (self->unk68 != self->unk69) {
            func_02041c20(self->unk44, self->unk5C, Ov003Cd_Color(self));
        }
        if (--self->timer < 0) {
            self->timer = 0x28;
            self->state++;
        }
        break;
    case 0x1f:
        if (self->unk68 != self->unk69) {
            func_02041c20(self->unk44, self->unk5C, Ov003Cd_Color(self));
        }
        if (--self->timer < 0) {
            self->timer = 0x28;
        }
        if (self->unk3C != NULL && !(self->unk3C->flags & 0x80000)) {
            self->unk3C->unk84->b0 = 1;
        }
        if (trig & 3) {
            if (self->unk68 == self->unk69) {
                self->state = 0x28;
            } else {
                self->state = 0x32;
            }
        }
        break;
    case 0x28: {
        Ov003CdWin *w;
        void *res = data_02149ef8;
        w = (Ov003CdWin *)func_0203dd9c(0xe8);
        if (w != NULL) {
            w->vtbl = &data_ov000_021cac60;
            OV003_VCALL(w, 28);
            w->vtbl = &data_ov000_021cad50;
            OV003_VCALL(w, 28);
        }
        self->unk40 = w;
        func_ov000_0215c1bc(self->unk40, 0x11, func_0204c0e8(res, 0x5d));
        self->unk40->flags &= ~0x10000;
        OV003_VCALL(self->unk40, 08);
        OV003_VCALL(self->unk40, 70);
        self->state++;
    }
    case 0x29:
        if (--self->timer < 0) {
            self->timer = 0x28;
        }
        OV003_VCALL(self->unk40, 1c);
        if (!(self->unk40->state == 5 ? TRUE : FALSE)) {
            break;
        }
        {
            void *saved = data_02097dd0->current;
            data_02097dd0->current = data_02097dd0->unk8;
            if (self->unk40 != NULL) {
                if (self->unk40 != NULL) {
                    OV003_VCALL(self->unk40, 04);
                }
                self->unk40 = NULL;
            }
            data_02097dd0->current = saved;
        }
        self->state = 0x32;
        break;
    case 0x32:
        self->unk3C->flags |= 2;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        OV003_VCALL(self, 0c, 0);
        self->state++;
    case 0x33:
        Ov003Cd_SetSprite(self->unk44, &self->pos, 0x99a, 0);
        Ov003Cd_SetSprite(self->unk48, &self->pos, 0x99a, 0);
        Ov003Cd_SetSprite(self->unk4C, &self->pos, 0x99a, 0);
        break;
    }
}
}
#endif
