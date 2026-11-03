#include "ov000/LoCommon.h"
#include "Main/Res/StageVars.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/std.h"

extern "C" {

extern u8 UiObj_vtbl[];
extern u8 Lo021cad50_vtbl[];
extern char data_ov000_021ca940[];
extern void *gSndMgr;
void Obj0215c1bc_SetMsg(Lo021cad50 *self, s32 id);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
Robo021ca458 *ActorMgr_FindPlayer(void);
void Robo021ca458_RestoreHp(void *p);
char *func_02061f08(u16 id);
int func_02060898(u16 a, s32 b, s32 c);
void SceneCmd_Push07(void *p, u16 id, s32 a, s32 b, s32 c, s32 d, s32 e);

static inline void Beep02151664(void) {
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
}

static inline void Show02151664(Lo021ca9c4 *self, s32 id) {
    if (self->unk_58 == NULL) {
        VObj *p = (VObj *)Heap_Alloc(0xe8);
        if (p) {
            VOBJ_SET_VTABLE(p, UiObj_vtbl);
            p->vfunc_28();
            VOBJ_SET_VTABLE(p, Lo021cad50_vtbl);
            p->vfunc_28();
        }
        self->unk_58 = (Lo021cad50 *)p;
    }
    self->unk_58->font = 4;
    self->unk_58->vfunc_08();
    Obj0215c1bc_SetMsg(self->unk_58, id);
    self->unk_58->posZ = -0x1666;
    self->unk_58->vfunc_70();
}

static inline BOOL Check02151664(Lo021ca9c4 *self) {
    char *s;
    if (ActorMgr_FindPlayer()->unk_b24_1) {
        return TRUE;
    }
    s = func_02061f08(LFLD(u16, self->unk_54, 6));
    if (s == NULL) {
        return FALSE;
    }
    return STD_SearchString(s, data_ov000_021ca940) != NULL ? TRUE : FALSE;
}

// onDecide of the list (Lo021ca9c4_UpdateActive).
BOOL func_ov000_02151664(UiList *p, UiListItem *msg) {
    Lo021ca9c4 *o = (Lo021ca9c4 *)p->owner;
    if (msg == NULL) {
        Beep02151664();
        return FALSE;
    }
    if (msg->id == 0) {
        u8 *info = (u8 *)o->unk_54;
        if (data_02fe1534.unk_46 != LFLD(u16, info, 0x30)) {
            Beep02151664();
            Show02151664(o, 0x68);
        } else if (data_02fe1534.unk_58 < LFLD(u16, info, 0x34)) {
            Beep02151664();
            Show02151664(o, 0x69);
            o->unk_5c = 0x6a;
        } else if (!Check02151664(o)) {
            Beep02151664();
            Show02151664(o, 0x6c);
        } else {
            Robo021ca458 *pl = ActorMgr_FindPlayer();
            if (pl != NULL) {
                Robo021ca458_RestoreHp(pl);
            }
            func_02060898(o->unk_40, 0, -1);
            SceneCmd_Push07(gSceneCmd, LFLD(u16, o->unk_54, 6), 10, 0, 0, 0, 0);
            if (o->unk_4c != NULL) {
                o->unk_4c->flags |= 2;
            }
            if (o->unk_50 != NULL) {
                o->unk_50->flags |= 2;
            }
            if (o->unk_58 != NULL) {
                o->unk_58->flags |= 2;
            }
            o->vfunc_3c();
        }
        return FALSE;
    } else if (msg->id == 1) {
        Beep02151664();
        return FALSE;
    }
    return TRUE;
}

}
