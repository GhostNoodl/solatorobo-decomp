#ifndef OV000_MODELVIEWER_H
#define OV000_MODELVIEWER_H

#include "types.h"
#include "ov000/Vec.h"
#include "ov000/ActorParts.h"
#include "ov000/Model0218fe1c.h"

// The resource loader of a ModelViewer (0x558 bytes at ModelViewer::res, vtable Ov000Vt_021cabd8_vtbl,
// dtor Ov000Vt_021cabd8_Dtor). It keeps two pairs of resource blocks and loads the next pair
// (cur ^ 1) from the names while the current one is shown (func_ov000_02161fac).
typedef struct ModelViewerRes {
    /* 0x000 */ void *vtbl;
    /* 0x004 */ u8 state; // 0: load, 10: wait, 20: loaded
    /* 0x005 */ u8 cur; // the pair shown
    /* 0x006 */ u8 reload;
    /* 0x007 */ char mdlArc[0x20];
    /* 0x027 */ char mdlName[0x18];
    /* 0x03f */ char anmArc[0x20];
    /* 0x05f */ char anmName[0x18];
    /* 0x077 */ u8 useMdlForB; // b[] loads the model names too (else it is cleared)
    /* 0x078 */ ActorRes a[2];
    /* 0x2e8 */ ActorRes b[2];
} ModelViewerRes;

// A 3D model drawn with its own camera and projection (0x708 bytes, ctor ModelViewer_Ctor, vtable
// ModelViewer_vtbl, dtors ModelViewer_Dtor / 0216251c). ModelViewer_SetModel requests new
// resources, func_ov000_02162bd4 steps the state machine, ModelViewer_Draw draws.
typedef struct ModelViewer {
    /* 0x000 */ void *vtbl;
    /* 0x004 */ ModelViewerRes res;
    /* 0x55c */ Model0218fe1c model;
    /* 0x644 */ VecFx32 eye; // GfxCamPos_Init
    /* 0x650 */ VecFx32 at;
    /* 0x65c */ VecFx32 up;
    /* 0x668 */ MtxFx44 proj; // func_ov000_0216295c
    /* 0x6a8 */ VecFx32 projOfs;
    /* 0x6b4 */ s32 projScale;
    /* 0x6b8 */ s32 state;
    /* 0x6bc */ u8 request;
    /* 0x6bd */ u8 unk_6bd[3];
    /* 0x6c0 */ const char *anim; // Model0218fe1c_SetAnim
    /* 0x6c4 */ s32 frame;
    /* 0x6c8 */ s16 speed; // Model0218fe1c_SetAnimSpeed
    /* 0x6ca */ u8 unk_6ca[2];
    /* 0x6cc */ VecFx32 home;
    /* 0x6d8 */ VecFx32 pos; // copied to model.trans when drawn
    /* 0x6e4 */ u16 rot[3];
    /* 0x6ea */ u8 unk_6ea[2];
    /* 0x6ec */ VecFx32 unk_6ec;
    /* 0x6f8 */ VecFx32 unk_6f8;
    /* 0x704 */ s32 timer;
} ModelViewer;

#endif
