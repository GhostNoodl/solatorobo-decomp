#include "ov002/ov002.h"

extern "C" {

// The staff roll's .bss: the task list head, the staff object, the list tail and the per-kind
// task lists. All of them are reached through the 0x021f0fa0 pool literal plus offsets (a
// constant index into data_ov002_021f0fac as base + 0x20), so they are defined before the first
// function. MWCC lays these three out in the reverse of this order.
void *data_ov002_021f0fa8;
void *data_ov002_021f0fa4;
void *data_ov002_021f0fa0;
void *data_ov002_021f0fac[9];

}

// ---- merged from ov002_021ecb90.cpp
namespace m_021ecb90 {
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
            self->alpha = FX_MUL(self->maxAlpha << 12, 0x1000 - ov002_Tag_Sin(FX_Div(self->timer, data_ov002_021f0d88.tagFadeOut))) >> 12;
            if (self->alpha == 0) {
                result = FALSE;
                break;
            }
        } else {
            self->alpha = FX_MUL(self->maxAlpha << 12, ov002_Tag_Sin(FX_Div(self->timer, data_ov002_021f0d88.tagFadeIn))) >> 12;
        }
        result = TRUE;
        break;
    case 1:
        for (p = (ov002_Tag *)data_ov002_021f0fac[5]; p != NULL; p = p->link) {
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
            t = data_ov002_021f0d88.tagTime;
        }
        if (ov002_Tag_Crossed(self, t << 12)) {
            self->flags.hit = 1;
        }
        break;
    }
    case 1:
        break;
    case 2:
        for (p = (ov002_Tag *)data_ov002_021f0fac[5]; p != NULL; p = p->link) {
            if (ov002_Tag_IsActive(p) && p != self) {
                if (!ov002_Tag_IsHit(p)) {
                    self->flags.hit = 1;
                    break;
                }
            }
        }
        break;
    case 3:
        for (p = (ov002_Tag *)data_ov002_021f0fac[5]; p != NULL; p = p->link) {
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
}  // namespace m_021ecb90

// ---- merged from ov002_021eceb8.cpp
namespace m_021eceb8 {
extern "C" {

typedef struct Bits021eceb8 {
    u32 lo : 2;
    u32 b : 5;
    u32 c : 6;
    u32 hi : 19;
} Bits021eceb8;

static inline bool isMode3(void *self) {
    return FIELD(self, 0x8, s32) == 3;
}

void func_ov002_021eceb8(void *self) {
    s32 x;
    s32 y;
    s32 z;
    void *model;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (FIELD(self, 0x38, void *) == NULL || !FIELD(self, 0x48, u8)) {
        return;
    }
    x = FIELD(self, 0x3c, s32) & -0x1000;
    y = FIELD(self, 0x40, s32) & -0x1000;
    {
        BOOL m3 = isMode3(self);
        if (m3) {
            z = -0x2000;
        } else {
            z = -0x1ccd;
        }
    }
    FIELD(FIELD(self, 0x38, void *), 0x6c, Bits021eceb8).c = (u32)func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x38, void *), 0x6c, Bits021eceb8).b = FIELD(self, 0x48, u8);
    {
        u8 *m = FIELD(self, 0x38, u8 *);
        FIELD(m, 0xfc, s32) = x;
        FIELD(m, 0x100, s32) = y;
    }
    FIELD(FIELD(self, 0x38, void *), 0x150, s32) = z;
    model = FIELD(self, 0x38, void *);
    if ((res = FIELD(model, 0x28, void *)) == NULL) {
        return;
    }
    anim = NULL;
    if (FIELD(model, 0x80, s32) > 0) {
        anim = FIELD(model, 0x78, void *);
    }
    if (anim != NULL && (t = FIELD(anim, 0x4, void *)) != NULL) {
        arg = FIELD(t, 0x30, void *);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), 0);
        arg = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(e, 0xc, void *));
    }
    func_02042628(model, arg, anim, 0);
}

}
}  // namespace m_021eceb8

