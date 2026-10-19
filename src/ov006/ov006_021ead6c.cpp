#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_State021ead6c {
    u16 phase;
    u16 timer;
} ov006_State021ead6c;

typedef struct ov006_Msg021ead6c {
    u16 a;
    u8 b;
    u16 c;
} ov006_Msg021ead6c;

typedef struct ov006_Tgt021ead6c {
    u8 unk0[0x70];
    VecFx32 pos;
} ov006_Tgt021ead6c;

typedef struct ov006_Obj021ead6c {
    u8 unk0[0xc];
    u16 unkC;
    u8 unkE[0x32];
    ov006_State021ead6c *unk40;
    u8 unk44[0x2c];
    VecFx32 unk70;
    u16 rot[3];
    u8 unk82[0xe];
    u16 unk90;
    u8 unk92[0xa];
    VecFx32 unk9C;
    u8 unkA8[0x14];
    s32 unkBC;
    VecFx32 unkC0;
} ov006_Obj021ead6c;

#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
void *func_02065f88(s32 id, VecFx32 *pos);
void func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *pos, u16 *rot,
                         s32 f, s32 g, s32 h, s32 i);
void func_ov000_0218bed8(void *a, s32 b, void *actor);
ov006_Tgt021ead6c *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_01ffc198(VecFx32 *a, VecFx32 *b, s32 r);
void func_ov000_0218d398(ov006_Tgt021ead6c *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

static inline ov006_Tgt021ead6c *GetTgt(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void RotYXZ(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL any = FALSE;
    ry = rot[1];
    rz = rot[2];
    rx = rot[0];
    MTX_Identity33_(m);
    if (ry != 0) {
        MTX_RotY33_(m, SC(ry));
        any = TRUE;
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
            any = TRUE;
        }
    }
    if (rz != 0) {
        if (any) {
            MTX_RotZ33_(&t, SC(rz));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, SC(rz));
        }
    }
}

#define MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov006_021ead6c(ov006_Obj021ead6c *self) {
    VecFx32 d;
    MtxFx33 m;
    ov006_Msg021ead6c msg;
    void *p;
    BOOL done;
    ov006_Tgt021ead6c *tgt;
    ov006_State021ead6c *st;
    switch (self->unk40->phase) {
    case 0:
        p = func_02065f88(0x324, &self->unk70);
        if (p != NULL) {
            self->unkBC = ((s32 *)p)[9];
            VCALL(p, 0C, 0x2000);
        }
        self->unk40->phase++;
    case 1:
        st = self->unk40;
        st->timer++;
        if (st->timer < 150) {
            done = FALSE;
            if (self->unk90 != 0xffff && (tgt = GetTgt(self->unk90)) != NULL) {
                d = tgt->pos;
                if (func_01ffc198(&d, &self->unk70, 0x2800)) {
                    msg.b = 0x11;
                    msg.a = 1;
                    msg.c = self->unkC;
                    func_ov000_0218d398(tgt, self->unkC, 9, 0, 6, &msg);
                    self->unk40->phase++;
                }
                d.x -= self->unk70.x;
                d.y -= self->unk70.y;
                d.z -= self->unk70.z;
                VEC_Normalize(&d, &d);
                self->unk9C.x = MUL(d.x, 0x4c00);
                self->unk9C.y = MUL(d.y, 0x4c00);
                self->unk9C.z = MUL(d.z, 0x4c00);
                self->rot[0] = FX_AsinIdx(-d.y);
                self->rot[1] = FX_Atan2(d.x, d.z);
                self->rot[2] = 0;
                done = TRUE;
            }
            if (!done) {
                RotYXZ(&m, self->rot);
                self->unk9C.x = 0;
                self->unk9C.y = 0;
                self->unk9C.z = 0x4c00;
                MTX_MultVec33(&self->unk9C, &m, &self->unk9C);
            }
            VEC_Add(&self->unk70, &self->unk9C, &self->unk70);
            self->unkC0.x = MUL(self->unk9C.x, -0x266);
            self->unkC0.y = MUL(self->unk9C.y, -0x266);
            self->unkC0.z = MUL(self->unk9C.z, -0x266);
        } else {
            self->unk40->phase++;
        }
        break;
    case 2:
        p = func_02065f88(5, &self->unk70);
        if (p != NULL) {
            VCALL(p, 0C, 0x5000);
        }
        func_02049f44(data_02097e4c, 0x56, &self->unk70, 0);
        func_ov000_0219aae8(self, self, 1, 0x11, 0x80, NULL, NULL, 0x7800, 0, -1, 0x1000);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        VCALL(self, 08);
        break;
    }
}

}
