#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3620(UiList *self, u16 id, s32 b);


void func_ov000_021b1d28(void);

void StageFlags_SetCounter(void *a, u8 b, u8 c);

s32 SndMgr_PlayPan(void *a, int b, int c);

void func_ov002_021d5f60(Task021efc24 *self) {
    UiList *g = self->unk_50;
    u16 prev;
    UiListItem *p;
    u8 i;
    if (g == NULL) {
        return;
    }
    prev = self->unk_74;
    p = g->topItem;
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = g->cursor;
        while (n-- != 0) {
            p = p->next;
        }
    }
    self->unk_74 = p->id;
    func_ov002_021e3620(self->unk_50, prev, 0);
    func_ov002_021e3620(self->unk_50, self->unk_74, 4);
    Obj0215bb14_SetText(self->unk_4c, Param_Get(self->unk_74));
    self->unk_4c->vfunc_70();
    gStageFlags->bits18.unk_3 = self->unk_74;
    if (ActorMgr_FindPlayer()) {
        func_ov000_021b1d28();
    } else {
        gStageFlags->bits18.mode = 1;
    }
    for (i = 0; i < 5; i++) {
        s16 v = self->unk_60[i] + self->unk_6a[i];
        if (v < 0) {
            v = 0;
        } else if (v > 99) {
            v = 99;
        }
        StageFlags_SetCounter(gStageFlags, i, (s8)v);
    }
    SndMgr_PlayPan(gSndMgr, 0x2c, -5);
    SndMgr_PlayVolume(gSndMgr, 0x44, -1, -1, -1);
}

static inline bool isState5(UiObj *p) {
    return p->state == 5;
}

void func_ov000_021c95fc(void *p);

BOOL MsgBox_Update(void *p);

void ModelViewer_Update(void *p);


void Task021efc24_PreUpdate(Task021efc24 *self) {
    switch (self->state) {
    case 8:
        self->unk_4c->flags &= ~2;
        self->unk_50->flags &= ~2;
        self->unk_54->flags &= ~2;
        break;
    case 13: {
        BOOL a = isState5(self->unk_50);
        if (a) {
            BOOL b = isState5(self->unk_54);
            if (b) {
                Task021efba4 *x = (Task021efba4 *)Task_FindById(0x1b);
                if (x != NULL) {
                    u8 buf[0x14];
                    func_ov000_021c95fc(buf);
                    if (x->hud != NULL) {
                        MI_CpuCopy8(buf, x->hud->unk_2c, 0x14);
                    }
                    if (x->hud != NULL) {
                        Ov002Hud_SetRow(x->hud, 0, 0);
                    }
                    if (x->hud != NULL) {
                        Ov002Hud_SetInfo(x->hud, 0xffff);
                    }
                }
                self->unk_04 |= 6;
                self->pendingId = 0x1c;
            }
        }
        break;
    }
    }
    ModelViewer_Update(self->unk_58);
    if (self->unk_5c != NULL && !MsgBox_Update(self->unk_5c)) {
        u16 id;
        Task021efba4 *x;
        {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(self->unk_5c);
            HEAP_POP(saved);
        }
        self->unk_50->flags &= ~4;
        self->unk_54->flags &= ~4;
        self->unk_54->flags &= ~2;
        self->unk_54->vfunc_1c();
        id = UiList_GetCurrent(self->unk_50)->id;
        if (self->unk_54 != NULL) {
            Obj0215bb14_SetText(self->unk_54, func_0206ec8c(id));
            self->unk_54->vfunc_70();
        }
        x = (Task021efba4 *)Task_FindById(0x1b);
        if (x != NULL && x->hud != NULL) {
            Ov002Hud_SetRow(x->hud, 9, 0);
        }
    }
    self->unk_4c->vfunc_1c();
    self->unk_50->vfunc_1c();
    self->unk_54->vfunc_1c();
}

}