// ---- merged from ov002_021ecfd8.cpp
namespace m_021ecfd8 {
extern "C" {

void func_ov002_021ecfd8(void *self) {
    FIELD(self, 0x4c, s32) = 0;
}

void func_ov002_021ecfe4(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_WITH(FIELD(self, 0x4c, void *), func_ov000_0214b724);
    HEAP_POP(saved);
}

BOOL func_ov002_021ed03c(void) {
    return TRUE;
}

BOOL func_ov002_021ed044(void *self) {
    switch (FIELD(self, 0x10, s32)) {
    case 0: {
        void *p = func_0203dd9c(0x3c);
        if (p != NULL) {
            p = func_ov000_0214b6d8(p);
        }
        FIELD(self, 0x4c, void *) = p;
        func_ov000_0214b88c(p, data_ov002_021f0d88.photo);
        FIELD(self, 0x10, s32)++;
        break;
    }
    case 1:
        func_ov000_0214b810(FIELD(self, 0x4c, void *));
        if (func_ov000_0214b8d8(FIELD(self, 0x4c, void *))) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL func_ov002_021ed0c0(void *self) {
    if (FIELD(self, 0x10, s32) != 0) {
        return FALSE;
    }
    FIELD(self, 0x24, s32) = FIELD(FIELD(self, 0x20, void *), 0xc, u16);
    FIELD(self, 0x49, u8) = 0x1f;
    return TRUE;
}

static inline BOOL func_ov002_021ed0ec_is3(void *self) {
    return FIELD(self, 8, s32) == 3 ? TRUE : FALSE;
}
void func_ov002_021ed0ec(void *self) {
    if (FIELD(self, 0x4c, void *) == NULL || FIELD(self, 0x48, u8) == 0) {
        return;
    }
    {
        Vec3 b = data_ov002_021ef124;
        Vec3 a;
        a.x = FIELD(self, 0x3c, s32);
        a.y = FIELD(self, 0x40, s32);
        a.z = FIELD(self, 0x44, s32);
        a.x = (a.x & ~0xfff) + 0x80000;
        a.y = (a.y & ~0xfff) + 0x60000;
        if (func_ov002_021ed0ec_is3(self)) {
            a.z = -0x2000;
        } else {
            a.z = -0x1ccd;
        }
        func_ov000_0214b1a0(&a, &b, FIELD(self, 0x48, u8), func_ov000_0214b8ec(FIELD(self, 0x4c, void *)));
    }
}

void func_ov002_021ed1ac(void *self) {
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x38, s32) = 0;
    FIELD(self, 0x3c, s32) = 0;
    FIELD(self, 0x40, s32) = 0;
    FIELD(self, 0x48, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, u8) = 0x1f;
}

void func_ov002_021ed1dc(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x44, VObject *));
    HEAP_POP(saved);
}

}

