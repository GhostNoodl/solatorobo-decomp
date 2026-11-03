#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/Model.h"
#include "ov006/SlotManager.h"
#include "ov006/Racer.h"
#include "Main/Effect/Effect.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

#include "Main/Sys/FieldState.h"
#include "ov000/Group.h"
#include "Main/Math/Rot16.h"

/* The task with vtable Ov006Vt_021ebfc0_vtbl (Ov006Vt_021ebfc0_Ctor, task type 1). */
struct ov006_Unk021d5b98 : public ov006_Task {
    u8 unk10[0xc];
    VObj *unk1C;
    VObj *unk20;
    Model *unk24;
    VObj *unk28;
    VObj *unk2C;
    VObj *unk30;
    VObj *unk34;
    u8 unk38[0x38];
    void *unk70[6];
};

extern "C" {

extern u8 Ov006Vt_021ebfc0_vtbl[];
extern char data_0214b105[];
extern char data_ov006_021ec864[];
void LangData_LocalizePath(char *dst, const char *src);
void *ResSet_ReleaseAll(void *p);
void func_ov006_021ccddc(ov006_Task *self);

static inline void ov006_Unk021d5b98_dtor(ov006_Unk021d5b98 *self) {
    char buf[0x20];
    int i;
    *(void **)self = Ov006Vt_021ebfc0_vtbl;
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
    OV006_DELETE_MODEL(self->unk24);
    OV006_DELETE_OBJECT(self->unk28);
    OV006_DELETE_OBJECT(self->unk2C);
    OV006_DELETE_OBJECT(self->unk30);
    OV006_DELETE_OBJECT(self->unk34);
    ResMgr_ReleaseByName(gResMgr, data_0214b105, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_0208cc94, 7, 0);
    LangData_LocalizePath(buf, "menu/skyrace");
    ResMgr_ReleaseByName(gResMgr, buf, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_ov006_021ec864, 7, 0);
    {
        // The name in a local makes the literal load come before the manager load.
        const char *s = "ef/effect3darc";
        ResMgr_ReleaseByName(gResMgr, s, 7, 0);
    }
    ResMgr_ReleaseByName(gResMgr, "ef/effect3dtri", 7, 0);
    i = 0;
    for (; i < 6; i++) {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk70[i] != NULL) {
            if (self->unk70[i] != NULL) {
                void *p = self->unk70[i];
                ResSet_ReleaseAll(p);
                Heap_Free(p);
            }
            self->unk70[i] = NULL;
        }
        gSysState->cur = saved;
    }
    func_ov006_021ccddc(self);
}

ov006_Unk021d5b98 *Ov006Vt_021ebfc0_Dtor(ov006_Unk021d5b98 *self) {
    ov006_Unk021d5b98_dtor(self);
    return self;
}

ov006_Unk021d5b98 *Ov006Vt_021ebfc0_DtorDelete(ov006_Unk021d5b98 *self) {
    ov006_Unk021d5b98_dtor(self);
    Heap_Free(self);
    return self;
}

}


typedef struct ov006_Info021d6140 {
    u8 unk0[0xa];
    u8 lo : 4;
    u8 hi : 4;
} ov006_Info021d6140;

