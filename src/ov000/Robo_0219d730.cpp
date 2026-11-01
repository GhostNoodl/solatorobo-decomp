#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 17;
    u32 b21 : 1;
    u32 rest : 10;
} B24_0219d730;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219d730;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} B2c_0219d730;

extern "C" {
extern void *data_0214a420;
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *p, s32 a);
void func_ov000_02191418(void *p, u16 delay, BOOL force);
VObj *func_020657b0(void *a, void *b);
void func_01ffc9fc(VecFx32 *out, void *a, u16 ang);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

struct Obj0219d730 {
    u8 unk_00[0x68];
    s32 unk_68;
    s32 unk_6c;
    VecFx32 unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x916];
    void *unk_998;
    u8 unk_99c[0x186];
    B22_0219d730 unk_b22;
    B24_0219d730 unk_b24;
    u8 unk_b28[0x4];
    B2c_0219d730 unk_b2c;
    u8 unk_b2e[0x12];
    void *unk_b40;
    void *unk_b44;
    void *unk_b48;
    u8 unk_b4c[0xc];
    u16 unk_b58;
    u16 unk_b5a;
    u16 unk_b5c;
    s16 unk_b5e;
};

void func_ov000_0219d730(Obj0219d730 *self) {
    void *zero = NULL;
    s32 t = func_0203db40((u8 *)self + 0x24);
    VObj *o;
    if (self->unk_b24.b2) {
        func_ov000_02190a80((u8 *)self + 0xac, t);
        func_ov000_02191418((u8 *)self + 0x368, 1, (BOOL)zero);
    } else {
        if (!self->unk_b24.b1) {
            func_ov000_02190a80((u8 *)self + 0xac, t);
            if (self->unk_b24.b21) {
                func_ov000_02190a80((u8 *)self + 0x778, 0x1000);
            }
            func_ov000_02191418((u8 *)self + 0x368, 1, 0);
        }
        if (self->unk_b22.b0 && self->unk_998 != NULL) {
            func_ov000_02190a80(self->unk_998, 0x1000);
        }
    }
    func_ov000_02190a80((u8 *)self + 0x368, t);
    if (self->unk_b40 != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b40);
        if (o != NULL) {
            VecFx32 v;
            VecFx32 p;
            v.x = LFLD(s32, o, 0x40);
            v.y = LFLD(s32, o, 0x44);
            v.z = LFLD(s32, o, 0x48) + 0xf6;
            o->vfunc_10(&v);
            p = self->unk_70;
            if (!self->unk_b22.b3) {
                p.y += self->unk_68 >> 2;
            } else {
                p.y += self->unk_6c;
            }
            o->vfunc_18(&p);
            if (!self->unk_b2c.b1) {
                o->vfunc_30((u8 *)self + 0x7c);
            }
        } else {
            self->unk_b40 = zero;
        }
    }
    if (self->unk_b44 != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b44);
        if (o == NULL) {
            self->unk_b44 = zero;
        } else {
            o->vfunc_18((u8 *)self + 0x70);
        }
    }
    if (self->unk_b48 != NULL) {
        o = func_020657b0(data_0214a420, self->unk_b48);
        if (o == NULL) {
            self->unk_b48 = zero;
            return;
        }
        {
            u16 r[3];
            VecFx32 w;
            VecFx32 s;
            r[0] = self->unk_b58 + self->unk_7c;
            r[1] = self->unk_b5a + self->unk_7e;
            r[2] = self->unk_b5c + self->unk_80;
            o->vfunc_30(r);
            func_01ffc9fc(&w, (u8 *)self + 0xb4c, r[1]);
            VEC_Add(&w, (VecFx32 *)((u8 *)self + 0x70), &w);
            o->vfunc_18(&w);
            s = LFLD(VecFx32, o, 0x40);
            s.x += self->unk_b5e;
            s.y += self->unk_b5e;
            s.z += self->unk_b5e;
            o->vfunc_10(&s);
        }
    }
}
}
