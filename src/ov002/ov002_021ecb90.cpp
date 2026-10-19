#include "ov002/ov002.h"

typedef struct ov002_TagFlags {
    u32 active : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 hit : 1;
    u32 rest : 28;
} ov002_TagFlags;

typedef struct ov002_TagDef {
    u8 unk0[8];
    const char *name;
    u8 unkC[2];
    u16 kind;
    u16 mode;
    u16 time;
} ov002_TagDef;

typedef struct ov002_Tag {
    void *vtbl;
    ov002_TagFlags flags;
    s32 state;
    s32 next;
    s32 unk10;
    s32 timer;
    s32 prevTimer;
    s32 step;
    ov002_TagDef *def;
    s32 id;
    u8 unk28[8];
    struct ov002_Tag *link;
    u8 unk34[0x14];
    u8 alpha;
    u8 maxAlpha;
} ov002_Tag;

typedef struct ov002_TagConfig {
    u8 unk0[0x30];
    s32 time;
    s32 fadeOut;
    s32 fadeIn;
} ov002_TagConfig;

extern "C" {

int STD_CompareString(const char *a, const char *b);

static inline BOOL ov002_Tag_IsActive(ov002_Tag *t) {
    return t->flags.active == 1 ? TRUE : FALSE;
}

static inline BOOL ov002_Tag_IsHit(ov002_Tag *t) {
    return t->flags.hit == 1 ? TRUE : FALSE;
}

static inline s32 ov002_Tag_Sin(s32 t) {
    if (t >= 0x1000) {
        t = 0x1000;
    }
    return FX_SinCosTable_[((t << 14) >> 16) * 2];
}

static inline BOOL ov002_Tag_Crossed(ov002_Tag *t, s32 time) {
    if (t->timer >= time && time > t->prevTimer) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov002_021ecb90(ov002_Tag *self) {
    BOOL result = TRUE;
    ov002_Tag *p;

    switch (self->def->kind) {
    case 0:
        if (self->state == 3) {
            self->alpha = FX_MUL(self->maxAlpha << 12, 0x1000 - ov002_Tag_Sin(FX_Div(self->timer, ((ov002_TagConfig *)data_ov002_021f0d88)->fadeOut))) >> 12;
            if (self->alpha == 0) {
                result = FALSE;
                break;
            }
        } else {
            self->alpha = FX_MUL(self->maxAlpha << 12, ov002_Tag_Sin(FX_Div(self->timer, ((ov002_TagConfig *)data_ov002_021f0d88)->fadeIn))) >> 12;
        }
        result = TRUE;
        break;
    case 1:
        for (p = (ov002_Tag *)data_ov002_021f0fa0[8]; p != NULL; p = p->link) {
            if (ov002_Tag_IsActive(p) && p != self) {
                if (self->def->name != NULL && p->def->name != NULL) {
                    if (STD_CompareString(self->def->name, p->def->name) == 0) {
                        break;
                    }
                } else if (self->id == p->id) {
                    break;
                }
            }
        }
        if (p != NULL) {
            p->flags.hit = 1;
        }
        return FALSE;
    }
    if (self->state == 3) {
        return result;
    }
    switch (self->def->mode) {
    case 0: {
        s32 t = self->def->time;
        if (t == 0) {
            t = ((ov002_TagConfig *)data_ov002_021f0d88)->time;
        }
        if (ov002_Tag_Crossed(self, t << 12)) {
            self->flags.hit = 1;
        }
        break;
    }
    case 1:
        break;
    case 2:
        for (p = (ov002_Tag *)data_ov002_021f0fa0[8]; p != NULL; p = p->link) {
            if (ov002_Tag_IsActive(p) && p != self) {
                if (!ov002_Tag_IsHit(p)) {
                    self->flags.hit = 1;
                    break;
                }
            }
        }
        break;
    case 3:
        for (p = (ov002_Tag *)data_ov002_021f0fa0[8]; p != NULL; p = p->link) {
            if (ov002_Tag_IsActive(p) && p != self && p->id == self->id) {
                if (!ov002_Tag_IsHit(p)) {
                    self->flags.hit = 1;
                    break;
                }
            }
        }
        break;
    }
    if (ov002_Tag_IsHit(self) && self->state != 3) {
        self->next = 3;
    }
    return result;
}

}
