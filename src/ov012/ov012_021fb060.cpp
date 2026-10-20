#include "ov012/ov012.h"

extern "C" {
void func_ov012_021fb060(Ov012Actor *self) {
    void *o;
    s32 r;
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    o = Ov012_FindRes(0x4000, 0x480f);
    if (FLD(u32, self, 0x10c) == 0) {
        r = func_02040498(9);
        if (((r >= 0 && r < 3) || func_ov000_021983b0(self->unk_40, 0x12, 2, 1) ||
             func_ov000_021983b0(self->unk_40, 0xe, 4, 1) || o != NULL) &&
            FLD(u8, self, 0x136) < 2) {
            u16 *hp = self->unk_50;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            FLD(u16, self, 0xde) = 0;
            if (pct > 0x4b) {
                FLD(u32, self, 0x10c) |= 0x100000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x32) {
                FLD(u32, self, 0x10c) |= 0x200000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x19) {
                FLD(u32, self, 0x10c) |= 8;
                self->unk_40->flags |= 0x10000;
            } else {
                FLD(u32, self, 0x10c) |= 0x10;
                self->unk_40->flags |= 0x20000;
            }
            FLD(u8, self, 0x136)++;
        } else if ((r >= 3 && r < 10) || FLD(u8, self, 0x136) >= 2) {
            if (o == NULL) {
                self->unk_40->flags |= 0x4000;
                FLD(u32, self, 0x10c) |= 0x20;
            }
            FLD(u8, self, 0x136) = 0;
        }
    } else if (FLD(u32, self, 0x10c) & 1) {
        if (o == NULL) {
            FLD(u8, self, 0x110)++;
            self->unk_40->timer = 0;
            if (FLD(u32, self, 0x10c) & 0x20) {
                FLD(u32, self, 0x10c) ^= 0x20;
            }
            if (FLD(u32, self, 0x10c) & 1) {
                FLD(u32, self, 0x10c) ^= 1;
            }
        } else if (func_ov003_021d9edc(0x480f) <= 1) {
            if (FLD(u8, self, 0x110)++ >= 0x64) {
                if (FLD(u32, self, 0x10c) & 0x20) {
                    FLD(u32, self, 0x10c) ^= 0x20;
                }
                if (FLD(u32, self, 0x10c) & 1) {
                    FLD(u32, self, 0x10c) ^= 1;
                }
            }
        }
    }
}

void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);

static inline void Ov012_LiftTick(Ov012Actor *self) {
    if (FLD(u8, self, 0x3af) & 1) {
        func_ov012_021feacc(self, 0);
    }
    if (FLD(u8, self, 0x3af) & 2) {
        func_ov012_021feacc(self, 1);
    }
    if (FLD(u8, self, 0x3af) & 4) {
        func_ov012_021fec58(self, 0);
    }
    if (FLD(u8, self, 0x3af) & 8) {
        func_ov012_021fec58(self, 1);
    }
}

