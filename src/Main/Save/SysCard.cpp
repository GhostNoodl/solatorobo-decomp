#include "Main/Save/SysCard.h"

extern "C" {

SysCard *data_02097e44;

static inline BOOL SysCard_Begin(SysCard *card) {
    if (card->state == 8) {
        return FALSE;
    }
    if (!func_02036328()) {
        return FALSE;
    }
    SysCard_Lock(card);
    return TRUE;
}

static inline void SysCard_End(SysCard *card) {
    if (card->state == 8) {
        return;
    }
    func_020471f0(data_02097e44, 11);
    SysCard_Unlock(card);
    SysCard_SetState(card, 1);
}

static inline BOOL SysCard_IsReady(void) {
    return (u8)CARD_GetCurrentBackupType() == 1 ? TRUE : FALSE;
}

void func_02046c6c(void) {
    SysCard *card;
    if (data_02097e44 != NULL) {
        return;
    }
    card = (SysCard *)func_0203dd9c(sizeof(SysCard));
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
    data_02097e44 = card;
    func_02046d1c(card);
}

void func_02046cd0(SysCard *card) {
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
        func_020471f0(data_02097e44, 11);
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

s32 func_02046e48(SysCard *card, void *dst, u32 src, u32 len) {
    if (card->state == 8) {
        return 2;
    }
    if (!SysCard_Begin(card)) {
        return 1;
    }
    SysCard_SetState(card, 3);
    if (!SysCard_IsReady()) {
        func_020471f0(data_02097e44, 8);
        SysCard_End(card);
        return 2;
    }
    CARDi_RequestStreamCommand(src, (u32)dst, len, func_02046fac, card, TRUE, 6, 1, 0);
    func_020471f0(data_02097e44, 11);
    return 0;
}

void func_02046fac(void *arg) {
    SysCard_SetState(data_02097e44, 4);
    if (data_02097e44->callback != NULL) {
        data_02097e44->callback(data_02097e44->callbackArg);
    }
    SysCard_SetState(data_02097e44, 2);
}

s32 func_02047004(SysCard *card, u32 dst, const void *src, u32 len) {
    if (card->state == 8) {
        return 2;
    }
    if (!SysCard_Begin(card)) {
        return 1;
    }
    SysCard_SetState(card, 5);
    if (dst + len > card->sectorSize) {
        func_020471f0(data_02097e44, 9);
        return 2;
    }
    if (!SysCard_IsReady()) {
        func_020471f0(data_02097e44, 8);
        SysCard_End(card);
        return 2;
    }
    CARDi_RequestStreamCommand((u32)src, dst, len, func_02047198, card, TRUE, 8, 10, 2);
    func_020471f0(data_02097e44, 11);
    return 0;
}

void func_02047198(void *arg) {
    SysCard_SetState(data_02097e44, 6);
    if (data_02097e44->callback != NULL) {
        data_02097e44->callback(data_02097e44->callbackArg);
    }
    SysCard_SetState(data_02097e44, 2);
}

BOOL func_020471f0(SysCard *card, s32 err) {
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

BOOL func_020472c4(void) {
    return SysCard_IsBusy() ? TRUE : FALSE;
}

}
