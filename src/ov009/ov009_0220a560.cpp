#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220a560(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        self->pos.y = FLD(s32, self, 0xfc) - 0xc00;
        FLD(u8, self->unk_38, 0xbe) = 0;
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x1f) {
            if (self->unk_1a == 0) {
                func_ov000_02198360(self->unk_40, 1, 0);
            } else {
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
            self->unk_40->timer = 0x1f;
        }
        FLD(u8, self->unk_38, 0xbe) = self->unk_40->timer;
        self->pos.y = self->pos.y + ((FLD(s32, self, 0xfc) - self->pos.y) >> 2);
        break;
    }
    }
    self->unk_48->unk_9a_4 = 0;
    self->unk_48->unk_9a_5 = 0;
}

extern u8 data_ov009_022172cd[];
extern void func_ov003_021d36fc(Ov009Actor *self);
extern void func_ov000_02191618(void *model);
extern void func_ov000_021911c8(void *model, s32 a);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220a654(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u16, self, 0xf0) = 0;
    }
    func_ov003_021d36fc(self);
    if (self->unk_40->state == 2) {
        self->unk_40->timer = 0;
    }
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    FLD(u16, self, 0xf0)++;
    if (FLD(u16, self, 0xf0) > 0xf0) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_022172cd, 0x29, 0);
    func_ov000_02191618(self->unk_38);
    func_ov000_021911c8(self->unk_38, 0x200);
}

extern void *data_02097e4c;
extern u8 data_ov009_022172af[];
extern u8 data_ov009_022172bb[];
extern s32 func_02040498(s32 max);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_02191418(void *m, s32 a, s32 b);
extern BOOL func_ov000_02191508(void *m);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov009_0220a750(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub38 *m = self->unk_38;
    u32 f = FLD(u32, m, 0xe4);
    Ov009Sub44 *s44;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(m, data_ov009_022172af, 0x400, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 1:
        if (f & 0x80) {
            self->rot[1] = FLD(u16, self, 0xf4);
            self->unk_98 = self->rot[1];
        } else {
            self->rot[1] = func_01ffc128(FLD(u16, self, 0xf4), self->rot[1], 0x400, 1, 0x8000);
        }
        if (f & 0x8000000) {
            func_ov000_02191418(self->unk_38, 3, 0);
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        if (self->unk_a0 < 0 && (self->unk_48->unk_50 & 0x20000000)) {
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = func_02040498(0x14) + 0x28;
            self->unk_a4 = 0xc00;
            FLD(u16, self, 0xf4) += 0x8000;
            func_02065f88(0x2bc, &self->pos);
            func_02065f88(0x2bd, &self->pos);
            func_02049a48(data_02097e4c, 0x3d, -1, -1, -1);
        }
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            FLD(u16, self, 0xf2)++;
            if (FLD(u16, self, 0xf2) <= 1) {
                self->unk_40->state = 0;
            } else {
                FLD(u16, self, 0xf2) = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        self->unk_48->unk_9a_5 = 0;
        break;
    }
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

extern u8 data_ov009_022172d3[];
extern void *func_ov000_02191318(Ov009Sub38 *m, s32 a);
void func_ov009_0220a984(Ov009Actor *self) {
    s32 prev;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x400, 0);
        self->unk_38->unk_c2_0 = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        FLD(u16, self, 0xf0) = 0;
        break;
    case 1:
        if (FLD(u32, self->unk_38, 0xe4) & 0x80) {
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a0 = 0x666;
            self->unk_a8 = 0x3d;
        }
        if (self->unk_40->timer == 1) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x1000, 0);
            func_ov000_02191318(self->unk_38, 0x19000);
        }
        {
            Ov009Sub40 *st = self->unk_40;
            prev = self->unk_a0;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                func_ov000_0218dbe0(self, 0);
                if (prev > 0 && self->unk_a0 < 0) {
                    self->unk_40->timer = 0x78;
                    func_ov000_02190cb0(self->unk_38, data_ov009_022172d3, 0x155, 0);
                    func_ov000_021915a0(self->unk_38);
                }
            }
        }
        if (FLD(u32, self->unk_38, 0xe4) & 0x8000000) {
            func_ov000_02191418(self->unk_38, 3, 0);
        }
        if (self->unk_a0 < 0) {
            if (self->unk_48->unk_50 & 0x20000000) {
                self->unk_a0 = 0;
                self->unk_a8 = 0;
                func_ov000_02190cb0(self->unk_38, data_ov009_022172bb, 0x200, 0);
                func_ov000_021915a0(self->unk_38);
                func_ov000_02198360(self->unk_40, 1, 0);
                func_02065f88(0x2bc, &self->pos);
                func_02065f88(0x2bd, &self->pos);
                func_02049a48(data_02097e4c, 0x3d, -1, -1, -1);
                self->unk_38->unk_c2_0 = 0;
            }
            if (FLD(u16, self, 0xf0)++ > 0xf0) {
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        }
        break;
    }
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
}

}
