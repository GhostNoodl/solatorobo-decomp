#ifndef MAIN_RES_STAGECMD_H
#define MAIN_RES_STAGECMD_H

#include "Main/Res/StageRes.h"
#include "Main/Sys/Field.h"

// Stage script commands: each takes the queued slot and returns 1 when done,
// or -0x63 while the field event queue is busy.

extern "C" {

typedef struct StageFlags {
    /* 0x000 */ u8 unk_000[0xc];
    /* 0x00c */ u32 unk_00c;
    /* 0x010 */ u8 unk_010[0x10];
    /* 0x020 */ u32 unk_020;
    /* 0x024 */ u16 unk_024;
    /* 0x026 */ u8 unk_026[0x4f2];
    /* 0x518 */ u32 unk_518_0 : 8;
    /* 0x518 */ u32 unk_518_8 : 8;
    /* 0x518 */ u32 unk_518_16 : 16;
} StageFlags;

extern StageFlags *data_0214a424;
extern void *data_02149ef8;
extern int (*const data_0208bf9c[])(StageResSlot *slot);
extern const u32 data_02082a28[];
extern BOOL func_0206f21c(u16 id, int a);
extern void func_0206f5e4(u16 id, int a);
extern void func_ov000_02184ea4(FieldState *state, u16 id);
extern void func_ov000_02184bb0(FieldState *state, u16 a);
extern void func_ov000_02184d90(FieldState *state, u16 a);
extern void func_ov000_021762e4(u16 a, u16 b);
extern void func_ov000_0214e7ac(u16 a);
extern void func_ov000_02188d28(u8 *buf);
extern void func_ov000_02188ca0(u8 *buf, int a);
extern void func_ov000_021865f8(FieldState *state);
extern void func_ov000_02186bb0(FieldState *state);
extern void func_ov000_0218547c(FieldState *state, u16 a, void *res, u16 id);
extern void func_ov000_021854d4(FieldState *state, void *res, u16 id);
extern void func_ov000_02172264(FieldPlayer *player, u32 v, u16 id, void *res);

static inline BOOL Field_IsEventPending(FieldState *state) {
    return state->head != state->tail;
}

static inline void Field_PushEvent(FieldState *state, s32 ev, s32 arg) {
    state->queue[state->tail] = ev;
    state->queueArg[state->tail] = arg;
    state->tail++;
    if (state->tail >= 0x10) {
        state->tail = 0;
    }
}

static inline BOOL Field_HasEvent(s32 ev) {
    FieldState *state = data_ov000_021ccd54;
    s32 i;
    for (i = state->head; i != state->tail;) {
        if (state->queue[i] == ev) {
            return TRUE;
        }
        i++;
        if (i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL Field_IsBusy(void) {
    FieldState *state = data_ov000_021ccd54;
    return state->head != state->tail;
}

static inline BOOL Field_HasEventIn(FieldState *state, s32 ev) {
    s32 tail = state->tail;
    s32 i = state->head;
    while (i != tail) {
        if (state->queue[i] == ev) {
            return TRUE;
        }
        i++;
        if (i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

}

#endif
