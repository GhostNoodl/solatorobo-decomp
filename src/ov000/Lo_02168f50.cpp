#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

extern "C" {

typedef struct {
    s32 timer;
    s32 unk_04;
    VObj *obj;
} LoTimedObj;

typedef struct {
    u8 pad[0x360];
    LoTimedObj objs[10];
} LoTimedHost;

Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void func_ov000_0216bcbc(void *self);

void func_ov000_02168f50(Lo021cb840 *self) {
    Robo021ca458 *p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    self->unk_80 = p->pos.x;
    self->unk_84 = p->pos.y;
    self->unk_88 = p->pos.z;
    VEC_Add((VecFx32 *)((u8 *)self + 0x80), (VecFx32 *)((u8 *)self + 0x9c), (VecFx32 *)((u8 *)self + 0x80));
}

}
