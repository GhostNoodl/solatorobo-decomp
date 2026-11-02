#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *p, s32 a);
void func_ov000_02191418(void *p, u16 delay, BOOL force);
void func_01ffc9fc(VecFx32 *out, void *a, u16 ang);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

void func_ov000_0219d730(Robo021ca458 *self) {
    void *zero = NULL;
    s32 t = func_0203db40((u8 *)self + 0x24);
    EffectObj *o;
    if (self->unk_b24_2) {
        func_ov000_02190a80((u8 *)self + 0xac, t);
        func_ov000_02191418((u8 *)self + 0x368, 1, (BOOL)zero);
    } else {
        if (!self->unk_b24_1) {
            func_ov000_02190a80((u8 *)self + 0xac, t);
            if (self->unk_b24_21) {
                func_ov000_02190a80((u8 *)self + 0x778, 0x1000);
            }
            func_ov000_02191418((u8 *)self + 0x368, 1, 0);
        }
        if (self->unk_b22_0 && self->unk_998 != NULL) {
            func_ov000_02190a80(self->unk_998, 0x1000);
        }
    }
    func_ov000_02190a80((u8 *)self + 0x368, t);
    if (LFLD(void *, self, 0xb40) != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b40);
        if (o != NULL) {
            VecFx32 v;
            VecFx32 p;
            v.x = o->scale.x;
            v.y = o->scale.y;
            v.z = o->scale.z + 0xf6;
            o->SetScale(&v);
            p = self->pos;
            if (!self->unk_b22_3) {
                p.y += self->height >> 2;
            } else {
                p.y += self->centerY;
            }
            o->SetPos(&p);
            if (!self->unk_b2c_1) {
                o->SetRot(&self->rot);
            }
        } else {
            LFLD(void *, self, 0xb40) = zero;
        }
    }
    if (LFLD(void *, self, 0xb44) != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b44);
        if (o == NULL) {
            LFLD(void *, self, 0xb44) = zero;
        } else {
            o->SetPos(&self->pos);
        }
    }
    if (LFLD(void *, self, 0xb48) != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b48);
        if (o == NULL) {
            LFLD(void *, self, 0xb48) = zero;
            return;
        }
        {
            Rot16 r;
            VecFx32 w;
            VecFx32 s;
            r.x = self->unk_b58 + self->rot_x;
            r.y = self->unk_b5a + self->rot_y;
            r.z = self->unk_b5c + self->rot_z;
            o->SetRot(&r);
            func_01ffc9fc(&w, (u8 *)self + 0xb4c, r.y);
            VEC_Add(&w, (VecFx32 *)((u8 *)self + 0x70), &w);
            o->SetPos(&w);
            s = o->scale;
            s.x += ((s16)self->unk_b5e);
            s.y += ((s16)self->unk_b5e);
            s.z += ((s16)self->unk_b5e);
            o->SetScale(&s);
        }
    }
}
}
