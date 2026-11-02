#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern u8 NNS_G3dGlb[];
extern u8 data_02092844[];
extern u8 data_02092800[];
extern u8 *data_02097dc8;
void MIi_CpuCopyFast(void *a, void *b, s32 c);
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

typedef struct LoAnimC {
    u8 rgb[4];
    u8 pad[0x84];
    u8 *frames[0x20];
    u8 cnt;
    u8 pad2;
    u16 state;
    u16 idx;
    u16 timer;
    u16 period;
} LoAnimC;

static inline BOOL LoAnimValid(LoAnimC *p) {
    if (p == NULL || p->state == 0) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0215c0c4(Lo021cadcc *self, void *a, s32 *pos, s32 d) {
    if (a == NULL) {
        return;
    }
    self->vfunc_64(a, pos, d);
    if (self->flags & 0x80000) {
        if (self->unk_84) {
            s32 py;
            s32 px;
            px = pos[0];
            py = pos[1];
            s32 x = self->vfunc_30();
            s32 y = self->vfunc_34();
            self->unk_84->vfunc_20(x + (px >> 12), y + (py >> 12));
            self->unk_84->vfunc_90();
        }
    } else if (self->state == 2 && self->unk_84) {
        self->unk_84->vfunc_90();
    }
    if (self->title) {
        self->vfunc_60(a, pos, d);
    }
    self->flags |= 0x200;
}

}
