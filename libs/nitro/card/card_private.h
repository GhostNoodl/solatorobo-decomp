#ifndef CARD_PRIVATE_H
#define CARD_PRIVATE_H

#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nitro/mi.h"

#define PXI_FIFO_TAG_FS 11

#define CARD_STAT_INIT          0x0001
#define CARD_STAT_INIT_CMD      0x0002
#define CARD_STAT_BUSY          0x0004
#define CARD_STAT_TASK          0x0008
#define CARD_STAT_RECV          0x0010
#define CARD_STAT_REQ           0x0020
#define CARD_STAT_CANCEL        0x0040

#define CARD_RESULT_SUCCESS     0
#define CARD_RESULT_CANCELED    7

#define CARD_TARGET_NONE   0
#define CARD_TARGET_ROM    1
#define CARD_TARGET_BACKUP 2

#define OS_LOCK_ID_ERROR (-3)

typedef void (*MIDmaCallback)(void *arg);

typedef struct CARDBackupSpec {
    u32 total_size;            // 0x18
    u32 sect_size;             // 0x1c
    u32 subpage_size;          // 0x20
    u32 page_size;             // 0x24
    u32 addr_width;            // 0x28
    u32 program_page;          // 0x2c
    u32 write_page;            // 0x30
    u32 write_page_total;      // 0x34
    u32 erase_chip;            // 0x38
    u32 erase_chip_total;      // 0x3c
    u32 erase_sector;          // 0x40
    u32 erase_sector_total;    // 0x44
    u32 erase_subsector;       // 0x48
    u32 erase_subsector_total; // 0x4c
    u32 erase_page;            // 0x50
    u8 initial_status;         // 0x54
    u8 padding1[3];
    u32 caps;                  // 0x58
    u8 padding2[4];
} CARDBackupSpec; // size 0x48

typedef struct CARDiCommandArg {
    u32 result;          // 0x00
    u32 type;            // 0x04
    u32 id;              // 0x08
    u32 src;             // 0x0c
    u32 dest;            // 0x10
    u32 len;             // 0x14
    CARDBackupSpec spec; // 0x18
} CARDiCommandArg; // size 0x60

typedef struct CARDiCommon CARDiCommon;
typedef void (*CARDiTaskFunc)(CARDiCommon *p);

struct CARDiCommon {
    CARDiCommandArg *cmd;     // 0x000
    volatile u32 flag;        // 0x004
    u32 priority;             // 0x008
    u32 unk_0c;               // 0x00c
    u32 unk_10;               // 0x010
    s32 lock_owner;           // 0x014
    s32 lock_ref;             // 0x018
    OSThreadQueue lock_queue; // 0x01c
    u32 lock_target;          // 0x024
    OSThread thread;          // 0x028
    u8 stack[0x400];          // 0x0e8
    CARDiTaskFunc task_func;  // 0x4e8
    MIDmaCallback callback;   // 0x4ec
    void *callback_arg;       // 0x4f0
    OSThreadQueue busy_q;     // 0x4f4
    u32 src;                  // 0x4fc
    u32 dst;                  // 0x500
    u32 len;                  // 0x504
    u32 dma;                  // 0x508
    u32 unk_50c;              // 0x50c
    u32 req_type;             // 0x510
    int req_retry;            // 0x514
    u32 req_mode;             // 0x518
    OSThread *cur_th;         // 0x51c
}; // size 0x520?

extern CARDiCommon data_0208df00;
#define cardi_common data_0208df00

void OSi_ReferSymbol(void *symbol);
#define SDK_USING_BACKUP() OSi_ReferSymbol((void *)0x02005050)

void OS_Terminate(void);
u16 OS_GetBootType(void);
BOOL OS_IsRunOnTwl(void);
void OS_SpinWaitSysCycles(u32 cycles);
BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
void OS_WakeupThreadDirect(OSThread *thread);
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
void PXI_Init(void);

void DC_FlushAll(void);
void DC_WaitWriteBufferEmpty(void);
void IC_InvalidateAll(void);
void IC_InvalidateRange(void *startAddr, u32 nBytes);

BOOL CARD_IsAvailable(void);
void CARD_CheckEnabled(void);
void CARD_Enable(BOOL enable);
u32 CARD_GetResultCode(void);
const u8 *CARD_GetRomHeader(void);
const u8 *CARD_GetOwnRomHeader(void);
const u8 *CARD_GetOwnRomHeaderTWL(void);
void CARDi_LockResource(s32 owner, u32 target);
void CARDi_UnlockResource(s32 owner, u32 target);
u32 CARDi_GetAccessLevel(void);
BOOL CARDi_WaitAsync(void);
BOOL CARDi_TryWaitAsync(void);
void CARDi_InitResources(void);
void CARDi_InitCommand(void);
BOOL CARDi_ExecuteOldTypeTask(CARDiTaskFunc task, BOOL async);
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, MIDmaCallback callback, void *callback_arg);
void CARDi_EndTask(CARDiCommon *p);
void CARDi_ICInvalidateSmart(void *buffer, u32 length, u32 threshold);
void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold);
BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);

#endif
