#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
s32 func_0203db40(void *p);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void Model0218fe1c_SetAnimDelay(void *p, u16 delay, BOOL force);
void func_01ffc9fc(VecFx32 *out, void *a, u16 ang);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

void Robo021ca458_Animate(Robo021ca458 *self) {
    s32 t = func_0203db40((u8 *)self + 0x24);
    EffectObj *o;
    if (self->unk_b24_2) {
        Model0218fe1c_UpdateAnim(&self->mdl0, t);
        Model0218fe1c_SetAnimDelay(&self->mdl1, 1, FALSE);
    } else {
        if (!self->unk_b24_1) {
            Model0218fe1c_UpdateAnim(&self->mdl0, t);
            if (self->unk_b24_21) {
                Model0218fe1c_UpdateAnim(&self->mdl2, 0x1000);
            }
            Model0218fe1c_SetAnimDelay(&self->mdl1, 1, 0);
        }
        if (self->unk_b22_0 && self->unk_998 != NULL) {
            Model0218fe1c_UpdateAnim(self->unk_998, 0x1000);
        }
    }
    Model0218fe1c_UpdateAnim(&self->mdl1, t);
    if (self->unk_b40 != 0) {
        o = Effect_Find_020657b0(data_0214a420, self->unk_b40);
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
            self->unk_b40 = 0;
        }
    }
    if (self->unk_b44 != 0) {
        o = Effect_Find_020657b0(data_0214a420, self->unk_b44);
        if (o == NULL) {
            self->unk_b44 = 0;
        } else {
            o->SetPos(&self->pos);
        }
    }
    if (self->unk_b48 != 0) {
        o = Effect_Find_020657b0(data_0214a420, self->unk_b48);
        if (o == NULL) {
            self->unk_b48 = 0;
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
