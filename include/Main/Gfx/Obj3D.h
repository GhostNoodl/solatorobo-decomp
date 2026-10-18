#ifndef MAIN_GFX_OBJ3D_H
#define MAIN_GFX_OBJ3D_H

#include "Main/Gfx/GfxMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Obj3DMtl {
    /* 0x0 */ u8 unk_0[0xc];
    /* 0xc */ u32 polyAttr;
} Obj3DMtl;

// Render state shared by 3D objects.
typedef struct Obj3DRender {
    /* 0x00 */ u8 unk_00[0x1c];
    /* 0x1c */ void (*callback)(struct Obj3DRender *render);
    /* 0x20 */ u8 unk_20[0x70];
    /* 0x90 */ u8 callbackMode;
    /* 0x91 */ u8 unk_91[0x1f];
    /* 0xb0 */ Obj3DMtl *mtl;
} Obj3DRender;

typedef struct Obj3DLayer {
    /* 0x0 */ u32 unk_0_0 : 13;
    /* 0x0 */ u32 cur : 3;
    /* 0x0 */ u32 prev : 3;
    /* 0x0 */ u32 unk_0_19 : 13;
} Obj3DLayer;

#ifdef __cplusplus
}
#endif

#endif
