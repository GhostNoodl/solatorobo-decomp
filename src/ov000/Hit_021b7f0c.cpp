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

BOOL func_ov000_021b7f0c(u8 *self) {
    BOOL ok = TRUE;
    if (LFLD(s16, self, 0x10) >= 0) {
        if (!func_ov000_021b6d28(self + 8)) {
            ok = FALSE;
        } else {
            s32 a = 0;
            s32 m;
            if (!LFLD(Flags021b7f0c, self, 0xf6).b0 && !LFLD(Flags021b7f0c, self, 0xf6).b1) {
                a = ok;
            }
            m = 0;
            if (LFLD(Flags021b7f0c, self, 0xf6).b1) {
                m = 2;
            }
            func_ov000_021b70c0(self + 0x2c, self + 8, LFLD(s32, self, 0xf0), LFLD(u8, self, 0xf4), a, m);
            if (LFLD(void *, self, 0x28) != NULL) {
                Mtx021b7f0c mtx;
                void *mesh;
                s32 scale;
                MI_Copy36B(self + 0xb4, mtx.m);
                { s32 x = LFLD(s32, self, 0xa8); s32 y = LFLD(s32, self, 0xac); s32 z = LFLD(s32, self, 0xb0); mtx.t.x = x; mtx.t.y = y; mtx.t.z = z; }
                scale = LFLD(s32, self, 0xd8);
                mesh = func_0203dd9c(0x98);
                if (mesh != NULL) {
                    func_0203f80c(mesh);
                }
                LFLD(void *, self, 0xec) = mesh;
                func_0203f990(mesh, *LFLD(void **, self, 0x28));
                func_0203f9dc(LFLD(void *, self, 0xec), &mtx);
                func_0203f9b8(LFLD(void *, self, 0xec), scale);
                func_0203f8d8(LFLD(void *, self, 0xec));
            }
        }
    }
    return ok;
}
}
