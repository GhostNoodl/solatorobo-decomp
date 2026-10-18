#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern void *func_020657b0(void *a, s32 b);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, void *v, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}


void func_ov013_0220aca0(Ov013Actor *self) {
    s32 v = 0;
    u8 *p;
    Ov013Actor *t;
    p = (u8 *)func_020657b0(data_0214a420, FLD(s32, self, 0xbc));
    if (p != NULL) {
        u8 *q;
        v = FLD(s32, p, 0x7c);
        if (v > 0) {
            v -= 0x52;
        }
        FLD(s32, p, 0x7c) = v < 0 ? 0 : v;
        FLD(s32, p, 0x7c) = v > 0x1000 ? 0x1000 : v;
        q = FLD(u8 *, p, 0xf0);
        if (q != NULL) {
            FLD(s32, q, 0x7c) = v < 0 ? 0 : v;
            FLD(s32, q, 0x7c) = v > 0x1000 ? 0x1000 : v;
        }
    }
    if (v <= 0) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
        }
        return;
    }
    t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 0x8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 1 << (t->id >> 12), NULL, 0,
                        self->unk_48->unk_38, FLD(s32, self, 0xd0), -1, 0x1000);
}

Ov013Actor *func_ov013_0220ade8(Ov013Actor *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220ae04(Ov013Actor *self) {
    func_ov000_0219429c(self);
    return self;
}

Ov013Actor *func_ov013_0220ae18(Ov013Actor *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220ae34(Ov013Actor *self) {
    func_ov000_0219429c(self);
    return self;
}

}