extern "C" {

extern VFunc data_0208ba70[];
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
char *func_02040ab0(char *s, int c);

typedef struct Ov002Text2 {
    VFunc *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 pad30[0x4];
    s16 unk_34;
    u8 pad36;
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u8 pad50[0x24];
    u16 unk_74;
    u16 unk_76;
    s32 unk_78;
} Ov002Text2;

static inline Ov002Text2 *ov002_021ed270_newText(char *str) {
    Ov002Text2 *t = (Ov002Text2 *)func_0203dd9c(0xb8);
    if (t != NULL) {
        t->vtbl = data_0208ba70;
        func_0204c7d0(t);
    }
    t->unk_28 = 4;
    t->unk_24 = (s32)str;
    t->unk_4c = func_0204c4fc(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
    FIELD(data_02097ce0, 0x4, s32) = t->unk_28;
    return t;
}

static inline void ov002_021ed270_create(void *self, char *str) {
    Ov002Text2 *t;
    char *sub = func_02040ab0(str, '/');
    if (sub) {
        *sub = 0;
        sub++;
    }
    t = ov002_021ed270_newText(str);
    FIELD(self, 0x34, Ov002Text2 *) = t;
    t->flags |= 0x40;
    FIELD(self, 0x34, Ov002Text2 *)->flags |= 0x1000000;
    FIELD(self, 0x34, Ov002Text2 *)->flags |= 4;
    if (sub != NULL) {
        t = ov002_021ed270_newText(sub);
        FIELD(self, 0x44, Ov002Text2 *) = t;
        t->flags |= 0x40;
        FIELD(self, 0x44, Ov002Text2 *)->flags |= 0x1000000;
        FIELD(self, 0x44, Ov002Text2 *)->flags |= 4;
    }
}

void func_ov002_021ed270(void *self) {
    void *info = FIELD(self, 0x20, void *);
    switch (FIELD(info, 0xc, u16)) {
    case 0:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x34, Ov002Text2 *)->unk_74 = 0x77df;
        FIELD(self, 0x34, Ov002Text2 *)->unk_76 = 0x67e;
        FIELD(self, 0x34, Ov002Text2 *)->unk_78 = 0x9000;
        FIELD(self, 0x3c, s32) = data_ov002_021f0d88.w24;
        FIELD(self, 0x24, s32) = 0;
        break;
    case 1:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x3c, s32) = data_ov002_021f0d88.w24;
        FIELD(self, 0x24, s32) = 0;
        break;
    case 2:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x34, VObject *)->v0x14();
        FIELD(self, 0x3c, s32) = 0x60000 - ((FIELD(self, 0x34, Ov002Text2 *)->unk_48 >> 1) << 12);
        if (FIELD(self, 0x44, void *) != NULL) {
            s32 h;
            FIELD(self, 0x44, VObject *)->v0x14();
            h = FIELD(self, 0x44, Ov002Text2 *)->unk_48;
            FIELD(self, 0x4c, s32) = FIELD(self, 0x3c, s32) + h + ((h + 2) << 12);
        }
        FIELD(self, 0x24, s32) = 0;
        break;
    case 3:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x34, Ov002Text2 *)->unk_74 = 0x339f;
        FIELD(self, 0x3c, s32) = data_ov002_021f0d88.w24;
        if (FIELD(self, 0x44, void *) != NULL) {
            s32 h;
            FIELD(self, 0x44, Ov002Text2 *)->unk_74 = 0x7fff;
            h = FIELD(self, 0x44, Ov002Text2 *)->unk_48;
            FIELD(self, 0x4c, s32) = FIELD(self, 0x3c, s32) + h + ((h + 2) << 12);
        }
        FIELD(self, 0x24, s32) = 0;
        break;
    case 4:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x3c, s32) = data_ov002_021f0d88.w24;
        FIELD(self, 0x24, s32) = 0;
        break;
    }
    if (FIELD(self, 0x34, void *) != NULL) {
        void *m;
        FIELD(self, 0x38, s32) = data_ov002_021f0d88.w20 - ((FIELD(self, 0x34, Ov002Text2 *)->unk_44 >> 1) << 12);
        m = FIELD(data_ov002_021f0fa4, 0x28, void *);
        if (m != NULL) {
            FIELD(self, 0x3c, s32) += FIELD(m, 0x3c, s32) & 0xfff;
        }
        func_0204ca70(FIELD(self, 0x34, void *));
    }
    if (FIELD(self, 0x44, void *) != NULL) {
        void *m;
        FIELD(self, 0x48, s32) = data_ov002_021f0d88.w20 - ((FIELD(self, 0x44, Ov002Text2 *)->unk_44 >> 1) << 12);
        m = FIELD(data_ov002_021f0fa4, 0x28, void *);
        if (m != NULL) {
            FIELD(self, 0x4c, s32) += FIELD(m, 0x3c, s32) & 0xfff;
        }
        func_0204ca70(FIELD(self, 0x44, void *));
    }
}

}

