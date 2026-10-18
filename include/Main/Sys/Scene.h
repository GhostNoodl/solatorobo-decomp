#ifndef MAIN_SYS_SCENE_H
#define MAIN_SYS_SCENE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Top-level scene (game mode) switcher. Each scene is an overlay plus callbacks.
typedef struct SceneDesc {
    /* 0x00 */ s32 overlay;
    /* 0x04 */ void (*onEnter)(void);
    /* 0x08 */ void (*update)(void);
    /* 0x0c */ void (*draw)(void);
    /* 0x10 */ void (*onExit)(void);
} SceneDesc; // size 0x14

typedef struct SceneEntry {
    /* 0x00 */ s32 valid;
    /* 0x04 */ SceneDesc desc;
} SceneEntry; // size 0x18

typedef struct SceneMgr {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 changing;
    /* 0x02 */ u8 noReset;
    /* 0x04 */ SceneDesc cur;
    /* 0x18 */ SceneDesc next;
    /* 0x2c */ s32 subOverlays[2];
    /* 0x34 */ s32 frame;
} SceneMgr; // size 0x38

extern SceneMgr *data_02149ef0;
extern SceneEntry data_02082998[];

// NitroSDK FS overlay load/unload
extern void func_0200f7a4(int target, s32 id);
extern void func_0200f7f8(int target, s32 id);

#ifdef __cplusplus
}
#endif

#endif
