#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void func_0203f364(Ov009Sub48 *p);
extern s32 func_01ffbd6c(Ov009Vec *a, Ov009Vec *b, s32 c, s32 d, s32 e, s32 f);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
void func_ov009_021fa6a0(Ov009Actor *self) {
    s32 dist;
    Ov009Actor *o;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->unk_50 != NULL && *self->unk_50 == 0) {
        return;
    }
    dist = 0x7fffffff;
    o = func_ov000_0219bf90();
    if (o != NULL) {
        if (func_ov000_021b4738(o)) {
            return;
        }
        self->unk_90 = o->id;
        dist = VEC_Distance(&self->pos, &o->pos);
    }
    if (dist > 0x12000) {
        self->unk_93_4 = 0;
        return;
    }
    if (self->unk_1a == 1) {
        if (dist > 0xa000) {
            Ov009Sub48 *s48;
            func_ov000_02198360(self->unk_40, 0, 0);
            self->unk_38->unk_c2_0 = 0;
            s48 = self->unk_48;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            self->unk_44->unk_22_1 = 0;
            self->unk_93_4 = 0;
            return;
        }
        self->unk_40->flags |= 2;
        self->unk_1a = 0;
        self->unk_38->unk_c2_0 = 1;
    } else if (self->unk_1a == 2) {
        if (!self->unk_93_4) {
            Ov009Vec a;
            Ov009Vec b;
            a.x = o->pos.x;
            a.y = o->pos.y;
            a.z = o->pos.z;
            b.x = self->pos.x;
            b.y = self->pos.y;
            b.z = self->pos.z;
            a.y += FLD(s32, o, 0x6c);
            b.y += FLD(s32, self, 0x6c);
            if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) != -0x1000) {
                return;
            }
        }
    }
    self->unk_93_4 = 1;
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    {
        Ov009Actor *e = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        if (e != NULL && FLD(u16, e, 0x16) <= 3) {
            if (self->unk_b6 != 0) {
                self->unk_b6--;
            }
        }
    }
    if (self->unk_b6 != 0 && dist > 0x4000) {
        return;
    }
    self->unk_40->flags |= 0x8000;
    self->unk_b6 = 0x5a;
}

}
