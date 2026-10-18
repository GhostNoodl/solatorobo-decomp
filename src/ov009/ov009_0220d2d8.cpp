#include "ov009/ov009.h"

extern "C" {

struct Ov009Ver {
    u8 a;
    u8 b;
    u8 c;
};

extern Ov009Ver data_ov009_02216004[];
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

static inline BOOL Ov009Game_IsVer(Ov009Ver v) {
    Ov009Game54 *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (FLD(u8, g, 0xca) == v.a && FLD(u8, g, 0xcb) == v.b && FLD(u8, g, 0xcc) == v.c) {
        r = TRUE;
    }
    return r;
}

void func_ov009_0220d2d8(Ov009Actor *self) {
    u32 saved;
    u8 *p;
    func_ov003_021d112c(self);
    if (Ov009Game_IsVer(data_ov009_02216004[0])) {
        u16 v = self->unk_50[1] >> 1;
        self->unk_50[1] = v;
        self->unk_50[0] = v;
    }
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *s = self->unk_48;
        if (s != NULL) {
            func_0203f2b8(s);
            func_0203de1c(s);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
    FLD(u8, self, 0x108) = 0;
    self->unk_93_4 = 1;
    FLD(u16, self, 0xea) |= 0x100;
    FLD(s32, self, 0x10c) = -1;
}

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void func_02049bb4(void *mgr, s32 h);

void func_ov009_0220d458(Ov009Actor *self) {
    Ov009Actor *a;
    u16 t;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
        if (func_ov000_021b4738(a) && FLD(s32, self, 0x10c) >= 0) {
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
            FLD(s32, self, 0x10c) = -1;
        }
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x4000;
    t = 0x78;
    if (Ov009Game_IsVer(data_ov009_02216004[1])) {
        t += 0x28;
    }
    FLD(u8, self, 0x108)++;
    if (FLD(u8, self, 0x108) == 3) {
        self->unk_b6 = t + 0xa0;
        FLD(u8, self, 0x108) = 0;
    } else {
        self->unk_b6 = t;
    }
}

}
