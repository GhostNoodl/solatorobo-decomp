#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern Ov009Path data_ov009_02215fd0[];
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
extern BOOL func_ov000_0219aae8(Ov009Actor *self, Ov009Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_022088d8(Ov009Actor *self) {
    Ov009Sub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    st = self->unk_40;
    if (st->unk_13 == 1 && st->timer >= 0x2d) {
        Ov009Actor *a = func_ov000_0219bf90();
        Ov009Vec v = self->unk_84;
        v.y -= 0x3000;
        s32 r = data_ov009_02215fd0[self->unk_1a].start.x;
        if (func_01ffc584(&a->pos, &v, r + a->unk_64, 0x5000)) {
            self->unk_40->flags = 0;
            func_ov000_02198360(self->unk_40, 0xf, 0);
        }
    }
    if (self->unk_40->unk_13 == 0xf) {
        func_ov000_0219aae8(self, self, 0x78, FLD(u16, FLD(u8 *, self, 0x4c), 0xa) & 0xff, 2, 0, 0, 0x3000, 0x1b33, 0x64, 0x1000);
    }
    if (FLD(s16, self->unk_38, 0xc4) == 1) {
        func_0204a028(data_02097e4c, 9, &self->pos, -3);
    }
}

extern void *data_ov009_02215ee4[];

void func_ov009_02208a84(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x2d) {
            self->unk_40->timer = 0x2d;
        }
        break;
    }
    }
}

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

// The path table is in .rodata. Declared const, its loads carry no alias edge to the stores
// through self, so the scheduler can issue p->end.y above the rot store (case 5) and the two
// p->end.x reads in case 3 are one load across the unk_9c store (round qpC).
extern const Ov009Path data_ov009_02215fbc[];
extern char data_ov009_022172c7[];
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_021911c8(Ov009Sub38 *m, s32 a);
extern void *func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern void func_ov000_02191780(Ov009Sub38 *m);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern u16 FX_Atan2(s32 y, s32 x);

void func_ov009_02208b24(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec v3;
    Ov009Vec d;
    const Ov009Path *p = &data_ov009_02215fbc[self->unk_1a];
    u16 state = self->unk_40->state;
    switch (state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172c7, 0x111, 0);
        func_ov000_02191318(self->unk_38, 0x3c000);
        func_ov000_021911c8(self->unk_38, 0x1800);
        func_ov000_02191780(self->unk_38);
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x52;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[1], 0x2ab, 0);
            func_ov000_021915a0(self->unk_38);
            func_ov000_021911c8(self->unk_38, 0xccd);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 2: {
        Ov009Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= 0x2d) {
            func_ov000_021911c8(self->unk_38, 0x1400);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 3: {
        s32 ang;
        v = self->unk_84;
        v.z -= 0x5000;
        self->unk_b8 = v;
        ang = FX_Atan2(Ov009_DistXZ(&self->pos, &v), v.y - self->pos.y);
        self->unk_9c = Ov009_FxMul(p->end.x, OV009_SIN(ang));
        self->unk_a0 = Ov009_FxMul(p->end.x, OV009_COS(ang));
        self->unk_98 = self->rot[1];
        self->unk_40->state++;
    }
    case 4:
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x800) {
            self->unk_a0 = 0;
            self->unk_18 = 1;
            self->unk_40->state++;
        }
        break;
    case 5:
        if (self->unk_18 == 2) {
            u8 *o = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
            if (o != NULL) {
                s32 off;
                self->rot[1] = FLD(u16, o, 0x96);
                v = FLD(Ov009Vec, o, 0x88);
                off = p->end.y;
                self->unk_b8 = v;
                v.y += off;
                self->pos = v;
            }
            self->unk_40->state++;
        }
        break;
    case 6: {
        Ov009Sub40 *s = self->unk_40;
        u16 t;
        s->timer++;
        t = s->timer;
        if (t == 0x96) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022172c7, 0x1000, 0);
        }
        if (t > 0x96) {
            v = self->unk_b8;
            OV009_BLKCPY(&v3, &v);
            v3.y -= 0x800;
            d.x = v3.x - self->pos.x;
            d.y = v3.y - self->pos.y;
            d.z = v3.z - self->pos.z;
            VEC_MultAdd(0x66, &d, &self->pos, &self->pos);
            if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x19a) {
                self->pos = v;
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            if (func_ov000_02191120(self->unk_38)) {
                func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x89, 0);
                func_ov000_021915a0(self->unk_38);
            }
        }
        break;
    }
    }
    if (state < 6) {
        func_ov000_0218dbe0(self, 0);
    }
}

}
