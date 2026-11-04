/* Built at a lower optimization level: 02197dec only matches with it. */
#pragma optimization_level 2

#include "types.h"

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
    u8 unk_ad[0x1d];
    u8 unk_ca;
    u8 unk_cb;
} Player021ccd54;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[(0x518 - 0x158) / 16][4]; // StageFlags.unk_158: 60 rows of 32 4-bit flags
} SaveData;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u16 kind;
    u8 unk_10[0x7];
    u8 index;
    u16 value;
    u8 unk_1a[0x92];
    u8 unk_ac;
    u8 unk_ad;
} Obj02197d80;

extern Player021ccd54 *gSceneCmd;
extern SaveData *gStageFlags;

u16 LangData_GetIndex(u32 a, u32 b);
void *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(void);
void Shared_SetEventActor(u16 kind, u16 id);
void StageVars_SetEventScript(u16 sfx);
void func_020627c8(void);
void SceneStage_StartScript(u8 *p);

static inline void SaveData_SetNibble(s32 row, s32 idx, u32 value) {
    u32 *p = &gStageFlags->flags[row][idx / 8];
    s32 sh = (idx % 8) * 4;
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int SaveData_GetNibble(s32 row, s32 idx) {
    return (gStageFlags->flags[row][idx / 8] >> ((idx % 8) * 4)) & 0xf;
}

static inline void Obj_StoreValue(Obj02197d80 *self, u8 value) {
    u8 idx = self->index;
    s32 row;

    if (idx != 0xff) {
        row = LangData_GetIndex(self->unk_ac, self->unk_ad);
        if (row != 0xffff) {
            value |= SaveData_GetNibble(row, idx) & 8;
            SaveData_SetNibble(row, idx, value);
        }
    }
}

void Obj02197d80_LoadValue(Obj02197d80 *self) {
    u8 idx = self->index;
    s32 row;

    if (idx == 0xff) {
        return;
    }
    row = LangData_GetIndex(gSceneCmd->unk_ca, gSceneCmd->unk_cb);
    self->value = SaveData_GetNibble(row, idx) & 7;
}

void func_ov000_02197dec(Obj02197d80 *self, u8 value, s16 sfx) {
    Obj_StoreValue(self, value);
    if (sfx > 0 && ActorMgr_FindPlayer() != NULL && !Actor_IsDead()) {
        Shared_SetEventActor(self->kind, self->id);
        StageVars_SetEventScript(sfx);
        {
            Player021ccd54 *pl = gSceneCmd;
            pl->unk_ac = 1;
            SceneStage_StartScript(&pl->unk_ac);
        }
    }
    func_020627c8();
}
