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
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d398(Ov009Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern Ov009Actor *func_ov000_02192b24(void *desc);
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void MTX_Identity43_(void *p);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
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
        VEC_Add(&self->unk_84, &t, &t);
        self->unk_b8 = t;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        t = self->unk_b8;
        d.x = t.x - self->pos.x;
        d.y = t.y - self->pos.y;
        d.z = t.z - self->pos.z;
        VEC_MultAdd(0x29, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &t) <= 0x1000) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

#pragma force_active on
Ov009Actor *func_ov009_02200b48(Ov009Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov009_02216d20;
    MIi_CpuClear32(0, &FLD(u8, self, 0xf8), 0x34);
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
    MTX_Identity43_(&FLD(u8, self, 0xfc));
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov009_021ff690);
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

extern void *data_ov000_021ccd68;
extern void *data_ov009_02215d0c[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void MI_Copy48B(const void *src, void *dst);
extern void func_ov003_021d3008(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

struct Ov009EaBits {
    u16 b0 : 3;
    u16 b3 : 8;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 2;
};

struct Ov009PosMsg {
    Ov009Vec pos;
    u16 rot[3];
    u32 unk_14;
};

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

void func_ov009_02200d00(Ov009Actor *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov009Actor *a;
    u32 zero = 0;
    s16 t;
    if (!(FLD(u16, self, 0xf0) & 1)) {
        u16 *p = self->unk_50;
        u16 v = self->unk_b0->unk_08;
        if (*p < v) {
            *p = v;
            self->unk_40->flags = zero;
            func_ov000_02198360(self->unk_40, 0x11, zero);
        }
        ((Ov009EaBits *)&FLD(u16, self, 0xea))->b11 = 0;
        a = Ov009_FindActor(FLD(u16, self, 0xf4));
        if (a != NULL) {
            if (Ov009_Mode(a) == 9) {
                Ov009Sub44 *s = self->unk_44;
                if (!(s->unk_22_0 == 1 && s->unk_22_1 == 1)) {
                    s->unk_22_0 = 1;
                    s->unk_22_1 = 1;
                }
                func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[10], 0x1000, zero);
                Ov009Pair_SetB((Ov009Pair *)&self->unk_50[4], 0x31);
                func_ov000_02198360(self->unk_40, 0x13, zero);
            } else {
                if (((Ov009EaBits *)&FLD(u16, self, 0xea))->b13) {
                    MI_Copy48B(&FLD(u8, self, 0xfc), mtx);
                    func_ov000_0218d398(a, self->id, 8, TRUE, 0x30, mtx);
                    msg.pos = FLD(Ov009Vec, self, 0x120);
                } else {
                    msg.pos = self->pos;
                }
                msg.rot[0] = self->rot[0];
                msg.rot[1] = self->rot[1];
                msg.rot[2] = self->rot[2];
                msg.unk_14 = zero;
                func_ov000_0218d398(a, self->id, 7, TRUE, 0x18, &msg);
                ((Ov009EaBits *)&FLD(u16, self, 0xea))->b0 = 3;
                goto tail;
            }
        }
        FLD(u16, self, 0xf4) = 0xffff;
        FLD(u16, self, 0xf0) |= 1;
        FLD(u16, self, 0xf6) = 0x1800;
    }
tail:
    func_ov003_021d3008(self);
    if (!(FLD(u16, self, 0xf0) & 1)) {
        self->unk_94_1 = 1;
    }
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        return;
    }
    if (!(self->unk_48->unk_50 & 0x400)) {
        return;
    }
    t = self->unk_1a + 1;
    if (t % 20 == 0) {
        t = 0;
        func_02065f88(0x2bd, &self->pos)->v0c(Ov009_FxMul(FLD(s32, self->unk_38, 0xa8), 0x199a));
    }
    self->unk_1a = t;
}

}
