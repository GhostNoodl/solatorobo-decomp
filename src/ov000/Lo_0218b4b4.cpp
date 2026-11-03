#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Group.h"

extern "C" {

// The actor (an Actor; its unk_18 .. unk_1e are read as the array the spawn args were copied to).
typedef struct {
    u8 pad_00[0xc];
    u16 id;
    u16 kind;
    u8 pad_10[8];
    s16 unk_18[4];
    u8 pad_20[2];
    s16 unk_22;
    u8 pad_24[0x4c];
    VecFx32 pos;
    Rot16 rot;
} Src0218b4b4;

void GroupNode_UpdateEntry(GroupNode *self, s32 mode, Src0218b4b4 *src) {
    GroupEntry *slot = NULL;
    GroupEntry *e = self->entries;
    BOOL flag = self->flags.unk_5;
    s32 i;
    for (i = 0; i < self->count; i++, e++) {
        if (e->actor == src->id) {
            slot = e;
            break;
        }
    }
    if (slot == NULL) {
        return;
    }
    switch (mode) {
    case 0:
        slot->actor = 0xffff;
        slot->kind = 0xffff;
        return;
    case 2:
        if (!self->flags.unk_6) {
            flag = TRUE;
        }
    case 1:
        slot->actor &= 0xf000;
        slot->kind = src->kind;
        if (!flag) {
            slot->pos.x = src->pos.x;
            slot->pos.y = src->pos.y;
            slot->pos.z = src->pos.z;
            slot->rot.x = src->rot.x;
            slot->rot.y = src->rot.y;
            slot->rot.z = src->rot.z;
            if (mode == 2) {
                slot->fieldId = data_ov000_021ccd54->unk_d0;
            } else {
                slot->fieldId = data_ov000_021ccd54->unk_ca;
            }
        }
        for (i = 0; i < 4; i++) {
            slot->args[i] = src->unk_18[i];
        }
        slot->unk_0c = src->unk_22;
        break;
    }
}
}
