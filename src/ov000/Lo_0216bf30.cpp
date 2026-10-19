#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 timer;
    s32 unk_04;
    VObj *obj;
} LoTimedObj;

typedef struct {
    u8 pad[0x360];
    LoTimedObj objs[10];
} LoTimedHost;

extern void *data_ov000_021ccd54;
extern u8 *data_02097d48;
void *func_ov000_0219bf90(void *self);
void VEC_Add(void *a, void *b, void *c);
BOOL func_0203dc9c(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

void func_ov000_0216bf30(void *self) {
    s32 i;
    LFLD(s32, self, 0) = 0x1000;
    for (i = 0; i < 0x10; i++) {
        u8 *e = (u8 *)self + i * 0x24;
        LFLD(s32, e, 4) = -1;
        LFLD(u8, e, 8) = 0;
    }
    LFLD(s32, self, 0x244) = 0;
    LFLD(s32, self, 0x248) = 0;
    LFLD(s32, self, 0x24c) = 0;
    LFLD(s32, self, 0x250) = 0;
    MI_CpuFill8((u8 *)self + 0x254, 0, 0x108);
    LFLD(s32, self, 0x35c) = 0;
}

void func_ov000_0216bf90(void *self) {
    s32 i;
    func_ov000_0216bcbc(self);
    for (i = 0; i < 10; i++) {
        if (LFLD(VObj *, (u8 *)self + i * 12, 0x368) != NULL && --LFLD(s32, (u8 *)self + i * 12, 0x360) == 0) {
            LO_FREE_V((u8 *)self + i * 12, 0x368);
        }
    }
}

typedef struct {
    void *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad2c[0xb];
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u8 pad50[0x20];
    s32 unk_70;
    u16 unk_74;
    u16 unk_76;
} LoText0216c018;

typedef struct {
    s32 a;
    s32 b;
} LoPair0216c018;

extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
extern LoPair0216c018 data_ov000_021c9bb4[];
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
void func_ov000_0216bae4(void *p, s32 b);
u8 *func_02066c58(void);
void func_ov000_0216bf18(void);

static inline LoText0216c018 *NewText0216c018(void) {
    LoText0216c018 *t = (LoText0216c018 *)func_0203dd9c(0xb8);
    if (t != NULL) {
        t->vtbl = data_0208ba70;
        func_0204c7d0(t);
    }
    return t;
}

static inline void SetText0216c018(LoText0216c018 *t, char *str) {
    t->unk_24 = (s32)str;
    t->unk_4c = func_0204c4fc(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
    LFLD(s32, data_02097ce0, 4) = t->unk_28;
}

static inline BOOL HasPending0216c018(u8 *self) {
    return LFLD(s32, self, 0x244) != LFLD(s32, self, 0x248) ? TRUE : FALSE;
}

void func_ov000_0216c018(void *obj) {
    u8 *self = (u8 *)obj;
    s32 sc;
    LoPair0216c018 *tbl;
    u8 *s;
    s32 i;
    s32 n;
    u8 *e;
    if (!HasPending0216c018(self)) {
        return;
    }
    n = LFLD(s32, self, 0x248) - LFLD(s32, self, 0x244);
    if (n < 0) {
        n += 16;
    }
    sc = LO_FX_MUL(n << 12, 0x400);
    LFLD(s32, self, 0) = sc;
    if (sc < 0x1000) {
        LFLD(s32, self, 0) = 0x1000;
    } else if (sc > 0x3000) {
        LFLD(s32, self, 0) = 0x3000;
    }
    if (LFLD(void *, self, 0x35c) != NULL ? TRUE : FALSE) {
        return;
    }
    e = (0, self + 4 + LFLD(s32, self, 0x244) * 0x24);
    tbl = data_ov000_021c9bb4;
    for (i = 0; i < 6; i++) {
        if (!(LFLD(u32, self + i * 0x2c, 0x254) & 1)) {
            break;
        }
    }
    s = i == 6 ? NULL : self + 0x254 + i * 0x2c;
    if (s == NULL) {
        return;
    }
    LFLD(s32, s, 0) = 3;
    LFLD(s32, s, 4) = LFLD(s32, e, 0);
    LFLD(s32, s, 0xc) = 0;
    LFLD(s32, s, 0x10) = 0;
    LFLD(s32, s, 0x1c) = 0;
    LFLD(s32, s, 0x20) = 0;
    LFLD(s32, s, 0x24) = 0;
    if (LFLD(s8, e, 4) != 0) {
        LFLD(LoText0216c018 *, s, 8) = NewText0216c018();
        LFLD(LoText0216c018 *, s, 8)->unk_28 = 4;
        SetText0216c018(LFLD(LoText0216c018 *, s, 8), (char *)e + 4);
        LFLD(LoText0216c018 *, s, 8)->unk_74 = 0x7fff;
        LFLD(LoText0216c018 *, s, 8)->unk_76 = 0x3b7f;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x40;
        LFLD(LoText0216c018 *, s, 8)->unk_70 = -0x1000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x1000000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x400000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x40000000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 4;
        func_0204ca70(LFLD(LoText0216c018 *, s, 8));
    } else {
        LFLD(void *, s, 8) = NULL;
    }
    func_ov000_0216bae4(self + 0x360 + tbl[LFLD(s32, s, 4)].a * 12, 0);
    func_ov000_0216bae4(self + 0x360 + tbl[LFLD(s32, s, 4)].b * 12, 0);
    if (LFLD(s32, s, 4) == 7) {
        LFLD(u8 *, s, 0x24) = func_02066c58();
        LFLD(void *, LFLD(u8 *, s, 0x24), 0x1c0) = (void *)func_ov000_0216bf18;
        LFLD(s32, LFLD(u8 *, s, 0x24), 0xcc) = 0x7fffffff;
        LFLD(s32, LFLD(u8 *, s, 0x24), 0xc8) = -1;
    }
    if (LFLD(void *, self, 0x24c) == NULL) {
        LFLD(void *, self, 0x24c) = s;
    } else {
        LFLD(void *, LFLD(u8 *, self, 0x250), 0x28) = s;
    }
    LFLD(void *, self, 0x250) = s;
    LFLD(void *, self, 0x35c) = s;
    LFLD(s32, self + LFLD(s32, self, 0x244) * 0x24, 4) = -1;
    LFLD(u8, self + LFLD(s32, self, 0x244) * 0x24, 8) = 0;
    if (++LFLD(s32, self, 0x244) >= 16) {
        LFLD(s32, self, 0x244) = 0;
    }
}

}
