#include "ov002/ov002.h"

extern "C" {

bool Ov002Task_GetFlag4(Task *self) {
    BOOL r = Task_getFlag4(self);
    return r;
}

void Task021ef530_Init(Task021ef530 *self) {
    self->fadeLen = 0x10000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    self->unk_44 = NULL;
    self->unk_48 = 0;
    self->unk_4c = -1;
    self->unk_4d = 0;
}

void Task021ef530_Release(Task021ef530 *self) {
    void *saved;
    void *p;
    VObj *o;

    HEAP_PUSH(saved);
    p = self->unk_3c;
    if (p != NULL) {
        if (p != NULL) {
            TexObj_Release((Model *)p);
            PlttRes_Release((PlttRes *)((u8 *)p + 0x88));
            Heap_Free(p);
        }
        self->unk_3c = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_40;
    if (o != NULL) {
        if (o != NULL) {
            o->vfunc_04();
        }
        self->unk_40 = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_44;
    if (o != NULL) {
        if (o != NULL) {
            o->vfunc_04();
        }
        self->unk_44 = NULL;
    }
    HEAP_POP(saved);

    if (self->unk_4d) {
        ResMgr_ReleaseArchive(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
    }
}

void Task021ef530_SwitchTo(Task021ef530 *self, int arg) {
    TaskHost_RequestSwitch(gTaskHost, arg, 0);
}

void func_ov002_021cd92c(Task021ef530 *self, int kind) {
    void *msg = gMsgRes;
    void *str = data_ov002_021ef3f8;
    switch (kind) {
    case 0:
        str = MsgRes_GetString(msg, 0xdf);
        break;
    case 1:
        str = MsgRes_GetString(msg, 0xe0);
        break;
    case 2:
        str = MsgRes_GetString(msg, 0xc3);
        break;
    case 3:
        str = MsgRes_GetString(msg, 0xe2);
        break;
    case 4:
        str = MsgRes_GetString(msg, 0xe1);
        break;
    case 5:
        str = MsgRes_GetString(msg, 0xde);
        break;
    }
    Obj0215bb14_SetText(self->unk_44, str);
    ((VObj *)(self->unk_44))->vfunc_70();
}

}

extern "C" {
void SceneCmd_Push26(void *p);
void func_02062524(void);
BOOL func_020624d8(void);
void MessageQueue_FreeBuffer(FieldPlayer *a, TimedBuffer021cb920 *b);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} Flags021cd9c0;

void Task021ef530_UpdateActive(Task021ef530 *self) {
    u16 keys;
    s8 sel;
    s8 v;
    keys = gPad->trig;
    sel = (s8)UiList_GetCurrent(self->unk_40)->id;
    v = data_ov002_021f0f80->unk_08;
    if (v != -1) {
        self->unk_4c = -1;
        sel = v;
        data_ov002_021f0f80->unk_08 = -1;
    }
    if (self->unk_4c != sel) {
        keys = 0;
    }
    if (keys & 1) {
        switch (sel) {
        case 0:
            if (!self->unk_48_0) {
                data_ov002_021f0f80->unk_08 = 0;
                GfxSys_StartFadeOut(self->fadeLen, 2, 0);
                SceneCmd_Push1f(gSceneCmd);
                self->vfunc_0c(0);
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
            break;
        case 1:
            if (!self->unk_48_2) {
                Task *o;
                data_ov002_021f0f80->unk_08 = 1;
                o = TaskHost_RequestSwitch(gTaskHost, 0x1a, 0);
                o->parent = NULL;
                FIELD(o, 0x3c, s32) = self->id;
                self->vfunc_50();
                self->unk_04 |= 6;
                GfxSys_StartFadeOut(self->fadeLen, 2, -1);
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
            break;
        case 2:
            data_ov002_021f0f80->unk_08 = 2;
            self->vfunc_60(6, 0);
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            break;
        case 3:
            data_ov002_021f0f80->unk_08 = 3;
            gStageFlags->unk_009 = 0;
            self->vfunc_60(7, 0);
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            break;
        case 4:
            data_ov002_021f0f80->unk_08 = 4;
            TaskHost_RequestSwitch(gTaskHost, 0x11, 0)->parent = NULL;
            gTaskSwitchPending = 1;
            gTaskHost->flag0 = 0;
            self->vfunc_50();
            self->unk_04 |= 6;
            GfxSys_StartFadeOut(self->fadeLen, 2, -1);
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            break;
        case 5:
            if (!self->unk_48_1) {
                FieldPlayer *t;
                GfxSys_StartFadeOut(self->fadeLen, 2, -1);
                if (func_020624d8()) {
                    u8 buf[3];
                    buf[0] = data_02fe1534.unk_52;
                    buf[1] = data_02fe1534.unk_54;
                    buf[2] = data_02fe1534.unk_56;
                    SceneCmd_Push26(gSceneCmd);
                    func_ov000_02188ca0(buf, 1);
                    func_02062524();
                }
                t = gMessageQueue;
                if (t != NULL) {
                    MessageQueue_FreeBuffer(t, t->unk_118);
                    t->unk_118 = NULL;
                }
                self->vfunc_0c(0);
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
            break;
        }
    } else if (keys & 2) {
        VObj *m = self->unk_40;
        sel = 5;
        m->vfunc_a8(UiList_GetItemById(m, 5));
    }
    if (self->unk_4c != sel) {
        self->vfunc_78(sel);
    }
    self->unk_4c = sel;
}
}
