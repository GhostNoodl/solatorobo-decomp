#include "Main/Gfx/SlidePanel.h"

extern "C" {

u16 func_0205422c(void) {
    return data_02097dc8->cur;
}

u16 func_02054240(void) {
    return data_02097dc8->release;
}

void func_02054254(SlidePanel *panel) {
    SLIDEPANEL_RESET(panel)
}

void func_020543bc(SlidePanel *panel) {
    SLIDEPANEL_UNLOAD(panel)
}

BOOL func_020544e4(SlidePanel *panel, BOOL sound) {
    int i;
    if (!panel->visible) {
        return FALSE;
    }
    if (!panel->flag27) {
        for (i = 0; i < 3; i++) {
            if (!panel->items[i].active) {
                if (panel->items[i].unk_1c != NULL && panel->items[i].state < 2) {
                    panel->items[i].active = 0;
                    panel->items[i].unk_0c = 0xffff;
                    panel->items[i].state = 2;
                }
            }
        }
        if (!panel->opened) {
            if (panel->cur == 3) {
                panel->state = 3;
                panel->frames = 10;
            } else {
                panel->state = 1;
                s32 target = SlidePanel_GetTarget(panel);
                panel->frames = SlidePanel_Abs(SlidePanel_GetEdge2(panel) - target) / 10;
            }
            panel->frame = 0;
            panel->moving = 1;
            panel->unk_20 = 0;
            if (sound && Gfx_IsFadeIdle(0)) {
                if (panel->kind >= 3) {
                    func_02049a48(data_02097e4c, 0x2f, -1, -1, -1);
                } else {
                    func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
                }
            }
        }
        panel->opened = 1;
        return TRUE;
    }
    return FALSE;
}

s32 func_02054894(SlidePanel *panel) {
    return SlidePanel_GetTarget(panel);
}

s32 func_020548c8(SlidePanel *panel) {
    return SlidePanel_GetEdge(panel);
}

s32 func_02054ae8(Model *model, s32 idx) {
    return Model_GetWidth(model, idx);
}

BOOL func_02054b4c(int ch) {
    return Gfx_IsFadeIdle(ch);
}

void func_02054b70(Model *model) {
    model->flags |= 0x20000;
}

void func_02054b80(Model *model) {
    model->flags |= 0x40000;
}

void *func_02054b90(Model *model) {
    return model->unk_000 + 0x24;
}

void func_02054b98(void *dst, u32 size) {
    func_02016e28(dst, 0, size);
}

void func_02054bac(Model *model, u32 v) {
    *(u32 *)((u8 *)model + 0xec) = v;
}

}
