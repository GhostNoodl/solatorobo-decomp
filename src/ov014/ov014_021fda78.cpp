#include "ov014/ov014.h"

extern "C" {

extern s32 func_ov014_021fe008(Ov014Actor *self, Ov014Msg *msg);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

s32 func_ov014_021fda78(Ov014Actor *self, Ov014Msg *msg) {
    s32 r = 0;
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        r = func_ov014_021fe008(self, msg);
        break;
    case 1:
        if (msg->type == 6) {
            FLD(u8, self, 0xf8) = msg->idx;
            switch (FLD(u16, msg, 6)) {
            case 0x482b:
                break;
            case 0x580c:
            case 0x580d:
            case 0x580e: {
                u16 n = FLD(u8, self, 0xf8) - 1;
                if (!(n != 0 && n != 1 && n != 2)) {
                    u8 bit = 1 << n;
                    if (FLD(u8, self, 0x138) & bit) {
                        FLD(u8, self, 0x138) ^= bit;
                    }
                    FLD(u8, self, 0xf8) = 0xff;
                    FLD(s32, self, 0xf4) |= 1;
                }
                break;
            }
            }
            self->unk_30 |= 1 << msg->type;
            msg->type = 0;
            r = 0;
        } else {
            r = func_ov003_021d1c00(self, msg);
        }
        break;
    }
    return r;
}

extern void *data_ov000_021ccd64;
extern const Ov014Vec data_ov014_02216704[];
extern const Ov014Vec data_ov014_02216564;
extern const u8 data_ov014_0221654c[];
extern const u8 data_ov014_02216740[];
extern const u8 data_ov014_022166aa[];
extern const u8 data_ov014_022166d2[];
extern const u8 data_ov014_02216788[];
extern const u8 data_ov014_0221686c[];
extern const u8 data_ov014_0221652c[];
extern const u8 data_ov014_02216524[];
extern const u8 data_ov014_0221655c[];
extern void func_ov003_021d112c(Ov014Actor *self);
extern BOOL func_ov003_021d8198(void *p);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_0203f324(Ov014Sub48 *p);
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *a);
extern Ov014Actor *func_ov003_021d69a0(Ov014Actor *self, u16 kind, s32 a);
extern void func_01ffc9fc(Ov014Vec *a, const Ov014Vec *b, u16 ang);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *c);
extern void func_ov014_021fd37c(void);
extern void func_ov014_021fd43c(void);

void func_ov014_021fdb78(Ov014Actor *self) {
    Ov014Vec w;
    Ov014Vec v;
    u8 *u;
    Ov014Sub48 *m;
    func_ov003_021d112c(self);
    FLD(s32 *, self, 0xfc) = Ov014_NewFx();
    func_ov003_021d8198((u8 *)self + 0x100);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        FLD(Ov014Flags8, u, 0xa2).b0 = 0;
    }
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    FLD(s32, m, 0x5c) = 0;
    FLD(s32, m, 0x60) = -0xb33;
    FLD(s32, m, 0x64) = 0;
    switch (FLD(s16, self, 0xf0)) {
    case 0: {
        u8 i;
        Ov014Sub44 *n;
        FLD(u32, self, 0xf4) |= 0x40;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        for (i = 0; i < 5; i++) {
            Ov014Actor *o = func_ov003_021d69a0(self, 0x5c19, 0x20);
            if (o != NULL) {
                o->unk_18 = i;
                v = data_ov014_02216704[i];
                func_01ffc9fc(&v, &v, self->rot[1]);
                VEC_Add(&self->pos, &v, &v);
                o->pos.x = v.x;
                o->pos.y = v.y;
                o->pos.z = v.z;
            }
        }
        break;
    }
    case 1:
        FLD(u8, self, 0x139) = 0;
        func_01ffc9fc(&w, &data_ov014_02216564, self->rot[1]);
        VEC_Add(&self->pos, &w, &self->pos);
        self->unk_93_4 = 1;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        FLD(s32, self, 0x12c) = self->pos.x;
        FLD(s32, self, 0x130) = self->pos.y;
        FLD(s32, self, 0x134) = self->pos.z;
        break;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_0221654c);
        FLD(u16, self, 0x13a) = 0x1800;
    }
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov003_021cf1f0((u8 *)self + 0x140, 0, 9, data_ov014_02216740);
        break;
    case 1:
        func_ov003_021cf1f0((u8 *)self + 0x140, 0, 5, data_ov014_022166aa);
        func_ov003_021cf1f0((u8 *)self + 0x140, 1, 6, data_ov014_022166d2);
        func_ov003_021cf1f0((u8 *)self + 0x140, 2, 9, data_ov014_02216788);
        func_ov003_021cf1f0((u8 *)self + 0x140, 3, 11, data_ov014_0221686c);
        func_ov003_021cf1f0((u8 *)self + 0x160, 10, 1, data_ov014_0221652c);
        func_ov003_021cf1f0((u8 *)self + 0x160, 11, 1, data_ov014_02216524);
        func_ov003_021cf1f0((u8 *)self + 0x160, 12, 1, data_ov014_0221655c);
        FLD(Ov014Actor *, self, 0x154) = self;
        FLD(Ov014Actor *, self, 0x174) = self;
        FLD(void *, self, 0x150) = (void *)func_ov014_021fd37c;
        FLD(void *, self, 0x170) = (void *)func_ov014_021fd43c;
        break;
    }
}

}
