#include "ov014/ov014.h"

typedef void (Ov014Actor::*Ov014ActorPmf)();

struct Ov014PmfEntry {
    u32 kind;
    Ov014ActorPmf fn;
};

struct Ov014D8a4Sub44 {
    Ov014Vec pos;
    s32 unk_0c;
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 4;
    u16 unk_22_4 : 1;
    u16 unk_22_5 : 11;
};

struct Ov014D8a4Icon {
    u8 unk_00[0x50];
    Ov014Vec pos;
    s32 unk_5c;
};

extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_02097cdc;
extern void *data_02097e4c;
extern u8 data_ov014_02217588[];
extern u8 data_ov014_022173b9[];
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern void func_ov000_0219763c(void *self);
extern void func_ov003_021daa6c(void *p, s32 a);
extern void *func_ov003_021cf278(void *self, s32 a, s32 b);
extern void *func_ov003_021d7f0c(void *p);
extern void *func_ov003_021d7fc0(void *p);
extern void func_ov003_021ceedc(void *p);
extern void *func_ov003_021cef0c(void *p);
extern void *func_ov003_021da940(void *p);
extern void func_02049de8(void *a, s32 b);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void *func_020359d0(void *a, s32 b, s32 c);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d883c(void *p, Ov014Vec *a, Ov014Vec *b, s32 c);

void func_ov014_021fd2bc(Ov014Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov014_021fd2d4(Ov014Actor *self) {
    if (FLD(u32, self, 0xf8) & 0x100000) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
    } else {
        func_ov000_0219763c(self);
    }
    if (FLD(u8, self, 0xfc) != 0) {
        func_ov003_021daa6c(FLD(void *, self, 0x100), 0xff);
    }
}

void func_ov014_021fd334(Ov014Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40((u8 *)self + 0x24));
    }
}

void func_ov014_021fd360(void) {
}

void func_ov014_021fd364(void) {
}

void func_ov014_021fd368(void) {
}

void func_ov014_021fd36c(void) {
}

void func_ov014_021fd370(void) {
}

void func_ov014_021fd374(void) {
}

void func_ov014_021fd378(void) {
}

