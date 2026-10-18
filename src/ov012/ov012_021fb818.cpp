#include "ov012/ov012.h"

extern "C" {
void func_ov012_021fb818(Ov012Actor *self) {
    u16 *hp = self->unk_50;
    s32 pct;
    u8 k = self->unk_40->unk_13;
    pct = (u16)(hp[0] * 100 / hp[1]);
    if (k == 1) {
        if (FLD(u32, self, 0x10c) == 0 && FLD(u8, self, 0x3af) == 0) {
            s32 r = func_02040498(9);
            if ((r >= 4 || func_ov000_021983b0(self->unk_40, 0xf, 4, 1)) && FLD(u8, self, 0x136) < 2) {
                s32 r2 = func_02040498(9);
                if (pct >= 0x2d) {
                    if (r2 >= 2) {
                        FLD(u32, self, 0x10c) |= 0x10;
                    } else {
                        FLD(u32, self, 0x10c) |= 8;
                    }
                } else if (pct < 0x2d) {
                    if (r2 >= 2) {
                        FLD(u32, self, 0x10c) |= 8;
                    } else {
                        FLD(u32, self, 0x10c) |= 0x10;
                    }
                }
                if (FLD(u32, self, 0x10c) & 8) {
                    FLD(u32, self, 0x10c) |= 0x400000;
                    self->unk_40->flags |= 0x10000;
                } else if (FLD(u32, self, 0x10c) & 0x10) {
                    self->unk_40->flags |= 0x20000;
                }
                FLD(u8, self, 0x136)++;
            } else if (r < 4 || FLD(u8, self, 0x136) >= 2) {
                FLD(u8, self, 0x136) = 0;
                FLD(u32, self, 0x10c) |= 0x28400000;
                if (pct > 0x32) {
                    FLD(u32, self, 0x10c) |= 0x100000;
                    self->unk_40->flags |= 0x8000;
                } else {
                    FLD(u32, self, 0x10c) |= 0x200000;
                    self->unk_40->flags |= 0x8000;
                }
            }
        } else if (FLD(u32, self, 0x10c) & 1) {
            if (FLD(u8, self, 0x110)++ >= 0x14) {
                FLD(u32, self, 0x10c) ^= 1;
                FLD(u8, self, 0x110) = 0;
            }
        }
    }
    if ((self->unk_30 & 0x40) && FLD(u16, self, 0x112) == 1) {
        Ov012Actor *o = Ov012_FindActor(FLD(u16, self, 0xde));
        if (o != NULL) {
            o->unk_1a = 1;
            self->unk_40->timer = 0;
            switch (k) {
            case 0x10:
                self->unk_40->state = 0xc;
                break;
            case 0x11:
                self->unk_40->state = 0xd;
                break;
            }
        }
    }
}
}

extern "C" {
void func_ov012_021fba44(Ov012Actor *self) {
    Ov012Sub40 *s;
    Ov012Vec d;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        func_02049f44(data_02097e4c, 0x50, &FLD(Ov012Vec, self, 0xf4), 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        s = self->unk_40;
        s->timer++;
        if (s->timer >= 0xa0) {
            if (FLD(u32, self, 0x10c) & 0x40) {
                FLD(u32, self, 0x10c) ^= 0x40;
            }
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            if (FLD(s16, self, 0xf0) == 0) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
    d.x = FLD(Ov012Vec, self, 0xf4).x - self->pos.x;
    d.y = FLD(Ov012Vec, self, 0xf4).y - self->pos.y;
    d.z = FLD(Ov012Vec, self, 0xf4).z - self->pos.z;
    func_02012fb8(0x52, &d, &self->pos, &self->pos);
}
}

extern "C" {
void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);
void func_ov012_021fbb80(Ov012Actor *self) {
    Ov012Actor *o;
    Ov012Sub40 *s;
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c13);
    if (o == NULL) {
        return;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u8, self, 0x3ae) = 0;
        FLD(u8, self, 0x3af) = 2;
        s->state++;
    case 1:
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
        o->pos = FLD(Ov012Vec, self, 0x3a0);
        if (FLD(u8, self, 0x3af) == 0) {
            self->unk_40->state++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021feacc(Ov012Actor *self, s32 a);
void func_ov012_021fec58(Ov012Actor *self, s32 a);
void func_ov012_021fbce0(Ov012Actor *self) {
    Ov012Actor *o;
    Ov012Sub40 *s;
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c14);
    if (o == NULL) {
        return;
    }
    s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u8, self, 0x3ae) = 0;
        FLD(u8, self, 0x3af) = 1;
        s->timer = 0;
        self->unk_40->state++;
    case 1:
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
        o->pos = FLD(Ov012Vec, self, 0x394);
        if (FLD(u8, self, 0x3af) == 0) {
            self->unk_40->state++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        FLD(u32, self, 0x10c) = 0x2000000;
        break;
    }
}
}

extern "C" {
void func_ov012_021fbe64(Ov012Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x89, 0);
    func_ov000_021915a0(self->unk_38);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->state++;
}
}