void func_ov012_021fb300(Ov012Actor *self) {
    u8 c;
    u8 d;
    s32 id;
    Ov012Actor *a = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c14);
    Ov012Actor *b = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c13);
    switch (FLD(u16, self, 0xb4)) {
    case 0:
        self->unk_b6++;
        if (self->unk_b6 > 10) {
            FLD(u8, self, 0x3ae) = 0;
            FLD(u8, self, 0x3af) = 0xc;
            self->unk_b6 = 0;
            FLD(u16, self, 0xb4)++;
        }
        break;
    case 1:
        Ov012_LiftTick(self);
        if (a != NULL) {
            a->pos = FLD(Ov012Vec, self, 0x394);
        }
        if (b != NULL) {
            b->pos = FLD(Ov012Vec, self, 0x3a0);
        }
        if (FLD(u8, self, 0x3af) == 0) {
            c = 1;
            func_ov000_0219bd20(0x5c13, self->kind, 6, 1, 1, &c);
            func_ov000_0219bd20(0x5c14, self->kind, 6, 1, 1, &c);
            FLD(u32, self, 0x10c) ^= 0x2000000;
            FLD(Ov012Flags, self, 0x36e).b0 = 0;
            FLD(u16, self, 0xb4) = 10;
        }
        break;
    case 10:
        if ((FLD(u32, self, 0x10c) & 0x8000000) || (FLD(u32, self, 0x10c) & 0x10000000)) {
            c = 2;
            if (FLD(u32, self, 0x10c) & 0x8000000) {
                id = 0x5c13;
            } else if (FLD(u32, self, 0x10c) & 0x10000000) {
                id = 0x5c14;
            }
            func_ov000_0219bd20(id, self->kind, 6, 1, 1, &c);
            if (!(FLD(u32, self, 0x10c) & 0x10)) {
                FLD(u8, self, 0x16e) = func_02040498(1);
            }
            d = FLD(u8, self, 0x16e);
            func_ov000_0219bd20(id, self->kind, 0xe, 1, 1, &d);
            FLD(u32, self, 0x10c) |= 0x4000000;
            FLD(u8, self, 0x3ae) = 0;
            FLD(Ov012Flags, self, 0x36e).b0 = true;
            FLD(u16, self, 0xb4)++;
        }
        break;
    case 11: {
        BOOL go;
        Ov012_LiftTick(self);
        switch (FLD(u16, self, 0x16c)) {
        case 0x5c13:
            if (b != NULL) {
                b->pos = ((Ov012Lift *)self)->arr[FLD(u8, self, 0x16e)];
            }
            break;
        case 0x5c14:
            if (a != NULL) {
                Ov012_VecSet(&FLD(Ov012Vec, a, 0x70), a->pos.x, ((Ov012Lift *)self)->arr[FLD(u8, self, 0x16e)].y, a->pos.z);
            }
            break;
        }
        if (FLD(u8, self, 0x3af) == 0) {
            go = FALSE;
            FLD(u8, self, 0x3ae) = 0;
            if (FLD(u32, self, 0x10c) & 0x4000000) {
                if (FLD(u32, self, 0x10c) & 0x20000000) {
                    c = 4;
                    FLD(u16, self, 0xb4)++;
                    go = TRUE;
                } else if (FLD(u32, self, 0x10c) & 0x40000000) {
                    c = 8;
                    FLD(u16, self, 0xb4)++;
                    go = TRUE;
                }
            } else {
                go = TRUE;
                c = 1;
                FLD(Ov012Flags, self, 0x36e).b0 = 0;
                FLD(u16, self, 0xb4) = 10;
            }
            if (go) {
                func_ov000_0219bd20(FLD(u16, self, 0x16c), self->kind, 6, 1, 1, &c);
            }
        }
        break;
    }
    case 12:
        if (FLD(u8, self, 0x3af) != 0) {
            if (FLD(u32, self, 0x10c) & 0x4000000) {
                FLD(u32, self, 0x10c) ^= 0x4000000;
            }
            if (FLD(u32, self, 0x10c) & 0x20000000) {
                FLD(u32, self, 0x10c) ^= 0x20000000;
            }
            if (FLD(u32, self, 0x10c) & 0x40000000) {
                FLD(u32, self, 0x10c) ^= 0x40000000;
            }
            if (FLD(u32, self, 0x10c) & 0x8000000) {
                FLD(u32, self, 0x10c) ^= 0x8000000;
            } else if (FLD(u32, self, 0x10c) & 0x10000000) {
                FLD(u32, self, 0x10c) ^= 0x10000000;
            }
            FLD(u16, self, 0xb4) = 11;
        }
        break;
    }
    if (!(self->unk_30 & 0x200)) {
        return;
    }
    if (self->unk_50[0] != 0) {
        return;
    }
    c = 0x10;
    func_ov000_0219bd20(0x5c13, self->kind, 6, 1, 1, &c);
    func_ov000_0219bd20(0x5c14, self->kind, 6, 1, 1, &c);
}
}