extern "C" {

static inline BOOL ov002_021edab4_reached(void *self, s32 lim) {
    BOOL r;
    if (FIELD(self, 0x14, s32) >= lim << 12 && lim << 12 > FIELD(self, 0x18, s32)) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov002_021edab4_flag3(void *self) {
    return ((FIELD(self, 0x4, u32) << 28) >> 31) == 1 ? TRUE : FALSE;
}

BOOL func_ov002_021edab4(void *self) {
    BOOL r = TRUE;
    s32 dt;
    if (FIELD(self, 0x34, void *) == NULL) {
        return FALSE;
    }
    FIELD(data_ov002_021f0fa4, 0x28, void *) = self;
    dt = FIELD(self, 0x1c, s32);
    switch (FIELD(FIELD(self, 0x20, void *), 0xc, u16)) {
    case 0:
    case 1:
    case 3:
    case 4:
        r = FALSE;
        if (FIELD(self, 0x34, void *) != NULL && FIELD(self, 0x3c, s32) > -0x10000) {
            FIELD(self, 0x3c, s32) += FX_MUL(data_ov002_021f0d88.w10, dt);
            r = TRUE;
        }
        if (FIELD(self, 0x44, void *) != NULL && FIELD(self, 0x4c, s32) > -0x10000) {
            FIELD(self, 0x4c, s32) += FX_MUL(data_ov002_021f0d88.w10, dt);
            r = TRUE;
        }
        break;
    case 2:
        if (FIELD(self, 0x8, s32) == 3) {
            s32 t = FX_Div(FIELD(self, 0x14, s32), data_ov002_021f0d88.w4);
            if (t >= 0x1000) {
                t = 0x1000;
            }
            FIELD(self, 0x54, u8) = (s32)(((s64)(0x1000 - FX_SinCosTable_[((s32)(t << 14) >> 16) * 2]) * 0x1f000 + 0x800) >> 12) >> 12;
            if (FIELD(self, 0x54, u8) == 0) {
                r = FALSE;
                break;
            }
        } else {
            s32 t = FX_Div(FIELD(self, 0x14, s32), data_ov002_021f0d88.w0);
            if (t >= 0x1000) {
                t = 0x1000;
            }
            FIELD(self, 0x54, u8) = (s32)(((s64)FX_SinCosTable_[((s32)(t << 14) >> 16) * 2] * 0x1f000 + 0x800) >> 12) >> 12;
        }
        r = TRUE;
        break;
    }
    if (FIELD(self, 0x8, s32) == 3) {
        return r;
    }
    if (FIELD(FIELD(self, 0x20, void *), 0xc, u16) == 2) {
        s32 lim = FIELD(FIELD(self, 0x20, void *), 0xe, u16);
        if (lim == 0) {
            lim = data_ov002_021f0d88.w1c;
        }
        if (ov002_021edab4_reached(self, lim)) {
            FIELD(self, 0x4, u32) |= 8;
        }
    }
    if (ov002_021edab4_flag3(self) && FIELD(self, 0x8, s32) != 3) {
        FIELD(self, 0xc, s32) = 3;
    }
    return r;
}

}
}  // namespace m_021ecfd8

// ---- merged from ov002_021edcec.cpp
namespace m_021edcec {
extern "C" {

typedef struct SprAttr021edcec {
    u32 lo : 8;
    u32 prio : 5;
    u32 pal : 8;
    u32 hi : 11;
} SprAttr021edcec;

void func_ov002_021edcec(void *self, int mode) {
    s32 x;
    s32 y;
    if (FIELD(self, 0x34, void *) == NULL || FIELD(self, 0x54, u8) == 0) {
        return;
    }
    x = FIELD(self, 0x38, s32) >> 12;
    y = FIELD(self, 0x3c, s32) >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    FIELD(FIELD(self, 0x34, void *), 0x4, SprAttr021edcec).pal = func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x34, void *), 0x4, SprAttr021edcec).prio = FIELD(self, 0x54, u8);
    FIELD(self, 0x34, VObject *)->v0x20(x, y);
    FIELD(FIELD(self, 0x34, void *), 0x70, s32) = -0x1000;
    FIELD(self, 0x34, VObject *)->v0x90();
    if (FIELD(self, 0x44, void *) == NULL) {
        return;
    }
    x = FIELD(self, 0x48, s32) >> 12;
    y = FIELD(self, 0x4c, s32) >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    FIELD(FIELD(self, 0x44, void *), 0x4, SprAttr021edcec).pal = func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x44, void *), 0x4, SprAttr021edcec).prio = FIELD(self, 0x54, u8);
    FIELD(self, 0x44, VObject *)->v0x20(x, y);
    FIELD(FIELD(self, 0x44, void *), 0x70, s32) = -0x1000;
    FIELD(self, 0x44, VObject *)->v0x90();
}

}
}  // namespace m_021edcec

// ---- merged from ov002_021ede54.cpp
namespace m_021ede54 {
extern "C" {

void func_ov002_021ede54(void) {
}

void func_ov002_021ede58(void) {
}

}
}  // namespace m_021ede54

