#include "ov002/ov002.h"

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
        func_ov000_0214b88c(p, data_ov002_021f0d88[3]);
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
        FIELD(self, 0x3c, s32) = (s32)data_ov002_021f0d88[9];
        FIELD(self, 0x24, s32) = 0;
        break;
    case 1:
        ov002_021ed270_create(self, FIELD(info, 0x8, char *));
        FIELD(self, 0x3c, s32) = (s32)data_ov002_021f0d88[9];
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
        FIELD(self, 0x3c, s32) = (s32)data_ov002_021f0d88[9];
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
        FIELD(self, 0x3c, s32) = (s32)data_ov002_021f0d88[9];
        FIELD(self, 0x24, s32) = 0;
        break;
    }
    if (FIELD(self, 0x34, void *) != NULL) {
        void *m;
        FIELD(self, 0x38, s32) = (s32)data_ov002_021f0d88[8] - ((FIELD(self, 0x34, Ov002Text2 *)->unk_44 >> 1) << 12);
        m = FIELD(data_ov002_021f0fa0[1], 0x28, void *);
        if (m != NULL) {
            FIELD(self, 0x3c, s32) += FIELD(m, 0x3c, s32) & 0xfff;
        }
        func_0204ca70(FIELD(self, 0x34, void *));
    }
    if (FIELD(self, 0x44, void *) != NULL) {
        void *m;
        FIELD(self, 0x48, s32) = (s32)data_ov002_021f0d88[8] - ((FIELD(self, 0x44, Ov002Text2 *)->unk_44 >> 1) << 12);
        m = FIELD(data_ov002_021f0fa0[1], 0x28, void *);
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
    FIELD(data_ov002_021f0fa0[1], 0x28, void *) = self;
    dt = FIELD(self, 0x1c, s32);
    switch (FIELD(FIELD(self, 0x20, void *), 0xc, u16)) {
    case 0:
    case 1:
    case 3:
    case 4:
        r = FALSE;
        if (FIELD(self, 0x34, void *) != NULL && FIELD(self, 0x3c, s32) > -0x10000) {
            FIELD(self, 0x3c, s32) += FX_MUL((s32)data_ov002_021f0d88[4], dt);
            r = TRUE;
        }
        if (FIELD(self, 0x44, void *) != NULL && FIELD(self, 0x4c, s32) > -0x10000) {
            FIELD(self, 0x4c, s32) += FX_MUL((s32)data_ov002_021f0d88[4], dt);
            r = TRUE;
        }
        break;
    case 2:
        if (FIELD(self, 0x8, s32) == 3) {
            s32 t = FX_Div(FIELD(self, 0x14, s32), (s32)data_ov002_021f0d88[1]);
            if (t >= 0x1000) {
                t = 0x1000;
            }
            FIELD(self, 0x54, u8) = (s32)(((s64)(0x1000 - FX_SinCosTable_[((s32)(t << 14) >> 16) * 2]) * 0x1f000 + 0x800) >> 12) >> 12;
            if (FIELD(self, 0x54, u8) == 0) {
                r = FALSE;
                break;
            }
        } else {
            s32 t = FX_Div(FIELD(self, 0x14, s32), (s32)data_ov002_021f0d88[0]);
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
            lim = (s32)data_ov002_021f0d88[7];
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
