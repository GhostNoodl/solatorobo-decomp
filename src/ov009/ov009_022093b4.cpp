#include "ov009/ov009.h"

extern "C" {

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_022093b4(Ov009Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    self->unk_38->unk_c2_0 = 0;
    FLD(Ov009Bits16, self, 0x2ea).b0 = 0;
    self->unk_40->state++;
}

extern void *data_02097e4c;
extern u8 data_ov009_022172b5[];
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern BOOL func_ov000_02191120(void *m);
extern void func_ov000_02191780(Ov009Sub38 *m);
extern void func_ov000_021917f8(Ov009Sub38 *m);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_022093f8(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172b5, 0x1000, 1);
        self->unk_38->unk_c2_0 = 1;
        func_ov000_02190e98(&FLD(u8, self, 0x228), 1, 0x1000, 1);
        FLD(Ov009Bits16, self, 0x2ea).b0 = 1;
        self->unk_40->state++;
        self->unk_40->timer = 0x41;
        break;
    case 1: {
        Ov009Sub40 *st;
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov009Sub44 *s44 = self->unk_44;
            Ov009Sub48 *s48;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->unk_48;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            func_0203f324(s48);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            if (FLD(u16, self, 0x310) % 2 == 0) {
                func_ov000_02191780(self->unk_38);
            } else {
                func_ov000_021917f8(self->unk_38);
            }
            if (FLD(u16, self, 0x310) == 1 || FLD(u16, self, 0x310) == 5) {
                func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
            }
            FLD(u16, self, 0x310)++;
            self->unk_40->timer = 0xc;
        }
        if (FLD(u16, self, 0x310) > 7) {
            self->unk_40->state++;
            self->unk_40->timer = 0;
            FLD(u16, self, 0x310) = 0;
        }
        break;
    }
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            Ov009Sub44 *s44 = self->unk_44;
            Ov009Sub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
            if (FLD(u8, self, 0x312) != 0) {
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                FLD(u8, data_ov000_021ccd54, 0xac) = 1;
                FLD(u8, self, 0x312) = 0;
            }
        }
        break;
    }
}


struct Ov009Vec3x3 {
    Ov009Vec v[3];
};

extern const Ov009Vec3x3 data_ov009_02215f50;
extern u8 data_ov009_022172af[];
extern void *data_0214a420;
extern void func_ov000_021911c8(void *model, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
extern void *func_020657b0(void *mgr, s32 id);

void func_ov009_02209668(Ov009Actor *self) {
    Ov009Vec3x3 tbl = data_ov009_02215f50;
    Ov009Vec v1;
    Ov009Actor *pl = func_ov000_0218d240(self);
    if (pl == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        u8 i;
        Ov009V *e;
        FLD(u8, self, 0x318) = 3;
        for (i = 0; i < 3; i++) {
            if (func_01ffc584(&pl->pos, &tbl.v[i], pl->unk_64 + 0x2400, 0xf000)) {
                FLD(u8, self, 0x318) = i;
            }
        }
        if (FLD(u8, self, 0x312) != 0) {
            FLD(u8, self, 0x318) = 1;
        }
        if (FLD(u8, self, 0x318) == 3) {
            return;
        }
        {
            Ov009Vec *p = &tbl.v[FLD(u8, self, 0x318)];
            v1.x = p->x;
            v1.z = p->z;
            v1.y = 0x7000;
        }
        e = func_02065f88(0x2bd, &v1);
        e->v0c(0x5000);
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, self, 0x314) = FLD(s32, e, 0x24);
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    }
    case 1: {
        Ov009Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x3c) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x1000, 1);
        self->unk_38->unk_c2_0 = 1;
        self->pos = tbl.v[FLD(u8, self, 0x318)];
        self->unk_40->state = 2;
        break;
    }
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            void *e = func_020657b0(data_0214a420, FLD(s32, self, 0x314));
            Ov009Sub44 *s44;
            Ov009Sub48 *s48;
            if (e != NULL) {
                FLD(s32, e, 0xc8) = 1;
                FLD(s32, self, 0x314) = 0;
            }
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->unk_48;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            func_0203f324(s48);
            func_ov000_021911c8(self->unk_38, 0x99a);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            Ov009Sub44 *s44 = self->unk_44;
            Ov009Sub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            func_ov000_021911c8(self->unk_38, 0x1000);
            {
                Ov009Vec t = tbl.v[FLD(u8, self, 0x318)];
                t.y = 0x7000;
                FLD(Ov009Vec, self, 0x2a0) = t;
            }
            FLD(s32, self, 0x2d0) = 0xccd;
            FLD(s32, self, 0x2d4) = 0xccd;
            FLD(s32, self, 0x2d8) = 0xccd;
            func_ov000_02190e98(&FLD(u8, self, 0x228), 0, 0x1000, 1);
            FLD(Ov009Bits16, self, 0x2ea).b0 = 1;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        if (FLD(u8, self, 0x312) == 0) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        FLD(u8, self, 0x312) = 0;
        FLD(u16, self, 0xb6) = 0xb4;
        break;
    }
}

}
