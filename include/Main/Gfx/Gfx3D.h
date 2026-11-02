#ifndef MAIN_GFX_GFX3D_H
#define MAIN_GFX_GFX3D_H

#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g3d.h"

#ifdef __cplusplus
extern "C" {
#endif

#define REG_DISP3DCNT (*(volatile u16 *)0x4000060)
#define REG_ALPHA_TEST_REF (*(volatile u16 *)0x4000340)
#define REG_FOG_COLOR (*(volatile u32 *)0x4000358)

extern void *Heap_AllocHi(u32 size, u32 align);
extern void Heap_FreeHi(void *ptr);

extern const int data_02082898[][4];
extern const int data_020828c8[][4];
extern u32 data_02fe00e8[];
extern const void *data_0208b3d0[];
extern const u32 data_020828f8[];
extern const u16 data_02082958[];
extern const u16 data_02082900[];
extern const u16 data_02075614[][4];
extern const u16 data_0207562c[][4];
extern const int data_02082884[];

typedef int OamShape;

typedef struct GfxLight {
    /* 0x00 */ VecFx16 dirs[4];
    /* 0x18 */ u16 colors[4];
    /* 0x20 */ u16 diffuse;
    /* 0x22 */ u16 ambient;
    /* 0x24 */ u16 specular;
    /* 0x26 */ u16 emission;
} GfxLight;

typedef struct Gfx3DState {
    /* 0x000 */ u8 alphaTest : 1;
    /* 0x000 */ u8 alphaBlend : 1;
    /* 0x000 */ u8 antiAlias : 1;
    /* 0x000 */ u8 fog : 1;
    /* 0x000 */ u8 edgeMarking : 1;
    /* 0x000 */ u8 unk_000_5 : 1;
    /* 0x000 */ u8 unk_000_6 : 2;
    /* 0x001 */ u8 polyId;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ u8 alphaRef;
    /* 0x005 */ u8 clearPolyId;
    /* 0x006 */ u16 clearColor;
    /* 0x008 */ int fogMode;
    /* 0x00c */ int fogSlope;
    /* 0x010 */ u16 fogOffset;
    /* 0x012 */ u16 fogAlpha;
    /* 0x014 */ u16 fogColor;
    /* 0x016 */ u16 unk_016;
    /* 0x018 */ u8 fogTable[0x20];
    /* 0x038 */ int shading;
    /* 0x03c */ u16 toonTable[0x20];
    /* 0x07c */ u16 edgeTable[8];
    /* 0x08c */ GfxLight light;
    /* 0x0b4 */ u8 unk_0b4[0x80];
    /* 0x134 */ int unk_134; // GfxSys.pltt.id when this is GfxSys.unk_8b0
    /* 0x138 */ int unk_138;
    /* 0x13c */ MtxFx44 unk_13c;
    /* 0x17c */ s32 *nearClip; // &Camera.nearClip of the camera last applied (GfxSys.nearClip)
} Gfx3DState;

typedef struct GfxOamTex {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 fmt;
    /* 0x0c */ int extPltt;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 mapping;
} GfxOamTex;

typedef struct GfxOamAttr {
    u32 attr01;
    u32 attr23;
} GfxOamAttr;

void func_02043578(GfxLight *light);
void func_020436f8(GfxPltt *pltt, u16 *buf, u32 size);

#ifdef __cplusplus
}
#endif

#endif
