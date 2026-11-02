#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits32_0219ff8c;

extern "C" {

void func_ov000_021bd300(void *p);
void func_ov000_021b1a54(u8 *self, BOOL flag);
void func_0203f364(void *p);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);

static inline s32 Dist0219ff8c(Robo021ca458 *self) {
    s32 dx = self->pos.x - self->unk_b10.x;
    s32 dz = self->pos.z - self->unk_b10.z;
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT + 1) >> 1;
}

void func_ov000_0219ff8c(Robo021ca458 *self) {
    self->padCur = 0;
    self->padTrig = 0;
    self->padRelease = 0;
    self->padDir = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b2c_4 = 0;
    LFLD(Bits32_0219ff8c, self->unk_5c, 0).b1 = 0;
    func_ov000_021bd300(((u8 *)self->unk_5c));
    LFLD(Bits32_0219ff8c, self->unk_9b0, 0).b1 = 0;
    func_ov000_021bd300(((u8 *)self->unk_9b0));
    if (self->unk_b24_0) {
        self->unk_b24_0 = 0;
        if (*self->hp == 0) {
            *self->hp = 1;
        }
    }
    if (self->unk_b22_3 && !self->unk_b22_4 &&
        !self->unk_93_4 && !self->unk_b24_0) {
        func_ov000_021b1a54((u8 *)self, TRUE);
    }
    if (self->unk_b28_0 != 0) {
        {
            ActorSub48 *p = self->hit;
            p->unk_9a_3 = 0;
            func_0203f364(p);
        }
        switch (self->unk_b28_0) {
        case 1:
            if (Dist0219ff8c(self) <= 0x400) {
                self->fsm->flags |= 2;
            } else {
                self->fsm->flags |= 4;
            }
            break;
        case 2:
            if (Dist0219ff8c(self) <= 0x400) {
                self->mode = 1;
                self->unk_b28_0 = 0;
                self->unk_b28_2 = 0;
                self->fsm->flags |= 2;
            } else {
                self->fsm->flags |= 4;
            }
            break;
        case 3:
            self->fsm->flags |= 4;
            self->unk_b28_0 = 2;
            break;
        }
        return;
    }
    if (self->unk_b1e != 0xffff) {
        Actor *a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, self->unk_b1e);
        if (a == NULL) {
            self->unk_b1e = 0xffff;
        }
    }
}

}
