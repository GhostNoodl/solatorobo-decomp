#include "ov002/ov002.h"

#define FX32_ONE 0x1000

// The resource-name table (Ov002ResNames in ov002.h) read by ov002_021d2410.cpp .. ov002_021d36b8.cpp. The original TU also
// held those functions and the string pool at 0x021ef5c4; here the strings stay extern. Round dtD
// folded in 0x021d2410..0x021d36b8 (12 files, each in its own namespace). ov002_021d36b8.cpp
// stays outside: in this TU its cepct load is scheduled after the num stores (24 lines).
extern "C" {
extern const char data_ov002_021ef5cb[];
extern const char data_ov002_021ef5d2[];
extern const char data_ov002_021ef5e9[];
extern const char data_ov002_021ef626[];
extern const char data_ov002_021ef606[];
}

extern "C" Ov002ResNames data_ov002_021ef5ac;
Ov002ResNames data_ov002_021ef5ac = {
    data_ov002_021ef5cb, data_ov002_021ef5d2, data_ov002_021ef5e9, data_ov002_021ef626,
    FX_Div(256 * FX32_ONE, 15 * FX32_ONE), data_ov002_021ef606,
};

// ---- merged from ov002_021d2410.cpp
namespace m_021d2410 {
extern "C" {


u32 func_ov002_021e4c30(int which);

u32 func_ov002_021e4960(void *self, s32 val);

void func_ov000_0215c1bc(void *a, int b, void *c);

extern VFunc data_ov000_021cad50[];

extern void *data_ov002_021ef634[];

BOOL func_ov002_021d2410(void *self, void *ev) {
    u8 *owner = FIELD(self, 0x8, u8 *);
    if (ev != NULL) {
        u16 idx = FIELD(ev, 0x4, u32);
        s32 n = func_ov002_021e4960(owner + 0x4c + idx * 0x18, func_ov002_021e4c30(idx));
        if (n <= 0) {
            VObject *p;
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            p = (VObject *)Heap_Alloc(0xe8);
            if (p != NULL) {
                *(VFunc **)p = data_ov000_021cac60;
                p->v0x28();
                *(VFunc **)p = data_ov000_021cad50;
                p->v0x28();
            }
            FIELD(owner, 0x48, VObject *) = p;
            func_ov000_0215c1bc(FIELD(owner, 0x48, void *), 0x11, MsgRes_GetString(data_02149ef8, 0xf6));
            FIELD(FIELD(owner, 0x48, void *), 0xc, u32) &= ~0x10000;
            FIELD(owner, 0x48, VObject *)->v0x8();
            FIELD(owner, 0x48, VObject *)->v0x70();
        } else {
            u8 *w = (u8 *)func_ov000_0218084c(data_ov000_021ccd44, 0x19, 0);
            if (idx < 7) {
                int mode = LangData_GetLang();
                func_ov002_021d4540(w + 0x44, 0x20, data_ov002_021ef5ac.param, data_ov002_021ef650, mode);
                func_ov002_021d4540(w + 0x64, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac.bmExt, mode);
                func_ov002_021d4540(w + 0x7c, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac.hdExt, mode);
                FIELD(w, 0xbc, s32) = idx;
                FIELD(w, 0xc0, s32) = (u16)n;
                func_ov002_021d36b8(w, (u16)(idx * 3));
            }
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        }
    }
    return TRUE;
}

}
}  // namespace m_021d2410

// ---- merged from ov002_021d25ec.cpp
namespace m_021d25ec {
extern "C" {


void func_ov002_021d25ec(Task50 *self) {
    u32 saved;
    int i;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_44);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x48));
    HEAP_POP(saved);
    for (i = 0; i < 7; i++) {
        func_ov002_021e4904((u8 *)self + 0x4c + i * 0x18);
    }
    func_02036838(data_02097cdc, (u8 *)self + 0xf4, 7, 0);
}

void func_ov002_021d2720(void *self) {
    func_ov002_021d4540((u8 *)self + 0xf4, 0x20, data_ov002_021ef5ac.param, data_ov002_021ef650, LangData_GetLang());
    func_020359d0((u8 *)self + 0xf4, 7, 0);
}

