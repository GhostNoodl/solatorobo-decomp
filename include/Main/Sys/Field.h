#ifndef MAIN_SYS_FIELD_H
#define MAIN_SYS_FIELD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Field (overlay 0) globals that main code reaches into.
typedef struct FieldState {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ void *unk_04;
    /* 0x08 */ u8 unk_08[8];
    /* 0x10 */ s32 queue[0x10];
    /* 0x50 */ s32 queueArg[0x10];
    /* 0x90 */ s32 head;
    /* 0x94 */ s32 tail;
    /* 0x098 */ u8 unk_098[0x14];
    /* 0x0ac */ u8 unk_0ac;
    /* 0x0ad */ u8 unk_0ad[0x1b];
    /* 0x0c8 */ u8 unk_0c8;
    /* 0x0c9 */ u8 unk_0c9[0xa];
    /* 0x0d3 */ u8 unk_0d3;
    /* 0x0d4 */ u32 unk_d4;
    /* 0x0d8 */ u8 unk_0d8[0xb4];
    /* 0x18c */ u8 unk_18c;
    /* 0x18d */ u8 unk_18d;
    /* 0x18e */ u8 unk_18e;
    /* 0x18f */ u8 unk_18f;
    /* 0x190 */ union {
        u8 unk_190;
        struct {
            u8 flag0 : 1;
            u8 unk_190_1 : 7;
        } bits190;
    };
} FieldState;

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
} FieldActor;

typedef struct FieldPlayer {
    /* 0x000 */ u8 unk_000[0x114];
    /* 0x114 */ u32 unk_114_0 : 1;
    /* 0x114 */ u32 flag1 : 1;
    /* 0x114 */ u32 unk_114_2 : 30;
    /* 0x118 */ u8 unk_118[4];
    /* 0x11c */ FieldActor *unk_11c;
} FieldPlayer;

extern FieldState *data_ov000_021ccd54;
extern FieldPlayer *data_ov000_021ccd30;
extern FieldState *data_ov000_021ccd70;
extern BOOL func_ov000_0216f674(FieldPlayer *player, int id);
extern BOOL func_ov000_02170568(void *p);
extern void func_ov000_021bc458(FieldState *state);


static inline BOOL Field_IsPlayerBusy(void) {
    FieldPlayer *player = data_ov000_021ccd30;
    if (player == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(player, 0x10)) {
        return TRUE;
    }
    if (func_ov000_0216f674(player, 0x11)) {
        return TRUE;
    }
    if (func_ov000_0216f674(player, 0x12)) {
        return TRUE;
    }
    if (func_ov000_0216f674(player, 0x13)) {
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
