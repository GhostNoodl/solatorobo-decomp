#include "ov002/ov002.h"

extern "C" {

void Task021ef71c_Draw(Task021ef71c *self) {
    if (self->unk_68 == 0 && self->state == 0xd && self->unk_64 == 1) {
        Ov002Stage_DrawCur();
    }
}

BOOL func_ov002_021d166c(Task021ef71c *self) {
    BOOL result = TRUE;
    switch (self->unk_64) {
    case 0:
        if (self->unk_5c < 8 && ((s32 *)((u8 *)self + 0x3c))[self->unk_5c] >= 0) {
            GfxSys_StopFade(-1);
            Movie_Load(gMovie, ((s32 *)((u8 *)self + 0x3c))[self->unk_5c], -1, 0);
            self->unk_64 = 1;
        } else {
            GfxSys_StartFadeOut(0xa000, 2, 0);
            self->unk_64 = 2;
        }
        break;
    case 1:
        if (gPad->trig & 0xa) {
            Movie_RequestStop(gMovie);
        }
        if (gMovie->state == 0) {
            self->unk_64 = 0;
            self->unk_5c++;
        }
        break;
    case 2:
        if (func_ov002_isMode4()) {
            result = FALSE;
        }
        break;
    }
    return result;
}

BOOL func_ov002_021d178c(Task021ef71c *self) {
    BOOL result = TRUE;
    switch (self->unk_64) {
    case 0:
        if (self->unk_5c < 8 && ((s32 *)((u8 *)self + 0x3c))[self->unk_5c] >= 0) {
            func_ov002_021e8f04(((s32 *)((u8 *)self + 0x3c))[self->unk_5c]);
            self->unk_64 = 1;
        } else {
            self->unk_64 = 2;
            break;
        }
    case 1:
        if (gPad->trig & 2) {
            Ov002Vt_021f0694_New(gOv002Stage->unk_d0);
            self->unk_5c = 7;
        }
        if (!Ov002Stage_UpdateCur()) {
            Ov002Stage_Delete_021e916c();
            self->unk_64 = 0;
            self->unk_5c++;
        }
        break;
    case 2:
        result = FALSE;
        break;
    }
    return result;
}

Task021ef69c *Task021ef69c_New(void) {
    Task021ef69c *p = (Task021ef69c *)Heap_Alloc(0x68);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021ef69c_vtbl;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = NULL;
        p->unk_50 = 0;
        p->unk_54 = 0;
        p->unk_58 = 0;
        p->unk_5c = 0;
        p->unk_60 = 0;
        p->unk_64 = 0;
    }
    p->vfunc_08(0x17, 0x64);
    return p;
}

BOOL Task021ef69c_List3cOnCursor(TextList *self, ListRow021cca70 *row) {
    Obj021c64b4_SetText(self, row->unk_40);
    return TRUE;
}

BOOL Task021ef69c_List3cOnDecide(TextList *self, ListRow021cca70 *ev) {
    Task021ef69c *owner = (Task021ef69c *)self->owner;
    if (ev->item.unk_0a != 0) {
        if (ev->scale <= 0x99a) {
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            owner->unk_44 = ev;
            TextList_Raise(owner->unk_3c);
            ev->unk_6c = 1;
        }
    } else {
        SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
    }
    return TRUE;
}

}
