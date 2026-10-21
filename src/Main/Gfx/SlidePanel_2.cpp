#include "Main/Gfx/SlidePanel.h"

extern "C" {

void func_02054254(SlidePanel *panel);



BOOL func_02054f10(Model *model, u32 idx) {
    if (!Transfer_Check(&model->plttTransfer) || !Transfer_Check(&model->extPltt->transfer)) {
        return FALSE;
    }
    if (idx != 0xffff) {
        ModelPart *part = (s32)idx >= model->numParts ? NULL : &model->parts[idx];
        if (part != NULL) {
            u16 j;
            for (j = 0; j < 3; j++) {
                if (!func_02042958(model, j, part)) {
                    return FALSE;
                }
            }
        }
    } else {
        u16 i;
        for (i = 0; i < model->numParts; i++) {
            u16 j;
            ModelPart *parts = model->parts;
            for (j = 0; j < 3; j++) {
                if (!func_02042958(model, j, &parts[i])) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

void func_02055068(SlidePanel *panel, SlidePanel *prev) {
    panel->pos = prev->model->x >> 12;
    if (panel->cur == 0) {
        panel->next = 4;
    } else {
        panel->next = panel->cur;
    }
    panel->cur = 4;
    if (panel->cur == 3) {
        panel->state = 2;
        panel->frames = 10;
    } else {
        panel->state = 0;
        s32 target = SlidePanel_GetTarget(panel);
        panel->frames = SlidePanel_Abs(SlidePanel_GetEdge2(panel) - target) / 10;
    }
    if (!panel->flag27) {
        panel->moving = 1;
        panel->frame = 0;
        panel->unk_20 = 0;
    } else {
        panel->moving = 0;
        panel->frame = panel->frames;
        panel->unk_20 = 0x1000;
    }
    panel->flag27 = 0;
    if (prev->state > 3) {
        SLIDEPANEL_RESET(prev)
    }
}

BOOL func_020554c8(SlidePanel *panel) {
    return panel->state <= 3 ? TRUE : FALSE;
}

void func_020554e4(SlidePanel *panel) {
    if (panel->pltt != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            void *p = panel->pltt;
            if (p != NULL) {
                if (p != NULL) {
                    func_02041278(p);
                    func_0203de1c(p);
                }
                panel->pltt = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    if (panel->model != NULL) {
        {
            // The target reads x before y.
            s32 x = *(volatile s32 *)&panel->model->x;
            s32 y = panel->model->y;
            Model_SetPos(panel->nextModel, x, y);
        }
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->unk_08;
            {
                Model *p = panel->model;
                if (p != NULL) {
                    if (p != NULL) {
                        func_02041558(p);
                        func_02041278(p->pltt);
                        func_0203de1c(p);
                    }
                    panel->model = NULL;
                }
            }
            data_02097dd0->cur = saved;
        }
    }
    if (panel->model2 != NULL) {
        {
            // The target reads x before y.
            s32 x = *(volatile s32 *)&panel->model2->x;
            s32 y = panel->model2->y;
            Model_SetPos(panel->nextModel2, x, y);
        }
        {
            void *saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->unk_08;
            {
                Model *p = panel->model2;
                if (p != NULL) {
                    if (p != NULL) {
                        func_02041558(p);
                        func_02041278(p->pltt);
                        func_0203de1c(p);
                    }
                    panel->model2 = NULL;
                }
            }
            data_02097dd0->cur = saved;
        }
    }
    panel->model = panel->nextModel;
    panel->pltt = panel->nextPltt;
    panel->model2 = panel->nextModel2;
    panel->nextModel = NULL;
    panel->nextPltt = NULL;
    panel->nextModel2 = NULL;
}

}
