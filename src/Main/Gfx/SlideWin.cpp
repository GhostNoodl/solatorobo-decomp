#include "Main/Gfx/SlideWin.h"
#include "Main/Res/StageRes.h"


extern "C" {

extern StageResSlot *func_0205b31c(void);
extern void func_0205b348(void);
extern void func_0204a284(SndMgr *mgr, s32 fade);

extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);
extern void func_02050f70(SlideWin *win);

#define SW_DELETE(field, dtor) \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            void *p = (field); \
            if (p != NULL) { \
                if (p != NULL) { \
                    dtor(p); \
                    func_0203de1c(p); \
                } \
                (field) = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    }

#define SW_DELETE_MODEL(field) \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            Model *p = (field); \
            if (p != NULL) { \
                if (p != NULL) { \
                    func_02041558(p); \
                    func_02041278(p->pltt); \
                    func_0203de1c(p); \
                } \
                (field) = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    }

#define SW_ITEM_INIT(x) \
    (x).bits = 0; \
    (x).state = 8; \
    (x).unk_10 = 0; \
    (x).unk_14 = 0; \
    (x).unk_18 = 0; \
    (x).unk_1c = 0; \
    (x).unk_08 = 0; \
    (x).unk_0a = 0xffff; \
    (x).unk_0c = 0xffff; \
    (x).pos[0] = 0; \
    (x).pos[1] = 0; \
    (x).pos[2] = 0; \
    (x).scale[0] = 0x1000; \
    (x).scale[1] = 0x1000; \
    (x).scale[2] = 0x1000; \
    (x).rot[0] = 0; \
    (x).rot[1] = 0; \
    (x).rot[2] = 0; \
    (x).unk_40 = 0; \
    (x).unk_44 = 0; \
    (x).unk_48 = 0x1e;

#define SW_ITEM_RELEASE(x) \
    SW_DELETE((x).unk_14, func_ov000_0218fee4) \
    SW_DELETE((x).unk_10, func_ov000_0218ea20) \
    SW_DELETE((x).unk_1c, func_ov000_0218fee4) \
    SW_DELETE((x).unk_18, func_ov000_0218ea20) \
    SW_ITEM_INIT(x)

// The VRAM bases are variables with two definitions (the second is dead but
// keeps the optimizer from propagating them into the loop), and `i` is a
// `long`: together these give the target's register order and put both
// bases in the entry block.
void func_02051210(SlideWin *win) {
    long i;
    int j;
    u8 *objBase;
    u8 *subObjBase;
    objBase = (u8 *)0x6400000;
    subObjBase = (u8 *)0x6600000;
    if ((u32)win & 3) {
        objBase = (u8 *)0x6400000;
        subObjBase = (u8 *)0x6600000;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            SlideObj *p = win->obj;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                win->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    for (i = 0; i < 0x80; i++) {
        if (win->blocks[i] != NULL) {
            VramBlock *b = win->blocks[i];
            MIi_CpuClearFast(0, (b->kind == 4 ? objBase : subObjBase) + b->addr, b->size - b->pad);
            func_02039828(win->blocks[i]);
        }
    }
    SW_ITEM_RELEASE(win->items[0])
    SW_ITEM_RELEASE(win->items[1])
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            SW_ITEM_RELEASE(win->panels[i].items[j])
        }
        SW_DELETE(win->panels[i].pltt, func_02041278)
        SW_DELETE(win->panels[i].nextPltt, func_02041278)
        SW_DELETE_MODEL(win->panels[i].model)
        SW_DELETE_MODEL(win->panels[i].nextModel)
        SW_DELETE_MODEL(win->panels[i].model2)
        SW_DELETE_MODEL(win->panels[i].nextModel2)
    }
    func_02050f70(win);
}

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
