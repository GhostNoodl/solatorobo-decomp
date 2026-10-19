#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);

void func_ov009_02209b20(Ov009Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
    func_ov003_021d6a3c(self, 0, 1, 1);
    self->unk_40->state++;
}

void func_ov009_02209b70(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0x312) = 1;
    }
    switch (self->unk_1a) {
    case 0:
    case 1:
        self->unk_93_4 = 1;
        self->v64();
        break;
    case 2:
        self->unk_93_4 = 1;
        self->v68();
        break;
    }
}


extern u8 data_ov009_022172b5[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern void func_ov000_02191780(void *p);
extern void func_ov000_021917f8(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

void func_ov009_02209bdc(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Vec p2;
    Ov009Vec v2;
    switch (self->unk_1a) {
    case 0:
    case 1:
        switch (self->unk_40->state) {
        case 0: {
            Ov009Sub48 *s48;
            Ov009Sub44 *s44;
            func_ov000_02190cb0(self->unk_38, data_ov009_022172b5, 0x1000, 0);
            func_ov000_02191318(self->unk_38, 0x40000);
            func_ov000_02191780(self->unk_38);
            self->unk_40->timer = 0xc;
            self->unk_40->state++;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            FLD(u16, self, 0x310) = 1;
            break;
        }
        case 1:
            {
                Ov009Sub40 *s = self->unk_40;
                if (s->timer != 0) {
                    s->timer--;
                }
                if (s->timer != 0) {
                    break;
                }
            }
            if (FLD(u16, self, 0x310) % 2 == 0) {
                func_ov000_02191780(self->unk_38);
            } else {
                func_ov000_021917f8(self->unk_38);
            }
            FLD(u16, self, 0x310)++;
            self->unk_40->timer = 0xc;
            if (FLD(u16, self, 0x310) % 2 == 0) {
                p = self->pos;
                if (self->unk_1a == 0) {
                    p.x += self->unk_64;
                } else {
                    p.x -= self->unk_64;
                }
                v.x = self->unk_64 * 2;
                v.y = FLD(s32, self, 0x68);
                v.z = self->unk_64;
                func_ov000_0219b71c(&p, &v, 0x99a, 0x1333, 0x38b, 0x32);
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
            if (FLD(u16, self, 0x310) > 0xd) {
                self->unk_40->state++;
                self->unk_40->timer = 0;
                FLD(u16, self, 0x310) = 0;
                func_ov000_021917f8(self->unk_38);
            }
            break;
        case 2:
            if (func_ov000_02191120(self->unk_38)) {
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                FLD(u8, data_ov000_021ccd54, 0xac) = 1;
                func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                self->v08();
            }
            break;
        }
        break;
    case 2:
        switch (self->unk_40->state) {
        case 0: {
            Ov009Sub48 *s48;
            Ov009Sub44 *s44;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            self->unk_40->timer = 0x18;
            self->unk_40->state++;
            func_ov000_021911c8(self->unk_38, 0x800);
            break;
        }
        case 1: {
            Ov009Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->unk_40->timer = 0x18;
                p2 = self->pos;
                p2.y += 0x5000;
                v2.x = self->unk_64;
                v2.y = FLD(s32, self, 0x68) * 2;
                v2.z = self->unk_64;
                func_ov000_0219b71c(&p2, &v2, 0x99a, 0x1333, 0x38b, 0x32);
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
            if (func_ov000_02191120(self->unk_38)) {
                func_ov000_021911c8(self->unk_38, 0x1000);
                func_020627a0(self->kind, self->id);
                func_020627dc(4);
                FLD(u8, data_ov000_021ccd54, 0xac) = 1;
                func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                self->v08();
            }
            break;
        }
        }
        break;
    }
}

}
