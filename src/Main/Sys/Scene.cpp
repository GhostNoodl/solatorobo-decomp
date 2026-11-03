#include "Main/Sys/Scene.h"
#include "Main/Res/ResMgr.h"
#include "Main/Movie/Movie.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Sys/Pad.h"
#include "Main/Res/StageFlags.h"
#include "Main/Res/ResLoader.h"

extern "C" {


extern SndMgr *gSndMgr;
extern const char *data_0208cb28[];

extern void G2x_SetBlendBrightness_(volatile void *reg, int a, int b);
extern void StageFlags_Create(void);
extern void func_0206e858(void);
extern BOOL PauseNode_IsUpdatePaused(UnkSysNode *node, BOOL recurse);
extern BOOL PauseNode_IsDrawPaused(UnkSysNode *node, BOOL recurse);
extern void func_0201bbfc(u32 a);
extern void GfxSys_StopFade(int a);
extern void StageFlags_Reset(StageFlags *obj);
extern void Snd_Reset(void);
extern void func_02039e0c(GfxMgr *mgr);
extern void GfxSys_SetBackdrop(GfxSys *sys, u16 color);
extern void GfxSys_SetBackdropSub(GfxSys *sys, u16 color);
extern void Gfx3DState_SetDefaults(void *obj);
extern BOOL func_02046ac4(void);
extern void SndMgr_StopAllSeq(SndMgr *mgr, int fadeFrames);
extern void GX_DispOn(void);
void func_0204af00(SceneMgr *mgr);

void func_0204ae14(void) {
    if (gSceneMgr == NULL) {
        SceneMgr *mgr;
        Movie *movie;
        s32 i;
        gSceneMgr = (SceneMgr *)Heap_AllocLo(sizeof(SceneMgr), 4);
        mgr = gSceneMgr;
        mgr->state = 4;
        mgr->changing = FALSE;
        mgr->noReset = FALSE;
        mgr->cur.overlay = -1;
        mgr->cur.onEnter = NULL;
        mgr->cur.update = NULL;
        mgr->cur.draw = NULL;
        mgr->cur.onExit = NULL;
        mgr->next.overlay = -1;
        mgr->next.onEnter = NULL;
        mgr->next.update = NULL;
        mgr->next.draw = NULL;
        mgr->next.onExit = NULL;
        for (i = 0; i < 2; i++) {
            mgr->subOverlays[i] = -1;
        }
        G2x_SetBlendBrightness_((volatile void *)0x4000050, 0x3f, 0x10);
        G2x_SetBlendBrightness_((volatile void *)0x4001050, 0x3f, 0x10);
        movie = gMovie;
        movie->names = data_0208cb28;
        movie->unk_0e8 = 2;
    }
    StageFlags_Create();
    func_0206e858();
}

void func_0204aee8(void) {
    func_0204af00(gSceneMgr);
}

static inline void Scene_SetNext(SceneDesc *desc) {
    SceneMgr *mgr = gSceneMgr;
    mgr->next = *desc;
    mgr->state = 1;
    mgr->changing = FALSE;
}

static inline void Scene_SetSubOverlay(SceneMgr *mgr, s32 id, s32 idx) {
    if (id == mgr->subOverlays[idx]) {
        return;
    }
    if (mgr->subOverlays[idx] != -1) {
        FS_UnloadOverlay(0, mgr->subOverlays[idx]);
    }
    if (id != -1) {
        FS_LoadOverlay(0, id);
    }
    mgr->subOverlays[idx] = id;
}

void func_0204af00(SceneMgr *mgr) {
    s32 i;
    SceneEntry *entry;
    switch (mgr->state) {
        case 0:
            if (mgr->cur.update != NULL && !PauseNode_IsUpdatePaused(&gSysState->node, TRUE)) {
                mgr->cur.update();
                if (!mgr->noReset && mgr->changing != TRUE && (gPad->cur & 0x30c) == 0x30c) {
                    func_0201bbfc(1);
                    gSysState->frameWait = 1;
                    GfxSys_StopFade(-1);
                    for (i = 0, entry = data_02082998; i < 2; i++, entry++) {
                        if (entry->valid == 1) {
                            Scene_SetNext(&entry->desc);
                            gSceneMgr->changing = TRUE;
                            break;
                        }
                    }
                    gSceneMgr->noReset = FALSE;
                    StageFlags_Reset(gStageFlags);
                    Snd_Reset();
                    func_02039e0c(gGfxMgr);
                }
            }
            if (mgr->state == 0 && mgr->cur.draw != NULL && !PauseNode_IsDrawPaused(&gSysState->node, TRUE)) {
                mgr->cur.draw();
            }
            break;
        case 1:
            GfxSys_SetBackdrop(gGfxSys, 0);
            GfxSys_SetBackdropSub(gGfxSys, 0);
            Gfx3DState_SetDefaults(gGfxSys->unk_8b0);
            if (mgr->cur.onExit != NULL) {
                mgr->cur.onExit();
            }
            mgr->state = 2;
        case 2:
            if (!func_02046ac4()) {
                gGfxSys->nextState = 1;
                SndMgr_StopAllSeq(gSndMgr, 0);
                gSndMgr->unk_5b = FALSE;
                Scene_SetSubOverlay(mgr, -1, 0);
                Scene_SetSubOverlay(mgr, -1, 1);
                mgr->state = 3;
            }
            break;
        case 3:
            if (mgr->next.overlay != mgr->cur.overlay) {
                if (mgr->cur.overlay != -1) {
                    FS_UnloadOverlay(0, mgr->cur.overlay);
                }
                if (mgr->next.overlay != -1) {
                    FS_LoadOverlay(0, mgr->next.overlay);
                }
            }
            if (mgr->next.onEnter != NULL) {
                mgr->next.onEnter();
            }
            mgr->cur = mgr->next;
            mgr->next.overlay = -1;
            mgr->next.onEnter = NULL;
            mgr->next.update = NULL;
            mgr->next.draw = NULL;
            mgr->next.onExit = NULL;
            mgr->state = 0;
            break;
        case 4:
            GX_DispOn();
            *(vu32 *)0x4001000 |= 0x10000;
            for (i = 0, entry = data_02082998; i < 2; i++, entry++) {
                if (entry->valid == 1) {
                    Scene_SetNext(&entry->desc);
                    gSceneMgr->changing = TRUE;
                    break;
                }
            }
            break;
    }
    mgr->frame++;
}

void Scene_SetSubOverlay_0204b270(SceneMgr *mgr, s32 id, s32 idx) {
    Scene_SetSubOverlay(mgr, id, idx);
}

}