typedef struct ov006_Unk02097e48 {
    u16 unk0_0 : 3;
    u16 active : 1;
    u16 unk0_4 : 12;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Unk02097e48;

struct ov006_Task021d6140 : public ov006_Task {
    u8 unk10[0x60];
    void *unk70[6];
};

extern "C" {

extern const u16 data_ov006_021eb7a8[];
extern ov006_Unk02097e48 *gSndQueue;

void LangData_LocalizePath(char *dst, const char *src);
void *ResSet_Init(void *p);
void func_ov000_02193e5c(void *p, u16 id);
void GfxSys_StartFadeOut(s32 a, int b, int c);
void GfxSys_UpdateFade(void);

static inline void ov006_Game_SetColor(u8 r, u8 g, u8 b) {
    // The aggregate initializer keeps c in memory; its stores are dead but still emitted.
    FieldId c = {r, g, b};
    FieldState *game = gSceneCmd;
    game->unk_cd = c;
    game = gSceneCmd;
    game->unk_d0 = game->unk_ca;
    game->unk_ca = game->unk_cd;
}

BOOL Ov006Vt_021ebfc0_Load(ov006_Task021d6140 *self) {
    char buf[0x21];
    int i;
    ResMgr_Load(data_0214b105, 7, 0);
    ResMgr_Load(data_0208cc94, 7, 0);
    LangData_LocalizePath(buf, "menu/skyrace");
    ResMgr_Load(buf, 7, 0);
    ResMgr_Load(data_ov006_021ec864, 7, 0);
    ResMgr_Load("ef/effect3darc", 7, 0);
    ResMgr_Load("ef/effect3dtri", 7, 0);
    for (i = 0; i < 6; i++) {
        void *p = Heap_Alloc(0x138);
        if (p != NULL) {
            p = ResSet_Init(p);
        }
        self->unk70[i] = p;
        func_ov000_02193e5c(p, data_ov006_021eb7a8[i]);
    }
    {
        ov006_Info021d6140 *info = (ov006_Info021d6140 *)gOv006SlotManager->info;
        ov006_Game_SetColor(0x12, info->lo, info->hi);
    }
    GfxSys_StartFadeOut(0x1000, 0, 0);
    GfxSys_StartFadeOut(0x1000, 0, 1);
    GfxSys_UpdateFade();
    {
        ov006_Unk02097e48 *p = gSndQueue;
        if (p->active) {
            p->unk6 = 0x8000;
            p->unk8 = 0xf0;
            p->unk2 = 0;
        }
    }
    return TRUE;
}

}


typedef struct ov006_PartyEntry {
    VecFx32 pos;
    u16 rot;
    u16 pad;
} ov006_PartyEntry;

typedef struct ov006_Party {
    u8 unk0[0x15];
    u8 count;
} ov006_Party;

typedef struct ov006_Unk021ccd6c {
    u8 unk0[0x14];
    ov006_Party *party;
} ov006_Unk021ccd6c;

typedef struct ov006_BitsDA {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 3;
    u8 b7 : 1;
} ov006_BitsDA;

typedef struct ov006_Info021d630c {
    u8 unk0[8];
    u16 unk8;
} ov006_Info021d630c;

struct ov006_Task021d630c : public ov006_Task {
    u8 unk10[0x60];
    s16 *unk70[6];
};

extern "C" {

extern Group *gGroup;
extern void *gActorMgr;
extern ov006_Unk021ccd6c *gFieldMgr;
extern void *gSndMgr;

void Group_RefreshAll(Group *self);
void func_ov000_0218be54(Group *self);
void ActorMgr_DestroyAll(void *p);
void func_ov000_021b53f4(void *p);
void LangData_LocalizePath(char *dst, const char *src);
BOOL ResSet_UpdateLoad(void *p);
BOOL FieldMgr_UpdateLoad(void *p);
void func_ov000_021b5dc0(void *p);
int LangBlockB_GetData(ov006_Party *party);
ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
Ov006Racer *Ov006Racer_New(u32 id, u8 a, const VecFx32 *pos, const Rot16 *rot);
BOOL ActorMgr_IsReady(void *p);
void func_0204a2f0(void *a, u16 b);
BOOL SndMgr_IsLoadDone(void *a);

static inline int ov006_GetPartyValue(ov006_Unk021ccd6c *self) {
    if (self->party == NULL || self->party->count == 0) {
        return 0;
    }
    return LangBlockB_GetData(self->party);
}

BOOL Ov006Vt_021ebfc0_IsLoaded(ov006_Task021d630c *self) {
    BOOL result;
    int i;
    int zero;
    i = 0;
    result = i;
    zero = i;
    switch (self->subState) {
    case 0:
        EffectMgr_FreeAll(gEffectMgr);
        gGroup->unk_0c.bits.flag_0 = 1;
        Group_RefreshAll(gGroup);
        ActorMgr_DestroyAll(gActorMgr);
        func_ov000_021b53f4(gFieldMgr);
        self->subState++;
        break;
    case 1: {
        char buf[0x20];
        if (!ResMgr_IsLoaded(data_0214b105, 7)) {
            break;
        }
        if (!ResMgr_IsLoaded(data_0208cc94, 7)) {
            break;
        }
        LangData_LocalizePath(buf, "menu/skyrace");
        if (!ResMgr_IsLoaded(buf, 7)) {
            break;
        }
        if (!ResMgr_IsLoaded(data_ov006_021ec864, 7)) {
            break;
        }
        if (!ResMgr_IsLoaded("ef/effect3darc", 7)) {
            break;
        }
        if (!ResMgr_IsLoaded("ef/effect3dtri", 7)) {
            break;
        }
        self->subState++;
        break;
    }
    case 2:
        result = TRUE;
        for (; i < 6; i++) {
            if (*self->unk70[i] >= 0 && !ResSet_UpdateLoad(self->unk70[i])) {
                result = zero;
            }
        }
        if (!result) {
            break;
        }
        result = FALSE;
        self->subState++;
        break;
    case 3:
        self->subState++;
        break;
    case 4:
        if (gEffectMgr->state >= 3) {
            self->subState++;
            break;
        }
        EffectMgr_Update(gEffectMgr);
        break;
    case 5: {
        ov006_PartyEntry *tbl;
        u8 j;
        u8 n;
        if (!FieldMgr_UpdateLoad(gFieldMgr)) {
            break;
        }
        func_ov000_021b5dc0(gFieldMgr);
        tbl = (ov006_PartyEntry *)ov006_GetPartyValue(gFieldMgr);
        n = gOv006SlotManager->numActive;
        for (j = 0; j < n; j++) {
            VecFx32 pos;
            Rot16 rot;
            ov006_Slot *slot;
            if (tbl != NULL) {
                pos.x = tbl[j].pos.x;
                pos.y = tbl[j].pos.y;
                pos.z = tbl[j].pos.z;
                rot.y = tbl[j].rot;
                rot.x = zero;
                rot.z = zero;
            } else {
                pos.x = zero;
                pos.y = zero;
                pos.z = zero;
                rot.x = zero;
                rot.y = zero;
                rot.z = zero;
            }
            slot = ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, j);
            if (slot->active) {
                Ov006Racer *prop = Ov006Racer_New(slot->unkC, j, &pos, &rot);
                if (prop != NULL) {
                    slot->actorId = prop->id;
                    Obj0218c208_AddPoint(gGroup, &pos, rot.y);
                }
            }
            if (j == gOv006SlotManager->unk5) {
                FieldCam *cam = &gSceneCmd->cam;
                cam->unk_d8 |= 2;
                cam->unk_e8 = pos;
                cam->unk_da |= 2;
                cam->unk_f8 = rot;
                cam->unk_f4 = 0xa000;
                cam->unk_da = ((cam->unk_da | 0x70) & ~0xc) | 4;
                cam->base.smooth = 0;
                ((VObj *)cam)->vfunc_00(); // slot 0x00: apply the camera
                cam->base.smooth = 1;
            }
        }
        if (gGroup != NULL) {
            func_ov000_0218be54(gGroup);
        }
        self->subState++;
        break;
    }
    case 6:
        if (!ActorMgr_IsReady(gActorMgr)) {
            break;
        }
        func_0204a2f0(gSndMgr, ((ov006_Info021d630c *)gOv006SlotManager->info)->unk8);
        self->subState++;
        break;
    case 7:
        if (SndMgr_IsLoadDone(gSndMgr)) {
            self->subState = i - 1;
            result = TRUE;
        }
        break;
    }
    return result;
}

}


