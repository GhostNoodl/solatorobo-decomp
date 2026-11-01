#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_0214a420;
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *p, s32 a);
void func_ov000_02191418(void *p, u16 delay, BOOL force);
VObj *func_020657b0(void *a, void *b);
void func_01ffc9fc(VecFx32 *out, void *a, u16 ang);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

void func_ov000_0219d730(Robo021ca458 *self) {
    void *zero = NULL;
    s32 t = func_0203db40((u8 *)self + 0x24);
    VObj *o;
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
        o = func_020657b0(data_0214a420, LFLD(void *, self, 0xb40));
        if (o != NULL) {
            VecFx32 v;
            VecFx32 p;
            v.x = LFLD(s32, o, 0x40);
            v.y = LFLD(s32, o, 0x44);
            v.z = LFLD(s32, o, 0x48) + 0xf6;
            o->vfunc_10(&v);
            p = self->pos;
            if (!self->unk_b22_3) {
                p.y += self->unk_68 >> 2;
            } else {
                p.y += self->unk_6c;
            }
            o->vfunc_18(&p);
            if (!self->unk_b2c_1) {
                o->vfunc_30((u8 *)self + 0x7c);
            }
        } else {
            LFLD(void *, self, 0xb40) = zero;
        }
    }
    if (LFLD(void *, self, 0xb44) != NULL) {
        o = func_020657b0(data_0214a420, LFLD(void *, self, 0xb44));
        if (o == NULL) {
            LFLD(void *, self, 0xb44) = zero;
        } else {
            o->vfunc_18((u8 *)self + 0x70);
        }
    }
    if (LFLD(void *, self, 0xb48) != NULL) {
        o = func_020657b0(data_0214a420, LFLD(void *, self, 0xb48));
        if (o == NULL) {
            LFLD(void *, self, 0xb48) = zero;
            return;
        }
        {
            u16 r[3];
            VecFx32 w;
            VecFx32 s;
            r[0] = self->unk_b58 + self->rot_x;
            r[1] = self->unk_b5a + self->rot_y;
            r[2] = self->unk_b5c + self->rot_z;
            o->vfunc_30(r);
            func_01ffc9fc(&w, (u8 *)self + 0xb4c, r[1]);
            VEC_Add(&w, (VecFx32 *)((u8 *)self + 0x70), &w);
            o->vfunc_18(&w);
            s = LFLD(VecFx32, o, 0x40);
            s.x += ((s16)self->unk_b5e);
            s.y += ((s16)self->unk_b5e);
            s.z += ((s16)self->unk_b5e);
            o->vfunc_10(&s);
        }
    }
}
}
