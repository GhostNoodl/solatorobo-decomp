#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb0219cbf8;

typedef struct {
    u16 lo : 6;
    u16 mode : 3;
    u16 b9 : 4;
    u16 b13 : 1;
    u16 hi : 2;
} B22_0219cbf8;

extern "C" {
extern Glb0219cbf8 NNS_G3dGlb;
extern u8 *data_ov000_021ccd6c;
void func_ov000_021bd300(void *p);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);
void func_ov000_02198d28(void *body, VecFx32 *pos, u32 angle);

void func_ov000_0219cbf8(VObj *self, VecFx32 *pos, u16 *rot) {
    LFLD(VecFx32, self, 0x70).x = pos->x;
    LFLD(VecFx32, self, 0x70).y = pos->y;
    LFLD(VecFx32, self, 0x70).z = pos->z;
    if (LFLD(B22_0219cbf8, self, 0xb22).mode != 5) {
        LFLD(VecFx32, self, 0xaf0).x = pos->x;
        LFLD(VecFx32, self, 0xaf0).y = pos->y;
        LFLD(VecFx32, self, 0xaf0).z = pos->z;
    } else {
        LFLD(VecFx32, self, 0xaf0).x = LFLD(VecFx32, self, 0x70).x - NNS_G3dGlb.camPos.x;
        LFLD(VecFx32, self, 0xaf0).y = LFLD(VecFx32, self, 0x70).y - NNS_G3dGlb.camPos.y;
        LFLD(VecFx32, self, 0xaf0).z = LFLD(VecFx32, self, 0x70).z - NNS_G3dGlb.camPos.z;
    }
    LFLD(VecFx32, self, 0xafc).x = LFLD(VecFx32, self, 0xaf0).x;
    LFLD(VecFx32, self, 0xafc).y = LFLD(VecFx32, self, 0xaf0).y;
    LFLD(VecFx32, self, 0xafc).z = LFLD(VecFx32, self, 0xaf0).z;
    {
        u16 ry;
        LFLD(u16, self, 0x7c) = rot[0];
        LFLD(u16, self, 0x7e) = ry = rot[1];
        LFLD(u16, self, 0x80) = rot[2];
        LFLD(u16, self, 0x98) = ry;
    }
    if (LBIT(self, 0xb24).b1) {
        LFLD(VecFx32, self, 0x75c).x = LFLD(VecFx32, self, 0x70).x;
        LFLD(VecFx32, self, 0x75c).y = LFLD(VecFx32, self, 0x70).y;
        LFLD(VecFx32, self, 0x75c).z = LFLD(VecFx32, self, 0x70).z;
        LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
        LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
        LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
    }
    if (LFLD(void *, self, 0x5c) != NULL) {
        func_ov000_021bd300(LFLD(void *, self, 0x5c));
        func_ov000_021bd438(LFLD(void *, self, 0x5c), &LFLD(VecFx32, self, 0x70), 0);
    }
    if (LFLD(void *, self, 0x9b0) != NULL) {
        func_ov000_021bd300(LFLD(void *, self, 0x9b0));
        func_ov000_021bd438(LFLD(void *, self, 0x9b0), &LFLD(VecFx32, self, 0x75c), 0);
    }
    func_ov000_02198d28((u8 *)self + 0x2cc, &LFLD(VecFx32, self, 0x70), LFLD(u16, self, 0x7e));
    LFLD(s32, self, 0x31c) = 0;
    LFLD(s32, self, 0x320) = 0;
    LFLD(s32, self, 0x324) = 0;
    func_ov000_02198d28((u8 *)self + 0x6c0, &LFLD(VecFx32, self, 0x75c), LFLD(u16, self, 0x76e));
    LFLD(s32, self, 0x710) = 0;
    LFLD(s32, self, 0x714) = 0;
    LFLD(s32, self, 0x718) = 0;
    self->vfunc_44();
    LBIT(self, 0xb24).b20 = 0;
    if (data_ov000_021ccd6c[9] == 0xff) {
        LFLD(B22_0219cbf8, self, 0xb22).b13 = 1;
    }
}
}
