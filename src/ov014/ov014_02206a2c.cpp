#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_02097e4c;
extern void *data_0214a420;
extern u8 data_ov014_02217670[];
extern void func_ov000_0219763c(void *self);
extern void func_ov000_02194074(void *self);
extern void func_ov003_021da940(void *p);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Actor *self, s32 a);
extern void func_ov000_02194758(void *self);
extern Ov014V *func_020657b0(void *a, void *b);
extern u8 data_ov014_02217640[];
extern u8 data_ov014_0221764f[];
extern u8 data_ov014_022169d4[];
extern u8 data_ov014_022169c8[];
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void *func_ov003_021daa3c(void *p, u8 id);

void func_ov014_02206a2c(Ov014Actor *self) {
    FLD(u32, self, 0xd0) |= 0x1000;
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov014_02206a50(Ov014Actor *self) {
    if (FLD(u32, self, 0xd0) & 0x1000) {
        func_ov000_0219763c(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        if (self->unk_44 != NULL) {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->unk_48 != NULL) {
            Ov014Sub48 *m;
            func_ov000_02198c8c(self->unk_48, 0xffff);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->unk_38->unk_c2_0 = 0;
        func_02065f88(4, &self->pos);
        self->unk_40->state++;
        break;
    case 1:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
}

void func_ov014_02206b5c(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->unk_64 + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = func_ov000_02199ba0(FLD(void *, self, 0x4c))->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov014Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            u8 *s = FLD(u8 *, q, 0x4c);
            if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
                return;
            }
        }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_02206c68(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217670;
    FLD(s32, self, 0xd0) = 0;
    FLD(void *, self, 0xdc) = NULL;
    FLD(u16, self, 0xd8) = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeDC(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xdc) != NULL) {
        void *p = FLD(void *, self, 0xdc);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xdc) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_02206c98(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217670;
    Ov014_FreeDC(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_02206d08(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217670;
    Ov014_FreeDC(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02206d80(Ov014Actor *self) {
    s32 *p;
    func_ov000_02194758(self);
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0xdc) = p;
    FLD(s32, self, 0xd4) = 0;
    func_ov000_02198360(self->unk_40, 0x20, 0);
}

void func_ov014_02206dbc(Ov014Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xdc));
}

void func_ov014_02206dd4(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Actor *a;
        Ov014V *e;
        self->pos.y += 0x19a;
        a = func_02065f88(0x646, &self->pos);
        a->v0c(0x1800);
        func_ov003_021da9ac(FLD(void *, self, 0xdc), 0xfd, a);
        e = func_02066774(data_ov014_02217640, data_ov014_0221764f, 0, &self->pos);
        e->v10(data_ov014_022169d4);
        e->v20(data_ov014_022169c8);
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        func_ov003_021da9ac(FLD(void *, self, 0xdc), 0xff, e);
        self->unk_40->state++;
        break;
    }
    case 1:
        if (FLD(s32, self, 0xd4) < 0x2000) {
            Ov014V *o;
            FLD(s32, self, 0xd4) += 0xcd;
            if (FLD(s32, self, 0xd4) >= 0x2000) {
                FLD(s32, self, 0xd4) = 0x2000;
            }
            o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xdc), 0xff));
            if (o != NULL) {
                o->v0c(FLD(s32, self, 0xd4));
            }
        } else if (!func_ov003_021daa0c(FLD(void *, self, 0xdc), 0xfd)) {
            func_ov000_02198360(self->unk_40, 0xb, 0);
        }
        break;
    }
}

}
