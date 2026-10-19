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

void func_ov000_0219d730(u8 *self) {
    void *zero = NULL;
    s32 t = func_0203db40(self + 0x24);
    VObj *o;
    if (LFLD(B24_0219d730, self, 0xb24).b2) {
        func_ov000_02190a80(self + 0xac, t);
        func_ov000_02191418(self + 0x368, 1, (BOOL)zero);
    } else {
        if (!LFLD(B24_0219d730, self, 0xb24).b1) {
            func_ov000_02190a80(self + 0xac, t);
            if (LFLD(B24_0219d730, self, 0xb24).b21) {
                func_ov000_02190a80(self + 0x778, 0x1000);
            }
            func_ov000_02191418(self + 0x368, 1, 0);
        }
        if (LFLD(B22_0219d730, self, 0xb22).b0 && LFLD(void *, self, 0x998) != NULL) {
            func_ov000_02190a80(LFLD(void *, self, 0x998), 0x1000);
        }
    }
    func_ov000_02190a80(self + 0x368, t);
    if (LFLD(void *, self, 0xb40) != NULL) {
        o = func_020657b0(data_0214a420, LFLD(void *, self, 0xb40));
        if (o != NULL) {
            VecFx32 v;
            VecFx32 p;
            v.x = LFLD(s32, o, 0x40);
            v.y = LFLD(s32, o, 0x44);
            v.z = LFLD(s32, o, 0x48) + 0xf6;
            o->vfunc_10(&v);
            p = LFLD(VecFx32, self, 0x70);
            if (!LFLD(B22_0219d730, self, 0xb22).b3) {
                p.y += LFLD(s32, self, 0x68) >> 2;
            } else {
                p.y += LFLD(s32, self, 0x6c);
            }
            o->vfunc_18(&p);
            if (!LFLD(B2c_0219d730, self, 0xb2c).b1) {
                o->vfunc_30(self + 0x7c);
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
            o->vfunc_18(self + 0x70);
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
            r[0] = LFLD(u16, self, 0xb58) + LFLD(u16, self, 0x7c);
            r[1] = LFLD(u16, self, 0xb5a) + LFLD(u16, self, 0x7e);
            r[2] = LFLD(u16, self, 0xb5c) + LFLD(u16, self, 0x80);
            o->vfunc_30(r);
            func_01ffc9fc(&w, self + 0xb4c, r[1]);
            VEC_Add(&w, (VecFx32 *)(self + 0x70), &w);
            o->vfunc_18(&w);
            s = LFLD(VecFx32, o, 0x40);
            s.x += LFLD(s16, self, 0xb5e);
            s.y += LFLD(s16, self, 0xb5e);
            s.z += LFLD(s16, self, 0xb5e);
            o->vfunc_10(&s);
        }
    }
}
}
