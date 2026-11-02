#include "ov002/ov002.h"

namespace K {
extern "C" const char data_ov002_021efdea[];
extern "C" const char data_ov002_021efdf6[];
extern "C" const char data_ov002_021efe02[];
}

extern "C" {

extern VFunc data_ov000_021ccbe0[];
extern VFunc data_ov002_021f0044[];
extern VFunc data_ov002_021ef684[];
extern VFunc data_ov002_021f002c[];
extern VFunc data_ov002_021efe8c[];
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov002_021e2f54(void *self);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov002_021ddcbc(void *self, void *ev);
BOOL func_ov002_021ddd30(void *self, void *ev);
void *Ov002Vt_021efe3c_Ctor(void *self);
void func_ov002_021d7620(void *self);

static inline void ov002_AddItem(void *list, s32 k, void *a, void *b) {
    u8 *q = (u8 *)Heap_Alloc(0x4c);
    if (q != NULL) {
        *(VFunc **)q = data_ov002_021ef684;
        func_ov000_021c22d8(q);
        *(VFunc **)q = data_ov002_021f002c;
        func_ov002_021e2f54(q);
    }
    FIELD(q, 0x4, s32) = k;
    FIELD(q, 0x3c, void *) = a;
    FIELD(q, 0x40, void *) = b;
    FIELD(q, 0x44, u8) = 1;
    func_ov000_021c3fd4(list, q);
}

static inline u8 *ov002_NewCursor(void) {
    u8 *c = (u8 *)Heap_Alloc(0x8c);
    if (c != NULL) {
        *(VFunc **)c = data_ov002_021efe8c;
        Ov002Vt_021efe3c_Ctor(c + 4);
        FIELD(c, 0x78, s32) = 0;
        FIELD(c, 0x74, s32) = 0;
        FIELD(c, 0x80, s32) = 0;
        FIELD(c, 0x7c, s32) = 0;
        FIELD(c, 0x84, s32) = 0;
        c[0x88] = 0;
        FIELD(c, 0x8a, u16) = 0x7fff;
    }
    return c;
}

static inline void ov002_Cursor_SetMode(u8 *c) {
    switch (c[0x88]) {
    case 0:
        { const char *s = ((char *)K::data_ov002_021efdea);
        FIELD(c, 0x8, void *) = ((char *)K::data_ov002_021efdf6);
        FIELD(c, 0xc, const char *) = s;
        FIELD(c, 0x10, const char *) = s; }
        FIELD(c, 0x84, s32) = 0x29;
        break;
    case 1:
        { const char *s = ((char *)K::data_ov002_021efe02);
        FIELD(c, 0x8, void *) = ((char *)K::data_ov002_021efdf6);
        FIELD(c, 0xc, const char *) = s;
        FIELD(c, 0x10, const char *) = s; }
        FIELD(c, 0x84, s32) = 0xcd;
        break;
    }
    func_ov002_021d7620(c + 4);
}

static inline void ov002_CamMove(u8 *c, const VecFx32 *pos, s32 tx, s32 ty, s32 tz) {
    FIELD(c, 0x90, s32) = 20;
    FIELD(c, 0x94, s32) = 20;
    *(VecFx32 *)(c + 0x98) = *(VecFx32 *)FIELD(c, 0x8c, u8 *);
    *(VecFx32 *)(c + 0xa4) = *(VecFx32 *)(FIELD(c, 0x8c, u8 *) + 0xc);
    if (pos != NULL) {
        FIELD(c, 0xb0, s32) = pos->x;
        FIELD(c, 0xb4, s32) = pos->y;
        FIELD(c, 0xb8, s32) = pos->z;
    }
    FIELD(c, 0xbc, s32) = tx;
    FIELD(c, 0xc0, s32) = ty;
    FIELD(c, 0xc4, s32) = tz;
}

static inline void *GetMgr021ddf18(void) { return data_02149ef8; }

// h and cam are locals passed as unused register parameters (the locals-as-parameters lever).
// As user variables they number above every temp and the registers rotate (124-127 diffs, round jkE).
void func_ov002_021ddf18(Obj021efef0 *self, void *owner, s32 h, u8 *cam) {
    s32 w;
    void *g;
    UiObj *p;
    u8 *c;
    self->unk_04 = owner;
    cam = FIELD(owner, 0x4, u8 *);
    g = GetMgr021ddf18();
    p = (UiObj *)Heap_Alloc(0xf4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021ccbe0;
        func_ov000_021c3af4(p);
        *(VFunc **)p = data_ov002_021f0044;
    }
    self->unk_08 = (LoBase021ccb54_021ccbe0 *)p;
    p->rows = 5;
    FIELD(self->unk_08, 0x24, s32) = 0x69;
    {
        u8 *s_0 = ((u8 *)self->unk_08);
        FIELD(s_0, 0x64, s16) = 0x96;
        FIELD(s_0, 0x66, s16) = 0x19;
        FIELD(s_0, 0x68, s16) = -0x199a;
    }
    FIELD(self->unk_08, 0xc, u32) &= ~0x20000;
    FIELD(self->unk_08, 0xc, u32) &= ~0x40000;
    ov002_AddItem(self->unk_08, 0, MsgRes_GetString(g, 0x48), MsgRes_GetString(g, 0x160));
    ov002_AddItem(self->unk_08, 1, MsgRes_GetString(g, 0x49), MsgRes_GetString(g, 0x161));
    ov002_AddItem(self->unk_08, 2, MsgRes_GetString(g, 0x4a), MsgRes_GetString(g, 0x162));
    ov002_AddItem(self->unk_08, 3, MsgRes_GetString(g, 0x4b), MsgRes_GetString(g, 0x163));
    ov002_AddItem(self->unk_08, 4, MsgRes_GetString(g, 0x4c), MsgRes_GetString(g, 0x164));
    self->unk_08->vfunc_08();
    {
        u8 *s_1 = ((u8 *)self->unk_08);
        FIELD(s_1, 0x58, s32) = 0x100;
        FIELD(s_1, 0x5c, s32) = 0;
        FIELD(s_1, 0x60, s32) = -0x199a;
    }
    FIELD(self->unk_08, 0x2c, s32) = 1;
    FIELD(self->unk_08, 0x8, void *) = (u8 *)self + 0x20;
    FIELD(self->unk_08, 0xe4, void *) = (void *)func_ov002_021ddcbc;
    FIELD(self->unk_08, 0xe8, void *) = (void *)func_ov002_021ddd30;
    FIELD(self->unk_08, 0xc, u32) |= 2;
    FIELD(self->unk_08, 0xc, u32) &= ~4;
    FIELD(self->unk_08, 0xc, u32) |= 0x10;

    c = ov002_NewCursor();
    self->unk_10 = (VObj *)c;
    {
        u8 *map = FIELD(FIELD(FIELD(owner, 0x4, u8 *), 0x4, u8 *), 0x6c, u8 *);
        h = FIELD(map, 0x6, Nibbles16).n1;
        w = FIELD(map, 0x6, Nibbles16).n0;
    }
    FIELD(c, 0x7c, s32) = w;
    FIELD(c, 0x80, s32) = h;
    ((u8 *)self->unk_10)[0x88] = 0;
    ov002_Cursor_SetMode(((u8 *)self->unk_10));

    c = ov002_NewCursor();
    self->unk_14 = (VObj *)c;
    FIELD(c, 0x7c, s32) = w;
    FIELD(c, 0x80, s32) = h;
    ((u8 *)self->unk_14)[0x88] = 1;
    ov002_Cursor_SetMode(((u8 *)self->unk_14));
    FIELD(((u8 *)self->unk_14), 0x84, s32) = 0x11f;

    self->unk_2c = FIELD(owner, 0x28, s32);
    self->unk_30 = FIELD(owner, 0x2c, s32);
    cam[0x74] = 5;
    cam[0x75] = 1;
    ov002_CamMove(FIELD(owner, 0x4, u8 *), (const VecFx32 *)(data_ov002_021eef74 + 0x28), 0x99a, 0, 0x148);
    {
        u16 id = self->unk_18;
        if (id == 0xffff) {
            self->unk_1c = 0;
        } else {
            self->unk_28 = *func_0206ede8(id);
            self->unk_1c = 10;
        }
    }
    self->unk_04 = NULL;
}

}
