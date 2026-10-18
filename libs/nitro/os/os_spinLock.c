#include "nitro/os.h"

#define HW_LOCK_ID_FLAG_MAIN 0x02ffffb0
#define HW_SHARED_LOCK_BUF   0x02ffffc0
#define HW_CARD_LOCK_BUF     0x02ffffe0
#define HW_CTRDG_LOCK_BUF    0x02ffffe8
#define HW_INIT_LOCK_BUF     0x02fffff0

#define REG_EXMEMCNT (*(vu16 *)0x04000204)
#define REG_MCCNT1   (*(vu32 *)0x040001a4)
#define REG_SCFG_MC  (*(vu16 *)0x04004010)

#define EXMEMCNT_CARTRIDGE_ARM7 0x0080
#define EXMEMCNT_CARD_ARM7      0x0800

#define OSi_SYNCTYPE_SENDER 0
#define OSi_SYNCTYPE_RECVER 1

void MIi_CpuClear32(u32 data, void *dest, u32 size);
u32 MI_SwapWord(u32 data, volatile u32 *destp);
void WaitByLoop(s32 count);

static inline void OSi_WaitByLoop(void) {
    WaitByLoop(0x400);
}

static void OSi_SyncWithOtherProc(int type, void *syncBuf) {
    vu8 *buf = (vu8 *)syncBuf;

    if (type == OSi_SYNCTYPE_SENDER) {
        int i = 0;
        buf[2] = 0;
        do {
            buf[0] = (u8)(0x80 | (i & 0xf));
            while (buf[0] != buf[1] && buf[2] == 0) {
                OSi_WaitByLoop();
            }
            i++;
        } while (buf[2] == 0);
        buf[3] = 1;
    } else {
        int sum = 0;
        buf[1] = 0;
        while (sum < 0x300) {
            if (buf[1] != buf[0]) {
                buf[1] = buf[0];
                sum += buf[1];
            } else {
                OSi_WaitByLoop();
            }
        }
        buf[3] = 0;
        buf[2] = 1;
        while (buf[3] == 0) {
            OSi_WaitByLoop();
        }
    }
}

void OS_InitLock(void) {
    static BOOL isInitialized = FALSE;
    OSLockWord *lockp = (OSLockWord *)HW_INIT_LOCK_BUF;

    if (isInitialized) {
        return;
    }
    isInitialized = TRUE;

    ((u32 *)HW_LOCK_ID_FLAG_MAIN)[0] = 0xffffffff;
    ((u32 *)HW_LOCK_ID_FLAG_MAIN)[1] = 0xffff0000;

    MIi_CpuClear32(0, (void *)HW_SHARED_LOCK_BUF, 0x28);

    REG_EXMEMCNT |= EXMEMCNT_CARD_ARM7;
    REG_EXMEMCNT |= EXMEMCNT_CARTRIDGE_ARM7;

    OSi_SyncWithOtherProc(OSi_SYNCTYPE_SENDER, lockp);
    OSi_SyncWithOtherProc(OSi_SYNCTYPE_RECVER, lockp);
}

s32 OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq) {
    s32 lastLockFlag;

    while ((lastLockFlag = OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFiq)) > 0) {
        OSi_WaitByLoop();
    }
    return lastLockFlag;
}

#pragma force_active on
s32 OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoLockByWord(lockID, lockp, ctrlFuncp, FALSE);
}
#pragma force_active reset

s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq) {
    OSIntrMode lastIntrMode;

    if (lockID != lockp->ownerID) {
        return -2;
    }

    lastIntrMode = disableFiq ? OS_DisableInterrupts_IrqAndFiq() : OS_DisableInterrupts();

    lockp->ownerID = 0;
    if (ctrlFuncp != NULL) {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;

    if (disableFiq) {
        (void)OS_RestoreInterrupts_IrqAndFiq(lastIntrMode);
    } else {
        (void)OS_RestoreInterrupts(lastIntrMode);
    }
    return 0;
}

s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq) {
    OSIntrMode lastIntrMode = disableFiq ? OS_DisableInterrupts_IrqAndFiq() : OS_DisableInterrupts();
    s32 lastLockFlag = (s32)MI_SwapWord(lockID, &lockp->lockFlag);

    if (lastLockFlag == 0) {
        if (ctrlFuncp != NULL) {
            ctrlFuncp();
        }
        lockp->ownerID = lockID;
    }

    if (disableFiq) {
        (void)OS_RestoreInterrupts_IrqAndFiq(lastIntrMode);
    } else {
        (void)OS_RestoreInterrupts(lastIntrMode);
    }
    return lastLockFlag;
}

s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OS_UnlockCartridge(u16 lockID) {
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_FreeCartridgeBus, TRUE);
}

// Old misspelled alias kept by the SDK
asm s32 OS_UnLockCartridge(u16 lockID) {
    ldr r1, =OS_UnlockCartridge
    bx r1
}

s32 OS_TryLockCartridge(u16 lockID) {
    return OSi_DoTryLockByWord(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_AllocateCartridgeBus, TRUE);
}

void OSi_AllocateCartridgeBus(void) {
    REG_EXMEMCNT = (u16)(REG_EXMEMCNT & ~EXMEMCNT_CARTRIDGE_ARM7);
}

void OSi_FreeCartridgeBus(void) {
    REG_EXMEMCNT |= EXMEMCNT_CARTRIDGE_ARM7;
}

s32 OS_UnlockCard(u16 lockID) {
    return OS_UnlockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_FreeCardBus);
}

s32 OS_TryLockCard(u16 lockID) {
    return OS_TryLockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_AllocateCardBus);
}

void OSi_AllocateCardBus(void) {
    if (((REG_SCFG_MC & 0xc) >> 2) == 2) {
        REG_MCCNT1 |= 0x20000000;
    }
    REG_EXMEMCNT = (u16)(REG_EXMEMCNT & ~EXMEMCNT_CARD_ARM7);
}

void OSi_FreeCardBus(void) {
    REG_EXMEMCNT |= EXMEMCNT_CARD_ARM7;
}

u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp) {
    return lockp->ownerID;
}
