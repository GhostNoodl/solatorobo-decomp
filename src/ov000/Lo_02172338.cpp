#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char gCommonTextPath[];
extern void *ArcPath_Menu;
extern void *ArcPath_MenuBattle;
extern void *gTaskHost;
extern u8 Ov000Vt_021cb940_vtbl[];
extern u8 Ov000Vt_021cb6d0_vtbl[];
void BufferList_Run(void *p, s32 a);
BOOL TaskHost_Update(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

void MessageQueue021cb980_Push0d_0e(VObj *self, s32 flag, s32 a, s32 b, s32 c) {
    u32 x = (u8)a | (c << 8);
    if (flag) {
        self->vfunc_0c(0, 0xd, x, b);
    } else {
        self->vfunc_0c(0, 0xe, 0, 0);
    }
}

}
