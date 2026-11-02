#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/FieldState.h"
#include "Main/Res/StageFlags.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/FieldMgr.h"
// Mini-map markers: quest targets, visible actors and point markers.
#define ABS021675ec(x) ((x) < 0 ? -(x) : (x))

typedef struct {
    u32 y : 8;
    u32 a0_8 : 6;
    u32 shape : 2;
    u32 x : 9;
    u32 a1_25 : 5;
    u32 size : 2;
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 a2 : 16;
} Oam021675ec;

typedef struct {
    s32 x;
    s32 y;
} Pos021675ec;

typedef struct {
    u8 kind;
    u8 pad;
    u16 id;
} Ent021675ec;

// The map centre is a class with a constructor. MWCC keeps such an object on the stack
// (stored once, reloaded before the later loops); a plain struct was split into registers.
struct Ctr021675ec : Pos021675ec {
    Ctr021675ec(s32 a, s32 b) {
        x = a;
        y = b;
    }
};

extern "C" {

extern void *data_ov000_021ccd64;
// In .rodata; declaring it const lets the 0x74 copy load both words before either store.
extern const u8 data_ov000_021c9a9c[];
Robo021ca458 *func_ov000_0219bf90(void);
void *func_0203bbfc(void *sys, int which);
s32 func_ov000_0218c040(void *mgr, s32 max, VecFx32 *out, s32 kind, u16 id);
BOOL NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);


static inline BOOL FieldState_HasCmd(FieldState *q, s32 kind) {
    s32 i;
    for (i = q->head; i != q->tail;) {
        if (q->queue[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline void AddPos021675ec(const Pos021675ec *a, const Pos021675ec *b, Pos021675ec *o) {
    o->x = a->x + b->x;
    o->y = a->y + b->y;
}

static inline void Sub021675ec(Pos021675ec *o, const Pos021675ec *a, const Pos021675ec *b) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
}

static inline BOOL ToMap021675ec(Pos021675ec *m, s32 x, s32 z, const Ctr021675ec *c) {
    m->x = x;
    m->y = z;
    Sub021675ec(m, m, c);
    m->x = LO_FX_MUL(m->x, 0x800);
    m->y = LO_FX_MUL(m->y, 0x800);
    if (ABS021675ec(m->x) > 0x80000 || ABS021675ec(m->y) > 0x40000) {
        return FALSE;
    }
    {
        Pos021675ec v;
        v.x = 0;
        v.y = 0x8000;
        AddPos021675ec(m, &v, m);
    }
    return TRUE;
}

static inline void SetPos021675ec(Oam021675ec *e, u16 x, u16 y) {
    e->x = x;
    e->y = y & 0x1ff;
}

typedef struct {
    u8 a : 2;
    u8 b : 1;
} Flags021675ec;

static inline BOOL Vis021675ec(FieldProp *o) {
    return o->loader.flag8 == 1 ? TRUE : FALSE;
}

static inline BOOL Bit2_021675ec(Robo021ca458 *pl) {
    return pl->unk_b28_2 == 1 ? TRUE : FALSE;
}

struct Obj021675ec {
    u8 unk_00[0x24];
    Model *unk_24;
};

void func_ov000_021675ec(Obj021675ec *self, u8 *w) {
    u16 k;
    VecFx32 pos;
    FieldProp *o;
    VecFx32 pts[8];
    Robo021ca458 *pl;
    s32 j;
    Ent021675ec *ents;
    void *oam;
    BOOL skip;
    u32 i;

    skip = FALSE;
    if (func_ov000_0219bf90() == NULL) {
        skip = TRUE;
    }
    if (FieldState_HasCmd(data_ov000_021ccd54, 9) || FieldState_HasCmd(data_ov000_021ccd54, 10)) {
        skip = TRUE;
    }
    if (skip) {
        return;
    }
    oam = func_0203bbfc(data_02097d48, 1);
    pl = func_ov000_0219bf90();
    Ctr021675ec c(pl->pos.x, pl->pos.z);
    Pos021675ec m;
    ents = (Ent021675ec *)data_0214a424->slots;
    w[2] = 0;
    for (i = 0; i < 2; i++) {
        if (ents[i].kind == 2) {
            u16 id = ents[i].id;
            if (func_ov000_0218c040(data_ov000_021ccd64, 1, &pos, id >> 12, id) && ToMap021675ec(&m, pos.x, pos.z, &c)) {
                u8 n = w[2]++;
                Oam021675ec *e = &((Oam021675ec *)(w + 0x64c))[n];
                LFLD(u32, e, 0) = LFLD(u32, w, 0x1c);
                LFLD(u32, e, 4) = LFLD(u32, w, 0x20);
                m.x = (m.x >> 12) + 0x7c;
                m.y = (m.y >> 12) + 0x54;
                if (m.x < 8 || m.x > 0xf8 || m.y < 8 || m.y > 0xb8) {
                    SetPos021675ec(e, 0, 0xc0);
                } else {
                    SetPos021675ec(e, m.x, m.y);
                }
                LFLD(u32, e, 0) = (LFLD(u32, e, 0) & ~0xc000c000) | 0x40000000;
                e->pal = LFLD(s8 *, w, 0xc90)[((u32)(u16)LFLD(u32, w, 0x30) >> 12) - 2];
            }
        }
    }
    if (w[2] != 0 && LFLD(s32, w, 0xcd8) > 0x800) {
        NNS_G2dEntryOamManagerOam(oam, w + 0x64c, w[2]);
    }
    if (pl->unk_b28_0 == 0 && !Bit2_021675ec(pl) && w[0] == 0) {
        LFLD(Pos021675ec, self->unk_24, 0x10c) = LFLD(const Pos021675ec, data_ov000_021c9a9c, 0x74);
        Model_PlayPartF(self->unk_24, 3, 0);
        NNS_G2dEntryOamManagerOam(oam, w + 0x14, 1);
    }
    for (o = data_ov000_021ccd6c->head; o != NULL; o = o->next) {
        if (Vis021675ec(o)) {
            s32 ox = o->model.trans.x;
            s32 oz = o->model.trans.z;
            u8 *a = LFLD(u8 *, o->model.rob, 4);
            s32 sx;
            s32 sy;
            a = a != NULL ? a + 0x14 : NULL;
            sx = LO_FX_MUL(LFLD(s16, a, 0x1e), LFLD(s32, a, 0x24));
            sy = LO_FX_MUL(LFLD(s16, a, 0x22), LFLD(s32, a, 0x24));
            if (ToMap021675ec(&m, ox, oz, &c)) {
                k = 4;
                if (sx >= 0x1e000) {
                    k++;
                }
                if (sy >= 0x1e000) {
                    k += 2;
                }
                LFLD(Pos021675ec, self->unk_24, 0x10c) = m;
                Model_PlayPartF(self->unk_24, k, 0);
            }
        }
    }
    for (j = func_ov000_0218c040(data_ov000_021ccd64, 8, pts, 4, 0x406b) - 1; j >= 0; j--) {
        if (ToMap021675ec(&m, pts[j].x, pts[j].z, &c)) {
            LFLD(Pos021675ec, self->unk_24, 0x10c) = m;
            Model_PlayPartF(self->unk_24, 4, 0);
        }
    }
    MTX_Identity22_(&self->unk_24->mtx[2]);
}

}
