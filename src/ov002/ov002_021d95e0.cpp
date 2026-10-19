#include "ov002/ov002.h"

extern "C" {

typedef struct Bits021d95e0 {
    u16 b0 : 1;
    u16 mode : 2;
    u16 rest : 13;
} Bits021d95e0;

void *func_02043548(void *p);
void func_0206ce78(void *a, u16 b);
void func_ov002_021d7058(void *self);
void func_ov002_021d98ac(void *self);

static inline void ov002_Vec_Copy(s32 *src, s32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static inline void ov002_Vec_Set(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline void ov002_Hud_Set(void *hud, u8 k) {
    if (hud != NULL) {
        func_ov002_021e2690(hud, k, 0);
    }
}

void func_ov002_021d95e0(void *self) {
    void *cam;
    void *t;
    if (FIELD(data_0214a424, 0x12a, u16) == 0x9000 && FIELD(data_0214a424, 0x18, Bits021d95e0).mode != 0) {
        func_0206ce78(data_0214a424, 0x9001);
    }
    FIELD(FIELD(self, 0x4, void *), 0x68, u16) = FIELD(data_0214a424, 0x12a, u16);
    func_ov002_021d7058(FIELD(self, 0x4, void *));
    cam = func_0203dd9c(0x24);
    if (cam != NULL) {
        cam = func_02043548(cam);
    }
    FIELD(self, 0x8c, void *) = cam;
    ov002_Vec_Copy((s32 *)(data_ov002_021eef74 + 0x70), (s32 *)cam);
    ov002_Vec_Set((s32 *)((u8 *)FIELD(self, 0x8c, void *) + 0xc), -0x2b8, 0, 0x2b8);
    ov002_Vec_Set((s32 *)((u8 *)FIELD(self, 0x8c, void *) + 0x18), 0, 0x1000, 0);
    FIELD(self, 0x90, s32) = -1;
    FIELD(self, 0x94, s32) = 0x14;
    func_ov002_021d98ac(self);
    t = func_ov000_02173610(0x1b);
    if (t != NULL && FIELD(self, 0x75, u8) != 0) {
        ov002_Hud_Set(FIELD(t, 0x3c, void *), FIELD(self, 0x74, u8));
        FIELD(self, 0x75, u8) = 0;
    }
    t = func_ov000_02173610(0x1b);
    if (t != NULL && FIELD(t, 0x3c, void *) != NULL) {
        MI_CpuCopy8((u8 *)self + 0x76, FIELD(t, 0x3c, u8 *) + 0x2c, 0x14);
    }
}

}
