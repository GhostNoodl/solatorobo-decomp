#include "ov010/ov010.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov010_0220f024[];
extern const Ov010Vec data_ov010_0220f144;
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d64f0(void *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline BOOL Ov010_Begin(u16 *st) {
    if (*st == 0) {
        (*st)++;
        return TRUE;
    }
    return FALSE;
}

struct Obj022089d8 : public Ov010Obj {

};

void func_ov010_022089d8(Obj022089d8 *self) {
    BOOL anim = FALSE;
    switch (self->unk_18[0]) {
    case 0: {
        u16 *st = self->unk_40;
        if (st[0] == 0) {
            Ov010_VecSet(&self->pos, -0xd9e, 0x2a35, -0x8687);
            self->pos.y += 0xd000;
            self->rot_x = 0;
            self->rot_y = 0xff;
            self->rot_z = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x200;
            anim = TRUE;
            func_02049f44(data_02097e4c, 0x51, &self->pos, 0);
            self->unk_40[0]++;
        } else {
            const Ov010Vec *t = &data_ov010_0220f144;
            if (self->unk_9c >= 0x40) {
                if (self->unk_a4 == 0) {
                    if (VEC_Distance(t, &self->pos) < 0x2000) {
                        self->unk_a4 = 0xf00;
                    }
                }
                func_ov003_021d9dbc(&self->pos, t, &self->pos, self->unk_9c, self->unk_a0);
                func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
                self->unk_98 = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
            } else {
                if (st[1] == 0) {
                    func_02065f88(0x12f, &self->pos)->v0c(0xe66);
                }
                self->unk_40[1]++;
                if (self->unk_40[1] > 0x5a) {
                    self->unk_9c = 0;
                    self->unk_a0 = 0;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    func_ov003_021d64f0(self);
                } else {
                    func_ov003_021d9dbc(&self->pos, t, &self->pos, self->unk_9c, self->unk_a0);
                    func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
                    self->unk_98 = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
                }
            }
        }
        break;
    }
    case 1:
    case 2: {
        if (((const u16 *)self->unk_40)[0] == 0) {
            self->unk_40[0]++;
            anim = TRUE;
        }
        Ov010_VecSet(&self->pos, -0xd9e, 0x2a35, -0x8687);
        self->rot_x = 0;
        self->rot_y = 0xff;
        self->rot_z = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
    if (anim) {
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
    }
}
}