// ---- merged from ov002_021ede5c.cpp
namespace m_021ede5c {
extern "C" {

void func_02049870(void *a, void *b);

s32 func_0204a2c8(void *a, void *b);

void func_02049950(void *a, s32 b, int c);

void func_02049960(void *a, void *b, u16 c);

void func_0204a2a8(void *a, int b, u16 c);

BOOL func_ov002_021ede5c(void *self) {
    BOOL busy = FALSE;
    u8 *d = FIELD(self, 0x20, u8 *);
    switch (FIELD(d, 0xc, u16)) {
    case 0:
        if (FIELD(self, 0x10, s32) == 0) {
            func_02049870(data_02097e4c, FIELD(d, 0x8, void *));
            FIELD(self, 0x10, s32)++;
        }
        if (FIELD(FIELD(self, 0x20, u8 *), 0xe, u16) != 0) {
            s32 t = FX_Div(FIELD(self, 0x14, s32), FIELD(FIELD(self, 0x20, u8 *), 0xe, u16) << 12);
            s32 tot;
            s32 cur;
            if (t >= 0x1000) {
                t = 0x1000;
            }
            tot = func_0204a2c8(data_02097e4c, FIELD(FIELD(self, 0x20, u8 *), 0x8, void *));
            cur = FX_MUL(tot << 12, FX_SINCOS_TABLE[((t << 14) >> 16) * 2]) >> 12;
            func_02049950(data_02097e4c, cur, 0);
            if (cur != tot) {
                busy = TRUE;
            }
        }
        break;
    case 1:
        func_02049960(data_02097e4c, FIELD(d, 0x8, void *), FIELD(d, 0xe, u16));
        break;
    case 2:
        func_0204a2a8(data_02097e4c, 100, FIELD(d, 0xe, u16));
        break;
    case 3:
        {
            u8 *g = data_02097e48;
            FIELD(g, 0x80, u16) = 0x8000;
            FIELD(g, 0x7c, u16) = 0;
        }
        break;
    }
    return busy;
}

}
}  // namespace m_021ede5c

// ---- merged from ov002_021edf98.cpp
namespace m_021edf98 {
extern "C" {

static inline void func_ov002_021edf98_setC(void *p, s32 v) {
    if (FIELD(p, 0xc, s32) != v) {
        FIELD(p, 0xc, s32) = v;
    }
}
void func_ov002_021edf98(void *arg) {
    void *p = func_0203dd9c(0x30);
    int i;
    if (p != NULL) {
        FIELD(p, 0x4, s32) = 0;
        FIELD(p, 0x8, s32) = 0;
        FIELD(p, 0xc, s32) = 0;
        FIELD(p, 0x10, s32) = 0;
        FIELD(p, 0x14, s32) = 0;
        FIELD(p, 0x18, s32) = 0;
        FIELD(p, 0x1c, s32) = 0x1000;
        FIELD(p, 0x0, void *) = arg;
        FIELD(p, 0x20, s32) = 0x1000;
        FIELD(p, 0x24, s32) = 0;
        func_ov002_021edf98_setC(p, 1);
    }
    data_ov002_021f0fa4 = p;
    data_ov002_021f0fa0 = NULL;
    data_ov002_021f0fa8 = NULL;
    for (i = 0; i < 9; i++) {
        data_ov002_021f0fac[i] = NULL;
    }
}

}
}  // namespace m_021edf98

