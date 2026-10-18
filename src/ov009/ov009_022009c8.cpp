#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov009_02215dc0[];
extern void *data_ov009_02216d20;
extern char data_ov009_02216b89[];
extern char data_ov009_02216b90[];
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_02012be8(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d398(Ov009Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_02016cd8(u32 v, void *dst, u32 size);
extern Ov009Actor *func_ov000_02192b24(void *desc);
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void func_02011820(void *p);
extern void func_020267e8(void *p, void *cb);
extern void func_ov009_021ff690(Ov009Actor *self);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

void func_ov009_022009c8(Ov009Actor *self) {
    Ov009Vec t;
    Ov009Vec d;
    u8 msg;
    Ov009Actor *a;
    switch (self->unk_40->state) {
    case 0:
        if (self->kind == 0x5423) {
            self->unk_84 = FLD(Ov009Vec, self, 0xf8);
            msg = 2;
            a = func_ov000_0219bf90();
            if (a != NULL) {
                func_ov000_0218d398(a, self->id, 0xc, TRUE, 1, &msg);
            }
        }
        func_01ffc9fc(&t, data_ov009_02215dc0, 0x5554);
        func_02012be8(&self->unk_84, &t, &t);
        self->unk_b8 = t;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        t = self->unk_b8;
        d.x = t.x - self->pos.x;
        d.y = t.y - self->pos.y;
        d.z = t.z - self->pos.z;
        func_02012fb8(0x29, &d, &self->pos, &self->pos);
        if (func_02013068(&self->pos, &t) <= 0x1000) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

#pragma force_active on
Ov009Actor *func_ov009_02200b48(Ov009Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov009_02216d20;
    func_02016cd8(0, &FLD(u8, self, 0xf8), 0x34);
    return self;
}
#pragma force_active reset

void func_ov009_02200b78(Ov009Actor *self) {
    Ov009SpawnDesc desc;
    Ov009Actor *o;
    s32 i;
    u8 *p;
    func_ov003_021d0fc0(self);
    FLD(u16, self, 0xf4) = 0xffff;
    desc.kind = 0x408f;
    desc.flags = 0x4000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = func_ov000_02192b24(&desc);
    if (o != NULL) {
        FLD(u16, self, 0xf4) = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->v04();
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b0 = 1;
        if (FLD(u8 *, o, 0x4c) != NULL) {
            FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
        }
    }
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void func_ov009_02200c5c(Ov009Actor *self) {
    Ov009Sub38 *m;
    func_ov003_021d112c(self);
    FLD(s32, self, 0xf8) = func_ov000_021909a8(self->unk_38, data_ov009_02216b89, data_ov009_02216b90);
    func_02011820(&FLD(u8, self, 0xfc));
    m = self->unk_38;
    func_020267e8(m->unk_24, (void *)func_ov009_021ff690);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf8);
    FLD(u16, self, 0xf0) = 0;
    FLD(u16, self, 0xf6) = 0x1000;
}

void func_ov009_02200cdc(Ov009Actor *self) {
    if (FLD(u16, self, 0xf0) & 1) {
        self->unk_ee_7 = 1;
    } else {
        self->unk_ee_7 = 0;
    }
    func_ov003_021d1e8c(self);
}

}
