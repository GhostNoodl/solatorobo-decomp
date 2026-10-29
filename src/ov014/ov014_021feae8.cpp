#include "ov014/ov014.h"

extern "C" {

extern const u8 data_ov014_022173c8[];
extern void *data_ov014_02216500[];
void func_ov000_02191690(void *a);
void *func_ov000_02191318(void *a, s32 b);
s32 func_ov000_0219a510(void *self, u16 mask, Ov014Vec *p, s32 r, s32 a, void **out);
Ov014Actor *func_ov000_021985c0(void *p);
void *func_ov000_0218d2e0(void *a);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

#pragma force_active on
void func_ov014_021feae8(Ov014Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
    case 0: {
        Ov014Vec p;
        void *ids[32];
        s32 n;
        s32 i;
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_022173c8, 0x89, 0);
            if (FLD(u32, self, 0xf4) & 0x40) {
                func_ov000_02191690(self->unk_38);
                func_ov000_02191318(self->unk_38, 0);
            } else {
                func_ov000_021915a0(self->unk_38);
            }
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        p.x = FLD(s32, self->unk_48, 0x68);
        p.y = FLD(s32, self->unk_48, 0x6c);
        p.z = FLD(s32, self->unk_48, 0x70);
        n = func_ov000_0219a510(self, 0xffdf, &p, FLD(s32, self->unk_48, 0x38), 0, ids);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (ids[i] != NULL) {
                Ov014Actor *a = func_ov000_021985c0(ids[i]);
                if (a != NULL) {
                    u16 id = a->id;
                    if ((u16)(FLD(u16, FLD(void *, a, 0x4c), 0x1c) & 0xf000) != 0x5000) {
                        if (func_ov000_0218d2e0(a) != NULL) {
                            return;
                        }
                        func_ov000_0218d46c(a, id, 0x15);
                        return;
                    } else {
                        func_ov000_0218d46c(a, id, 0x15);
                        return;
                    }
                }
            }
        }
        break;
    }
    case 1:
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        break;
    }
}
#pragma force_active reset
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Ov014V *func_02065f88(s32 id, Ov014Vec *v);
extern void func_ov000_021911c8(void *a, s32 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern Ov014Actor *func_ov003_021d69a0(Ov014Actor *self, u16 kind, s32 a);
extern u16 func_ov003_021d9edc(s32 kind);
extern void func_01ffc9fc(Ov014Vec *a, Ov014Vec *b, u16 ang);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *c);

static inline void Ov014_SpawnPart(Ov014Actor *self, u16 kind, u8 bit, s16 n) {
    Ov014Actor *o;
    FLD(u8, self, 0x138) |= bit;
    o = func_ov003_021d69a0(self, kind, 0x20);
    if (o != NULL) {
        Ov014Vec v;
        o->unk_18 = n;
        v.x = 0;
        v.y = 0;
        v.z = 0x9000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(&self->pos, &v, &v);
        o->pos.x = v.x;
        o->pos.y = v.y;
        o->pos.z = v.z;
    }
}

#pragma force_active on
void func_ov014_021fecc8(Ov014Actor *self) {
    u16 lim = 0;
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[2], 0x400, 0);
        self->unk_40->state++;
        e = func_02065f88(0x648, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x2000);
        break;
    }
    case 1:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x400, 0);
        func_ov000_021911c8(self->unk_38, 0x2000);
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 2:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        if (FLD(u32, self, 0xf4) & 0x200000) {
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x482b, 0x15);
        }
        self->unk_40->state++;
        break;
    case 3: {
        s32 n = *FLD(s16 *, self, 0x13c);
        switch (n) {
        case 0:
            Ov014_SpawnPart(self, 0x580c, 1, 0);
            break;
        case 1:
            Ov014_SpawnPart(self, 0x580d, 2, 1);
            break;
        case 2:
            Ov014_SpawnPart(self, 0x580e, 4, 2);
            break;
        case 3:
            if (FLD(u32, self, 0xf4) & 0x200000) {
                Ov014_SpawnPart(self, 0x580e, 4, 2);
                self->unk_40->state = 0x14;
            } else {
                Ov014_SpawnPart(self, 0x580c, 1, 0);
                self->unk_40->state = 0x15;
            }
            break;
        case 4:
            if (FLD(u32, self, 0xf4) & 0x200000) {
                Ov014_SpawnPart(self, 0x580e, 4, 2);
                self->unk_40->state = 0x14;
            } else {
                Ov014_SpawnPart(self, 0x580d, 2, 1);
                self->unk_40->state = 0x15;
            }
            break;
        }
        switch (n) {
        case 0:
        case 1:
        case 2:
            self->unk_40->state = 0x1e;
            break;
        }
        break;
    }
    case 0x14: {
        Ov014Sub40 *s = self->unk_40;
        if (FLD(void *, self, 0x13c) != NULL) {
            lim = FLD(u16, FLD(void *, self, 0x13c), 2);
        }
        s->timer++;
        if (s->timer < lim) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 0x200000) {
            FLD(u32, self, 0xf4) ^= 0x200000;
        }
        self->unk_40->state = 3;
        break;
    }
    case 0x15: {
        s32 c = 0;
        s32 k = 0x580c;
        c += func_ov003_021d9edc(k);
        c += func_ov003_021d9edc(k + 1);
        c += func_ov003_021d9edc(k + 2);
        if (c != 0) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    case 0x1e: {
        Ov014Sub40 *s = self->unk_40;
        if (FLD(void *, self, 0x13c) != NULL) {
            lim = FLD(u16, FLD(void *, self, 0x13c), 2);
        }
        s->timer++;
        if (s->timer < lim) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
#pragma force_active reset

}