// ---- merged from ov002_021ee024.cpp
namespace m_021ee024 {
extern "C" {


void func_0204a284(void *a, int b);

void func_ov002_021ee024(void) {
    u32 saved;
    u8 *n;
    u8 *next;
    u32 s2;
    void *x;
    u32 s3;
    HEAP_PUSH(saved);
    x = data_ov002_021f0fa4;
    if (x != NULL) {
        if (x != NULL) {
            func_0204a284(data_02097e4c, -1);
            for (n = (u8 *)data_ov002_021f0fa0; n != NULL; n = next) {
                s32 k = *FIELD(n, 0x20, s32 *);
                u8 *c;
                u8 *prev;
                next = FIELD(n, 0x2c, u8 *);
                prev = NULL;
                for (c = (u8 *)data_ov002_021f0fac[k]; c != NULL; c = FIELD(c, 0x30, u8 *)) {
                    if (c == n) {
                        if (prev == NULL) {
                            data_ov002_021f0fac[k] = FIELD(n, 0x30, void *);
                        } else {
                            FIELD(prev, 0x30, void *) = FIELD(n, 0x30, void *);
                        }
                        FIELD(n, 0x30, void *) = NULL;
                        break;
                    }
                    prev = c;
                }
                if (FIELD(n, 0x28, u8 *) != NULL) {
                    FIELD(FIELD(n, 0x28, u8 *), 0x2c, void *) = FIELD(n, 0x2c, void *);
                } else {
                    data_ov002_021f0fa0 = FIELD(n, 0x2c, void *);
                }
                if (FIELD(n, 0x2c, u8 *) != NULL) {
                    FIELD(FIELD(n, 0x2c, u8 *), 0x28, void *) = FIELD(n, 0x28, void *);
                } else {
                    data_ov002_021f0fa8 = FIELD(n, 0x28, void *);
                }
                FIELD(n, 0x28, void *) = NULL;
                FIELD(n, 0x2c, void *) = NULL;
                {
                    HEAP_PUSH(s2);
                    if (n != NULL) {
                        if (n != NULL) {
                            ((VObject *)n)->v0x4();
                        }
                    }
                    HEAP_POP(s2);
                }
            }
            {
                HEAP_PUSH(s3);
                DELETE_VOBJ(FIELD(x, 0x24, VObject *));
                HEAP_POP(s3);
            }
            func_0203de1c(x);
        }
        data_ov002_021f0fa4 = NULL;
    }
    HEAP_POP(saved);
}

}
}  // namespace m_021ee024

// ---- merged from ov002_021ee1a8.cpp
namespace m_021ee1a8 {
typedef struct ov002_StaffFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 paused : 1;
    u32 rest : 29;
} ov002_StaffFlags;

typedef struct ov002_Staff {
    s32 id;
    ov002_StaffFlags flags;
    s32 state;
    s32 next;
    s32 sub;
    s32 timer;
    s32 prevTimer;
    s32 step;
    s32 nextStep;
    VObject *loader;
    u8 unk28[4];
    u16 scroll;
} ov002_Staff;

typedef struct ov002_Disp021ee1a8 {
    u8 unk0[0xe];
    u8 unkE_0 : 2;
    u8 mode : 2;
    u8 unkE_4 : 4;
} ov002_Disp021ee1a8;

typedef struct ov002_Fade021ee1a8 {
    u8 unk0[4];
    s32 mode;
} ov002_Fade021ee1a8;

extern "C" {

extern char data_ov002_021f0e06[];
extern ov002_Disp021ee1a8 *data_ov000_021ccd54;

int func_0200779c(char *dst, const char *fmt, ...);
void func_02070874(char *dst, const char *fmt, ...);
void func_ov002_021ec2d8(VObject *obj);
BOOL func_ov002_021ee55c(ov002_Staff *self, u16 y, int h);
void func_ov002_021ee7f8(ov002_Staff *self);

static inline BOOL ov002_Staff_IsPaused(ov002_Staff *s) {
    return s->flags.paused == 1 ? TRUE : FALSE;
}

static inline void ov002_Staff_Update(ov002_Staff *s) {
    if (s->next != 0) {
        s->state = s->next;
        s->next = 0;
        s->sub = 0;
        s->timer = 0;
        s->prevTimer = -1;
        s->step = 0x1000;
    } else if (!ov002_Staff_IsPaused(s)) {
        s->prevTimer = s->timer;
        s->timer += s->step;
    }
}

static inline void ov002_Staff_SetNext(ov002_Staff *s, s32 state) {
    if (s->state != state) {
        s->next = state;
    }
}

void func_ov002_021ee1a8(void) {
    VObject *o;
    ov002_Staff *s = (ov002_Staff *)data_ov002_021f0fa4;

    ov002_Staff_Update(s);
    s->flags.paused = 0;
    switch (s->state) {
    case 1:
        ov002_Staff_SetNext(s, 4);
        break;
    case 4:
        switch (s->sub) {
        case 0:
            s->sub = 3;
            break;
        case 3: {
            char path[0x20];
            char num[8];
            char dir[0x20];
            s32 id;
            o = (VObject *)func_0203dd9c(0x50);
            if (o != NULL) {
                *(VFunc **)o = data_0208b318;
                o->v0x8();
                *(VFunc **)o = data_ov002_021f0f2c;
                o->v0x8();
            }
            s->loader = o;
            id = s->id;
            func_0206e900(dir, data_ov002_021f0d88.dir2);
            func_0200779c(num, data_ov002_021f0e06, id);
            func_02070874(path, data_ov002_021f0d88.pathFmt, num);
            o->v0x24(dir, path);
            s->sub = 4;
        }
        case 4:
            if (!s->loader->v0x2c()) {
                break;
            }
            func_ov002_021ec2d8(s->loader);
            s->nextStep = 0x1000;
            ov002_Staff_SetNext(s, 6);
            break;
        }
        break;
    case 6:
        switch (s->sub) {
        case 0:
            data_ov000_021ccd54->mode = 2;
            func_0203cb78(1, 2, -1);
            s->scroll = 0;
            s->sub++;
        case 1:
            if (!func_ov002_021ee55c(s, s->scroll, 0x20)) {
                s->scroll += 0x20;
                break;
            }
            ((ov002_Fade021ee1a8 *)data_02097d48)->mode = 2;
            s->sub++;
            break;
        case 5:
            ov002_Staff_SetNext(s, 7);
            break;
        default:
            s->sub++;
            break;
        }
        break;
    case 3:
    case 7:
        func_ov002_021ee7f8(s);
        break;
    case 8:
        switch (s->sub) {
        case 0:
            ((ov002_Fade021ee1a8 *)data_02097d48)->mode = 1;
            s->sub++;
            return;
        case 5:
            func_0203cc58(1, 2, -1);
            ov002_Staff_SetNext(s, 2);
            return;
        default:
            s->sub++;
            return;
        }
    }
    s->step = s->nextStep;
}

}
}  // namespace m_021ee1a8

