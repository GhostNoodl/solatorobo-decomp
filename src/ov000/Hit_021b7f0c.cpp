#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
} Flags021b7f0c;

typedef struct {
    s32 m[9];
    VecFx32 t;
} Mtx021b7f0c;

extern "C" {
void MI_Copy36B(const void *src, void *dst);
void func_0203f80c(void *mesh);
void func_0203f8d8(void *mesh);
void func_0203f990(void *mesh, void *res);
void func_0203f9b8(void *mesh, int scale);
void func_0203f9dc(void *mesh, const void *mtx);
BOOL func_ov000_021b6d28(void *p);
void func_ov000_021b70c0(void *a, void *b, s32 c, u8 d, s32 e, s32 f);

struct Obj021b7f0c {
    u8 unk_00[0x10];
    s16 unk_10;
    u8 unk_12[0x16];
    void **unk_28;
    u8 unk_2c[0x7c];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0x24];
    s32 unk_d8;
    u8 unk_dc[0x10];
    void *unk_ec;
    s32 unk_f0;
    u8 unk_f4;
    u8 unk_f5[0x1];
    Flags021b7f0c unk_f6;
};

BOOL func_ov000_021b7f0c(Obj021b7f0c *self) {
    BOOL ok = TRUE;
    if (self->unk_10 >= 0) {
        if (!func_ov000_021b6d28((u8 *)self + 8)) {
            ok = FALSE;
        } else {
            s32 a = 0;
            s32 m;
            if (!self->unk_f6.b0 && !self->unk_f6.b1) {
                a = ok;
            }
            m = 0;
            if (self->unk_f6.b1) {
                m = 2;
            }
            func_ov000_021b70c0((u8 *)self + 0x2c, (u8 *)self + 8, self->unk_f0, self->unk_f4, a, m);
            if ((void *)self->unk_28 != NULL) {
                Mtx021b7f0c mtx;
                void *mesh;
                s32 scale;
                MI_Copy36B((u8 *)self + 0xb4, mtx.m);
                { s32 x = self->unk_a8; s32 y = self->unk_ac; s32 z = self->unk_b0; mtx.t.x = x; mtx.t.y = y; mtx.t.z = z; }
                scale = self->unk_d8;
                mesh = func_0203dd9c(0x98);
                if (mesh != NULL) {
                    func_0203f80c(mesh);
                }
                self->unk_ec = mesh;
                func_0203f990(mesh, *self->unk_28);
                func_0203f9dc(self->unk_ec, &mtx);
                func_0203f9b8(self->unk_ec, scale);
                func_0203f8d8(self->unk_ec);
            }
        }
    }
    return ok;
}
}
