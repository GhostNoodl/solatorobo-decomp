#include "nitro/os.h"
#include "nitro/pxi.h"

typedef struct {
    u32 startAddress;
    u8 nintendoLogo[0x9c];
    char titleName[12];
    u32 gameCode;
    u16 makerCode;
    u8 isRomCode;
    u8 machineCode;
    u8 deviceType;
    u8 exLsiID[3];
    u8 reserved_A[4];
    u8 softVersion;
    u8 complement;
    u16 moduleID;
} CTRDGHeader;

typedef struct {
    union {
        struct {
            u8 bitID;
            u8 numberID : 5;
            u8 : 2;
            u8 disableExLsiID : 1;
        };
        u16 raw;
    };
} CTRDGModuleID;

typedef struct {
    CTRDGModuleID moduleID;
    u8 exLsiID[3];
    u8 isAgbCartridge : 1;
    u8 detectPullOut : 1;
    u8 : 0;
    u16 makerCode;
    u32 gameCode;
} CTRDGModuleInfo;

typedef enum {
    MI_CTRDG_ROMCYCLE1_10 = 0,
    MI_CTRDG_ROMCYCLE1_8 = 1,
    MI_CTRDG_ROMCYCLE1_6 = 2,
    MI_CTRDG_ROMCYCLE1_18 = 3
} MICartridgeRomCycle1st;

typedef enum {
    MI_CTRDG_ROMCYCLE2_6 = 0,
    MI_CTRDG_ROMCYCLE2_4 = 1
} MICartridgeRomCycle2nd;

typedef struct CTRDGRomCycle {
    MICartridgeRomCycle1st c1;
    MICartridgeRomCycle2nd c2;
} CTRDGRomCycle;

typedef struct CTRDGLockByProc {
    BOOL locked;
    OSIntrMode irq;
} CTRDGLockByProc;

typedef struct CTRDGWork {
    vu16 subpInitialized;
    u16 lockID;
} CTRDGWork;

#define CTRDG_IS_ROM_CODE 0x96
#define CTRDG_LOCKED_BY_MYPROC_FLAG 0x40
#define PXI_FIFO_TAG_CTRDG 13

#define REG_EXMEMCNT (*(vu16 *)0x04000204)

static inline MICartridgeRomCycle1st MI_GetCartridgeRomCycle1st(void) {
    return (MICartridgeRomCycle1st)((REG_EXMEMCNT & 0xc) >> 2);
}

static inline MICartridgeRomCycle2nd MI_GetCartridgeRomCycle2nd(void) {
    return (MICartridgeRomCycle2nd)((REG_EXMEMCNT & 0x10) >> 4);
}

static inline void MI_SetCartridgeRomCycle1st(MICartridgeRomCycle1st c1) {
    REG_EXMEMCNT = (u16)((REG_EXMEMCNT & ~0xc) | (c1 << 2));
}

static inline void MI_SetCartridgeRomCycle2nd(MICartridgeRomCycle2nd c2) {
    REG_EXMEMCNT = (u16)((REG_EXMEMCNT & ~0x10) | (c2 << 4));
}

void CpuSet(const void *src, void *dest, u32 dmaCntData);
void WaitByLoop(s32 count);
s32 OS_GetLockID(void);
s32 OS_UnLockCartridge(u16 lockID);

static inline CTRDGHeader *CTRDGi_GetHeaderAddr(void) {
    return (CTRDGHeader *)0x08000000;
}

static inline CTRDGModuleInfo *CTRDGi_GetModuleInfoAddr(void) {
    return (CTRDGModuleInfo *)0x02fffc30;
}

static inline u16 *CTRDGi_GetModuleIDImageAddr(void) {
    return (u16 *)0x0801fffe;
}

static inline u16 OS_ReadOwnerOfLockCartridge(void) {
    return OS_ReadOwnerOfLockWord((OSLockWord *)0x02ffffe8);
}

static inline void SVC_CpuClear(u32 data, void *destp, u32 size, u32 bit) {
    CpuSet(&data, destp, (1 << 24) | ((bit == 32) << 26) | (size / (bit / 8)));
}

void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
void CTRDGi_LockByProcessor(u16 lockID, CTRDGLockByProc *info);
void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);

static BOOL CTRDGi_EnableFlag = FALSE;

CTRDGWork CTRDGi_Work = {0};

BOOL func_020218f0(void) {
    return CTRDGi_GetModuleInfoAddr()->moduleID.raw != 0xffff ? TRUE : FALSE;
}

void CTRDGi_InitCommon(void) {
    SVC_CpuClear(0, &CTRDGi_Work, sizeof(CTRDGi_Work), 32);
    CTRDGi_Work.lockID = (u16)OS_GetLockID();
}

BOOL CTRDG_IsExisting(void) {
    BOOL retval = TRUE;
    CTRDGLockByProc lockInfo;

    CTRDGHeader *chp = CTRDGi_GetHeaderAddr();
    CTRDGModuleInfo *cip = CTRDGi_GetModuleInfoAddr();

    if (!func_020218f0()) {
        return FALSE;
    }

    if (cip->detectPullOut == TRUE) {
        return FALSE;
    }

    CTRDGi_LockByProcessor(CTRDGi_Work.lockID, &lockInfo);

    {
        CTRDGRomCycle rc;
        u8 isRomCode;

        CTRDGi_ChangeLatestAccessCycle(&rc);
        isRomCode = chp->isRomCode;

        if ((isRomCode == CTRDG_IS_ROM_CODE && cip->moduleID.raw != chp->moduleID)
            || (isRomCode != CTRDG_IS_ROM_CODE && cip->moduleID.raw != *CTRDGi_GetModuleIDImageAddr())
            || ((cip->gameCode != chp->gameCode) && cip->isAgbCartridge)) {
            cip->detectPullOut = TRUE;
            retval = FALSE;
        }

        CTRDGi_RestoreAccessCycle(&rc);
    }

    CTRDGi_UnlockByProcessor(CTRDGi_Work.lockID, &lockInfo);
    return retval;
}

void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r) {
    r->c1 = MI_GetCartridgeRomCycle1st();
    r->c2 = MI_GetCartridgeRomCycle2nd();

    MI_SetCartridgeRomCycle1st(MI_CTRDG_ROMCYCLE1_18);
    MI_SetCartridgeRomCycle2nd(MI_CTRDG_ROMCYCLE2_6);
}

void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r) {
    MI_SetCartridgeRomCycle1st(r->c1);
    MI_SetCartridgeRomCycle2nd(r->c2);
}

void CTRDGi_LockByProcessor(u16 lockID, CTRDGLockByProc *info) {
    while (1) {
        info->irq = OS_DisableInterrupts();

        if (((info->locked = OS_ReadOwnerOfLockCartridge() & CTRDG_LOCKED_BY_MYPROC_FLAG) != 0)
            || (OS_TryLockCartridge(lockID) == 0)) {
            break;
        }
        (void)OS_RestoreInterrupts(info->irq);

        WaitByLoop(1);
    }
}

void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info) {
    if (!info->locked) {
        (void)OS_UnLockCartridge(lockID);
    }

    (void)OS_RestoreInterrupts(info->irq);
}

void CTRDGi_SendtoPxi(u32 data) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_CTRDG, data, FALSE) != 0) {
        WaitByLoop(1);
    }
}
