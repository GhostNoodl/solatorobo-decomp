#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "Main/Gfx/Model.h"
#include "Main/Sys/Pad.h"

typedef struct {
    u32 cnt : 16;
    u32 rest : 16;
} Cnt021b8994;

extern "C" {
extern int data_02097d78[];
extern u8 data_0208b318[];
extern char data_ov000_021cc885[];
void LangData_LocalizePath(char *dst, const char *src);
BOOL func_ov000_02184498(void *g);
void GfxSys_SetFadePlanes(s32 a, s32 b);
void GfxSys_StartFadeOut(s32 a, s32 b, s32 c);
void GfxSys_SetFadeRange(s32 a, s32 b, s32 c);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
s32 GfxSys_GetFadeTimer(s32 ch);
s32 GfxSys_GetFadeLevel(s32 ch);
void Blend_SetPlanes(s32 ch, s32 planes);
void Blend_Start(s32 ch, s32 duration, s32 start, s32 end);
BOOL Blend_Tick(s32 ch);

static inline BOOL StOk021b8994(FieldState *g) {
    s32 st = g->unk_98;
    if (st == 0x14 || (u32)(st - 0x16) <= 1) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Fade2_021b8994(void) {
    if (data_02097d78[3] == 2) {
        return TRUE;
    }
    return data_02097d78[2] == 2 ? TRUE : FALSE;
}

static inline BOOL FadeIdle021b8994(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

struct Obj021b8994 {
    Cnt021b8994 unk_00;
    char unk_04[0x20];
    VObj *unk_24;
    s32 unk_28;
    u8 unk_2c[0x4];
    Model *unk_30;
};

BOOL func_ov000_021b8994(Obj021b8994 *self) {
    switch (self->unk_28) {
    case 1: {
        char buf[0x20];
        VObj *p = (VObj *)Heap_Alloc(0x4c);
        if (p != NULL) {
            *(void **)p = data_0208b318;
            p->vfunc_08();
        }
        self->unk_24 = p;
        LangData_LocalizePath(buf, data_ov000_021cc885);
        LFLD(s32, self->unk_24, 0x44) = 2;
        self->unk_24->vfunc_24(buf, self->unk_04);
        self->unk_28 = 2;
        break;
    }
    case 2:
        if (!self->unk_24->vfunc_2c()) {
            break;
        }
        self->unk_28 = 4;
    case 3:
        if (!func_ov000_02184498(data_ov000_021ccd54)) {
            break;
        }
        GfxSys_SetFadePlanes(0x21, 0);
        GfxSys_StartFadeOut(0x1e000, 1, 2);
        GfxSys_SetFadeRange(0, 8, 2);
        self->unk_28 = 4;
        break;
    case 4: {
        Model *p;
        if (!StOk021b8994(data_ov000_021ccd54)) {
            break;
        }
        if (!func_ov000_02184498(data_ov000_021ccd54)) {
            break;
        }
        p = (Model *)Heap_Alloc(sizeof(Model));
        if (p != NULL) {
            PlttRes_Init_02041218(&p->pltt);
            TexObj_Init(p, self->unk_04, 0);
        }
        self->unk_30 = p;
        TexObj_SetRes(self->unk_30, (void *)self->unk_24->vfunc_10());
        TexObj_SelectImage(self->unk_30, 1, 0xffff);
        GfxSys_StartFadeIn(0, 1, 0);
        GfxSys_StartFadeOut(0, 1, 2);
        self->unk_28 = 6;
        break;
    }
    case 6:
        GfxSys_StartFadeIn(0x3c000, 1, 2);
        GfxSys_SetFadeRange(0x10, 8, 2);
        self->unk_28 = 7;
        break;
    case 7:
        if (GfxSys_GetFadeTimer(2) <= 0x1e000) {
            break;
        }
        GfxSys_SetFadePlanes(0x10, 0);
        GfxSys_StartFadeIn(0x1e000, 1, 0);
        self->unk_28 = 9;
        break;
    case 9:
        if (!Fade2_021b8994()) {
            break;
        }
        if (FadeIdle021b8994()) {
            self->unk_28 = 0xc;
        }
        break;
    case 12:
        self->unk_00.cnt++;
        if (self->unk_00.cnt <= 0x78 && !(data_02097dc8->trig & 3)) {
            break;
        }
        self->unk_28 = 0xd;
        break;
    case 13: {
        s32 v = GfxSys_GetFadeLevel(2);
        GfxSys_StartFadeIn(0x3c000, 1, 2);
        GfxSys_SetFadeRange(v, 0, 2);
        Blend_SetPlanes(1, 1);
        Blend_Start(1, 0x1e, 0x10, 0);
        self->unk_30->flags |= 0x80000;
        self->unk_28 = 0xe;
        break;
    }
    case 14: {
        BOOL ok;
        if (Blend_Tick(1)) {
            break;
        }
        ok = TRUE;
        if (data_02097d78[3] != 0 || data_02097d78[2] != 0) {
            ok = FALSE;
        }
        if (!ok) {
            break;
        }
        LO_FREE_M(self, 0x30);
        self->unk_28 = 0x11;
        break;
    }
    case 17:
        return FALSE;
    }
    return TRUE;
}
}