typedef struct ov006_Info021d6724 {
    u8 unk0[4];
    int unk4;
    u8 unk8[4];
    s16 unkC;
    s16 unkE;
    s16 unk10;
} ov006_Info021d6724;

typedef struct ov006_Gauge021d6724 {
    u8 unk0[0x10];
    u8 cur;
    u8 max;
    u8 unk12[0xa];
    void *unk1C;
} ov006_Gauge021d6724;

typedef struct VecFx32021d6724 {
    u8 unk0[8];
    int x;
    int y;
    u8 unk10[0x40];
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
} VecFx32021d6724;

struct ov006_Task021d6724 : public ov006_Task {
    u8 unk10[0xc];
    ov006_Gauge021d6724 *unk1C;
    void *unk20;
    Model *unk24;
    VecFx32021d6724 *unk28;
    VecFx32021d6724 *unk2C;
    VecFx32021d6724 *unk30;
};

typedef struct ov006_Msg021d6724 {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    int unk4;
    int unk8;
    int unkC;
} ov006_Msg021d6724;

typedef struct ov006_Bits0e {
    u8 b0 : 2;
    u8 b2 : 2;
    u8 rest : 4;
} ov006_Bits0e;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

#define OV006_MIN(a, b) ((a) > (b) ? (b) : (a))

