#ifndef MAIN_GFX_SLIDEPANEL_H
#define MAIN_GFX_SLIDEPANEL_H

#include "types.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResMgr.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Sys/Pad.h"

#ifdef __cplusplus
extern "C" {
#endif

extern s32 data_02097d78[5];
extern SndMgr *data_02097e4c;

extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern s32 func_02041b10(Model *model, void *tex);
extern BOOL func_0203e63c(void *id);
extern BOOL func_02042958(Model *model, u32 slot, ModelPart *part);
extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);

typedef struct SlidePanelItem {
    /* 0x00 */ u32 unk_00_0 : 2;
    /* 0x00 */ u32 active : 1;
    /* 0x00 */ u32 unk_00_3 : 29;
    /* 0x04 */ s32 state;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u8 unk_0e[0xe];
    /* 0x1c */ void *unk_1c;
    /* 0x20 */ u8 unk_20[0x2c];
} SlidePanelItem; // size 0x4c

// Owner of the SlidePanel helpers at 0x02055654 (the class of func_020534dc).
typedef struct SlideCtrl {
    /* 0x00 */ u8 unk_00[0xb8];
    /* 0xb8 */ u32 unk_b8_0 : 4;
    /* 0xb8 */ u32 flag4 : 1;
    /* 0xb8 */ u32 unk_b8_5 : 6;
    /* 0xb8 */ u32 flag11 : 1;
    /* 0xb8 */ u32 lock : 2;
    /* 0xb8 */ u32 unk_b8_14 : 18;
} SlideCtrl;

// Panel that slides in from a screen edge.
typedef struct SlidePanel {
    /* 0x000 */ u32 state : 4;
    /* 0x000 */ u32 flag4 : 1;
    /* 0x000 */ u32 opened : 1;
    /* 0x000 */ u32 kind : 3;
    /* 0x000 */ u32 flag9 : 1;
    /* 0x000 */ u32 unk_0_10 : 3;
    /* 0x000 */ u32 cur : 3;
    /* 0x000 */ u32 next : 3;
    /* 0x000 */ u32 visible : 1;
    /* 0x000 */ u32 flag20 : 1;
    /* 0x000 */ u32 moving : 1;
    /* 0x000 */ u32 unk_0_22 : 5;
    /* 0x000 */ u32 flag27 : 1;
    /* 0x000 */ u32 unk_0_28 : 4;
    /* 0x004 */ u32 unk_04;
    /* 0x008 */ u16 unk_08;
    /* 0x00a */ u16 unk_0a;
    /* 0x00c */ u16 unk_0c;
    /* 0x00e */ u16 unk_0e;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u32 unk_14;
    /* 0x018 */ s32 frame;
    /* 0x01c */ s32 frames;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ void *pltt;
    /* 0x028 */ void *nextPltt;
    /* 0x02c */ Model *model;
    /* 0x030 */ Model *nextModel;
    /* 0x034 */ Model *model2;
    /* 0x038 */ Model *nextModel2;
    /* 0x03c */ s32 unk_3c;
    /* 0x040 */ s32 pos;
    /* 0x044 */ SlidePanelItem items[3];
    /* 0x128 */ u8 unk_128;
} SlidePanel;

static inline void *Model_GetPartTex(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        return part->res->tex;
    }
    return func_02023410(res->texRes, ***(u16 ***)((u8 *)func_02023390(res->mdlRes, idx) + 0xc));
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

static inline s32 Model_GetWidth(Model *model, s32 idx) {
    return func_02041b10(model, Model_GetPartTex(model, idx));
}

static inline BOOL Gfx_IsFadeIdle(int ch) {
    return (data_02097d78[3] == 0 && data_02097d78[ch] == 0) ? TRUE : FALSE;
}

#define SLIDEPANEL_UNLOAD(panel) \
    if (!panel->flag20) { \
        panel->cur = 0; \
        panel->next = 0; \
        panel->unk_0a = 0; \
        panel->unk_0e = 0; \
        panel->unk_12 = 0xffff; \
        panel->unk_128 = 0; \
    } \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            void *p = panel->pltt; \
            if (p != NULL) { \
                if (p != NULL) { \
                    func_02041278(p); \
                    func_0203de1c(p); \
                } \
                panel->pltt = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    } \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            Model *p = panel->model; \
            if (p != NULL) { \
                if (p != NULL) { \
                    func_02041558(p); \
                    func_02041278(p->pltt); \
                    func_0203de1c(p); \
                } \
                panel->model = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    } \
    { \
        void *saved = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
        { \
            Model *p = panel->model2; \
            if (p != NULL) { \
                if (p != NULL) { \
                    func_02041558(p); \
                    func_02041278(p->pltt); \
                    func_0203de1c(p); \
                } \
                panel->model2 = NULL; \
            } \
        } \
        data_02097dd0->cur = saved; \
    }

static inline s32 SlidePanel_GetTarget(SlidePanel *panel) {
    if (panel->cur == 4) {
        return panel->pos;
    }
    if (panel->cur == 1) {
        return -0xd8;
    }
    return panel->cur == 2 ? 0xd8 : 0;
}

static inline s32 SlidePanel_GetEdge(SlidePanel *panel) {
    u32 kind = panel->kind;
    if (kind == 1) {
        Model *model = panel->model;
        if (model != NULL && panel->flag9) {
            return (Model_GetWidth(model, 0) >> 1) - 0x80;
        }
        return -0x40;
    }
    if (kind == 2) {
        Model *model = panel->model;
        if (model != NULL && panel->flag9) {
            return 0x80 - (Model_GetWidth(model, 0) >> 1);
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
            return 0x80 - (Model_GetWidth(panel->model2, 0) >> 1);
        }
        return 0x40;
    }
    return 0;
}

static inline s32 SlidePanel_GetEdge2(SlidePanel *panel) {
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
            return 0x80 - (Model_GetWidth(panel->model2, 0) >> 1);
        }
        return 0x40;
    }
    return 0;
}

static inline s32 SlidePanel_GetTarget2(SlidePanel *panel) {
    if (panel->cur == 4) {
        return panel->pos;
    }
    if (panel->cur == 1) {
        return -0xd8;
    }
    if (panel->cur == 2) {
        return 0xd8;
    }
    return 0;
}

static inline s32 SlidePanel_Abs(s32 x) {
    return x < 0 ? -x : x;
}

#define SLIDEPANEL_RESET(panel) \
    panel->unk_3c = 0; \
    panel->pos = 0; \
    panel->unk_08 = 0; \
    panel->unk_0c = 0; \
    panel->unk_10 = 0xffff; \
    panel->unk_20 = 0; \
    panel->state = 0; \
    panel->flag4 = 0; \
    panel->visible = 0; \
    panel->opened = 0; \
    if (panel->model == NULL) { \
        return; \
    } \
    if (panel->flag20) { \
        return; \
    } \
    SLIDEPANEL_UNLOAD(panel)

static inline BOOL Transfer_Check(void **p) {
    if (*p == NULL) {
        return TRUE;
    }
    if (func_0203e63c(*p)) {
        *p = NULL;
    } else {
        return FALSE;
    }
    return TRUE;
}

#ifdef __cplusplus
}
#endif

#endif