void func_ov014_021fd37c(void *self, Ov014Actor *a) {
    u8 *q = FLD(u8 *, self, 0xc);
    s32 pct = (u16)(a->unk_50[0] * 100 / a->unk_50[1]);
    if (pct >= 80) {
        if (FLD(u16, q, 4) != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    } else if (pct >= 55) {
        if (FLD(u16, q, 4) != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else if (pct >= 30) {
        if (FLD(u16, q, 4) != 2) {
            func_ov003_021cf278(self, 2, 0);
        }
    } else {
        if (FLD(u16, q, 4) != 3) {
            func_ov003_021cf278(self, 3, 0);
        }
    }
}

void func_ov014_021fd43c(void *self, Ov014Actor *a) {
    u8 *q = FLD(u8 *, self, 0xc);
    s32 pct = (u16)(a->unk_50[0] * 100 / a->unk_50[1]);
    if (pct >= 75) {
        if (FLD(u16, q, 4) != 10) {
            func_ov003_021cf278(self, 10, 0);
        }
    } else if (pct >= 55) {
        if (FLD(u16, q, 4) != 11) {
            func_ov003_021cf278(self, 11, 0);
        }
    } else {
        if (FLD(u16, q, 4) != 12) {
            func_ov003_021cf278(self, 12, 0);
        }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_021fd4d4(Ov014Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217588;
    func_ov003_021d7f0c((u8 *)self + 0x100);
    func_ov003_021ceedc((u8 *)self + 0x140);
    func_ov003_021ceedc((u8 *)self + 0x160);
    FLD(s32, self, 0xf4) = 0;
    FLD(u8, self, 0x138) = 0;
    FLD(u8, self, 0xf8) = 0xff;
    FLD(void *, self, 0xfc) = NULL;
    FLD(s32, self, 0x13c) = 0;
    FLD(s32, self, 0x15c) = 0;
    FLD(u8, self, 0xf9) = 0;
    FLD(s16, self, 0x13a) = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_StopSnd(void) {
    if (func_02035b90(data_ov014_022173b9, 7)) {
        func_02036838(data_02097cdc, data_ov014_022173b9, 7, 0);
    }
}

static inline void Ov014_FreeFC(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xfc) != NULL) {
        void *p = FLD(void *, self, 0xfc);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xfc) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_021fd53c(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217588;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    func_02049de8(data_02097e4c, 0x38);
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x160);
    func_ov003_021cef0c((u8 *)self + 0x140);
    func_ov003_021d7fc0((u8 *)self + 0x100);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Actor *func_ov014_021fd624(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217588;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    func_02049de8(data_02097e4c, 0x38);
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x160);
    func_ov003_021cef0c((u8 *)self + 0x140);
    func_ov003_021d7fc0((u8 *)self + 0x100);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_021fd714(Ov014Actor *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov014_022173b9, 7, 0);
    FLD(s16, self, 0xf0) = self->unk_18;
}

BOOL func_ov014_021fd740(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    return (r & func_02035b90(data_ov014_022173b9, 7)) ? TRUE : FALSE;
}

BOOL func_ov014_021fd76c(Ov014Actor *self) {
    BOOL r;
    Ov014Vec saved = self->pos;
    if (!func_ov003_021d8820((u8 *)self + 0x100)) {
        if (self->unk_50[0] != 0 && FLD(s16, self, 0xf0) == 1) {
            Ov014Vec t = self->pos;
            Ov014Vec d;
            s16 dir = self->unk_1a;
            if (dir == 0) {
                t.y += 0x1000;
            } else {
                t.y -= 0x1000;
            }
            d.x = t.x - FLD(Ov014Vec, self, 0x12c).x;
            d.y = t.y - FLD(Ov014Vec, self, 0x12c).y;
            d.z = t.z - FLD(Ov014Vec, self, 0x12c).z;
            VEC_MultAdd(0x29, &d, &FLD(Ov014Vec, self, 0x12c), &self->pos);
            FLD(Ov014Vec, self, 0x12c) = self->pos;
            if (VEC_Distance(&self->pos, &t) <= 0x800) {
                if (dir == 0) {
                    self->unk_1a = 1;
                } else {
                    self->unk_1a = 0;
                }
            }
        }
        func_ov003_021d883c((u8 *)self + 0x100, &self->pos, &self->pos, 0x300);
    }
    r = func_ov003_021d16cc(self);
    self->pos = saved;
    return r;
}

extern const Ov014PmfEntry data_ov014_022168c4[];
extern void func_ov000_0219af3c(Ov014Actor *self, void *icon);
extern void func_ov000_021bd624(void *icon);
extern void func_ov000_0219a210(Ov014Vec *pos, Ov014Vec *v, u16 ang);
extern void func_ov003_021d3008(Ov014Actor *self);

static inline void Ov014_Dispatch(Ov014Actor *self, u32 kind) {
    s32 i;
    for (i = 0; i < 0x15; i++) {
        if (data_ov014_022168c4[i].kind != kind) {
            continue;
        }
        (self->*data_ov014_022168c4[i].fn)();
        return;
    }
}

void func_ov014_021fd8a4(Ov014Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        FLD(u8, self, 0xec) = 0;
        Ov014_Dispatch(self, self->unk_40->unk_13);
        if (FLD(void *, self, 0x5c) != NULL && Ov014_GameIdle()) {
            Ov014Vec pos;
            s32 r;
            func_ov000_0219af3c(self, FLD(void *, self, 0x5c));
            if (self->unk_44 != NULL) {
                Ov014D8a4Sub44 *s44 = (Ov014D8a4Sub44 *)self->unk_44;
                pos = s44->pos;
                if (s44->unk_22_4) {
                    Ov014Vec v;
                    v.z = s44->unk_1c;
                    v.x = 0;
                    v.y = 0;
                    func_ov000_0219a210(&pos, &v, self->rot[1]);
                }
                r = ((Ov014D8a4Sub44 *)self->unk_44)->unk_10;
                if (r == 0) {
                    r = ((Ov014D8a4Sub44 *)self->unk_44)->unk_1c;
                }
            } else {
                pos = self->pos;
                r = FLD(s32, self, 0x68);
                if (r == 0) {
                    r = self->unk_64;
                }
            }
            FLD(Ov014D8a4Icon *, self, 0x5c)->pos = pos;
            FLD(Ov014D8a4Icon *, self, 0x5c)->unk_5c = r;
            func_ov000_021bd624(FLD(void *, self, 0x5c));
        }
        self->unk_40->flags = 0;
        break;
    case 1:
        func_ov003_021d3008(self);
        break;
    }
    ((Ov014V *)((u8 *)self + 0x100))->v0c();
}

}
