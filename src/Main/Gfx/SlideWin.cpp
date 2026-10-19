#include "Main/Gfx/SlideWin.h"
#include "Main/Res/StageRes.h"


extern "C" {

extern StageResSlot *func_0205b31c(void);
extern void func_0205b348(void);
extern void func_0204a284(SndMgr *mgr, s32 fade);

static inline void SlidePanelItem_Close(SlidePanelItem *item) {
    if (!item->active) {
        if (item->unk_1c != NULL && item->state < 2) {
            item->active = 0;
            item->unk_0c = 0xffff;
            item->state = 2;
        }
    }
}

void func_020518bc(SlideWin *win) {
    int i;
    if (win->mode == 2 || win->mode == 3) {
        if (win->unk_b8_24) {
            win->flag14 = 1;
            return;
        }
        StageResSlot *cmd = func_0205b31c();
        if (cmd != NULL && cmd->id == 0x371) {
            win->flag14 = 1;
            cmd->bits.flag8 = 1;
            func_0205bef8(cmd);
            func_0205b348();
            for (i = 0; i < 5; i++) {
                SlidePanelItem_Close(&win->panels[i].items[0]);
            }
            return;
        }
    }
    win->flag3 = 1;
    SlidePanelItem_Close(&win->items[0]);
    SlidePanelItem_Close(&win->items[1]);
    func_0204a284(data_02097e4c, -1);
}

}
