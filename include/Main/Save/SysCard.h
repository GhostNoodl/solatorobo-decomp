#ifndef MAIN_SAVE_SYSCARD_H
#define MAIN_SAVE_SYSCARD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Card backup (save memory) access manager.

typedef void (*SysCardCallback)(void *arg);

typedef struct SysCard {
    /* 0x00 */ u16 lockId;
    /* 0x04 */ u32 totalSize;
    /* 0x08 */ u32 sectorSize;
    /* 0x0c */ s32 state;
    /* 0x10 */ SysCardCallback callback;
    /* 0x14 */ void *callbackArg;
    /* 0x18 */ s32 prevState;
    /* 0x1c */ s32 error;
    /* 0x20 */ s32 lockCount;
} SysCard; // size 0x24

extern SysCard *data_02097e44;

extern void *func_0203dd9c(u32 size);
extern u16 func_0200c1b4(void);
extern s32 OS_GetLockID(void);
extern void func_0200c3a4(u16 lockId);
extern void func_0200c3b4(u16 lockId);
extern BOOL func_0200d034(u32 type);
extern u32 func_0200d0b0(void);
extern u32 func_0200d088(void);
extern u32 func_0200d074(void);
extern s32 func_0200c2e0(void);
extern BOOL func_0200d8f0(void);
extern BOOL func_0200d0d0(void);
extern void func_0200cfc8(u32 src, u32 dst, u32 len, void (*cb)(void *), void *arg, BOOL async, s32 type, s32 retry, s32 mode);
extern BOOL func_02036328(void);

void func_02046d1c(SysCard *card);
s32 func_02046e48(SysCard *card, void *dst, u32 src, u32 len);
s32 func_02047004(SysCard *card, u32 dst, const void *src, u32 len);
void func_02046fac(void *arg);
void func_02047198(void *arg);
BOOL func_020471f0(SysCard *card, s32 err);

static inline void SysCard_Lock(SysCard *card) {
    if (card->lockCount == 0) {
        func_0200c3a4(card->lockId);
        card->lockCount++;
    }
}

static inline void SysCard_Unlock(SysCard *card) {
    if (card->state != 8 && card->lockCount != 0) {
        func_0200c3b4(card->lockId);
        card->lockCount--;
    }
}

static inline void SysCard_SetState(SysCard *card, s32 state) {
    if (card->state != 7) {
        card->state = state;
    }
}

static inline void SysCard_Reset(SysCard *card) {
    if (card->state == 8) {
        return;
    }
    SysCard_Unlock(card);
    card->state = 1;
    card->prevState = 1;
    card->error = 0;
}

// Returns TRUE while the last backup access has not finished successfully.
static inline BOOL SysCard_IsBusy(void) {
    BOOL done = func_0200d8f0();
    if (done) {
        done = func_0200d0d0();
    }
    func_020471f0(data_02097e44, 11);
    return done ? FALSE : TRUE;
}

static inline void SysCard_EndAccess(void) {
    SysCard *card = data_02097e44;
    if (card->state == 8) {
        return;
    }
    func_020471f0(card, 11);
    SysCard_Unlock(card);
    SysCard_SetState(card, 1);
}

#ifdef __cplusplus
}
#endif

#endif