extern "C" {

extern ov006_Unk02097e40 *gWhMgr;

ov006_SlotManager *ov006_GetSlotManager(void);
void ov006_Manager_DispatchMenuCb(int a, void *b, int c);
ov006_Gauge021d6724 *Ov006Vt_021ec2bc_Ctor(void *p);
void ov006_Unk021ddcc0_Load(ov006_Gauge021d6724 *p);
void LoTimer_Setup(void *p, int a, int b, int c);
VecFx32021d6724 *Ov006Vt_021ec1fc_Ctor(void *p);
void ov006_Unk021e16b0_Load(VecFx32021d6724 *p);
void *Param_Get(u32 id);
void ov006_Unk021e1e6c_PlayText(VecFx32021d6724 *a, const void *b);
void ov006_Unk021e1ddc_SetLabel(VecFx32021d6724 *a, const char *b, int c, int d);
VecFx32021d6724 *Ov006Vt_021ec2cc_Ctor(void *p);
void ov006_MarkerSet_Load(VecFx32021d6724 *p);
VecFx32021d6724 *Ov006Vt_021ec2ac_Ctor(void *p);
void ov006_Unk021e279c_Load(VecFx32021d6724 *p);
BOOL Vram_IsIdle(void);
void func_02039518(void *p);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);
u16 func_02046ab4(ov006_Unk02097e40 *a);
u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
void ov006_Menu_ClearEntries(ov006_Menu *self);

static inline void ov006_Gauge_Init(ov006_Gauge021d6724 *g, int a, int b, int c) {
    if (g->unk1C != NULL) {
        LoTimer_Setup(g->unk1C, a, b, c);
    }
}

static inline void VecFx32_SetXY(VecFx32021d6724 *p, int x, int y) {
    p->x = x;
    p->y = y;
}

static inline void VecFx32_Set3(VecFx32021d6724 *p, int x, int y, int z) {
    p->unk54 = x;
    p->unk58 = y;
    p->unk5C = z;
}

