#include "ov002/ov002.h"

extern "C" {

void Task021efa1c_PostUpdate(void) {
}

void Task021efa1c_Draw(Task021efa1c *self) {
    if (self->unk_3c != NULL) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
}

Task021ef89c *Task021ef89c_New(void) {
    Task021ef89c *p = (Task021ef89c *)Heap_Alloc(0x44);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021ef89c_vtbl;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
    }
    p->vfunc_08(0x15, 0x64);
    return p;
}

// The onDecide callback of Task021ef89c's row list (func_ov002_021d0b98); arg is the chosen row.
BOOL func_ov002_021d0a80(Ov002RowList *self, Hud021cca10 *arg) {
    u8 *obj;
    s16 *info;
    int i;
    s16 v;
    int j;
    if (arg != NULL) {
        data_ov002_021f0f84[1] = self->unk_a8;
        obj = (u8 *)TaskHost_RequestSwitch(gTaskHost, 0x16, 0);
        info = func_0206ee90((u16)arg->unk_08);
        if (!((Info0206ee90 *)info)->flag) {
            obj[0x68] = 0;
        } else {
            obj[0x68] = 1;
        }
        for (i = 0; i < 8; i++) {
            v = info[i + 1];
            if (v < 0) {
                break;
            }
            for (j = 0; j < 8; j++) {
                if (((s32 *)(obj + 0x3c))[j] < 0) {
                    ((s32 *)(obj + 0x3c))[j] = v;
                    break;
                }
            }
        }
        FIELD(obj, 0x60, s32) = info[9];
        GfxSys_SetFadePlanes(0x3f, -1);
        GfxSys_StartFadeOut(0xa000, 2, -1);
    }
    return TRUE;
}

void Task021ef89c_Start(Task021ef89c *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28() != 0) {
        return;
    }
    func_ov002_021d0b98(self);
    TaskList_Insert(self);
}

}
