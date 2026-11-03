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

extern SysCard *gSysCard;

extern void *Heap_Alloc(u32 size);
extern void CARD_Init(void);
extern s32 OS_GetLockID(void);
extern void CARD_LockBackup(u16 lockId);
extern void CARD_UnlockBackup(u16 lockId);
extern BOOL CARD_IdentifyBackup(u32 type);
extern u32 CARD_GetBackupPageSize(void);
extern u32 CARD_GetBackupTotalSize(void);
extern u32 CARD_GetCurrentBackupType(void);
extern s32 CARD_GetResultCode(void);
extern BOOL CARD_TryWaitRomAsync(void);
extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void (*cb)(void *), void *arg, BOOL async, s32 type, s32 retry, s32 mode);
extern BOOL ResMgr_IsIdle(void);

void func_02046d1c(SysCard *card);
s32 SysCard_Read(SysCard *card, void *dst, u32 src, u32 len);
s32 SysCard_Write(SysCard *card, u32 dst, const void *src, u32 len);
void SysCard_OnReadDone(void *arg);
void SysCard_OnWriteDone(void *arg);
BOOL SysCard_CheckError(SysCard *card, s32 err);

static inline void SysCard_Lock(SysCard *card) {
    if (card->lockCount == 0) {
        CARD_LockBackup(card->lockId);
        card->lockCount++;
    }
}

static inline void SysCard_Unlock(SysCard *card) {
    if (card->state != 8 && card->lockCount != 0) {
        CARD_UnlockBackup(card->lockId);
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
    BOOL done = CARD_TryWaitRomAsync();
    if (done) {
        done = CARD_TryWaitBackupAsync();
    }
    SysCard_CheckError(gSysCard, 11);
    return done ? FALSE : TRUE;
}

static inline void SysCard_EndAccess(void) {
    SysCard *card = gSysCard;
    if (card->state == 8) {
        return;
    }
    SysCard_CheckError(card, 11);
    SysCard_Unlock(card);
    SysCard_SetState(card, 1);
}

#ifdef __cplusplus
}
#endif

#endif
