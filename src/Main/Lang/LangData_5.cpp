#include "Main/Lang/LangData.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/fx.h"

extern "C" {

typedef struct GfxEnv {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 unk_01[4];
    /* 0x05 */ u8 alpha;
    /* 0x06 */ u16 color;
    /* 0x08 */ u32 fogShift;
    /* 0x0c */ u32 fogOffset;
    /* 0x10 */ u16 fogMode;
    /* 0x12 */ u16 fogAlpha;
    /* 0x14 */ u16 fogColor;
    /* 0x16 */ u8 unk_16[2];
    /* 0x18 */ u8 fogTable[0x20];
    /* 0x38 */ u32 toonMode;
    /* 0x3c */ u8 toonTable[0x40];
    /* 0x7c */ u8 edgeTable[0x10];
    /* 0x8c */ VecFx16 lightDir;
    /* 0x92 */ u8 unk_92[0x12];
    /* 0xa4 */ u16 lightColor;
    /* 0xa6 */ u8 unk_a6[6];
    /* 0xac */ u16 unk_ac;
    /* 0xae */ u16 unk_ae;
    /* 0xb0 */ u16 unk_b0;
    /* 0xb2 */ u16 unk_b2;
} GfxEnv;

typedef struct LangCamera {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s16 sin;
    /* 0x0a */ s16 cos;
    /* 0x0c */ s16 dist;
    /* 0x0e */ u16 angle;
    /* 0x10 */ s32 deg;
    /* 0x14 */ u8 unk_14[2];
    /* 0x16 */ u8 dirty;
} LangCamera;

typedef struct LangGame54 {
    u8 unk_00[0x11c];
    LangCamera camera;
} LangGame54;

extern LangGame54 *data_ov000_021ccd54;

void G3X_SetClearColor(u16 color, int a, int b, u8 alpha, int c);
void G3X_SetToonTable(const void *p);
void G3X_SetEdgeColorTable(const void *p);
void G3X_SetFogTable(const void *p);
void G3X_SetFog(BOOL enable, int mode, int slope, int offset);
void MIi_CpuCopyFast(const void *src, void *dst, u32 size);

#define REG_DISP3DCNT (*(vu16 *)0x04000060)
#define REG_FOG_COLOR (*(vu32 *)0x04000358)

static inline void LangCamera_SetPos(LangCamera *cam, s32 x, s32 y) {
    cam->x = x;
    cam->y = y;
    cam->dirty = 1;
}

static inline void LangCamera_SetDist(LangCamera *cam, s16 dist) {
    cam->dist = dist;
    cam->dirty = 1;
}

static inline void LangCamera_SetAngle(LangCamera *cam, u16 angle) {
    cam->angle = angle;
    cam->deg = (s32)(((u64)angle * 0x1680000 + 0x80000) >> 20);
    cam->sin = FX_SinCosTable_[((angle / 2) >> 4) * 2];
    cam->cos = FX_SinCosTable_[((angle / 2) >> 4) * 2 + 1];
    cam->dirty = 1;
}

void func_0206e3a0(LangSecFlags *flags, const u8 *p) {
    GfxEnv *env = (GfxEnv *)data_02097d48->unk_8b0;
    if (flags->sec0) {
        u8 alpha = p[2];
        u16 color = *(const u16 *)p;
        p += 4;
        env->color = color;
        env->alpha = alpha;
        G3X_SetClearColor(color, 0x1f, 0x7fff, alpha, 1);
    }
    if (flags->sec1) {
        env->toonMode = 0;
        REG_DISP3DCNT = (u16)(REG_DISP3DCNT & ~0x3002);
        if (p != NULL) {
            MIi_CpuCopyFast(p, env->toonTable, 0x40);
            G3X_SetToonTable(p);
        }
        p += 0x40;
    }
    if (flags->sec2) {
        env->flags |= 0x30;
        REG_DISP3DCNT = (u16)((REG_DISP3DCNT & ~0x3000) | 0x20);
        MIi_CpuCopyFast(p, env->edgeTable, 0x10);
        G3X_SetEdgeColorTable(p);
        p += 0x10;
    }
    if (flags->sec3) {
        u16 alpha = *(const u16 *)(p + 2);
        u16 color = *(const u16 *)p;
        env->fogColor = color;
        env->fogAlpha = alpha;
        REG_FOG_COLOR = color | (alpha << 16);
        MIi_CpuCopyFast(p + 8, env->fogTable, 0x20);
        G3X_SetFogTable(p + 8);
        env->fogShift = 0;
        env->fogOffset = *(const u16 *)(p + 6);
        env->fogMode = *(const u16 *)(p + 4);
        G3X_SetFog(TRUE, 0, *(const u16 *)(p + 6), *(const u16 *)(p + 4));
        p += 0x28;
        env->flags |= 8;
    }
    if (flags->sec4) {
        env->unk_ac = *(const u16 *)p;
        env->unk_ae = *(const u16 *)(p + 2);
        env->unk_b0 = *(const u16 *)(p + 4);
        env->unk_b2 = *(const u16 *)(p + 6);
        p += 8;
    }
    if (flags->sec5) {
        VEC_Fx16Normalize((const VecFx16 *)p, &env->lightDir);
        env->lightDir.x = (env->lightDir.x >= 0x1000) ? 0xfff : env->lightDir.x;
        env->lightDir.y = (env->lightDir.y >= 0x1000) ? 0xfff : env->lightDir.y;
        env->lightDir.z = (env->lightDir.z >= 0x1000) ? 0xfff : env->lightDir.z;
        env->lightColor = *(const u16 *)(p + 6);
        p += 8;
    }
    if (flags->sec6) {
        LangCamera *cam = &data_ov000_021ccd54->camera;
        LangCamera_SetPos(cam, *(const s32 *)p, *(const s32 *)(p + 4));
        LangCamera_SetDist(cam, *(const s16 *)(p + 0xa));
        LangCamera_SetAngle(cam, *(const u16 *)(p + 8));
    }
}

}
