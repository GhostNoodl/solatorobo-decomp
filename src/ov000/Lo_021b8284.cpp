#include "ov000/LoCommon.h"
#include "nitro/std.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"


extern "C" {
extern int gFadeState[];
extern void *gSndMgr;
extern char data_ov000_021cc879[];
char *StageTbl_GetImage(u16 id);
void ResMgr_LoadArchive(void *a, void *b, s32 c, s32 d);
BOOL ResMgr_IsArchiveLoaded(void *a, void *b, s32 c);
void *ResMgr_GetArchiveList(void *a, void *b, s32 c);
void *Heap_Alloc(u32 size);
void *ResList_FindType2(void *a, void *b);
BOOL Model_IsReady(void *a, s32 b);
void TexObj_ShrinkRes(void *model);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
s32 FX_Div(s32 a, s32 b);

static inline BOOL FadeIdle021b8284(void) {
    BOOL r;
    if (gFadeState[3] == 0 && gFadeState[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Fade4_021b8284(void) {
    if (gFadeState[3] == 4) {
        return TRUE;
    }
    return gFadeState[0] == 4 ? TRUE : FALSE;
}

// ListBuffer021cb940::unk_34 (0x5c bytes, ctor ImageCard_Init).
struct Obj021b8284 {
    union {
        u32 flags;
        struct {
            u32 stop : 1; // set by field message 10 (MessageQueue021cb980_HandleMsg)
            u32 unk_00_1 : 31;
        };
    };
    char arcName[0x20]; // the part of StageTbl_GetImage's path before the separator
    char fileName[0x20]; // the part after it

    s32 unk_44;
    u16 unk_48;
    u8 unk_4a[0x2];
    Model *unk_4c;
    u32 unk_50;
    s32 unk_54;
    u16 unk_58;
};

BOOL ImageCard_Update(Obj021b8284 *self) {
    switch (self->unk_44) {
    case 1: {
        char *c;
        STD_CopyString(self->arcName, StageTbl_GetImage(self->unk_48));
        c = STD_SearchString(self->arcName, data_ov000_021cc879);
        *c = 0;
        STD_CopyString(self->fileName, c + 1);
        ResMgr_LoadArchive(self->arcName, self->fileName, 2, 0);
        {
            GfxSys *g = gGfxSys;
            g->unk_8b0_4 = 0;
            g->unk_8b0_5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        self->unk_44 = 2;
        break;
    }
    case 2:
        if (!ResMgr_IsArchiveLoaded(self->arcName, self->fileName, 2)) {
            break;
        }
        self->unk_44 = 4;
    case 4: {
        void *res = ResMgr_GetArchiveList(self->arcName, self->fileName, 2);
        Model *p;
        u16 i;
        if (!FadeIdle021b8284() && !Fade4_021b8284()) {
            break;
        }
        p = (Model *)Heap_Alloc(sizeof(Model));
        if (p != NULL) {
            PlttRes_Init_02041218(&p->pltt);
            TexObj_Init(p, self->fileName, 1);
            STD_CopyString(p->name, self->arcName);
        }
        self->unk_4c = p;
        TexObj_SetRes(self->unk_4c, ResList_FindType2(res, p->unk_04c));
        self->unk_4c->flags |= 2;
        {
            ModelRes *q = (ModelRes *)((u8 *)self->unk_4c->res);
            self->unk_58 = q != NULL ? *LFLD(u16 *, q, 0xc) : 0;
        }
        for (i = 0; i < self->unk_58; i++) {
            TexObj_SelectImage(self->unk_4c, 0, i);
        }
        self->unk_44 = 5;
        break;
    }
    case 5:
        if (!Model_IsReady(self->unk_4c, 0xffff)) {
            break;
        }
        TexObj_ShrinkRes(self->unk_4c);
        if (Fade4_021b8284()) {
            self->unk_50 = 0x3e7000;
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
            self->unk_50 = 0;
        }
        self->unk_44 = 7;
        break;
    case 7:
        self->unk_50 += 0x1000;
        if (self->unk_50 >= 0xa000) {
            self->unk_50 = 0xa000;
            self->unk_54 = 0x1000;
        } else {
            self->unk_54 = FX_Div(self->unk_50, 0xa000);
            break;
        }
        self->unk_44 = 0xb;
        break;
    case 11:
        if (!self->stop) {
            break;
        }
        if (!FadeIdle021b8284()) {
            self->unk_50 = 0x3e7000;
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
            self->unk_50 = 0;
        }
        self->unk_44 = 0xd;
        break;
    case 13:
        self->unk_50 += 0x1000;
        if (self->unk_50 >= 0xa000) {
            self->unk_50 = 0xa000;
            self->unk_54 = 0x1000;
        } else {
            self->unk_54 = 0x1000 - FX_Div(self->unk_50, 0xa000);
            break;
        }
        if (FadeIdle021b8284() || Fade4_021b8284()) {
            self->unk_44 = 0xf;
        }
        break;
    case 15:
        LO_FREE_M(self, 0x4c);
        return FALSE;
    }
    return TRUE;
}
}
