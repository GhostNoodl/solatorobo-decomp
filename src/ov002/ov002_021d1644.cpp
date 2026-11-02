#include "ov002/ov002.h"

extern "C" {

void Task021ef71c_Draw(Task021ef71c *self) {
    if (self->unk_68 == 0 && self->state == 0xd && self->unk_64 == 1) {
        func_ov002_021e90dc();
    }
}

BOOL func_ov002_021d166c(Task021ef71c *self) {
    BOOL result = TRUE;
    switch (self->unk_64) {
    case 0:
        if (self->unk_5c < 8 && ((s32 *)((u8 *)self + 0x3c))[self->unk_5c] >= 0) {
            func_0203caf8(-1);
            Movie_Load(data_02097e3c, ((s32 *)((u8 *)self + 0x3c))[self->unk_5c], -1, 0);
            self->unk_64 = 1;
        } else {
            func_0203cc58(0xa000, 2, 0);
            self->unk_64 = 2;
        }
        break;
    case 1:
        if (data_02097dc8->trig & 0xa) {
            Movie_RequestStop(data_02097e3c);
        }
        if (data_02097e3c->state == 0) {
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
        if (data_02097dc8->trig & 2) {
            func_ov002_021e9b28(data_ov002_021f0f9c->unk_d0);
            self->unk_5c = 7;
        }
        if (!func_ov002_021e90ac()) {
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

Task021ef69c *func_ov002_021d184c(void) {
    Task021ef69c *p = (Task021ef69c *)Heap_Alloc(0x68);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef69c;
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

BOOL func_ov002_021d18d4(void *self, void *arg) {
    Obj021c64b4_SetText(self, FIELD(arg, 0x40, void *));
    return TRUE;
}

BOOL func_ov002_021d18e8(void *self, void *ev) {
    void *owner = FIELD(self, 0x8, void *);
    if (FIELD(ev, 0x52, u8) != 0) {
        if (FIELD(ev, 0x58, s32) <= 0x99a) {
            SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
            FIELD(owner, 0x44, void *) = ev;
            func_ov000_021c7000(FIELD(owner, 0x3c, void *));
            FIELD(ev, 0x6c, u8) = 1;
        }
    } else {
        SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
    }
    return TRUE;
}

}