bool func_ov002_021d276c(void *self) {
    return func_02035b90((u8 *)self + 0xf4, 7) != 0;
}

}
}  // namespace m_021d25ec

// ---- merged from ov002_021d278c.cpp
namespace m_021d278c {
extern "C" {


extern void *data_ov002_021ef634[];
extern VFunc data_ov000_021cc9f8[];
extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov000_021cb5a8[];
void *func_02035d8c(void *a, void *b);
void func_ov002_021e4814(void *self, u8 *src);
u32 func_ov002_021e4c30(int which);
u32 func_ov002_021e4960(void *self, s32 val);
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2bb0(void *self);
void func_ov000_021c2c0c(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov002_021d2390(void *self, void *arg);
BOOL func_ov002_021d2410(void *self, void *ev);

typedef struct Ent021d278c {
    u8 pad0[8];
    u32 n;
    s32 *arr;
    void *p10;
    u8 pad14[4];
} Ent021d278c;

typedef struct Self021d278c {
    u8 pad[0x4c];
    Ent021d278c ent[7];
} Self021d278c;

static inline s32 ov002_Thresh(Ent021d278c *e, s32 idx) {
    s32 *arr = e->arr;
    if (arr == NULL) {
        return -1;
    }
    if ((u32)idx < e->n) {
        return arr[idx];
    }
    return -1;
}

void func_ov002_021d278c(void *self) {
    void *g;
    u16 i;
    u8 buf[0x18];
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    for (i = 0; i < 7; i++) {
        func_ov002_021d4540(buf, 0x18, data_ov002_021ef634[i], data_ov002_021ef5ac.hdExt, ((int (*)(void))LangData_GetLang)());
        func_ov002_021e4814((u8 *)self + 0x4c + i * 0x18, *(u8 **)func_02035d8c((u8 *)self + 0xf4, buf));
    }
    {
        VObject *p = (VObject *)Heap_Alloc(0xf4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021ccbe0;
            func_ov000_021c3af4(p);
        }
        FIELD(self, 0x3c, VObject *) = p;
        FIELD(p, 0x24, s32) = 0xdb;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x20, s32) = 7;
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x64, s16) = 0x12;
        FIELD(s, 0x66, s16) = 0x14;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(self, 0x3c, VObject *)->v0x10(MsgRes_GetString(g, 0xe5));
    FIELD(self, 0x3c, VObject *)->v0x14(MsgRes_GetString(g, 0xe7));
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x40000;
    for (i = 0; i < 7; i++) {
        u32 val;
        u32 lvl;
        u8 *q;
        q = (u8 *)Heap_Alloc(0x44);
        if (q != NULL) {
            *(VFunc **)q = data_ov002_021ef684;
            func_ov000_021c22d8(q);
            *(VFunc **)q = data_ov000_021cc9f8;
            func_ov000_021c2bb0(q);
        }
        FIELD(q, 0x4, s32) = i;
        func_ov000_021c2c0c(q, ((Self021d278c *)self)->ent[i].p10);
        val = func_ov002_021e4c30(i);
        lvl = func_ov002_021e4960(&((Self021d278c *)self)->ent[i], val);
        if (lvl != 3) {
            s32 lo = 0;
            s32 hi;
            if (lvl != 0) {
                lo = ov002_Thresh(&((Self021d278c *)self)->ent[i], lvl - 1);
            }
            hi = ov002_Thresh(&((Self021d278c *)self)->ent[i], lvl);
            FIELD(q, 0x3c, s32) = (s32)((val - lo) * 100) / (hi - lo) + lvl * 100;
        } else {
            FIELD(q, 0x3c, s32) = 300;
        }
        FIELD(q, 0x38, s32) = 300;
        func_ov000_021c3fd4(FIELD(self, 0x3c, void *), q);
    }
    FIELD(FIELD(self, 0x3c, void *), 0x8, void *) = self;
    FIELD(FIELD(self, 0x3c, void *), 0xe8, void *) = (void *)func_ov002_021d2390;
    FIELD(FIELD(self, 0x3c, void *), 0xe4, void *) = (void *)func_ov002_021d2410;
    FIELD(self, 0x3c, VObject *)->v0x8();
    {
        VObject *p = (VObject *)Heap_Alloc(0x8c);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cadcc;
            p->v0x28();
        }
        FIELD(self, 0x40, VObject *) = p;
        FIELD(p, 0x24, s32) = 0xf5;
    }
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 1;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x8e;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x10000;
    FIELD(FIELD(self, 0x40, void *), 0x48, u16) = 0xb;
    FIELD(self, 0x40, VObject *)->v0x8();
    {
        VObject *p = (VObject *)Heap_Alloc(0xe0);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021caec8;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cb5a8;
            p->v0x28();
        }
        FIELD(self, 0x44, VObject *) = p;
        FIELD(p, 0xc, u32) |= 0x4000000;
    }
    FIELD(FIELD(self, 0x44, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x44, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x44, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x44, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x44, VObject *)->v0xf4(1, MsgRes_GetString(g, 0x34));
    FIELD(self, 0x44, VObject *)->v0xf4(2, MsgRes_GetString(g, 0x33));
    FIELD(self, 0x44, VObject *)->v0x8();
    func_ov000_02173648(self);
}

}
}  // namespace m_021d278c

