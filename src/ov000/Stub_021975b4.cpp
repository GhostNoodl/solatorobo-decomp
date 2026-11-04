#include "ov000/VObj.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0x52];
    s32 unk_68;
    u8 unk_6c[4];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
} Obj021975b4;

extern "C" {

Obj0219bf90 *ActorMgr_FindPlayer(void);
void func_020627b4(void);
void Shared_SetEventActor(u16 a, u16 b);
void StageVars_SetEventScript(s32 a);
void SceneStage_StartScript(u8 *p);
s32 StageRes_HasQueued(void);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
extern void *gSndMgr;

void func_ov000_021974b0(Obj021975b4 *self) {
    Obj0219bf90 *p = ActorMgr_FindPlayer();
    func_020627b4();
    Shared_SetEventActor(self->unk_0e, self->unk_0c);
    StageVars_SetEventScript(0x8002);
    {
        FieldState *pl = gSceneCmd;
        pl->stageFlags = 1;
        SceneStage_StartScript(&pl->stageFlags);
    }
    if (StageRes_HasQueued() == 1 && p != NULL && p->unk_b28_0 == 0) {
        p->unk_15 = 3;
        p->unk_b28_0 = 0;
        p->unk_b28_2 = 1;
    }
    if (p == NULL) {
        return;
    }
    {
        VecFx32 pos;
        pos.x = p->unk_70;
        pos.y = p->unk_74;
        pos.z = p->unk_78;
        Effect_SpawnId(0x44f, &pos)->AddPosXYZ(0, p->unk_68, 0);
    }
    SndMgr_PlayVolume(gSndMgr, 0x88, -1, -1, -1);
}

void func_ov000_021975b4(Obj021975b4 *self) {
    Obj0219bf90 *p;
    func_020627b4();
    Shared_SetEventActor(self->unk_0e, self->unk_0c);
    StageVars_SetEventScript(0x8003);
    {
        FieldState *pl = gSceneCmd;
        pl->stageFlags = 1;
        SceneStage_StartScript(&pl->stageFlags);
    }
    if (StageRes_HasQueued() != 1) {
        return;
    }
    p = ActorMgr_FindPlayer();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

}
