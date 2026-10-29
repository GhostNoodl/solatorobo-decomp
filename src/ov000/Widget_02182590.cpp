#include "ov000/VObj.h"
#include "ov000/CmdQueue.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 unk_00[0x4];
    CmdQueue *unk_04;
} Data021ccd50;

typedef struct {
    u8 unk_00;
    u8 pad_01[3];
    VObj *unk_04;
    u8 pad_08[4];
    VObj *unk_0c;
    VObj *unk_10;
    VObj *unk_14;
    u8 unk_18;
} Obj02182590;

static inline BOOL IsActive(VObj *p) {
    return LFLD(u8, p, 0x5a) != 0 ? TRUE : FALSE;
}

extern "C" {
extern void *data_02149efc;
extern Data021ccd50 data_ov000_021ccd50;
extern u8 data_02fe1534[];
BOOL func_0205b23c(s32 id);
void func_0206228c(void);

static inline BOOL CmdQueue_Has2(CmdQueue *q, s32 i, s32 end, s32 kind) {
    for (; i != end;) {
        if (q->kinds[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL IsBusy(void) {
    return data_02149efc != NULL ? TRUE : FALSE;
}

static inline CmdQueue *GetQueue02182590(void) {
    return data_ov000_021ccd50.unk_04;
}

void func_ov000_02182590(Obj02182590 *self) {
    VObj *w;
    CmdQueue *q;
    s32 rd;
    s32 wr;
    data_02149efc = NULL;
    if (self->unk_00 == 0) {
        return;
    }
    // The getter, the reused wr and the const-view reload below give the target's registers
    // and its second load of the queue pointer.
    q = GetQueue02182590();
    wr = q->unk_90;
    rd = wr;
    wr = q->index;
    if (CmdQueue_Has2(q, rd, wr, 6)) {
        return;
    }
    if (CmdQueue_Has2(*(CmdQueue *const *)&data_ov000_021ccd50.unk_04, rd, wr, 7)) {
        return;
    }
    self->unk_00 = 0;
    if (self->unk_14 != NULL) {
        return;
    }
    if (func_0205b23c(0x21b)) {
        return;
    }
    w = self->unk_10;
    if (LFLD(u16, data_02fe1534, 0x44) == 1) {
        if (self->unk_04 != NULL) {
            self->unk_04->vfunc_38(1);
            data_02149efc = NULL;
        }
        if (self->unk_0c != NULL) {
            self->unk_0c->vfunc_38(1);
            data_02149efc = NULL;
            if (IsActive(self->unk_0c)) {
                self->unk_14 = self->unk_0c;
                self->unk_18 = 1;
            }
        }
        for (; w != NULL; w = LFLD(VObj *, w, 0xd4)) {
            w->vfunc_38(1);
            if (IsActive(w)) {
                self->unk_18 = 1;
                self->unk_14 = w;
            }
        }
    } else {
        for (; w != NULL; w = LFLD(VObj *, w, 0xd4)) {
            w->vfunc_38(1);
            if (IsActive(w)) {
                self->unk_14 = w;
                self->unk_18 = 1;
            }
            if (IsBusy()) {
                break;
            }
        }
        if (self->unk_0c != NULL && w == NULL) {
            self->unk_0c->vfunc_38(1);
            if (IsActive(self->unk_0c)) {
                self->unk_14 = self->unk_0c;
                self->unk_18 = 1;
            }
        }
        if (self->unk_04 != NULL && !IsBusy()) {
            self->unk_04->vfunc_38(1);
            if (IsActive(self->unk_04)) {
                self->unk_14 = self->unk_04;
            }
        }
    }
    if (self->unk_14 == NULL) {
        func_0206228c();
    }
}
}