// ---- merged from ov002_021d2c2c.cpp
namespace m_021d2c2c {
extern "C" {

void func_ov002_021d2c2c(Task50 *self) {
    if (!(FIELD(data_02097dc8, 0x12, u16) & 2)) {
        return;
    }
    if (self->unk_48 != 0) {
        FIELD(self->unk_48, 0xc, u32) |= 2;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    self->v0xc(0);
}

}
}  // namespace m_021d2c2c

// ---- merged from ov002_021d2ca4.cpp
namespace m_021d2ca4 {
extern "C" {

typedef struct E18_2ca4 { void *p; u8 pad[0x14]; } E18_2ca4;

static inline bool ov002_Task50_getFlag1(Task50 *self) {
    return self->flag1;
}

static inline BOOL ov002_isDone2ca4(VObject *o) {
    return FIELD(o, 4, s32) == 5;
}

void func_ov002_021d2ca4(Task50 *self) {
    switch (self->unk_08) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        FIELD(self->unk_3c, 0xc, u32) &= ~2;
        FIELD(self->unk_40, 0xc, u32) &= ~2;
        FIELD(self->unk_44, 0xc, u32) &= ~2;
        break;
    case 12: {
        void *x = (&FIELD(self, 0x60, E18_2ca4))[FIELD(FIELD(self->unk_3c, 0xa0, void *), 4, s32)].p;
        if (self->unk_40 != NULL) {
            func_ov000_0215bb14(self->unk_40, x);
            self->unk_40->v0x70();
        }
        break;
    }
    case 10:
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        FIELD(self->unk_3c, 0xc, u32) |= 2;
        FIELD(self->unk_40, 0xc, u32) |= 2;
        FIELD(self->unk_44, 0xc, u32) |= 2;
        break;
    }
    if (FIELD(self, 0x48, VObject *) != NULL) {
        data_ov000_021ccd34 = 1;
        FIELD(self->unk_3c, 0xc, u32) |= 4;
        FIELD(self, 0x48, VObject *)->v0x1c();
        if (ov002_isDone2ca4(FIELD(self, 0x48, VObject *))) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0x48, VObject *));
            HEAP_POP(saved);
            data_ov000_021ccd34 = 0;
            FIELD(self->unk_3c, 0xc, u32) &= ~4;
        }
    } else if (self->unk_3c != NULL) {
        if (self->v0x54()) {
            BOOL f = ov002_Task50_getFlag1(self);
            if (!f) {
                FIELD(self->unk_3c, 0xc, u32) &= ~4;
                goto done;
            }
        }
        FIELD(self->unk_3c, 0xc, u32) |= 4;
    }

done:
    ((VObject *)self->unk_3c)->v0x1c();
    self->unk_40->v0x1c();
    self->unk_44->v0x1c();
}

}
}  // namespace m_021d2ca4

