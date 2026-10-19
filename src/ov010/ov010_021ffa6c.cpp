#include "ov010/ov010.h"

struct Ov010Fade {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    u16 timer;
    u16 unk_06;
    s32 state;
    s32 unk_0c;
    s32 key;
    void (*getPos)(Ov010Vec *out, u8 *obj);
};

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Ov010V *func_020657b0(void *a, s32 b);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);

static inline u8 Ov010_Clamp31(u8 v) {
    return v > 0x1f ? 0x1f : v;
}

void func_ov010_021ffa6c(Ov010Fade *self) {
    u8 *tgt;
    s32 flag;
    Ov010V *obj;
    s32 x;
    s32 v;

    if (!self->b0) {
        return;
    }
    if (self->state != 0) {
        obj = func_020657b0(data_0214a420, self->key);
        u16 id = self->id;
        tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        if (obj == NULL || tgt == NULL) {
            self->state = 2;
            self->timer = 0;
        } else if (self->b1) {
            FLD(u8, obj, 0xd0) = 1;
        } else {
            Ov010Vec c;
            Ov010Vec b;
            Ov010Vec a;
            x = 0x1f;
            flag = 0;
            FLD(u8, obj, 0xd0) = 0;
            switch (self->state) {
            case 1:
                if (self->timer == 0) {
                    FLD(u8, obj, 0xd0) = 0;
                    FLD(s32, obj, 0xc8) = -1;
                    flag = 1;
                }
                break;
            case 2:
                FLD(u8, obj, 0xd0) = 1;
                obj->v0c(FLD(s32, obj, 0x40) + (s32)(((s64)(0x2800 - FLD(s32, obj, 0x40)) * 0x280 + 0x800) >> 12));
                x = 0x1f - self->timer * 2;
                if (self->timer > 0x1e) {
                    FLD(s32, obj, 0x1c) = 4;
                    self->state = 0;
                    self->timer = 0;
                }
                break;
            }
            v = x - (0x1f - self->unk_01);
            if (v > 0x1f) {
                v = 0x1f;
            } else if (v < 1) {
                v = 1;
            }
            FLD(s32, obj, 0x7c) = FX_Div(Ov010_Clamp31(v) << 12, 0x1f000);
            self->getPos(&a, tgt);
            *(Ov010Blk12 *)&b = *(Ov010Blk12 *)&a;
            c.x = FLD(s32, tgt, 0x70);
            c.y = FLD(s32, tgt, 0x74);
            c.z = FLD(s32, tgt, 0x78);
            obj->v18(&c);
            obj->v20(&b);
            if (flag) {
                func_02049f44(data_02097e4c, 0x7a, &c, 0);
            }
            self->timer++;
        }
    }
    self->b1 = 0;
}

}
