#include "types.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u8 unk_00[0xa];
    u16 unk_0a;
    u8 unk_0c[0x14c];
    u32 flags[1][4];
} Ov003SaveData;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
} Ov003Player;

extern "C" {
extern Ov003SaveData *gStageFlags;
extern void *gGroup;

u16 LangData_GetIndex(int a, int b);
Ov003Player *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(void);
void Shared_SetEventActor(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_ov000_02182590(u8 *p);
void Ov003_AddExp(u16 id);
void Group_UpdateActor(void *mgr, s32 a, void *obj);

}

static inline void SaveData_SetNibble(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &gStageFlags->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int SaveData_GetNibble(s32 row, s32 idx) {
    u32 w = gStageFlags->flags[row][idx / 8];
    return (w >> ((idx % 8) * 4)) & 0xf;
}

static inline void Obj_StoreValue(Ov003Actor *self, u8 value) {
    u8 idx = self->unk_17;
    s32 row;

    if (idx != 0xff) {
        row = LangData_GetIndex(self->unk_ac, self->unk_ad);
        if (row != 0xffff) {
            value |= SaveData_GetNibble(row, idx) & 8;
            SaveData_SetNibble(row, idx, value);
        }
    }
}

extern "C" void Ov003Actor_Defeat(Ov003Actor *self, BOOL release, BOOL mark, BOOL sound) {
    Ov003Player *pl = ActorMgr_FindPlayer();
    if (pl != NULL && !Actor_IsDead()) {
        if (sound) {
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(2);
            {
                FieldState *g = gSceneCmd;
                g->stageFlags = 1;
                func_ov000_02182590(&g->stageFlags);
            }
        }
        if (mark) {
            u8 idx = self->unk_17;
            if (idx != 0xff) {
                s32 row = LangData_GetIndex(self->unk_ac, self->unk_ad);
                if (row != 0xffff) {
                    u8 value = 0xf;
                    value |= SaveData_GetNibble(row, idx) & 8;
                    SaveData_SetNibble(row, idx, value);
                }
            }
        }
        if (self->hpObj->unk_04 == pl->unk_0c || self->hpObj->unk_04 == self->id) {
            u32 n;
            Ov003_AddExp(self->unk_b0->unk_04);
            n = gStageFlags->unk_0a + 1;
            if (n >= 0xffff) {
                n = 0xffff;
            }
            gStageFlags->unk_0a = n;
        }
    }
    if (release) {
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
    }
}
