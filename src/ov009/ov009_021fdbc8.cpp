#include "ov009/ov009.h"

extern "C" {

extern s32 func_02040528(s32 range);
extern Ov009Actor *func_ov000_0219bf90(void);
struct Ov009AngSrc3 {
    u8 unk_00[0x10];
    Ov009Vec pos;
    u8 unk_1c[0x24];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern s32 func_0204bfa8(Ov009AngSrc3 *p);

static inline s32 Ov009_GetAng3(Ov009AngSrc3 *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return func_0204bfa8(p);
}

void func_ov009_021fdbc8(Ov009Actor *self) {
    func_ov003_021d112c(self);
    switch (self->unk_1a) {
    case 0: {
        Ov009AngSrc3 *g = (Ov009AngSrc3 *)((u8 *)data_ov000_021ccd54 + 0xf4);
        u16 a = Ov009_GetAng3(g) + func_02040528(0x1000);
        s32 r = func_02040528(0x1800) + 0x3800;
        self->pos = g->pos;
        self->pos.x += Ov009_FxMul(r, OV009_SIN(a));
        self->pos.z += Ov009_FxMul(r, OV009_COS(a));
        self->pos.y += 0xa000;
        break;
    }
    case 1:
        self->unk_a0 = 0x466;
        func_ov000_02198360(self->unk_40, 0x20, 0);
        break;
    case 2: {
        Ov009Actor *t = func_ov000_0219bf90();
        if (t != NULL) {
            u16 r = t->rot[1];
            u16 a = r + func_02040528(0x1000);
            s64 k = 0x333;
            self->pos.x = t->pos.x;
            self->pos.y = t->pos.y;
            self->pos.z = t->pos.z;
            self->unk_9c = (s32)((OV009_SIN(a) * k + 0x800) >> 12);
            self->unk_a4 = (s32)((OV009_COS(a) * k + 0x800) >> 12);
            self->unk_a0 = 0x266;
            VEC_MultAdd(0x28000, (Ov009Vec *)&self->unk_9c, &self->pos, &self->pos);
        }
        func_ov000_02198360(self->unk_40, 0x20, 0);
        break;
    }
    }
    FLD(u16, self, 0xf4) = self->kind;
    switch (self->kind) {
    case 0x5013:
        FLD(u16, self, 0xf2) = 0x12c;
        break;
    case 0x5045:
        FLD(u16, self, 0xf2) = 0xc8;
        break;
    }
    if (FLD(u8, data_ov000_021ccd54, 0xca) == 2) {
        self->unk_18 = 1;
    }
    FLD(s32, self, 0xf8) = 0;
    self->unk_ea_6 = 1;
}


struct Ov009PlB22 {
    u16 b0 : 3;
    u16 b3 : 13;
};

extern void *data_0214a420;
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_02065804(void *mgr, s32 h);
extern u16 FX_Atan2(s32 y, s32 x);

void func_ov009_021fde1c(Ov009Actor *self) {
    Ov009Vec t;
    Ov009Actor *pl;
    self->unk_93_4 = 0;
    if (*self->unk_50 == 0) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->unk_90 = pl->id;
    switch (FLD(u16, self, 0xb4)) {
    case 0: {
        BOOL blocked = FALSE;
        BOOL go = FALSE;
        s32 ang;
        u16 a;
        u16 d;
        u16 r;
        s32 dist;
        FLD(u8, self, 0xf0) = 0;
        if (FLD(Ov009PlB22, pl, 0xb22).b0 != 3 && FLD(Ov009PlB22, pl, 0xb22).b0 != 4) {
            FLD(u8, self, 0xf0) = 1;
            if (pl->unk_48 != NULL && (pl->unk_48->unk_50 & 0x20000000)) {
                if (Ov009_GameIdle()) {
                    go = TRUE;
                } else {
                    blocked = TRUE;
                }
            }
            if (!blocked) {
                self->unk_93_4 = 1;
            }
        }
        if (go) {
            FLD(u16, self, 0xb6)++;
            if (FLD(u16, self, 0xb6) > FLD(u16, self, 0xf2)) {
                self->unk_40->flags |= 0x8000;
                FLD(u16, self, 0xb4)++;
            }
        } else {
            FLD(u16, self, 0xb6) = 0;
        }
        {
            Ov009AngSrc3 *g = (Ov009AngSrc3 *)((u8 *)data_ov000_021ccd54 + 0xf4);
            t = pl->pos;
            t.y += 0x1400;
            ang = Ov009_GetAng3(g);
        }
        if (blocked) {
            ang = pl->rot[1];
        }
        a = FX_Atan2(self->pos.x - t.x, self->pos.z - t.z);
        d = a - ang;
        if (d < 0x8000) {
            if (d > 0x1100) {
                r = ang + 0x1100;
            } else {
                r = 0;
            }
        } else {
            if (d < 0xef00) {
                r = ang - 0x1100;
            } else {
                r = 0;
            }
        }
        if (r != 0) {
            a = func_01ffc128(r, a, 0x400, 1, 0x8000);
        }
        dist = 0x6800;
        if (FLD(u8, self, 0xf0) != 0 && !blocked) {
            dist = 0x2800;
        }
        t.x += Ov009_FxMul(dist, OV009_SIN(a));
        t.z += Ov009_FxMul(dist, OV009_COS(a));
        if (!func_01ffc198(&self->pos, &t, self->unk_64 + 0x400)) {
            self->unk_40->flags |= 4;
            self->unk_b8 = t;
        }
        break;
    }
    case 1:
        if (Ov009_GameIdle()) {
            self->unk_93_4 = 1;
            if (self->unk_40->unk_13 != 0xf) {
                FLD(u16, self, 0xb6) = func_02040498(0x3c);
                FLD(u16, self, 0xb4) = 0;
            }
        }
        break;
    }
    if (self->unk_40->unk_13 == 0xf) {
        return;
    }
    if (FLD(s32, self, 0xf8) != 0) {
        func_02065804(data_0214a420, FLD(s32, self, 0xf8));
        FLD(s32, self, 0xf8) = 0;
    }
    if (self->rot[0] == 0) {
        return;
    }
    self->rot[0] = func_01ffc128(0, self->rot[0], 0x19a, 1, 0x8000);
}

}
