#include "ov014/ov014.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;
extern u8 *data_02097d48;
extern u8 data_ov014_02217aac[];
extern u8 data_ov014_02217c6c[];
extern void func_02065860(void *a, void *b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_0219763c(void *self);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern s32 func_ov000_02191318(void *a, s32 b);
extern s32 func_ov000_02191f18(void *a, void *b);
extern s32 func_ov014_0220ec18(s16 *a, u8 *b);
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_02049de8(void *a, s32 b);
extern u8 func_02043d48(void *p);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_02191618(void *p);
extern void func_ov000_02191708(void *p);

void func_ov014_0220ea94(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        func_02065860(data_0214a420, FLD(void *, self, 0xd0));
        FLD(void *, self, 0xd0) = NULL;
    }
    func_ov000_02195d88(self);
}

void func_ov014_0220ead4(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        func_02065860(data_0214a420, FLD(void *, self, 0xd0));
        FLD(void *, self, 0xd0) = NULL;
    }
    func_ov000_0219763c(self);
}

BOOL func_ov014_0220eb14(Ov014Actor *self) {
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
    if (o == NULL || p == NULL) {
        return FALSE;
    }
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->unk_64;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (FLD(u16, p, 0xb1e) == self->id) {
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


// The result is kept in the parameter slot: the original reuses a's register
// for the return value.
s32 func_ov014_0220ec18(s16 *a, u8 *b) {
    s32 **q;
    s32 prev;
    if (a[0] == 5) {
        prev = 0;
        q = func_ov000_02190a30(b, 0);
        if (q != NULL && *q != NULL) {
            prev = **q;
        }
        a = (s16 *)func_ov000_02191318(b, ((u16 *)a)[1] << 12);
        if (q != NULL) {
            s32 cur = (*q != NULL) ? **q : 0;
            if (prev >= cur) {
                FLD(u32, b, 0xe4) |= 0x20000000;
            }
        }
    } else {
        a = (s16 *)func_ov000_02191f18(a, b);
    }
    return (s32)a;
}

}
