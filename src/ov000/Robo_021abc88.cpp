#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 rest : 7;
} G18_021abc88;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Bits16_021abc88;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits8_021abc88;

extern "C" {
extern u8 data_ov000_021cc62a[];
extern u8 data_ov000_021cc6c0[];
extern u8 data_ov000_021cc5e3[];
extern u8 *data_0214a424;
extern void *data_02097e4c;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_02062764(s32 a, s32 b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
void Actor_TurnToPos(void *self, void *v, s32 a);
void Actor_MoveToPos(void *self, const VecFx32 *target, s32 turn);
BOOL func_ov000_02191120(void *a);
void Body_SetPos(void *body, VecFx32 *pos, u32 angle);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);

void func_ov000_021abc88(Robo021ca458 *self) {
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    LFLD(Bits16_021abc88, self->unk_44, 0x22).b1 = 0;
    switch (self->fsm->st) {
    case 0: {
        s32 dx;
        s32 dz;
        self->unk_b24_2 = 1;
        func_ov000_02190cb0((u8 *)self + 0xac, data_ov000_021cc62a, 0x800, 0);
        dx = self->unk_75c.x - self->pos.x;
        dz = self->unk_75c.z - self->pos.z;
        self->unk_178 = -1;
        {
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            REG_SQRT_PARAM = (u64)(sq << 2);
        }
        while (REG_SQRTCNT & 0x8000) {
        }
        self->speed = (s32)(REG_SQRT_RESULT + 1) >> 5;
        self->velY = 0x53f;
        self->gravity = 0x52;
        self->target = 0xffff;
        self->friction = 0;
        func_02049f44(data_02097e4c, 7, (u8 *)self + 0x70, 0);
        self->fsm->st++;
        self->fsm->timer = 0;
        LFLD(G18_021abc88, data_0214a424, 0x18).b8 = 0;
        func_02062764(3, 1);
        data_ov000_021ccd54->stageFlags = 1;
        break;
    }
    case 1: {
        s32 d;
        u16 *s;
        Actor_TurnToPos(self, (u8 *)self + 0x75c, 0x59a);
        Actor_MoveToPos(self, (VecFx32 *)((u8 *)self + 0x75c), 0);
        d = self->pos.y - self->unk_75c.y;
        if (d < 0x1800) {
            self->pos.y += (self->unk_75c.y + 0x1800 - self->pos.y) >> 2;
        } else if (d > 0x1ccd) {
            self->pos.y += (self->unk_75c.y + 0x1ccd - self->pos.y) >> 2;
        }
        s = (u16 *)self->fsm;
        s[1]++;
        if (s[1] < 0x10) {
            return;
        }
        self->rot_y = func_01ffc128(self->unk_76e, self->rot_y, 0x800, 1, 0x8000);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_ov000_02190cb0((u8 *)self + 0xac, data_ov000_021cc6c0, 0x400, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        if (func_ov000_02191120((u8 *)self + 0xac)) {
            u8 *p;
            self->pos = self->unk_75c;
            self->rot_x = self->unk_76c;
            self->rot_y = self->unk_76e;
            self->rot_z = self->unk_770;
            Body_SetPos((u8 *)self + 0x2cc, (VecFx32 *)((u8 *)self + 0x70), self->rot_y);
            Body_SetPos((u8 *)self + 0x6c0, (VecFx32 *)((u8 *)self + 0x75c), self->unk_76e);
            self->unk_b24_2 = 0;
            self->unk_b24_1 = 1;
            self->unk_b36 = 0;
            func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x155, 0);
            p = self->unk_384;
            if (p != NULL) {
                NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, LFLD(void *, p, 0));
                LFLD(u8, p, 0x108) = 0;
                LFLD(u8, p, 0x110) = 0xff;
                LFLD(Bits8_021abc88, p, 0x111).b0 = 0;
                LFLD(Bits8_021abc88, p, 0x111).b1 = 0;
            }
            func_02049f44(data_02097e4c, 0xe, (u8 *)self + 0x70, 0);
            func_ov000_02198360(self->fsm, 1, 0);
        } else {
            VecFx32 d;
            s32 ty;
            self->rot_y = func_01ffc128(self->unk_76e, self->rot_y, 0x59a, 1, 0x8000);
            ty = self->unk_75c.y + 0x119a;
            {
                s32 tx = self->unk_75c.x;
                s32 tz = self->unk_75c.z;
                d.x = tx - self->pos.x;
                d.y = ty - self->pos.y;
                d.z = tz - self->pos.z;
            }
            VEC_MultAdd(0x400, &d, (VecFx32 *)((u8 *)self + 0x70), (VecFx32 *)((u8 *)self + 0x70));
        }
        break;
    }
}
}
