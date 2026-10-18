#include "ov009/ov009.h"

extern "C" {

extern void func_ov003_021d4fd8(Ov009Actor *self);

void func_ov009_022117ac(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0xfc) = FLD(u8, FLD(u8 *, self, 0x100) + FLD(u8, self, 0xfc) * 16, 0xc);
        FLD(u8, self, 0xfe) = 0;
    }
    func_ov003_021d4fd8(self);
}

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void func_ov000_021911c8(void *m, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern s32 func_02040528(s32 range);
extern s32 func_02040498(s32 max);
void func_ov009_022117e4(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Vec q;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        Ov009Sub48 *s48;
        self->unk_ea_6 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4802, 0x15);
        self->unk_93_4 = 0;
        self->unk_40->state++;
        func_ov000_021911c8(self->unk_38, 0x800);
    }
    case 1: {
        u16 t;
        self->unk_40->timer++;
        t = self->unk_40->timer;
        if (t == 0xdc) {
            Ov009V *e;
            if (FLD(u8, self, 0xff) == 0) {
                return;
            }
            func_ov000_0218996c(0x19, 0x3c);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
            e = func_02065f88(5, &self->pos);
            e->v24(0, FLD(s32, self, 0x6c) + (FLD(s32, self, 0x6c) >> 1), 0);
            e->v14((self->unk_64 >> 1) + 0x3800, (self->unk_64 >> 1) + 0x3800, (self->unk_64 >> 1) + 0x3800);
            return;
        }
        if (t >= 0xfa) {
            {
                s32 b = 0;
                if (FLD(u8, self, 0xff) != 0) {
                    b = 1;
                }
                func_ov003_021d6a3c(self, b, 1, 1);
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
            return;
        }
        if (t >= 0xdc) {
            return;
        }
        if (t % 0x19 != 1) {
            return;
        }
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += FLD(s32, self, 0x68);
        v.x = self->unk_64 + (self->unk_64 >> 1);
        v.y = FLD(s32, self, 0x68) >> 1;
        v.z = self->unk_64 + (self->unk_64 >> 1);
        func_ov000_0219b71c(&p, &v, 0x800, 0xccd, 3, 0x32);
        func_ov000_0218996c(10, 0xf);
        func_02049f44(data_02097e4c, 0x35, &p, 0);
        return;
    }
    case 2: {
        Ov009Sub40 *st = self->unk_40;
        Ov009V *e;
        s32 h;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        q.x = self->pos.x;
        q.y = self->pos.y;
        q.z = self->pos.z;
        q.x += func_02040528(self->unk_64);
        q.z += func_02040528(self->unk_64);
        h = FLD(s32, self, 0x68);
        q.y += h + func_02040528(h >> 2);
        e = func_02065f88(0x325, &q);
        e->v34(0xc000, 0, 0);
        e->v0c(0xccd);
        self->unk_40->timer = func_02040498(0x28) + 0x3c;
        return;
    }
    }
}

}
