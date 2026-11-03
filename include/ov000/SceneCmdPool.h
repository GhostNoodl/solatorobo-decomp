#ifndef OV000_SCENECMDPOOL_H
#define OV000_SCENECMDPOOL_H

#include "ov000/SceneCmd.h"

// The scene command TU's .bss (defined in Lo_021814dc.cpp from 0x021ccd50) as the functions the
// ROM places in that TU after SceneCmd_Run29 reach it: through the 0x021ccd50 pool literal plus an
// offset. Those functions sit in their own files here (SceneCmd_Run29 is not matched, so the TU
// cannot be merged further), so they declare the pool with this view. Lo_021814dc.cpp itself
// defines the objects one by one and does not include this header.
typedef struct SceneCmdPool {
    /* 0x00 */ u8 running;      // data_ov000_021ccd50 itself: a scene command is running
    /* 0x04 */ SceneCmd *scene; // gSceneCmd
} SceneCmdPool;

#ifdef __cplusplus
extern "C" {
#endif
extern SceneCmdPool data_ov000_021ccd50;
#ifdef __cplusplus
}
#endif

#endif
