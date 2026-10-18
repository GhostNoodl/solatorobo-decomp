#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_02195d88(void *self);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);

void func_ov014_02216300(Ov014Actor *self) {
    func_ov000_02195d88(self);
}

void func_ov014_0221630c(Ov014Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

BOOL func_ov014_02216324(Ov014Actor *self) {
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
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
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

void func_ov014_0221641c(Ov014Actor *self) {
    self->v74();
}

}
