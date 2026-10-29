#include "ov014/ov014.h"

struct Ov014HitArg {
    u8 a;
    u8 pad;
    u16 b;
    u16 c;
};

extern "C" {

extern void *data_02097e4c;
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov000_0218d398(Ov014Actor *t, u16 id, s32 a, s32 b, s32 c, Ov014HitArg *arg);
extern BOOL func_ov003_021daa0c(void *p, s32 a);
extern void func_ov003_021da9ac(void *p, s32 a, void *e);
extern void func_ov003_021daae4(void *p, s32 a, Ov014Vec *v, s32 b, s32 c, s32 d, s32 e);
extern void func_ov003_021daa6c(void *p, s32 a);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *v);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
void MIi_CpuClear32(u32 data, void *dest, u32 size);

static inline BOOL Ov014_AnyHit(Ov014Actor *self) {
    s32 r = FLD(s32, self, 0xd4);
    if (r != 0) {
        Ov014Actor *list[0x20];
        s32 n = func_ov000_0219a510(self, 2, &self->pos, Ov014_FxMul(r, 0xb33), 0x800, list);
        s32 i;
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && func_ov000_021985c0(list[i]) != NULL) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void func_ov014_0220840c(Ov014Actor *self) {
    Ov014Actor *t = func_ov000_0218d240(self);
    Ov014Vec p;
    p.x = t->pos.x;
    p.y = t->pos.y;
    p.z = t->pos.z;
    if (t->unk_50[0] != 0) {
        if (Ov014_AnyHit(self) && t != NULL) {
            Ov014HitArg arg;
            arg.b = 0x666;
            arg.a = 1;
            arg.c = 1;
            func_ov000_0218d398(t, self->id, 0xb, 1, 6, &arg);
            p.y += 0x1800;
            if (!func_ov003_021daa0c(FLD(void *, self, 0xd8), 0xfe)) {
                Ov014V *e = func_02065f88(0xcb, &p);
                e->v34(0, 0, 0x7fff);
                e->v0c(0xb33);
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                func_0204a028(data_02097e4c, 0x11, &self->pos, -10);
                func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xfe, e);
            } else {
                func_ov003_021daae4(FLD(void *, self, 0xd8), 0xfe, &p, 0, 0, 0, 0);
            }
        } else {
            func_ov003_021daa6c(FLD(void *, self, 0xd8), 0xfe);
        }
    } else {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}


extern u8 data_ov014_02217708[];
extern void *func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);

#pragma force_active on
Ov014Actor *func_ov014_02208618(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217708;
    FLD(s32, self, 0xd0) = 0;
    FLD(void *, self, 0xd8) = NULL;
    FLD(u8, self, 0xd4) = 0;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_02208648(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_022086b8(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02208730(Ov014Actor *self) {
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd8) = Ov014_NewFx();
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->unk_48->unk_30 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void func_ov014_02208790(Ov014Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xd8));
}

}
