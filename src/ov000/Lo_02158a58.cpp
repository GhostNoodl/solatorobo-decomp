#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

BOOL Model_IsReady(void *a, s32 b);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
BOOL func_ov000_02151664(UiList *p, UiListItem *msg);

void UiList021cb4a8_DrawLabels(UiList021cb4a8 *self, s32 unused, s32 *pos) {
    s32 px;
    s32 a;
    s32 y;
    s32 z;
    UiLabel *q;
    px = pos[0];
    a = self->vfunc_8c();
    a += self->vfunc_30() + (px >> 12);
    y = (pos[1] >> 12) - 2;
    if (self->unk_d4) {
        s32 c = self->vfunc_f0();
        z = self->posZ;
        q = self->unk_d4;
        q->x = a + c;
        q->y = y;
        q->z = z - 0x40;
        UiLabel_Draw(self->unk_d4);
    }
    if (self->unk_d8) {
        px = pos[0];
        a = self->vfunc_88();
        a = self->vfunc_94() + (px >> 12) + (a >> 1);
        if (self->flags & 0x800000) {
            a += 10;
        }
        z = self->posZ - 0x40;
        q = self->unk_d8;
        q->x = a;
        q->y = y;
        q->z = z;
        UiLabel_Draw(self->unk_d8);
    }
}

}
