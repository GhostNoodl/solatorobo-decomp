#include "card_private.h"
#include "nitro/os_alarm.h"

#pragma force_active on


#define REG_MI_MCCNT0_E_MASK   0x8000
#define REG_MI_MCCNT0_I_MASK   0x4000
#define REG_MI_MCCNT0_SEL_MASK 0x2000

#define REG_MI_MCCNT1_START_MASK 0x80000000
#define REG_MI_MCCNT1_RDY_MASK   0x00800000
#define REG_MI_MCCNT1_PC_MASK    0x07000000
#define REG_MI_MCCNT1_CT_MASK    0x08000000
#define REG_MI_MCCNT1_RESB_MASK  0x20000000
#define REG_MI_MCCNT1_WR_MASK    0x40000000
#define REG_MI_MCCNT1_SCR_MASK   0x00002000

#define CARD_ROM_HEADER_CTRL (*(u32 *)0x02fffae0)
#define CARD_ROM_STATUS_FLAG (*(u32 *)0x02fffc00)

extern BOOL data_0208ec30;
void OS_Sleep(u32 msec);

typedef struct {
    u8 unk_00[0x1b4];
    u32 unk_0_4 : 5;
    u32 game_card_nitro_mode : 1;
    u32 unk_6_7 : 2;
    u32 game_card_on : 1;
    u32 unk_9_31 : 23;
} CARDRomHeaderTWLFlags;

void func_0200d1a8(u32 src);
u32 func_0200d1f0(void);
void func_0200d2c0(u32 mask);

#define CARD_ROM_PAGE_SIZE 0x200
#define OS_IE_CARD_DATA    0x80000

typedef struct CARDiDmaOps {
    void (*Copy)(u32 dma, const void *src, void *dst, u32 len);
    void (*Stop)(u32 dma);
} CARDiDmaOps;

typedef struct CARDTransferInfo {
    u32 command;                     // 0x00
    void (*callback)(void *userdata); // 0x04
    void *userdata;                  // 0x08
    u32 src;                         // 0x0c
    u32 dst;                         // 0x10
    u32 len;                         // 0x14
    u32 work;                        // 0x18
} CARDTransferInfo;

typedef int (*CARDiReadFunc)(void *userdata, void *buffer, u32 offset, u32 length);

typedef struct CARDiRomStat {
    u32 base;                   // 0x00
    CARDiReadFunc read_func;    // 0x04
    BOOL flush_ic;              // 0x08
    CARDTransferInfo *transfer; // 0x0c
    CARDTransferInfo info;      // 0x10
} CARDiRomStat;

typedef struct CARDiRomCache {
    BOOL flush_dc;  // 0x00
    u32 cache_page; // 0x04
} CARDiRomCache;

extern CARDiRomStat data_0208e540;
#define rom_stat data_0208e540
extern CARDiRomCache data_0208af30;
#define rom_cache data_0208af30
extern u32 data_0208e600[CARD_ROM_PAGE_SIZE / sizeof(u32)];
#define cache_buf data_0208e600

void func_0200da28(void);
void OS_SetIrqFunction(u32 mask, void (*func)(void));
void *OS_GetDTCMAddress(void);
const void *CARDi_GetRomAccessor(u32 type);
BOOL CARD_WaitRomAsync(void);

int func_0200d36c(void *userdata, void *buffer, u32 offset, u32 length);

void func_0200d488(void) {
    CARDTransferInfo *const info = rom_stat.transfer;

    if (info) {
        info->src += CARD_ROM_PAGE_SIZE;
        info->dst += CARD_ROM_PAGE_SIZE;
        info->len -= CARD_ROM_PAGE_SIZE;
        if (info->len != 0) {
            func_0200d1a8(info->src);
        } else {
            ((const CARDiDmaOps *)cardi_common.unk_50c)->Stop(cardi_common.dma);
            OS_DisableIrqMask(OS_IE_CARD_DATA);
            OS_ResetRequestIrqMask(OS_IE_CARD_DATA);
            rom_stat.transfer = NULL;
            (void)func_0200d1f0();
            func_0200da28();
            if (info->callback) {
                info->callback(info->userdata);
            }
        }
    }
}

void func_0200d528(CARDTransferInfo *info) {
    OSIntrMode bak_psr = OS_DisableInterrupts();

    rom_stat.transfer = info;
    OS_SetIrqFunction(OS_IE_CARD_DATA, func_0200d488);
    OS_ResetRequestIrqMask(OS_IE_CARD_DATA);
    OS_EnableIrqMask(OS_IE_CARD_DATA);
    (void)OS_RestoreInterrupts(bak_psr);

    ((const CARDiDmaOps *)cardi_common.unk_50c)->Copy(cardi_common.dma, (const void *)&reg_MI_MCD1, (void *)info->dst, CARD_ROM_PAGE_SIZE);
    func_0200d1a8(info->src);
}

