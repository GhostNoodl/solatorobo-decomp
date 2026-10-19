#include "ov000/LoCommon.h"

typedef struct {
    const void *vtbl;
    u32 unk_04;
    u8 unk_08[0x20];
    s32 unk_28;
    u8 unk_2c[0x8c];
    u32 unk_b8_0 : 4;
    u32 unk_b8_4 : 28;
    u8 unk_bc[0xab4];
    s32 unk_b70;
    s32 unk_b74;
    u8 unk_b78[0x4];
    s32 unk_b7c;
} Obj0214c6b4;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x1f0];
    Obj0214c6b4 *unk_200;
    s32 unk_204;
} Obj0214c668;

typedef struct {
    u8 pad[8];
    u8 *unk_08;
} Glob021ccd24;

extern "C" {

extern const u8 data_0208ba70[];
extern const u8 data_0208bbc8[];
extern Glob021ccd24 data_ov000_021ccd24;
void func_0204c7d0(void *obj);
void func_02050f70(void *obj);
s32 func_0204c08c(void *a, u16 b, s32 *out, s32 c);

static inline void Obj0214c6b4_SetParams(Obj0214c6b4 *obj, s32 a, s32 b) {
    obj->unk_b7c = a;
    obj->unk_b70 = 0;
    obj->unk_b74 = b;
}

static inline BOOL HasWin(Obj0214c668 *w) {
    return w->unk_200 != NULL ? TRUE : FALSE;
}

void func_ov000_0214f7a4(VObj *self) {
    if (LFLD(s32, self, 0x8) == 0xd) {
        s32 n;
        if (LFLD(VObj *, self, 0x5c) != NULL) {
            if (LFLD(VObj *, self, 0x5c)->vfunc_1c()) {
                if (LFLD(u8 *, self, 0x50) != NULL) {
                    LFLD(u32, LFLD(u8 *, self, 0x50), 0xc) |= 4;
                }
            } else {
                LO_FREE_V(self, 0x5c);
            }
        }
        if (LFLD(Obj0214c668 *, self, 0x60) != NULL) {
            if (!HasWin(LFLD(Obj0214c668 *, self, 0x60))) {
                if (LFLD(u16, self, 0x64) != 0xffff) {
                    s32 a;
                    Obj0214c668 *w;
                    Obj0214c6b4 *obj;
                    s32 b;
                    b = func_0204c08c(LFLD(void *, data_ov000_021ccd24.unk_08, 0xbc), LFLD(u16, self, 0x64), &a, 1);
                    w = LFLD(Obj0214c668 *, self, 0x60);
                    w->unk_204 = 0x1e;
                    obj = (Obj0214c6b4 *)func_0203dd9c(0xb80);
                    if (obj != NULL) {
                        obj->vtbl = data_0208ba70;
                        func_0204c7d0(obj);
                        obj->vtbl = data_0208bbc8;
                        func_02050f70(obj);
                    }
                    w->unk_200 = obj;
                    obj->unk_28 = 8;
                    Obj0214c6b4_SetParams(w->unk_200, a, b);
                    w->unk_200->unk_b8_0 = 4;
                    w->unk_200->unk_04 |= 4;
                    w->unk_0c |= 2;
                    LFLD(u32, LFLD(u8 *, self, 0x50), 0xc) |= 4;
                    LFLD(u16, self, 0x64) = 0xffff;
                }
            } else {
                LFLD(u32, LFLD(u8 *, self, 0x50), 0xc) |= 4;
            }
        }
        n = 0;
        if (LFLD(VObj *, self, 0x4c) != NULL && LFLD(VObj *, self, 0x4c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x50) != NULL && LFLD(VObj *, self, 0x50)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x60) != NULL && LFLD(VObj *, self, 0x60)->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
    }
    if (LFLD(u8 *, self, 0x50) != NULL) {
        LFLD(u32, LFLD(u8 *, self, 0x50), 0xc) |= 4;
    }
}

}
