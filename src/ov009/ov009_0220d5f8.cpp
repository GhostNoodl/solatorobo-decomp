#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern s32 func_02049afc(void *mgr, s32 id);
extern void func_0204a058(void *mgr, s32 h, s32 a, s32 b);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void func_ov009_0220d5f8(Ov009Actor *self) {
    Ov009Vec d;
    switch (self->unk_40->state) {
    case 0:
        FLD(s32, self, 0x10c) = func_02049afc(data_02097e4c, 0x3f);
        self->unk_40->state++;
        break;
    case 1:
        d.x = FLD(Ov009Vec, self, 0xf0).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xf0).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xf0).z - self->pos.z;
        VEC_MultAdd(0x35, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xf0)) >= 0x333) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        self->pos = FLD(Ov009Vec, self, 0xf0);
        self->unk_b6 = 0x1e;
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        func_0204a058(data_02097e4c, FLD(s32, self, 0x10c), 0x28, 0x1c2);
        break;
    }
}

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov000_0218dfb4(Ov009Actor *a, u16 id);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220d730(Ov009Actor *self) {
    Ov009Vec d;
    if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x19a) {
        self->unk_9c = func_02040528(0x29) + 0x8f;
        FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
        if (!Ov009_GameIdle() || Ov009Game_IsPaused(data_ov000_021ccd54) || self->unk_40->unk_13 == 0x15) {
            FLD(Ov009Vec, self, 0xfc).x += func_02040528(0xa000);
            FLD(Ov009Vec, self, 0xfc).y += func_02040528(0x5000);
            FLD(Ov009Vec, self, 0xfc).z += func_02040528(0x5000);
        } else {
            FLD(Ov009Vec, self, 0xfc).x += func_02040528(0x14000);
            FLD(Ov009Vec, self, 0xfc).y += func_02040528(0xa000);
            FLD(Ov009Vec, self, 0xfc).z += func_02040528(0xd000);
            if (func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x5017) && FLD(Ov009Vec, self, 0xfc).z > -0x37000) {
                FLD(Ov009Vec, self, 0xfc).z = -0x37000;
            }
        }
    }
    d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_9c, &d, &self->pos, &self->pos);
}

}
