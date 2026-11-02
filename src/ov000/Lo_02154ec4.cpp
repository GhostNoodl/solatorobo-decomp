#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"
#include "ov000/UiObj.h"
#include "ov000/SceneRes.h"

typedef struct {
    s32 d;
    VecFx32 pos;
} Arg02154fb0;

extern "C" {

extern void *data_02fe152c;
extern void *data_02097e4c;
void *DataRes_GetTable(void *a, s32 b);
u32 DataRes_GetCount(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void TextWin_Init(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *ActorMgr_FindPlayer(void);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd24.unk_08)) {
        r = FALSE;
    }
    return r;
}


void func_ov000_02154ec4(UiList *self) {
    if (!self->flag4) {
        return;
    }
    switch (self->state) {
    case 0:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 1:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
}

void func_ov000_02154f34(UiList *self) {
    if (self->state == 2) {
        self->openTime = self->openLen;
        self->openRatio = 0x1000;
        self->vfunc_c8();
        self->vfunc_c4();
    }
    self->vfunc_cc();
    self->vfunc_d0();
    self->vfunc_48(2, 0);
}

BOOL Model_IsReady(void *p, s32 a);

static inline void VecAdd(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab) {
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}

static inline BOOL NoB5(UiList *self) {
    return !self->flag5 ? TRUE : FALSE;
}

void func_ov000_02154fb0(UiList *self, s32 a, VecFx32 *pos, s32 d) {
    Arg02154fb0 arg;
    s32 v;
    if (self->fadeRatio == 0) {
        arg.d = d;
        arg.pos = *pos;
        v = a;
    } else {
        v = self->vfunc_18(&arg.pos, &arg.d, LO_FX_MUL(a, 0x1000 - self->fadeRatio));
        {
            VecFx32 ofs;
            ofs.x = self->posX << 12;
            ofs.y = self->posY << 12;
            ofs.z = 0;
            VecAdd(&arg.pos, &ofs, &arg.pos);
        }
    }
    if (self->flags & 0x80000) {
        self->vfunc_d4(v, &arg.pos, arg.d);
    }
    self->vfunc_64(v, &arg.pos, arg.d);
    if (NoB5(self)) {
        self->vfunc_d8(v, &arg.pos, arg.d);
    }
    self->vfunc_e8(v, &arg.pos, arg.d);
    if (!Model_IsReady(self->model, 0xffff)) {
        return;
    }
    if (self->flags & 0x40000) {
        self->vfunc_ec(v, &arg.pos, arg.d);
    }
    self->vfunc_60(a, pos, d);
    self->flags |= 0x200;
}

}
