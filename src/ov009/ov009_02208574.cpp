#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern char data_ov009_022172c1[];
extern char data_ov009_022172af[];
extern Ov009Path data_ov009_02215fbc[];
extern void func_ov000_021911c8(Ov009Sub38 *m, s32 a);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov000_0218db58(Ov009Actor *self, u16 ang, u16 b, s32 c, s32 d);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern void func_0203f2b8(void *p);
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

extern char data_ov009_022172bb[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern s32 func_02040528(s32 n);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void VEC_MultAdd(s32 k, const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

static inline u16 Ov009_AngTo(Ov009Actor *self, Ov009Actor *a) {
    if (a == NULL || a == self) {
        return self->rot[1];
    }
    return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
}

void func_ov009_02208204(Ov009Multi *self) {
    Ov009Vec off;
    Ov009Vec d;
    s32 k = 0x66;
    BOOL moved = FALSE;
    u16 ang = self->unk_492;
    switch (self->unk_40->state) {
    case 0:
        if (self->unk_490 < 4) {
            self->unk_40->state = 10;
            self->unk_40->timer = 0xf0;
            off.x = 0;
            off.y = 0;
            off.z = 0;
            k = 0x19a;
            moved = TRUE;
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0x200, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 1: {
        Ov009Actor *a;
        u16 a2 = self->unk_492;
        a = func_ov000_0218d240(self);
        if (a != NULL) {
            a2 = Ov009_AngTo(self, a);
        }
        func_ov000_0218db58(self, a2, self->unk_492, 0x3000, self->unk_b0->unk_02);
        {
            Ov009Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                s32 x;
                s32 y;
                s32 z;
                self->unk_40->timer = 0x2d;
                z = func_02040528(0x59a);
                y = func_02040528(0x59a);
                x = func_02040528(0x4cd);
                off.x = x;
                off.y = y;
                off.z = z;
                ang = self->rot[1];
                moved = TRUE;
            }
        }
        break;
    }
    case 10: {
        Ov009Sub40 *s = self->unk_40;
        k = 0x59a;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer <= 0x19) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0xa4, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
        }
        self->rot[1] = func_01ffc128(self->unk_492, self->rot[1], self->unk_b0->unk_02 << 1, 1, 0x8000);
        break;
    }
    case 11: {
        Ov009Sub40 *s = self->unk_40;
        k = 0xcd;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            off.x = 0;
            off.y = 0;
            off.z = 0;
            moved = TRUE;
            if (++self->unk_490 < 4) {
                self->unk_40->timer = 0x2d;
            } else {
                self->unk_490 = 4;
                func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0x200, 0);
                func_ov000_021915a0(self->unk_38);
                self->unk_40->state = 1;
            }
        }
        self->rot[1] = func_01ffc128(self->unk_492, self->rot[1], self->unk_b0->unk_02 << 1, 1, 0x8000);
        break;
    }
    }
    if (moved) {
        s32 r = self->unk_490 * 0xc00;
        FLD(s32, self, 0x4a4) = self->unk_494.y;
        FLD(s32, self, 0x4a0) = self->unk_494.x + Ov009_FxMul(r, OV009_SIN(ang));
        FLD(s32, self, 0x4a8) = self->unk_494.z + Ov009_FxMul(r, OV009_COS(ang));
        VEC_Add(&FLD(Ov009Vec, self, 0x4a0), &off, &FLD(Ov009Vec, self, 0x4a0));
    }
    d.x = FLD(s32, self, 0x4a0) - self->pos.x;
    d.y = FLD(s32, self, 0x4a4) - self->pos.y;
    d.z = FLD(s32, self, 0x4a8) - self->pos.z;
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

void func_ov009_02208574(Ov009Multi *self) {
    if (self->unk_490 > 1) {
        self->unk_490 -= 2;
    } else {
        self->unk_490 = 0;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_022172c1, 0x1000, 1);
    func_ov000_021911c8(self->unk_38, 0xe66);
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov009_022085d0(Ov009Multi *self) {
    if (self->unk_490 > 1) {
        self->unk_490 -= 2;
    } else {
        self->unk_490 = 0;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_022172c1, 0x1000, 1);
    func_ov000_021911c8(self->unk_38, 0xe66);
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov009_0220862c(Ov009Multi *self) {
    Ov009Actor *a;
    u16 ang;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x200, 1);
        self->unk_40->state++;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        break;
    case 1:
        a = Ov009_FindActor(self->unk_90);
        if (a == NULL || a == self) {
            ang = self->rot[1];
        } else {
            ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        func_ov000_0218db58(self, ang, self->unk_492, 0x3800, self->unk_b0->unk_02 << 1);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->state++;
        }
        break;
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

BOOL func_ov009_02208764(Ov009Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (self->unk_18 == 1 && r == FALSE) {
        self->unk_18 = 2;
    }
    return r;
}

void func_ov009_02208788(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void func_ov009_022087c4(Ov009Actor *self) {
    u32 saved;
    func_ov003_021d112c(self);
    {
        Ov009Vec v = data_ov009_02215fbc[self->unk_1a].start;
        v.x = self->pos.x;
        self->unk_84 = v;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            func_0203de1c(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_44 != NULL) {
        func_0203de1c(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}


}
