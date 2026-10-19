#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022170d8[];
extern const u8 data_ov014_0221643a[];
extern const u8 data_ov014_02216480[];
extern const char *const data_ov014_02216430[];
extern void *data_02097e4c;
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_ov000_021903b4(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov003_021ceff4(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

void func_ov014_021fad9c(Ov014Actor *self) {
    const char *anim;
    if (self->unk_40->state != 0) {
        return;
    }
    anim = data_ov014_02216430[0];
    func_ov000_02190cb0(self->unk_38, anim, 0x111, 0);
    func_ov000_021911c8(self->unk_38, 0x1ec);
    func_ov000_021915a0(self->unk_38);
    func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
    func_ov000_021915a0((u8 *)self + 0x25c);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->state++;
}

extern const u8 data_ov014_022170fe[];
extern const u8 data_ov014_02217104[];
extern const Ov014Vec data_ov014_02216444;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern BOOL func_ov000_02191120(void *a);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_020657b0(void *a, void *b);
extern void func_ov014_021fbb90(Ov014Actor *self, s16 n);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);

void func_ov014_021fae44(Ov014Actor *self) {
    Ov014Vec v;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x400);
        self->unk_84.x = self->pos.x;
        self->unk_84.y = self->pos.y - 0x1333;
        self->unk_84.z = self->pos.z;
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
            func_02049f44(data_02097e4c, 0x36, &v, 0);
            self->unk_40->state++;
        } else {
            self->pos.y += (s32)(((s64)(self->unk_84.y - self->pos.y) * 0x133 + 0x800) >> 12);
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) == NULL) {
            func_ov014_021fbb90(self, 1);
            self->unk_40->state = 10;
        }
        break;
    case 10: {
        Ov014Actor *a;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            Ov014Sub40 *s = a->unk_40;
            if ((s != NULL ? s->unk_13 : 0) == 11) {
                self->unk_40->state++;
            }
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->unk_38, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 12:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        Ov014Actor *a;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a == NULL) {
            u8 *g;
            func_ov000_02190cb0(self->unk_38, data_ov014_02216430[0], 0x400, 0);
            func_ov000_021911c8(self->unk_38, 0x1ec);
            func_ov000_021915a0(self->unk_38);
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
            self->unk_40->state++;
        }
        break;
    }
    }
}

extern const Ov014Vec data_ov014_0221645c;
extern const u8 data_ov014_02216450[];
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov014_021fbab8(Ov014Actor *self, s16 n);

void func_ov014_021fb198(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Vec w;
    Ov014Actor *t = func_ov000_0218d240(self);
    v.x = t->pos.x;
    v.y = t->pos.y;
    v.z = t->pos.z;
    switch (self->unk_40->state) {
    case 0: {
        Ov014Actor *e;
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x400);
        FLD(s16, self, 0x11c) = 0;
        FLD(Ov014Vec, self, 0x110) = v;
        FLD(u8, self, 0x11e) = 0;
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        e = func_02065f88(0x5e3, &w);
        FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        func_02065f88(0xcb, &w);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014Actor *e;
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) != NULL) {
            break;
        }
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x4cd);
        func_02049f44(data_02097e4c, 0x900, &self->pos, 0);
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        e = func_02065f88(0x68, &w);
        e->v10(data_ov014_02216450);
        e->v34(0xbfff, self->rot[1], self->rot[2]);
        FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
        self->unk_40->state = 10;
        break;
    }
    case 10: {
        u8 b = FLD(u8, self, 0x11e);
        if (b == 1) {
            if (FLD(s32, self, 0x110) >= v.x) {
                FLD(s16, self, 0x11c) = 10;
            }
        }
        func_ov014_021fbab8(self, b + FLD(s16, self, 0x11c));
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    case 11: {
        Ov014V *e;
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= 14) {
            u16 n;
            self->unk_40->timer = 0;
            n = 0;
            if (++FLD(u8, self, 0x11e) < 6) {
                self->unk_40->state = 10;
            } else {
                if (FLD(u16 *, self, 0x344) != NULL) {
                    n = FLD(u16 *, self, 0x344)[2];
                }
                if (++FLD(u8, self, 0x11f) >= n) {
                    self->unk_40->state = 0x1e;
                } else {
                    func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02216430[0], 0x111, 0);
                    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
                    func_ov000_021915a0((u8 *)self + 0x25c);
                    self->unk_40->state = 0x14;
                }
            }
        }
        e = (Ov014V *)func_020657b0(data_0214a420, FLD(void *, self, 0x120));
        if (e != NULL) {
            e->v0c(FLD(s32, e, 0x40) + 0xcd);
        }
        break;
    }
    case 0x14: {
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= FLD(u16 *, self, 0x344)[1]) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

extern void func_020639d4(void *e, s32 a, s32 b);
extern void *func_ov000_02199ba0(void *p);

void func_ov014_021fb554(Ov014Actor *self) {
    Ov014Vec v;
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x400);
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            func_020639d4(e, 0x36, 0);
            FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) == NULL) {
            func_02049f44(data_02097e4c, 0xa01, &self->pos, 0);
            func_ov014_021fbb90(self, 0);
            self->unk_40->state = 10;
        }
        break;
    case 10: {
        Ov014Actor *a;
        void *r;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            if (FLD(void *, a, 0x4c) == NULL) {
                break;
            }
            r = func_ov000_02199ba0(FLD(void *, a, 0x4c));
            if (r == NULL) {
                break;
            }
            {
                Ov014Sub40 *s = a->unk_40;
                if ((s != NULL ? s->unk_13 : 0) == 11 && FLD(u16, r, 0xe) == 0x5c15) {
                    self->unk_40->state++;
                }
            }
        } else {
            self->unk_40->state = 0;
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->unk_38, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 12:
        if (func_ov000_02191120(self->unk_38)) {
            u16 n = 0;
            if (FLD(u16 *, self, 0x344) != NULL) {
                n = FLD(u16 *, self, 0x344)[2];
            }
            if (++FLD(u8, self, 0x11f) >= n) {
                self->unk_40->state = 0x1e;
                break;
            }
            func_ov000_02190cb0(self->unk_38, data_ov014_02216430[0], 0x111, 0);
            func_ov000_021911c8(self->unk_38, 0x1ec);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x14;
        }
        break;
    case 0x14: {
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= FLD(u16 *, self, 0x344)[1]) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

}
