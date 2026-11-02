#ifndef MAIN_SYS_FIELD_H
#define MAIN_SYS_FIELD_H

#include "types.h"
#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"

#ifdef __cplusplus
extern "C" {
#endif

// Field (overlay 0) globals that main code reaches into.

typedef struct FieldActorState {
    /* 0x00 */ union {
        u32 flags;
        struct {
            u32 unk_0 : 9;
            u32 flag9 : 1;
            u32 unk_10 : 22;
        } bits;
    };
    /* 0x04 */ u8 unk_04[0x18];
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 unk_20;
} FieldActorState;

typedef struct FieldActor {
    /* 0x00 */ u8 unk_00[0x54];
    /* 0x54 */ FieldActorState *state;
    /* 0x58 */ u8 unk_58[0x8];
    /* 0x60 */ void *unk_60; // passed to func_ov000_0216912c by the ov009 actors
} FieldActor;

struct TimedBuffer021cb920;

// The field's message queue (ov000/MessageQueue.h MessageQueue021cb980) as main code sees it.
typedef struct FieldPlayer {
    /* 0x000 */ u8 unk_000[0x114];
    /* 0x114 */ u32 unk_114_0 : 1;
    /* 0x114 */ u32 flag1 : 1;
    /* 0x114 */ u32 unk_114_2 : 30;
    /* 0x118 */ struct TimedBuffer021cb920 *unk_118;
    /* 0x11c */ FieldActor *unk_11c;
} FieldPlayer;

extern FieldPlayer *data_ov000_021ccd30;
extern BOOL MessageQueue_GetById(FieldPlayer *player, int id);
extern BOOL func_ov000_02170568(void *p);
extern void func_ov000_021bc458(FieldFade *fade);


static inline BOOL Field_IsPlayerBusy(void) {
    FieldPlayer *player = data_ov000_021ccd30;
    if (player == NULL) {
        return FALSE;
    }
    if (MessageQueue_GetById(player, 0x10)) {
        return TRUE;
    }
    if (MessageQueue_GetById(player, 0x11)) {
        return TRUE;
    }
    if (MessageQueue_GetById(player, 0x12)) {
        return TRUE;
    }
    if (MessageQueue_GetById(player, 0x13)) {
        return TRUE;
    }
    if (player->unk_11c == NULL) {
        return FALSE;
    }
    return func_ov000_02170568(player->unk_11c);
}

#ifdef __cplusplus
}
#endif

#endif
