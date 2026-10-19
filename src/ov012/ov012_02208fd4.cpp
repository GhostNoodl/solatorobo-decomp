#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220b34d[];
extern char data_ov012_0220b341[];
extern char data_ov012_0220b335[];
extern u8 data_ov012_0220a88c[];
extern void func_ov000_021911c8(void *p, s32 a);
extern s32 func_ov000_02191318(void *a, s32 b);
extern Ov012Actor *func_ov003_021d69f0(Ov012Actor *self, u16 kind, Ov012Vec *pos, void *rot, Ov012Actor *tgt);

struct Ov012Rot16T {
    u16 x;
    u16 y;
    u16 z;
};

#define OV012T_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012T_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012T_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline u16 Ov012_HpPct(Ov012Actor *self) {
    return self->unk_50[0] * 100 / self->unk_50[1];
}

void func_ov012_02208c0c(Ov012Actor *self) {
    Ov012Vec v;
    Ov012Rot16T r;
    Ov012Actor *pl;
    BOOL on;
    u16 add;
    Ov012Sub40 *s;
    pl = func_ov000_0218d240(self);
    s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b34d, 0x333, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 10) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        func_ov000_0218d988(self, pl, 0x59a);
        break;
    case 2: {
        s16 c4 = FLD(s16, self->unk_38, 0xc4);
        on = FALSE;
        add = 0;
        if (c4 == 1) {
            if (Ov012_HpPct(self) <= 0x32) {
                on = TRUE;
                add = 0xd800;
            }
        } else if (c4 == 2) {
            if (Ov012_HpPct(self) <= 0x50) {
                on = TRUE;
                add = 0xec00;
            }
        } else if (c4 == 3) {
            on = TRUE;
        } else if (c4 == 4) {
            if (Ov012_HpPct(self) <= 0x50) {
                on = TRUE;
                add = 0x1400;
            }
        } else if (c4 == 5) {
            if (Ov012_HpPct(self) <= 0x32) {
                on = TRUE;
                add = 0x2800;
            }
            s->state++;
        }
        if (!on) {
            break;
        }
        r = *(Ov012Rot16T *)self->rot;
        r.y += add;
        {
        s32 y = FLD(s32, self, 0x6c);
        v.x = 0;
        v.y = y;
        v.z = 0x1000;
        }
        func_01ffc9fc(&v, &v, r.y);
        VEC_Add(&v, &self->pos, &v);
        if (pl != NULL) {
            s32 sq_r;
            {
                s64 sq;
                s32 dx = pl->pos.x - v.x;
                s32 dz = pl->pos.z - v.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV012T_SQRTCNT = 1;
                OV012T_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012T_SQRTCNT & 0x8000) {
            }
            sq_r = (s32)(OV012T_SQRT_RESULT + 1) >> 1;
            r.x = FX_Atan2(v.y, sq_r);
        }
        {
            Ov012Actor *o = func_ov003_021d69f0(self, 0x480e, &v, &r, pl);
            if (o != NULL) {
                FLD(void *, o, 0x60) = data_ov012_0220a88c;
                if (func_020621c4()) {
                    func_ov000_0219bebc(o, 0x1800);
                }
            }
        }
        break;
    }
    case 3:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b341, 0x19a, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
        }
        break;
    case 4:
        if (self->unk_48->unk_50 & 0x20000000) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b335, 0x800, 0);
            func_ov000_02191318(self->unk_38, 0x8000);
            self->unk_40->state++;
        }
        break;
    case 5:
        s->timer++;
        if (s->timer > 10) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
    if (self->unk_48->unk_50 & 0x20000000) {
        self->unk_a0 = 0;
    }
}

}


extern "C" {
void func_ov012_02208fd4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        if (*self->unk_50 == 0) {
            if (self->unk_1a == 0) {
                func_02049f44(data_02097e4c, 0x603, &self->pos, 0);
            }
        } else {
            if (self->unk_1a == 0) {
                func_02049f44(data_02097e4c, 0x602, &self->pos, 0);
            }
        }
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
void func_ov012_0220904c(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x602, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
}
}

extern "C" {
void func_ov012_02209098(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x603, &self->pos, 0);
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void func_ov012_022090e4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480e, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2400);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
void *func_ov012_02209164(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *func_ov012_02209184(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_022091ac(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_02049678(data_02097e4c, 4, 7, -1);
}
}

extern "C" {
BOOL func_ov012_022091e4(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a8d0[];
extern const u8 data_ov012_0220a8c8[];
void func_ov012_02209214(Ov012Actor *self) {
    func_ov003_021d112c(self);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a8d0);
        return;
    }
    if (self->kind == 0x5036) {
        func_ov003_021d6bac(self, data_ov012_0220a8c8);
    }
}
}