// ---- merged from ov002_021ee4d0.cpp
namespace m_021ee4d0 {
extern "C" {

void func_ov002_021ee4d0(void) {
    void *o4 = data_ov002_021f0fa4;
    BOOL flag = FIELD(data_02097d48, 0xa30, Bits8).b4 ? TRUE : FALSE;
    VObject *v;
    if (FIELD(o4, 8, s32) != 3 && FIELD(o4, 8, s32) != 7) {
        return;
    }
    for (v = (VObject *)data_ov002_021f0fa0; v != NULL; v = FIELD(v, 0x2c, VObject *)) {
        v->v0xc(flag);
    }
    if (FIELD(o4, 8, s32) == 3) {
        func_ov002_021eea74(o4);
    }
}

}
}  // namespace m_021ee4d0

// ---- merged from ov002_021ee55c.cpp
namespace m_021ee55c {
extern "C" {

void func_ov002_021ec6fc(void *node);

struct N3_55c {
    VFunc *vt;
    s32 f4, f8, fc, f10, f14, f18, f1c;
    void *e;
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    N3_55c() {
        vt = data_ov002_021f0ef4;
        f4 = 0; f8 = 0; fc = 0; f10 = 0; f14 = 0; f18 = 0; f1c = 0x1000;
        ((VObject *)this)->v0x10();
    }
};

struct N3b_55c : N3_55c { u8 pad[0x34 - 0x24]; };

struct N4_55c : N3_55c {
    u8 pad[0x58 - 0x24];
    N4_55c() { vt = data_ov002_021f0e84; ((VObject *)this)->v0x10(); }
};

struct N5_55c : N3_55c {
    u8 pad[0x4c - 0x24];
    N5_55c() { vt = data_ov002_021f0e4c; ((VObject *)this)->v0x10(); }
};

struct N6_55c : N5_55c {
    u8 pad6[0x50 - 0x4c];
    N6_55c() { vt = data_ov002_021f0ebc; ((VObject *)this)->v0x10(); }
};

struct N7_55c : N3_55c {
    u8 pad[0x34 - 0x24];
    N7_55c() { vt = data_ov002_021f0e14; ((VObject *)this)->v0x10(); }
};

BOOL func_ov002_021ee55c(void *self, s32 start, s32 count) {
    u8 *hdr = FIELD(FIELD(self, 0x24, void *), 0x4c, u8 *);
    u8 *e = hdr + 0xc + start * 0x14;
    s32 end = start + count;
    bool clipped = FALSE;
    N3_55c *o;
    s32 i;
    if (end >= FIELD(hdr, 0xa, u16)) {
        clipped = TRUE;
        end = FIELD(hdr, 0xa, u16);
    }
    for (i = start; i < end; i++, e += 0x14) {
        switch (FIELD(e, 0, s32)) {
        case 1:
        case 2:
        case 8:
            continue;
        case 3:
            o = new N3b_55c;
            break;
        case 4:
            o = new N4_55c;
            break;
        case 5:
            o = new N5_55c;
            break;
        case 6:
            o = new N6_55c;
            break;
        case 7:
            o = new N7_55c;
            break;
        }
        o->e = e;
        func_ov002_021ec6fc(o);
    }
    return clipped;
}

}
}  // namespace m_021ee55c

