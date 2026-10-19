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

extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern void VEC_Normalize(Ov014Vec *a, Ov014Vec *b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern BOOL func_ov014_0220eb14(Ov014Actor *self);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, Ov014Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);

#define OV014Y_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014Y_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014Y_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014y_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_0220e72c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        {
            u8 *m = FLD(u8 *, self, 0x4c);
            FLD(s32, m, 0x50) = 0x1000;
            FLD(s32, m, 0x54) = 0x29;
            FLD(s32, m, 0x58) = 0;
        }
        FLD(s32, self->unk_48, 0x30) = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            Ov014Vec d;
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014Y_SQRTCNT = 1;
                OV014Y_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014Y_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014Y_SQRT_RESULT + 1) >> 1;
            d.x = Ov014_FxMul(r, OV014_SIN(self->rot[1]));
            d.z = Ov014_FxMul(r, OV014_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov014y_FxMul64(d.x, 0x800);
            self->unk_a0 = Ov014y_FxMul64(d.y, 0x800);
            self->unk_a4 = Ov014y_FxMul64(d.z, 0x800);
        } else {
            self->unk_9c = OV014_SIN(self->rot[1]);
            self->unk_a4 = OV014_COS(self->rot[1]);
            self->unk_9c = Ov014y_FxMul64(self->unk_9c, 0x800);
            self->unk_a0 = Ov014y_FxMul64(self->unk_a0, 0x800);
            self->unk_a4 = Ov014y_FxMul64(self->unk_a4, 0x800);
        }
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        func_02065860(data_0214a420, FLD(void *, self, 0xd0));
        FLD(void *, self, 0xd0) = NULL;
        self->unk_40->state++;
        break;
    }
    case 1: {
        void *a;
        Ov014Vec v;
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        if (!(self->unk_48->unk_50 & 0xe0000000) && !func_ov014_0220eb14(self)) {
            return;
        }
        a = func_ov000_02199ba0(FLD(void *, self, 0x4c));
        v.x = self->pos.x - FLD(s32, self, 0x70);
        v.y = self->pos.y - FLD(s32, self, 0x74);
        v.z = self->pos.z - FLD(s32, self, 0x78);
        func_ov000_0219aae8(self, a, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 0x20, &v, 0,
                            0x4000, 0, 3, 0x1000);
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
        FLD(u8, FLD(void *, self, 0x4c), 2) = 0;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
    }
}

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
