#include "ov000/VObj.h"
#include "nitro/std.h"
#include "Main/Sys/SysState.h"
#include "ov000/SceneRes.h"

typedef struct {
    u8 unk_00;
    u8 unk_01[0x3];
    u32 unk_04;
    s32 unk_08;
    u16 unk_0c;
    u8 unk_0e[0x2];
    u32 unk_10;
    void *unk_14;
    u32 unk_18;
    char *unk_1c;
} Loader;

typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
} Data0202aca0;

typedef struct {
    u32 unk_00;
} Data02034f5c;

extern "C" {
extern void *data_ov000_021c9838;
extern u8 ResHandle_vtbl[];
extern u8 StageRes_vtbl[];
extern const char data_ov000_021ca8f7[];
extern const char data_ov000_021ca8ff[];
extern const char data_ov000_021ca907[];
extern const char data_ov000_021ca917[];

void *Heap_AllocArray(u32 size);
void *Heap_Alloc(u32 size);
BOOL OS_IsRunOnTwl(void);
void ResMgr_LoadArchive(void *a, char *name, s32 b, s32 c);
BOOL ResMgr_IsArchiveLoaded(void *a, char *name, s32 b);
void *ResMgr_GetArchiveList(void *a, char *name, s32 b);
Data02034f5c *ResList_FindType5(void *a, char *name);
char *G3dRes_SetupVram(char *name, u32 a);
void *Vram_GetTexTransferId(char *name);
Data0202aca0 *NNS_G3dGetTex(u32 a);
BOOL Vram_IsTransferDone(void *a);
void StageRes_Init(VObj *obj);
void StageRes_Open(VObj *obj, char *a, const char *b);
BOOL StageRes_IsAllLoaded(VObj *obj);
s32 StageRes_Bind(VObj *obj);

void Loader_Start(Loader *self, const char *name) {
    s32 len = STD_GetStringLength(name);
    self->unk_1c = (char *)Heap_AllocArray(len + 1);
    STD_CopyLString(self->unk_1c, name, len + 1);
    self->unk_08 = 1;
    self->unk_04 = OS_IsRunOnTwl() ? 0 : 1;
}

BOOL Loader_IsDone(Loader *self) {
    return self->unk_08 == 2;
}

u32 Loader_GetTexAddr(Loader *self) {
    return self->unk_10;
}

u8 func_ov000_0214b8f4(Loader *self) {
    if (OS_IsRunOnTwl()) {
        return self->unk_00;
    }
    return 1;
}

void Loader_StepLoadTex(Loader *self) {
    Data02034f5c *entry;
    void *data;
    char *name;
    switch (self->unk_0c) {
    case 0:
        ResMgr_LoadArchive(data_ov000_021c9838, self->unk_1c, 5, 0);
        self->unk_0c = 1;
        break;
    case 1:
        if (ResMgr_IsArchiveLoaded(data_ov000_021c9838, self->unk_1c, 5)) {
            self->unk_0c = 2;
        }
        break;
    case 2:
        data = ResMgr_GetArchiveList(data_ov000_021c9838, self->unk_1c, 5);
        entry = ResList_FindType5(data, self->unk_1c);
        name = self->unk_1c;
        if (entry != NULL) {
            name = G3dRes_SetupVram(name, entry->unk_00);
        }
        self->unk_14 = Vram_GetTexTransferId(name);
        self->unk_18 = NNS_G3dGetTex(entry->unk_00)->unk_08;
        self->unk_0c = 3;
        break;
    case 3:
        if (Vram_IsTransferDone(self->unk_14)) {
            self->unk_0c = 4;
        }
        break;
    case 4:
        self->unk_10 = (u16)self->unk_18 << 3;
        self->unk_08 = 2;
        self->unk_0c = 0;
        break;
    }
}

static inline SceneRes *CreateLoader(void) {
    SceneRes *obj = (SceneRes *)Heap_Alloc(sizeof(SceneRes));
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, ResHandle_vtbl);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, StageRes_vtbl);
        StageRes_Init(obj);
    }
    return obj;
}

void SceneResSet_Open04(void) {
    char path[0x20];
    gSceneResSet.unk_04 = CreateLoader();
    STD_CopyString(path, data_ov000_021ca8f7);
    STD_ConcatenateString(path, data_ov000_021ca8ff);
    StageRes_Open(gSceneResSet.unk_04, path, data_ov000_021ca907);
}

void SceneResSet_Close04(void) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (gSceneResSet.unk_04 != NULL) {
        if (gSceneResSet.unk_04 != NULL) {
            gSceneResSet.unk_04->vfunc_04();
        }
        gSceneResSet.unk_04 = NULL;
    }
    gSysState->cur = saved;
}

BOOL SceneResSet_IsLoaded04(void) {
    BOOL ret = TRUE;
    if (!StageRes_IsAllLoaded(gSceneResSet.unk_04)) {
        ret = FALSE;
    }
    return ret;
}

s32 SceneResSet_Bind04(void) {
    s32 ret = gSceneResSet.unk_04->vfunc_34();
    if (ret != 0) {
        return ret;
    }
    return StageRes_Bind(gSceneResSet.unk_04);
}

void SceneResSet_Run04(void) {
    gSceneResSet.unk_04->vfunc_38(1);
}

void SceneResSet_Open08(void) {
    char path[0x20];
    gSceneResSet.unk_08 = CreateLoader();
    STD_CopyString(path, data_ov000_021ca8f7);
    STD_ConcatenateString(path, data_ov000_021ca8ff);
    StageRes_Open(gSceneResSet.unk_08, path, data_ov000_021ca917);
}

void SceneResSet_Close08(void) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (gSceneResSet.unk_08 != NULL) {
        if (gSceneResSet.unk_08 != NULL) {
            gSceneResSet.unk_08->vfunc_04();
        }
        gSceneResSet.unk_08 = NULL;
    }
    gSysState->cur = saved;
}

BOOL SceneResSet_IsLoaded08(void) {
    BOOL ret = TRUE;
    if (!StageRes_IsAllLoaded(gSceneResSet.unk_08)) {
        ret = FALSE;
    }
    return ret;
}

s32 SceneResSet_Bind08(void) {
    s32 ret = gSceneResSet.unk_08->vfunc_34();
    if (ret != 0) {
        return ret;
    }
    return StageRes_Bind(gSceneResSet.unk_08);
}

}
