#include "Main/Save/SysCard.h"

extern "C" {

SysCard *gSysCard;

static inline BOOL SysCard_Begin(SysCard *card) {
    if (card->state == 8) {
        return FALSE;
    }
    if (!ResMgr_IsIdle()) {
        return FALSE;
    }
    SysCard_Lock(card);
    return TRUE;
}

static inline void SysCard_End(SysCard *card) {
    if (card->state == 8) {
        return;
    }
    SysCard_CheckError(gSysCard, 11);
    SysCard_Unlock(card);
    SysCard_SetState(card, 1);
}

static inline BOOL SysCard_IsReady(void) {
    return (u8)CARD_GetCurrentBackupType() == 1 ? TRUE : FALSE;
}

void SysCard_Create(void) {
    SysCard *card;
    if (gSysCard != NULL) {
        return;
    }
    card = (SysCard *)Heap_Alloc(sizeof(SysCard));
    if (card != NULL) {
        card->lockId = 0;
        card->totalSize = 0;
        card->sectorSize = 0;
        card->state = 0;
        card->callback = NULL;
        card->callbackArg = NULL;
        card->prevState = 1;
        card->error = 0;
        card->lockCount = 0;
    }
    gSysCard = card;
    func_02046d1c(card);
}

void SysCard_Reset_02046cd0(SysCard *card) {
    SysCard_Reset(card);
}

void func_02046d1c(SysCard *card) {
    s32 id;
    CARD_Init();
    id = OS_GetLockID();
    if (id == -3) {
        return;
    }
    card->lockId = id;
    if (card->state != 8) {
        SysCard_Lock(card);
    }
    if (!CARD_IdentifyBackup(0xd01)) {
        SysCard_CheckError(gSysCard, 11);
    }
    SysCard_Unlock(card);
    card->totalSize = CARD_GetBackupPageSize();
    card->sectorSize = CARD_GetBackupTotalSize();
    if (card->state != 7) {
        SysCard_SetState(card, 1);
    } else {
        card->state = 8;
    }
    SysCard_Reset(card);
}

static inline BOOL SysCard_IsLocked(SysCard *card) {
    return card->lockCount != 0 ? TRUE : FALSE;
}

BOOL func_02046e28(SysCard *card) {
    return SysCard_IsLocked(card) ? TRUE : FALSE;
}

s32 SysCard_Read(SysCard *card, void *dst, u32 src, u32 len) {
    if (card->state == 8) {
        return 2;
    }
    if (!SysCard_Begin(card)) {
        return 1;
    }
    SysCard_SetState(card, 3);
    if (!SysCard_IsReady()) {
        SysCard_CheckError(gSysCard, 8);
        SysCard_End(card);
        return 2;
    }
    CARDi_RequestStreamCommand(src, (u32)dst, len, SysCard_OnReadDone, card, TRUE, 6, 1, 0);
    SysCard_CheckError(gSysCard, 11);
    return 0;
}

void SysCard_OnReadDone(void *arg) {
    SysCard_SetState(gSysCard, 4);
    if (gSysCard->callback != NULL) {
        gSysCard->callback(gSysCard->callbackArg);
    }
    SysCard_SetState(gSysCard, 2);
}

s32 SysCard_Write(SysCard *card, u32 dst, const void *src, u32 len) {
    if (card->state == 8) {
        return 2;
    }
    if (!SysCard_Begin(card)) {
        return 1;
    }
    SysCard_SetState(card, 5);
    if (dst + len > card->sectorSize) {
        SysCard_CheckError(gSysCard, 9);
        return 2;
    }
    if (!SysCard_IsReady()) {
        SysCard_CheckError(gSysCard, 8);
        SysCard_End(card);
        return 2;
    }
    CARDi_RequestStreamCommand((u32)src, dst, len, SysCard_OnWriteDone, card, TRUE, 8, 10, 2);
    SysCard_CheckError(gSysCard, 11);
    return 0;
}

void SysCard_OnWriteDone(void *arg) {
    SysCard_SetState(gSysCard, 6);
    if (gSysCard->callback != NULL) {
        gSysCard->callback(gSysCard->callbackArg);
    }
    SysCard_SetState(gSysCard, 2);
}

BOOL SysCard_CheckError(SysCard *card, s32 err) {
    if (card->state == 7) {
        return FALSE;
    }
    if (err == 11) {
        switch (CARD_GetResultCode()) {
            case 0: card->error = 0; break;
            case 1: card->error = 1; break;
            case 2: card->error = 2; break;
            case 3: card->error = 3; break;
            case 4: card->error = 4; break;
            case 5: card->error = 7; break;
            case 6: card->error = 5; break;
            case 7: card->error = 6; break;
            default: card->error = 10; break;
        }
    } else {
        card->error = err;
    }
    if (card->error != 0 && card->error != 1) {
        card->prevState = card->state;
        SysCard_SetState(card, 7);
        return TRUE;
    }
    return FALSE;
}

BOOL func_020472c4(SysCard *card) {
    return SysCard_IsBusy() ? TRUE : FALSE;
}

}