static inline void ov006_Gauge_Set(u8 n, ov006_Gauge021d6724 *g) { g->cur = OV006_MIN((u8)(n ? 1 : 0), n); g->max = n; }
BOOL Ov006Vt_021ebfc0_Start(ov006_Task021d6724 *self) {
    int zero = 0;
    BOOL result = zero;
    switch (self->subState) {
    case 0: {
        ov006_Info021d6724 *info;
        ov006_Gauge021d6724 *g;
        Model *model;
        VecFx32021d6724 *p;
        ov006_Manager_DispatchMenuCb(7, ov006_GetSlotManager(), result);
        g = (ov006_Gauge021d6724 *)Heap_Alloc(0x38);
        if (g != NULL) {
            g = Ov006Vt_021ec2bc_Ctor(g);
        }
        self->unk1C = g;
        ov006_Unk021ddcc0_Load(g);
        ov006_Gauge_Init(self->unk1C, gOv006SlotManager->unk13C ? 2 : 1, gOv006SlotManager->time, gOv006SlotManager->unk144);
        ov006_Gauge_Set(gOv006SlotManager->info->unkB, self->unk1C);
        model = (Model *)Heap_Alloc(sizeof(Model));
        if (model != NULL) {
            const char *name = "cefly1pic00";
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
        self->unk24 = model;
        TexObj_SetRes(self->unk24, ResMgr_FindArcType2(data_ov006_021ec864, "cefly1pic00"));
        self->unk24->flags |= 2;
        self->unk24->flags |= 0x400000;
        TexObj_SelectImage(self->unk24, 2, 0xffff);
        info = (ov006_Info021d6724 *)gOv006SlotManager->info;
        p = (VecFx32021d6724 *)Heap_Alloc(0x30);
        if (p != NULL) {
            p = Ov006Vt_021ec1fc_Ctor(p);
        }
        self->unk28 = p;
        ov006_Unk021e16b0_Load(p);
        ov006_Unk021e1e6c_PlayText(self->unk28, Param_Get(gOv006SlotManager->unk6));
        ov006_Unk021e1ddc_SetLabel(self->unk28, "menu/skyrace_map", info->unk4, zero);
        VecFx32_SetXY(self->unk28, -0x2c, 0xc);
        p = (VecFx32021d6724 *)Heap_Alloc(0xa4);
        if (p != NULL) {
            p = Ov006Vt_021ec2cc_Ctor(p);
        }
        self->unk2C = p;
        ov006_MarkerSet_Load(p);
        VecFx32_SetXY(self->unk2C, 0x24, -0x2c);
        p = (VecFx32021d6724 *)Heap_Alloc(0x64);
        if (p != NULL) {
            p = Ov006Vt_021ec2ac_Ctor(p);
        }
        self->unk30 = p;
        ov006_Unk021e279c_Load(p);
        VecFx32_SetXY(self->unk30, -0x2d, 9);
        self->unk30->unk50 = (info->unkC << 12) / 100;
        VecFx32_Set3(self->unk30, info->unkE << 12, zero, info->unk10 << 12);
        ((ov006_Bits0e *)&gSceneCmd->pause[6])->b2 = 0;
        gSysState->frameWait = 2;
        gOv006Menu->unk15E = 1;
        self->subState++;
        break;
    }
    case 1:
        if (!Vram_IsIdle()) {
            break;
        }
        func_02039518(ResMgr_FindArcType2(data_ov006_021ec864, "cefly1pic00"));
        func_02039518(ResMgr_FindArcType2(data_ov006_021ec864, "cefly1cmn01"));
        self->subState = 10;
        break;
    case 10:
        if (gOv006Manager->unk1C != 0 && gOv006Menu->state != 9) {
            ov006_Msg021d6724 msg;
            msg.unk0 = 0;
            msg.unk2 = 0;
            msg.unk3 = 0;
            msg.unk4 = 0;
            msg.unk8 = 0;
            msg.unkC = 0;
            ov006_Menu_SetOwnEntry(gOv006Menu, 7, 3, &msg, 0x10);
            if (func_02046ab4(gWhMgr) == 0) {
                self->subState = 20;
            } else {
                self->subState = 30;
            }
        } else {
            self->subState = 40;
        }
        break;
    case 20: {
        u16 mask;
        if (gOv006Menu->state == 9) {
            self->subState = 40;
            break;
        }
        mask = gWhMgr->unk32;
        if (mask == ov006_Menu_GetEntryMask_021e60e8(7, mask)) {
            ov006_Msg021d6724 msg;
            msg.unk0 = 0;
            msg.unk2 = 0;
            msg.unk3 = 0;
            msg.unk4 = 0;
            msg.unk8 = 0;
            msg.unkC = 0;
            ov006_Menu_SetOwnEntry(gOv006Menu, 8, 3, &msg, 0x10);
            self->subState++;
        }
        break;
    }
    case 21:
        self->subState = 40;
        break;
    case 30: {
        u16 mask;
        if (gOv006Menu->state == 9) {
            self->subState = 40;
            break;
        }
        mask = gWhMgr->unk32;
        if (mask != ov006_Menu_GetEntryMask_021e60e8(8, mask)) {
            break;
        }
        self->subState = 40;
    }
    case 40:
        ov006_Menu_ClearEntries(gOv006Menu);
        self->subState = -1;
        result = TRUE;
        break;
    }
    return result;
}

}
