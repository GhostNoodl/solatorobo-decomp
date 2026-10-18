#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd30;
extern Ov009Path data_ov009_02215cf4[];
extern u8 data_ov009_02216ab6[];
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const Ov009Vec *pos);

static inline void Ov009_Notify(u16 id, u16 a, u16 b, const Ov009Vec *pos) {
    void *g = FLD(void *, data_ov000_021ccd30, 0x11c);
    if (g != NULL && FLD(void *, g, 0x60) != NULL) {
        func_ov000_0216912c(FLD(void *, g, 0x60), id, 0, a, b, pos);
    }
}

BOOL func_ov009_021fd24c(Ov009Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (r) {
        Ov009_Notify(self->id, self->unk_50[0], self->unk_50[1], &self->pos);
    }
    return r;
}

void func_ov009_021fd2b4(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Path *path = &data_ov009_02215cf4[self->unk_1a - 1];
    u8 *anim = data_ov009_02216ab6;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        func_ov000_02190cb0(self->unk_38, anim, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        {
            u16 r = self->rot[1];
            s32 x = path->start.x;
            s32 y = path->start.y;
            s32 z = path->start.z;
            self->unk_98 = r;
            self->pos.x = x;
            self->pos.y = y;
            self->pos.z = z;
        }

        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        d.x = path->end.x - self->pos.x;
        d.y = path->end.y - self->pos.y;
        d.z = path->end.z - self->pos.z;
        VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
        if (func_01ffc198(&self->pos, &path->end, self->unk_64 + 0x800)) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            FLD(Ov009Vec, self, 0xf0) = self->pos;
            FLD(Ov009Vec, self, 0xfc) = self->pos;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov009_021fd430(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec *t = &FLD(Ov009Vec, self, 0xfc);
    if (st->timer != 0) {
        st->timer--;
    }
    if (st->timer == 0) {
        self->unk_40->timer = 0x4b;
        *t = FLD(Ov009Vec, self, 0xf0);
        t->y += func_02040528(0xc00);
        t->x += func_02040528(0x59a);
        t->z += func_02040528(0x59a);
    }
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
}

extern void *data_02097e4c;
extern s32 func_02040498(s32 max);
extern Ov009Actor *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
static inline u16 Ov009_AngleTo(Ov009Actor *a, Ov009Actor *b) {
    if (a != NULL && a != b) {
        return FX_Atan2(a->pos.x - b->pos.x, a->pos.z - b->pos.z);
    }
    return b->rot[1];
}

void func_ov009_021fd510(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Actor *p;
        FLD(Ov009Vec, self, 0xfc) = self->pos;
        if (self->unk_18 == 1) {
            FLD(s32, self, 0x100) -= func_02040498(0x800) + 0x1000;
        } else {
            FLD(s32, self, 0x100) -= func_02040498(0x800) + 0x2800;
        }
        if (FLD(s32, self, 0x100) < FLD(s32, self, 0xf4) - 0x1000) {
            FLD(s32, self, 0x100) = FLD(s32, self, 0xf4) - 0x1000;
        }
        if (FLD(u8, data_ov000_021ccd54, 0xca) != 0x11) {
            p = func_ov000_02199f60(self->unk_50);
            if (p != NULL) {
                u16 a = Ov009_AngleTo(self, p);
                FLD(s32, self, 0xfc) += Ov009_FxMul(OV009_SIN(a), 0x1000);
                FLD(s32, self, 0x104) += Ov009_FxMul(OV009_COS(a), 0x1000);
            }
        }
        if (self->unk_18 == 1) {
            func_02049f44(data_02097e4c, 0xd03, &self->pos, 0);
        }
        self->unk_40->state++;
    }
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x2d) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
        break;
    }
}

}
