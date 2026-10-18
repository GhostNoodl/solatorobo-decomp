#ifndef MAIN_GFX_GFX3D_H
#define MAIN_GFX_GFX3D_H

#include "Main/Gfx/GfxMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define REG_DISP3DCNT (*(volatile u16 *)0x4000060)
#define REG_ALPHA_TEST_REF (*(volatile u16 *)0x4000340)
#define REG_FOG_COLOR (*(volatile u32 *)0x4000358)

extern void func_0202a1d4(void);
extern void func_0202a260(const void *list, u32 size);
extern void func_0202a3ec(int cmd, const void *data, int count);
extern void func_0202717c(int light, int x, int y, int z);
extern void func_020271b8(int light, u16 color);
extern void func_020271cc(u16 diffuse, u16 ambient, BOOL setVtxColor);
extern void func_020271f0(u16 specular, u16 emission, BOOL shininess);
extern void func_02019294(const void *addr, u32 size);
extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);

extern const int data_02082898[][4];
extern const int data_020828c8[][4];
extern u32 data_02fe00e8[];
extern const void *data_0208b3d0[];
extern const u32 data_020828f8[];
extern void func_02013dbc(BOOL enable, int mode, int slope, int offset);
extern void func_02013e70(const u16 *table);
extern void func_02013e88(const u8 *table);
extern void func_02013e9c(const u16 *table);
extern void func_02013eb4(u16 color, int alpha, int depth, int polygonId, BOOL fog);
extern void func_02016d68(const void *src, void *dst, u32 size);
extern void func_020128a4(int t, int b, int l, int r, int n, int f, int scaleW, void *mtx);
extern const u16 data_02082958[];
extern const u16 data_02082900[];
extern const u16 data_02075614[][4];
extern const u16 data_0207562c[][4];
extern const int data_02082884[];

typedef int OamShape;

typedef struct GfxLightVec {
    s16 x;
    s16 y;
    s16 z;
} GfxLightVec;

typedef struct GfxLight {
    /* 0x00 */ GfxLightVec dirs[4];
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
    /* 0x134 */ int unk_134;
    /* 0x138 */ int unk_138;
    /* 0x13c */ u8 unk_13c[0x40];
    /* 0x17c */ int unk_17c;
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
