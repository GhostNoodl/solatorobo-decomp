/* TWL-only PXI service (tag 23) delivering a 64-bit value in four 16-bit parts, and an ARM9 clock switch */
#include "nitro/os.h"
#include "nitro/pxi.h"

typedef void (*TwlInfoCallback)(u64 data, void *arg);

typedef struct TwlInfoWork {
    u32 lock;
    u64 data;
    u32 flags;
    TwlInfoCallback callback;
    void *arg;
} TwlInfoWork;

typedef union TwlInfoResult {
    u64 raw;
    u16 result;
} TwlInfoResult;

static TwlInfoWork sWork = { 0 };

void func_0201bbd4(void);
void func_0201bc38(PXIFifoTag tag, u32 data, BOOL err);
void func_0201bbfc(u32 clock);
void func_01ff82a8(u32 clock);

#define reg_SCFG_CLK (*(vu16 *)0x04004004)

void func_0201bbd4 (void)
{
    PXI_SetFifoRecvCallback(23, func_0201bc38);
    sWork.lock = 0;
}

void func_0201bbfc (u32 clock)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (clock != (reg_SCFG_CLK & 1)) {
        func_01ff82a8(clock);
    }

    (void)OS_RestoreInterrupts(enabled);
}

void func_0201bc38 (PXIFifoTag tag, u32 data, BOOL err)
{
    u16 command = (u16)((data & 0x3f00000) >> 20);
    u16 index = (u16)((data & 0xf0000) >> 16);
    u16 value = (u16)data;

    switch (command) {
    case 1:
        sWork.data |= (u64)value << (index * 16);
        sWork.flags |= 1 << index;
        if (sWork.flags == 0xf) {
            if (sWork.callback) {
                sWork.callback(sWork.data, sWork.arg);
                sWork.callback = NULL;
            }
            sWork.lock = 0;
        }
        break;
    case 2:
        {
            TwlInfoResult r;
            r.result = value;
            if (sWork.callback) {
                sWork.callback(r.raw, sWork.arg);
                sWork.callback = NULL;
            }
            sWork.lock = 0;
        }
        break;
    default:
        OS_Panic("");
    }
}