// ---- merged from ov002_021d2ef4.cpp
namespace m_021d2ef4 {
extern "C" {

void func_ov002_021d2ef4(void) {
}

void func_ov002_021d2ef8(Task50 *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->v0x20();
    }
    if (TASK_VOBJ(self, 0x48) != NULL) {
        TASK_VOBJ(self, 0x48)->v0x20();
    }
}

Task50 *func_ov002_021d2f64(void) {
    Task50 *p = (Task50 *)Heap_Alloc(0xd0);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef91c;
        func_ov002_021e4714((u8 *)p + 0x94);
        func_ov002_021e49a0((u8 *)p + 0xac);
        p->v0x58();
    }
    p->v0x8(0x19, 0xc8);
    return p;
}

}
}  // namespace m_021d2ef4

// ---- merged from ov002_021d2fdc.cpp
namespace m_021d2fdc {
extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021ccadc[];
extern VFunc data_ov000_021cca58[];
void *func_02035d8c(void *a, void *b);
void func_ov002_021e4814(void *self, u8 *src);
void func_ov002_021e4a78(void *self, u8 *src);
s32 func_ov002_021e4bd0(void *self, u32 idx);
s32 func_ov002_021e4c00(void *self, u32 idx);
void func_ov000_021c22d8(void *self);
void func_ov000_021c37bc(void *self);
void func_ov000_021c6140(void *self);
void func_ov000_021c6474(void *list, void *item);

static inline bool ov002_IsActive(void *p) {
    return FIELD(p, 0x28, s32) != 1 ? 0 : FIELD(p, 0x30, s32);
}

static inline bool ov002_HasActive(void *t) {
    void *p = FIELD(t, 0x118, void *);
    if (p == NULL) {
        return false;
    }
    return ov002_IsActive(p) != 0;
}

void func_ov002_021d2fdc(void *self) {
    VObject *p;
    void *g;
    u32 i;
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    func_ov002_021e4814((u8 *)self + 0x94, *(u8 **)func_02035d8c((u8 *)self + 0x44, (u8 *)self + 0x7c));
    func_ov002_021e4a78((u8 *)self + 0xac, *(u8 **)func_02035d8c((u8 *)self + 0x44, (u8 *)self + 0x64));
    {
        p = (VObject *)Heap_Alloc(0xe0);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021caec8;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cb5a8;
            p->v0x28();
        }
        FIELD(self, 0x40, VObject *) = p;
        FIELD(p, 0xc, u32) |= 0x4000000;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = 0;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x40, VObject *)->v0xf4(2, MsgRes_GetString(g, 0x33));
    FIELD(self, 0x40, VObject *)->v0x8();
    {
        p = (VObject *)Heap_Alloc(0xd4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021ccadc;
            func_ov000_021c6140(p);
        }
        FIELD(self, 0x3c, VObject *) = p;
        p->v0x10(FIELD(self, 0xa4, void *));
    }
    FIELD(self, 0x3c, VObject *)->v0x14(FIELD(self, 0xa8, void *));
    FIELD(FIELD(self, 0x3c, void *), 0x68, s16) = -0x199a;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, u32) &= ~2;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, u32) &= ~1;
    for (i = 0; i < FIELD(self, 0xc0, u32); i++) {
        u8 *q = (u8 *)Heap_Alloc(0x44);
        if (q != NULL) {
            *(VFunc **)q = data_ov002_021ef684;
            func_ov000_021c22d8(q);
            *(VFunc **)q = data_ov000_021cca58;
            func_ov000_021c37bc(q);
        }
        FIELD(q, 0x38, s32) = func_ov002_021e4bd0((u8 *)self + 0xac, i);
        FIELD(q, 0x34, s32) = func_ov002_021e4c00((u8 *)self + 0xac, i);
        func_ov000_021c6474(FIELD(self, 0x3c, void *), q);
    }
    FIELD(self, 0x3c, VObject *)->v0x8();
    func_ov000_02173648(self);
    {
        void *t = data_ov000_021ccd30;
        if (t != NULL) {
            if (ov002_HasActive(t) && FIELD(t, 0x118, void *) != NULL) {
                // Read as a u32, so MWCC does not reuse the void * load from the test above.
                func_ov000_0216f844((void *)FIELD(t, 0x118, u32), 0);
            }
        }
    }
}

}
}  // namespace m_021d2fdc

