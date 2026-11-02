#include "ov013/ov013.h"

extern "C" {

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, void *v, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}


void func_ov013_0220aca0(Ov013ActEx_0220a9a8 *self) {
    s32 v = 0;
    u8 *p;
    Ov003Actor *t;
    p = (u8 *)func_020657b0(data_0214a420, ((s32)self->unk_bc));
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
        func_ov000_02198360(self->fsm, 0x15, 0);
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
        }
        return;
    }
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 1 << (t->id >> 12), NULL, 0,
                        self->hit->radius, self->unk_d0, -1, 0x1000);
}

Ov003Actor *Ov013ActEx_0220a9a8_DtorDelete(Ov003Actor *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov013ActEx_0220a9a8_Dtor(Ov003Actor *self) {
    func_ov000_0219429c(self);
    return self;
}

Ov003Actor *Ov013ActEx_0220a4e0_DtorDelete(Ov003Actor *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov013ActEx_0220a4e0_Dtor(Ov003Actor *self) {
    func_ov000_0219429c(self);
    return self;
}

}
