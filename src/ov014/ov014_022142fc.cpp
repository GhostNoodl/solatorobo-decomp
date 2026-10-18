#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217fb0[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);

#pragma force_active on
Ov014Actor *func_ov014_022142fc(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217fb0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    FLD(s32, self, 0xe0) = 0;
    return self;
}
#pragma force_active reset

void *func_ov014_02214334(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov014_02214348(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02214364(Ov014Actor *self) {
    Ov014Sub44 *n;
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->unk_44->unk_1c = 0x4000;
    self->unk_44->unk_10 = 0x4cd;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    FLD(s32, self->unk_48, 0x4c) = 0x28000;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void func_ov014_022143e8(Ov014Actor *self) {
    func_ov000_02194c08(self);
}

BOOL func_ov014_022143f4(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    BOOL r = FALSE;
    Ov014Actor *o;
    Ov014Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    p = func_ov000_0219bf90();
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->unk_64;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (p != NULL && FLD(u16, p, 0xb1e) == self->id) {
        rad >>= 1;
    }
    n = func_ov000_0219a510(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov014Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL && q->kind != self->kind) {
                u8 *s = FLD(u8 *, q, 0x4c);
                if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}

}
