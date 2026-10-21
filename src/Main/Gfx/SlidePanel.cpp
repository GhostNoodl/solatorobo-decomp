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
    MI_CpuFill8(dst, 0, size);
}

void func_02054bac(Model *model, u32 v) {
    *(u32 *)((u8 *)model + 0xec) = v;
}

// Model_GetPartTex with the resource pointer held by the caller. Using it for
// one of the four edge cases gives the target's register assignment.
static inline void *Model_GetPartTexR(Model *model, s32 idx, ModelRes *&res) {
    res = model->res;
    ModelPart *part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        return part->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
}

static inline s32 Model_GetWidthR(Model *model, s32 idx, ModelRes *&res) {
    return func_02041b10(model, Model_GetPartTexR(model, idx, res));
}

static inline s32 SlidePanel_GetEdge3(SlidePanel *panel, ModelRes *&res) {
    u32 kind = panel->kind;
    if (kind == 1) {
        if (panel->model != NULL && panel->flag9) {
            return (Model_GetWidth(panel->model, 0) >> 1) - 0x80;
        }
        return -0x40;
    }
    if (kind == 2) {
        if (panel->model != NULL && panel->flag9) {
            return 0x80 - (Model_GetWidth(panel->model, 0) >> 1);
        }
        return 0x40;
    }
    if (kind == 3) {
        if (panel->model2 != NULL) {
            return (Model_GetWidth(panel->model2, 0) >> 1) - 0x80;
        }
        return -0x40;
    }
    if (kind == 4) {
        if (panel->model2 != NULL) {
            return 0x80 - (Model_GetWidthR(panel->model2, 0, res) >> 1);
        }
        return 0x40;
    }
    return 0;
}

void func_02054bb4(SlidePanel *panel) {
    ModelRes *res;
    s32 target;
    panel->unk_08 = panel->unk_0a;
    panel->unk_0c = panel->unk_0e;
    panel->unk_10 = panel->unk_12;
    panel->cur = panel->next;
    if (panel->cur == 3) {
        panel->state = 2;
        panel->frames = 10;
    } else {
        panel->state = 0;
        target = SlidePanel_GetTarget2(panel);
        panel->frames = SlidePanel_Abs(SlidePanel_GetEdge3(panel, res) - target) / 10;
    }
    if (!panel->flag27) {
        panel->moving = 1;
        panel->frame = 0;
        panel->unk_20 = 0;
        if (Gfx_IsFadeIdle(0) && panel->cur != 3) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
    } else {
        panel->moving = 0;
        panel->frame = panel->frames;
        panel->unk_20 = 0x1000;
    }
    panel->flag27 = 0;
    panel->visible = 1;
}

}
