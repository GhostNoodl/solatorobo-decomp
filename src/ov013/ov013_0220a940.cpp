#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220beb4;
extern char data_ov013_0220b3f8[];
extern char data_ov013_0220b404[];
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);

void func_ov013_0220a940(Ov013Actor *self) {
    Ov013Sub38 *s;
    Ov013Sub40 *q;
    u8 v;
    func_ov000_0218dbe0(self, 0);
    s = self->unk_38;
    v = FLD(u8, s, 0xbe);
    if (v > 1) {
        v -= 2;
    } else if (v != 0) {
        v -= 1;
    }
    FLD(u8, s, 0xbe) = v;
    q = self->unk_40;
    q->timer++;
    if (q->timer > 0xf) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

#pragma force_active on
Ov013Actor *func_ov013_0220a9a8(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220beb4;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    return self;
}
#pragma force_active reset

void func_ov013_0220a9d8(Ov013Actor *self) {
    Ov013Actor *pl;
    Ov013V *fx;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 1, 0);
    FLD(u16, self, 0xce) = 600;
    self->unk_48->unk_38 = 0x1b33;
    FLD(s32, self, 0xd0) = 0x1000;
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    fx = func_02065f88(0x38c, &self->pos);
    if (fx == NULL) {
        return;
    }
    fx->v10(data_ov013_0220b3f8);
    fx->v20(data_ov013_0220b404);
    FLD(s32, self, 0xbc) = FLD(s32, fx, 0x24);
}
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern Ov013V *func_020657b0(void *a, void *b);
extern void func_0203f364(void *p);
extern BOOL func_ov000_021b4738(Ov013Actor *a);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);

static inline Ov013Actor *Ov013_FindActorA(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_0220aa7c(Ov013Actor *self) {
    Ov013Actor *t;
    switch (self->unk_40->state) {
    case 0:
        if (FLD(s32, self, 0xd4) != 0) {
            Ov013V *fx;
            s32 k = 0x1b33;
            self->unk_48->unk_38 = Ov013_FxMul(FLD(s32, self, 0xd4), k);
            FLD(s32, self, 0xd0) = Ov013_FxMul(FLD(s32, self, 0xd4), 0x1000);
            fx = func_020657b0(data_0214a420, FLD(void *, self, 0xbc));
            if (fx != NULL) {
                Ov013Vec v;
                s32 d = FLD(s32, self, 0xd4);
                v.x = Ov013_FxMul(d, 0x1000);
                v.z = v.x;
                v.y = Ov013_FxMul(d, k - 0x1000);
                fx->v10(&v);
            }
        }
        self->unk_40->state++;
        {
            Ov013Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        break;
    case 1: {
        Ov013Actor *pl = func_ov000_0219bf90();
        if (pl == NULL || func_ov000_021b4738(pl)) {
            FLD(u16, self, 0xce) = 1;
        }
        FLD(u16, self, 0xce)--;
        if (FLD(u16, self, 0xce) == 0) {
            func_ov000_02198360(self->unk_40, 10, 0);
            return;
        }
        break;
    }
    }
    t = Ov013_FindActorA(self->unk_90);
    if (t == NULL) {
        return;
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), (u16)(1 << (t->id >> 12)), NULL, 0,
                        self->unk_48->unk_38, FLD(s32, self, 0xd0), 0x25f, 0x1000);
}

}
