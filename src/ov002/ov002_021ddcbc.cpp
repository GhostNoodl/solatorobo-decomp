#include "ov002/ov002.h"

extern "C" {

// List callbacks of Obj021efef0's lists: owner points at its unk_20/unk_21 (or unk_22/unk_23) pair,
// [0] set on cancel, [1] set when a usable row is decided.
BOOL func_ov002_021ddcbc(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev) {
    u8 *t;
    if (ev == NULL) {
        return FALSE;
    }
    t = (u8 *)self->owner;
    if (ev->unk_44 != 0) {
        t[1] = 1;
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    } else {
        t[1] = 0;
        SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov002_021ddd30(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev) {
    if (ev == NULL) {
        return FALSE;
    }
    ((u8 *)self->owner)[0] = 1;
    SndMgr_PlayVolume(gSndMgr, 0x1d, -1, -1, -1);
    return TRUE;
}

void Obj021efef0_Init(Obj021efef0 *self) {
    self->owner = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0xffff;
    self->unk_20 = 0;
    self->unk_21 = 0;
    self->unk_22 = 0;
    self->unk_23 = 0;
    self->unk_30 = 0;
    self->unk_2c = 0;
    self->unk_24 = NULL;
    self->unk_28 = 0;
    self->unk_34 = 0;
    self->unk_38[0] = 0;
}

}
