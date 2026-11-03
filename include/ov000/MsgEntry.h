#ifndef OV000_MSGENTRY_H
#define OV000_MSGENTRY_H

#include "types.h"

class VObj;

// A 0x30-byte record (ctor MsgEntry_Init, dtor MsgEntry_Release) about the message `id`
// (looked up with MsgRes_GetLines, func_02061e7c and func_ov000_0214bf2c). The prev / next words link
// it into the list of Lo021caac8_AddItem.
typedef struct MsgEntry {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u16 id;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ s32 unk_0c;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1c */ VObj *unk_1c; // freed by the dtor
    /* 0x20 */ VObj *unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ struct MsgEntry *prev;
    /* 0x2c */ struct MsgEntry *next;
} MsgEntry;

// The 0x38-byte form, with the four values that command 0x25 of the message's script sets
// (func_ov000_0214dc20, the Text_ScanTags callback).
struct MsgEntryEx : MsgEntry {
    /* 0x30 */ u16 vals[4];
};

#ifdef __cplusplus
extern "C" {
#endif

void MsgEntry_Init(MsgEntry *self);
void MsgEntry_Release(MsgEntry *self);
void func_ov000_0214dc20(MsgEntryEx *self, s32 *cmd);

#ifdef __cplusplus
}
#endif

#endif
