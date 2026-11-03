#include "ov006/ov006.h"
#include "Main/Effect/Effect.h"

typedef struct ov006_Color021d6d3c {
    u8 c[3];
} ov006_Color021d6d3c;

typedef struct ov006_Game021d6d3c {
    u8 unk0[0xca];
    ov006_Color021d6d3c cur;
    ov006_Color021d6d3c next;
    ov006_Color021d6d3c prev;
    u8 unkD3[0xb9];
    u8 unk18C;
    u8 unk18D;
    u8 unk18E;
    u8 unk18F;
    u8 unk190[0x3c];
    u8 unk1CC_0 : 1;
    u8 unk1CC_1 : 1;
    u8 unk1CC_2 : 6;
} ov006_Game021d6d3c;

typedef struct ov006_Fade021d6d3c {
    s32 unk0[3];
    s32 unkC;
} ov006_Fade021d6d3c;

typedef struct ov006_Scene021d6d3c {
    u8 unk0[0xc];
    int unkC;
    u8 unk10[0x2c];
    int unk3C;
} ov006_Scene021d6d3c;

extern "C" {

extern void *gSndMgr;
extern ov006_Game021d6d3c *gSceneCmd;
extern void *gGroup;
extern void *gActorMgr;
extern void *gFieldMgr;
extern ov006_Fade021d6d3c gFadeState;
void SndMgr_StopAll(void *a, int b);
void Group_RefreshAll(void *p);
void ActorMgr_DestroyAll(void *p);
void func_ov000_021b53f4(void *p);
void GfxSys_StartFadeOut(s32 a, int b, int c);
void GfxSys_UpdateFade(void);
BOOL func_ov006_021cd2a8(ov006_Manager *m);
void *ov006_GetSlotManager(void);
void ov006_Manager_DispatchMenuCb(int a, void *b, int c);


static inline void ov006_Game_SetColor(u8 r, u8 g, u8 b) {
    ov006_Game021d6d3c *game = gSceneCmd;
    game->next.c[0] = r;
    game->next.c[1] = g;
    game->next.c[2] = b;
    game = gSceneCmd;
    game->prev = game->cur;
    game->cur = game->next;
}

static inline BOOL ov006_FadeIdle(void) {
    BOOL r;
    if (gFadeState.unkC == 0 && gFadeState.unk0[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

BOOL Ov006Vt_021ebfc0_Exit(ov006_Scene021d6d3c *self) {
    BOOL r = FALSE;

    switch (self->unkC) {
    case 0:
        SndMgr_StopAll(gSndMgr, 0x1e);
        ov006_Game_SetColor(0xff, 0xff, 0xff);
        Group_RefreshAll(gGroup);
        ActorMgr_DestroyAll(gActorMgr);
        func_ov000_021b53f4(gFieldMgr);
        EffectMgr_FreeAll(gEffectMgr);
        {
            ov006_Game021d6d3c *game = gSceneCmd;
            game->unk1CC_1 = 0;
            game->unk18C = 0;
            game->unk18D = 0;
            game->unk18E = 0;
            game->unk18F = 0;
        }
        gSysState->frameWait = 1;
        gOv006Menu->unk15E = 2;
        if (ov006_FadeIdle()) {
            GfxSys_StartFadeOut(0x1000, 0, 0);
            GfxSys_StartFadeOut(0x1000, 0, 1);
        }
        GfxSys_UpdateFade();
        if (func_ov006_021cd2a8(gOv006Manager)) {
            self->unkC = 2;
        } else {
            self->unkC++;
        }
        break;
    case 1:
        self->unkC++;
        break;
    case 2:
        gOv006Manager->unk18++;
        ov006_Manager_DispatchMenuCb(8, ov006_GetSlotManager(), self->unk3C);
        r = TRUE;
        break;
    }
    return r;
}

}
