#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char gCommonTextPath[];
extern const char *ArcPath_Menu;
extern const char *ArcPath_MenuBattle;
extern void *gTaskHost;
extern u8 Ov000Vt_021cb940_vtbl[];
extern u8 Ov000Vt_021cb6d0_vtbl[];
void BufferList_Run(void *p, s32 a);
BOOL TaskHost_Update(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

void MessageQueue021cb980_Start(MessageQueue021cb980 *self) {
    BOOL r;
    if (!self->unk_04) {
        self->unk_04 = 1;
        self->vfunc_0c(2, 1, 0, 0);
    }
    if (!self->flag0) {
        return;
    }
    r = TRUE;
    if (!ResMgr_IsLoaded(gCommonTextPath, 7)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(ArcPath_Menu, 7)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(ArcPath_MenuBattle, 7)) {
        r = FALSE;
    }
    if (r) {
        self->flag0 = 0;
    }
}

void MessageQueue021cb980_Update(VObj *self) {
    u8 buf[0x10];
    self->vfunc_1c();
    while (self->vfunc_14(buf, 1)) {
        self->vfunc_10(buf);
    }
    BufferList_Run((u8 *)self + 8, 0);
    if (gTaskHost != NULL) {
        TaskHost_Update(gTaskHost);
    }
}

}
