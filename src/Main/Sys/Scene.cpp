#include "Main/Sys/Scene.h"
#include "Main/Res/ResMgr.h"
#include "Main/Movie/Movie.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

typedef struct ScenePad {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u16 cur;
} ScenePad;

extern ScenePad *data_02097dc8;
extern void *data_0214a424;
extern SndMgr *data_02097e4c;
extern const char *data_0208cb28[];

extern void *func_0203dec8(u32 size, int align);
extern void func_020137a8(volatile void *reg, int a, int b);
extern void func_0206c44c(void);
extern void func_0206e858(void);
extern BOOL func_0203dbb0(UnkSysNode *node, BOOL recurse);
extern BOOL func_0203dc9c(UnkSysNode *node, BOOL recurse);
extern void func_0201bbfc(int a);
extern void func_0203caf8(int a);
extern void func_0206c4c4(void *obj);
extern void func_0204a904(void);
extern void func_02039e0c(GfxMgr *mgr);
extern void func_0203b924(GfxSys *sys, u16 color);
extern void func_0203b948(GfxSys *sys, u16 color);
extern void func_02043904(void *obj);
extern BOOL func_02046ac4(void);
extern void func_0204a2e0(SndMgr *mgr, int fadeFrames);
extern void func_02013658(void);
void func_0204af00(SceneMgr *mgr);

void func_0204ae14(void) {
    if (data_02149ef0 == NULL) {
        SceneMgr *mgr;
        Movie *movie;
        s32 i;
        data_02149ef0 = (SceneMgr *)func_0203dec8(sizeof(SceneMgr), 4);
        mgr = data_02149ef0;
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
        func_020137a8((volatile void *)0x4000050, 0x3f, 0x10);
        func_020137a8((volatile void *)0x4001050, 0x3f, 0x10);
        movie = data_02097e3c;
        movie->names = data_0208cb28;
        movie->unk_0e8 = 2;
    }
    func_0206c44c();
    func_0206e858();
}

void func_0204aee8(void) {
    func_0204af00(data_02149ef0);
}

static inline void Scene_SetNext(SceneDesc *desc) {
    SceneMgr *mgr = data_02149ef0;
    mgr->next = *desc;
    mgr->state = 1;
    mgr->changing = FALSE;
}

static inline void Scene_SetSubOverlay(SceneMgr *mgr, s32 id, s32 idx) {
    if (id == mgr->subOverlays[idx]) {
        return;
    }
    if (mgr->subOverlays[idx] != -1) {
        func_0200f7f8(0, mgr->subOverlays[idx]);
    }
    if (id != -1) {
        func_0200f7a4(0, id);
    }
    mgr->subOverlays[idx] = id;
}

void func_0204af00(SceneMgr *mgr) {
    s32 i;
    SceneEntry *entry;
    switch (mgr->state) {
        case 0:
            if (mgr->cur.update != NULL && !func_0203dbb0(&data_02097dd0->node, TRUE)) {
                mgr->cur.update();
                if (!mgr->noReset && mgr->changing != TRUE && (data_02097dc8->cur & 0x30c) == 0x30c) {
                    func_0201bbfc(1);
                    data_02097dd0->frameWait = 1;
                    func_0203caf8(-1);
                    for (i = 0, entry = data_02082998; i < 2; i++, entry++) {
                        if (entry->valid == 1) {
                            Scene_SetNext(&entry->desc);
                            data_02149ef0->changing = TRUE;
                            break;
                        }
                    }
                    data_02149ef0->noReset = FALSE;
                    func_0206c4c4(data_0214a424);
                    func_0204a904();
                    func_02039e0c(data_02097ce0);
                }
            }
            if (mgr->state == 0 && mgr->cur.draw != NULL && !func_0203dc9c(&data_02097dd0->node, TRUE)) {
                mgr->cur.draw();
            }
            break;
        case 1:
            func_0203b924(data_02097d48, 0);
            func_0203b948(data_02097d48, 0);
            func_02043904(data_02097d48->unk_8b0);
            if (mgr->cur.onExit != NULL) {
                mgr->cur.onExit();
            }
            mgr->state = 2;
        case 2:
            if (!func_02046ac4()) {
                data_02097d48->nextState = 1;
                func_0204a2e0(data_02097e4c, 0);
                data_02097e4c->unk_5b = FALSE;
                Scene_SetSubOverlay(mgr, -1, 0);
                Scene_SetSubOverlay(mgr, -1, 1);
                mgr->state = 3;
            }
            break;
        case 3:
            if (mgr->next.overlay != mgr->cur.overlay) {
                if (mgr->cur.overlay != -1) {
                    func_0200f7f8(0, mgr->cur.overlay);
                }
                if (mgr->next.overlay != -1) {
                    func_0200f7a4(0, mgr->next.overlay);
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
            func_02013658();
            *(vu32 *)0x4001000 |= 0x10000;
            for (i = 0, entry = data_02082998; i < 2; i++, entry++) {
                if (entry->valid == 1) {
                    Scene_SetNext(&entry->desc);
                    data_02149ef0->changing = TRUE;
                    break;
                }
            }
            break;
    }
    mgr->frame++;
}

void func_0204b270(SceneMgr *mgr, s32 id, s32 idx) {
    Scene_SetSubOverlay(mgr, id, idx);
}

}