void func_0200d5a4(void *arg) {
    CARDiCommon *p = &cardi_common;

    (void)func_0200d1f0();
    func_0200da28();
    func_0200d2c0(8);
    p->cmd->result = CARD_RESULT_SUCCESS;
    CARDi_EndTask(p);
}

static inline BOOL CARDi_IsOutOfRange(u32 addr, u32 len, u32 start, u32 end) {
    return (addr + len <= start) || (addr >= end);
}

static inline BOOL CARDi_IsOutOfDTCM(u32 addr, u32 len) {
    return (addr + len <= (u32)OS_GetDTCMAddress()) || (addr >= (u32)OS_GetDTCMAddress() + 0x4000);
}

BOOL func_0200d5d4(u32 dma, void *dst, u32 src, u32 len) {
    return (dma <= 3) && (len > 0) && !((u32)dst & 31) &&
           CARDi_IsOutOfRange((u32)dst, len, 0x01ff8000, 0x02000000) &&
           CARDi_IsOutOfDTCM((u32)dst, len) &&
           !((src | len) & (CARD_ROM_PAGE_SIZE - 1));
}

void func_0200d688(CARDiCommon *p) {
    (void)rom_stat.read_func(NULL, (void *)p->dst, p->src, p->len);
    (void)func_0200d1f0();
    func_0200da28();
    func_0200d2c0(8);
    cardi_common.cmd->result = CARD_RESULT_SUCCESS;
}

void func_0200d6d4(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    CARDiCommon *const p = &cardi_common;

    CARD_CheckEnabled();
    if (!(CARDi_GetAccessLevel() & 4)) {
        OS_Terminate();
    }

    (void)CARDi_WaitForTask(p, TRUE, callback, arg);

    p->unk_50c = (u32)CARDi_GetRomAccessor(dma);
    p->dma = p->unk_50c ? (dma & 3) : (u32)-1;
    if (p->dma <= 3) {
        ((const CARDiDmaOps *)p->unk_50c)->Stop(p->dma);
    }

    p->dst = (u32)dst;
    p->src = (u32)src + rom_stat.base;
    p->len = len;

    rom_stat.info.callback = func_0200d5a4;
    rom_stat.info.userdata = NULL;
    rom_stat.info.src = p->src;
    rom_stat.info.dst = p->dst;
    rom_stat.info.len = p->len;
    rom_stat.info.work = 0;

    if (rom_stat.read_func == func_0200d36c && func_0200d5d4(p->dma, (void *)p->dst, p->src, p->len)) {
        OSIntrMode bak_psr = OS_DisableInterrupts();

        if (rom_stat.flush_ic) {
            CARDi_ICInvalidateSmart((void *)p->dst, p->len, p->unk_0c);
        }
        if (rom_cache.flush_dc) {
            CARDi_DCInvalidateSmart((void *)p->dst, p->len, p->unk_10);
        }
        (void)OS_RestoreInterrupts(bak_psr);

        func_0200d528(&rom_stat.info);
        if (!is_async) {
            (void)CARD_WaitRomAsync();
        }
    } else {
        if (rom_stat.flush_ic) {
            CARDi_ICInvalidateSmart((void *)p->dst, p->len, p->unk_0c);
        }
        (void)CARDi_ExecuteOldTypeTask(func_0200d688, is_async);
    }
}

void CARD_LockRom(u16 lock_id);
void CARD_UnlockRom(u16 lock_id);
s32 OS_GetLockID(void);
void OS_ReleaseLockID(u16 lockID);
extern u8 data_0208e56c[0x88];
void func_0228cd7c(void);

void func_0200d85c(void) {
    rom_stat.read_func = func_0200d36c;
    if (OS_GetBootType() == 1 && *(u32 *)(CARD_GetOwnRomHeader() + 0x80) != 0) {
        u16 id = (u16)OS_GetLockID();
        CARD_LockRom(id);
        (void)func_0200d36c(NULL, data_0208e56c, *(u32 *)(CARD_GetOwnRomHeader() + 0x80), 0x88);
        CARD_UnlockRom(id);
        OS_ReleaseLockID(id);
    }
    if (OS_IsRunOnTwl()) {
        func_0228cd7c();
    }
}
