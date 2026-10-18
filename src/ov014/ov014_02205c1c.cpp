#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_02097e4c;
extern void *data_0214a420;
extern u8 data_ov014_022169c0[];
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
extern BOOL func_020657b0(void *a, void *b);

void func_ov014_02205c1c(Ov014Actor *self) {
    FLD(u32, self, 0xd0) |= 0x1000;
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov014_02205c40(Ov014Actor *self) {
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
        if (FLD(u32, self, 0xd0) & 0x1000) {
            func_02065f88(0x38f, &self->pos);
        } else {
            func_02065f88(4, &self->pos);
        }
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
}

void func_ov014_02205d70(Ov014Actor *self) {
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

void func_ov014_02205e7c(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(u8, self, 0xe4) = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->unk_38;
    Ov014_VecCopyYZ(&FLD(Ov014Vec, self, 0xd4), &FLD(Ov014Vec, m, 0xa8));
    FLD(Ov014Vec, m, 0xa8) = FLD(Ov014Vec, data_ov014_022169c0, 0x14);
    func_ov000_02198360(self->unk_40, 1, 0);
}

static inline void Ov014_SetScale(Ov014Actor *self) {
    Ov014Sub38 *m = self->unk_38;
    s32 s = FLD(s32, self, 0xe0);
    FLD(Ov014Vec, m, 0xa8).x = s;
    FLD(Ov014Vec, m, 0xa8).y = s;
    FLD(Ov014Vec, m, 0xa8).z = s;
}

void func_ov014_02205f2c(Ov014Actor *self) {
    if (!func_ov000_02199ba0(FLD(void *, self, 0x4c))) {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        if (FLD(s32, self, 0xe0) < FLD(s32, self, 0xd4) + 0x1000) {
            FLD(s32, self, 0xe0) += 0xcd;
        } else {
            FLD(void *, self, 0xe8) = FLD(void *, func_02065f88(0x648, &self->pos), 0x24);
            self->unk_40->state++;
        }
        Ov014_SetScale(self);
        break;
    case 1:
        if (FLD(s32, self, 0xe0) <= FLD(s32, self, 0xd4)) {
            FLD(s32, self, 0xe0) = FLD(s32, self, 0xd4);
            self->unk_40->state++;
        } else {
            FLD(s32, self, 0xe0) -= 0xcd;
        }
        Ov014_SetScale(self);
        break;
    case 2:
        if (!func_020657b0(data_0214a420, FLD(void *, self, 0xe8))) {
            func_ov000_02198360(self->unk_40, 0xb, 0);
        }
        break;
    }
}

}