// ---- merged from ov002_021ee7c8.cpp
namespace m_021ee7c8 {
extern "C" {

VObject *Ov002Vt_021f0ef4_DtorDelete(VObject *self) {
    *(VFunc **)self = data_ov002_021f0ef4;
    self->v0x14();
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021ee7c8

// ---- merged from ov002_021ee7f8.cpp
namespace m_021ee7f8 {
extern "C" {


static inline void ov002_unlink7f8(u8 *n) {
    s32 k = *FIELD(n, 0x20, s32 *);
    u8 *c;
    u8 *prev = NULL;
    for (c = (u8 *)data_ov002_021f0fac[k]; c != NULL; c = FIELD(c, 0x30, u8 *)) {
        if (c == n) {
            if (prev == NULL) {
                data_ov002_021f0fac[k] = FIELD(n, 0x30, void *);
            } else {
                FIELD(prev, 0x30, void *) = FIELD(n, 0x30, void *);
            }
            FIELD(n, 0x30, void *) = NULL;
            break;
        }
        prev = c;
    }
    if (FIELD(n, 0x28, u8 *) != NULL) {
        FIELD(FIELD(n, 0x28, u8 *), 0x2c, void *) = FIELD(n, 0x2c, void *);
    } else {
        data_ov002_021f0fa0 = FIELD(n, 0x2c, void *);
    }
    if (FIELD(n, 0x2c, u8 *) != NULL) {
        FIELD(FIELD(n, 0x2c, u8 *), 0x28, void *) = FIELD(n, 0x28, void *);
    } else {
        data_ov002_021f0fa8 = FIELD(n, 0x28, void *);
    }
    FIELD(n, 0x28, void *) = NULL;
    FIELD(n, 0x2c, void *) = NULL;
    {
        u32 s2;
        HEAP_PUSH(s2);
        if (n != NULL) {
            if (n != NULL) {
                ((VObject *)n)->v0x4();
            }
        }
        HEAP_POP(s2);
    }
}

static inline BOOL ov002_flag3_7f8(void *self) {
    return FIELD(self, 4, Bits32).b3 == 1 ? TRUE : FALSE;
}

void func_ov002_021ee7f8(void *self) {
    u8 *n;
    u8 *next;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        n = (u8 *)data_ov002_021f0fa0;
        FIELD(self, 0x28, s32) = 0;
        for (; n != NULL; n = next) {
            next = FIELD(n, 0x2c, u8 *);
            if (!((VObject *)n)->v0x8((u8 *)self + 4)) {
                ov002_unlink7f8(n);
            }
        }
        if (ov002_flag3_7f8(self) && FIELD(self, 0x8, s32) != 3) {
            FIELD(self, 0xc, s32) = 3;
        }
        if (FIELD(self, 0x8, s32) != 3) {
            return;
        }
        if (FIELD(self, 0x14, s32) <= 0x78000) {
            return;
        }
        {
            u8 *m;
            u8 *mnext;
            for (m = (u8 *)data_ov002_021f0fa0; m != NULL; m = mnext) {
                mnext = FIELD(m, 0x2c, u8 *);
                ov002_unlink7f8(m);
            }
        }
        FIELD(self, 0x10, s32)++;
        break;
    case 5:
        if (FIELD(self, 0x8, s32) != 8) {
            FIELD(self, 0xc, s32) = 8;
        }
        break;
    default:
        FIELD(self, 0x10, s32)++;
        break;
    }
}

}
}  // namespace m_021ee7f8