// ---- merged from ov002_021d32d4.cpp
namespace m_021d32d4 {
extern "C" {

void func_ov002_021d32d4(Task50 *self) {
    self->unk_20 = 0x1000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    func_ov002_021e4904((u8 *)self + 0x94);
    func_ov002_021e4b80((u8 *)self + 0xac);
    FIELD(self, 0xbc, s32) = 0;
    FIELD(self, 0xc0, s32) = 0;
    FIELD(self, 0xc4, s32) = 0;
    FIELD(self, 0xc8, s32) = 0;
    FIELD(self, 0xcc, s32) = -1;
}

}
}  // namespace m_021d32d4

// ---- merged from ov002_021d331c.cpp
namespace m_021d331c {
extern "C" {

void func_ov002_021d331c(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x3c, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x40, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0xc4, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278((u8 *)p + 0x88);
                Heap_Free(p);
            }
            FIELD(self, 0xc4, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0xc8, VObject *));
    HEAP_POP(saved);
    func_ov002_021e4b80((u8 *)self + 0xac);
}

}
}  // namespace m_021d331c

// ---- merged from ov002_021d3434.cpp
namespace m_021d3434 {
extern "C" {

static inline bool func_ov002_021d3434_idle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}
void func_ov002_021d3434(Task50 *self) {
    void *t;
    if (!(FIELD(data_02097dc8, 0x12, u16) & 2) || FIELD(self, 0xc4, void *) == NULL) {
        return;
    }
    if (!func_ov002_021d3434_idle()) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    if (self->unk_3c != NULL) {
        FIELD(self->unk_3c, 0xc, u32) |= 2;
    }
    if (self->unk_40 != NULL) {
        FIELD(self->unk_40, 0xc, u32) |= 2;
    }
    self->flag0 = 1;
    t = data_ov000_021ccd30;
    if (t != NULL && FIELD(t, 0x118, void *) != NULL) {
        func_ov000_0216f844(FIELD(t, 0x118, void *), 1);
    }
}

void func_ov002_021d3518(Task50 *self) {
    if (self->unk_08 == 0xd) {
        func_ov002_021d37f8(self);
    }
}

}
}  // namespace m_021d3434

// ---- merged from ov002_021d3530.cpp
namespace m_021d3530 {
extern "C" {

void func_ov002_021d3530(void *self) {
    s32 cnt;
    if (FIELD(self, 0x8, s32) != 0xd) {
        return;
    }
    cnt = 0;
    if (FIELD(self, 0x3c, VObject *) != NULL && FIELD(self, 0x3c, VObject *)->v0x1c()) {
        s32 n = FIELD(FIELD(self, 0x3c, void *), 0x94, s32) + FIELD(self, 0xbc, s32) * 3;
        cnt++;
        if (FIELD(self, 0xcc, s32) != n) {
            func_ov002_021d36b8(self, n);
        }
    }
    if (FIELD(self, 0x40, VObject *) != NULL && FIELD(self, 0x40, VObject *)->v0x1c()) {
        cnt++;
    }
    if (cnt == 0) {
        ((VObject *)self)->v0xc(0);
    }
}

}
}  // namespace m_021d3530

// ---- merged from ov002_021d35d4.cpp
namespace m_021d35d4 {
extern "C" {

void func_ov002_021d35d4(Task50 *self) {
    void *model;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (self->unk_24 == 0 || self->unk_08 == 0) {
        return;
    }
    if (self->unk_08 != 0xc && self->unk_08 != 0xd) {
        return;
    }
    if (self->unk_3c != NULL) {
        ((VObject *)self->unk_3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (FIELD(self, 0xc4, void *) == NULL) {
        return;
    }
    if (func_02054f10(FIELD(self, 0xc4, void *), 0xffff) == 0) {
        return;
    }
    model = FIELD(self, 0xc4, void *);
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
}  // namespace m_021d35d4
