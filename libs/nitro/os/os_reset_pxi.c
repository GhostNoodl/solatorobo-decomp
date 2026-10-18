#include "nitro/os.h"
#include "nitro/pxi.h"

#define OS_PXI_COMMAND_RESET      0x10
#define OS_PXI_COMMAND_TERMINATE  0x20
#define OS_PXI_COMMAND_MASK       0x00007f00
#define OS_PXI_COMMAND_SHIFT      8
#define PXI_FIFO_TAG_OS           12

static vu16 OSi_IsResetOccurred = FALSE;
static vu16 OSi_IsTerminateOccurred = FALSE;

void OSi_CommonCallback(u32 tag, u32 data, BOOL err);
void func_02017c1c(u16 data);

void OSi_CommonCallback (u32 tag, u32 data, BOOL err)
{
#pragma unused(tag, err)
    u16 command;

    command = (u16)((data & OS_PXI_COMMAND_MASK) >> OS_PXI_COMMAND_SHIFT);

    if (command == OS_PXI_COMMAND_RESET) {
        OSi_IsResetOccurred = TRUE;
    } else if (command == OS_PXI_COMMAND_TERMINATE) {
        OSi_IsTerminateOccurred = TRUE;
        OS_Terminate();
    } else {
        OS_Panic("");
    }
}

void func_02017c1c (u16 data)
{
    u32 pxiData = (u32)(data << 8);

    while (PXI_SendWordByFifo(PXI_FIFO_TAG_OS, pxiData, FALSE) != 0) {
    }
}
