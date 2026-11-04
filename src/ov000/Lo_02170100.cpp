#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/SlideWin.h"
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

s32 ListBuffer021cb940_GetWindowMode(ListBuffer021cb940 *self) {
    if (self->win == NULL) {
        Message *m = MessageQueue_FindById((MessageQueue *)self->unk_0c, 6);
        return m != NULL ? (s32)(m->unk_0c >> 16) : -1;
    }
    return self->win->mode;
}

}
